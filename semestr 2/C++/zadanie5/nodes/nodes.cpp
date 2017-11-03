#include <iostream>
#include <cstdlib>
#include "nodes.h"


/*class List
{
public:
    class Node;
private:
    Node *First;
    Node *Last;
    int Size;

protected:
    Node* GetFirst();
    Node* GetLast();
public:
    List();
    ~List();
    List(List &&Obj);
    List(const List &Obj);
    void Add(int Index, double Value);
    bool Remove(int Index=0);
    virtual void WriteAll();
    bool Empty();
    int GetSize();
    double Front();
    double Back();
    List& operator =(const List &Obj);
    List& operator =(List &&Obj);

    friend std::ostream& operator<<(std::ostream &Out, const List &Obj);
};

class List::Node
{
public:
    double Value;
    Node *Next;
    Node *Prev;
    Node():Next(nullptr), Prev(nullptr){;}

    void* operator new(size_t MemSize);
    void operator delete(void* ToRemove);
};
*/
std::ostream& operator<<(std::ostream &Out, const List &Obj)
{
    if(Obj.First)
    {
        Out<<"List: ";
        List::Node *temp = Obj.First;
        while(temp)
        {
            Out<<temp->Value<<' ';
            temp = temp->Next;
        }
    }
    else Out<<"[Is empty]";
    Out<<'\n';
	return Out;
}

List::~List() //destruktor
{
    if(First)
    {
        Node* Temp = First;
        while(Temp)
        {
            delete Temp;
            Temp = Temp->Next;
        }
    }

    First=nullptr;
    Last=nullptr;
    Size=0;
}
List::List(const List &Obj) //kopiujacy
{
    Size = Obj.Size;
    Node *TempObj = Obj.First;
    First = new Node(*TempObj);
    Node *Temp = First;
    while(TempObj)
    {
        Temp->Next = new Node(*TempObj->Next);
        TempObj = TempObj->Next;
        Temp = Temp->Next;
    }
}
List::List(List &&Obj)// konstruktor przenoszenia
{
    Size = Obj.Size;
    Obj.Size = 0;
    First = Obj.First;
    Obj.First = nullptr;
}

List& List::operator =(const List &Obj) //operator kopiujacy
{
    if(First)  List::~List();
    Size = Obj.Size;
    Node *TempObj = Obj.First;
    First = new Node(*TempObj);
    Node *Temp = First;
    while(TempObj)
    {
        Temp->Next = new Node(*TempObj->Next);
        TempObj = TempObj->Next;
        Temp = Temp->Next;
    }
    return *this;
}

List& List::operator =(List &&Obj) //operator przeniesienia
{
    if(First) List::~List();
    Size = Obj.Size;
    Obj.Size = 0;
    First = Obj.First;
    Obj.First = nullptr;
    return *this;
}

// ##################################### Memory Breaker ###################################

const unsigned int NODES_SIZE=1000;

List::Node NODES_TAB[NODES_SIZE];
bool NODES_TAB_BOOL[NODES_SIZE]{};

void* List::Node::operator new(size_t MemSize)
{
    for(int i=0; i<NODES_SIZE; ++i)
    {
        if(!NODES_TAB_BOOL[i])
        {
            NODES_TAB[i]=List::Node();
            NODES_TAB_BOOL[i]=true;
            return (NODES_TAB+i);
        }
    }
    return nullptr;
}

void List::Node::operator delete(void* _ToRemove)
{
    //rzutowanie czystego adresu na adres Node*
    List::Node *ToRemove = reinterpret_cast<List::Node*>(_ToRemove);

    for(int i=0; i<NODES_SIZE; ++i)
    {
        if(ToRemove==NODES_TAB+i)
        {
            NODES_TAB_BOOL[i]=false;
        }
    }
}

// ##################################### List ###################################

List::Node* List::GetFirst()
{
    return First;
}
List::Node* List::GetLast()
{
    return Last;
}

List::List()
    : First(nullptr), Last(nullptr), Size(0)
{
    ;
}
void List::Add(int Index, double Value)
{
    if(Index>Size+1 || Index<0) //Poza lista
    {
        std::cout<<"Error: [Element doesn't exist]\n";
        return;
    }

    Node *NewNode = new Node;
    NewNode->Value = Value;

    if(First)
    {
        if(Index==0)
        {
            NewNode->Next=First;
            First->Prev=NewNode;
            First = NewNode;
        }
        else if(Index==Size)
        {
            NewNode->Prev=Last;
            Last->Next=NewNode;
            Last = NewNode;
        }
        else
        {
            Node *temp = First;
            while(temp->Next && Index)
            {
                temp = temp->Next;
                --Index;
            }
            Node *temp_before = temp->Prev;
            temp_before->Next = NewNode;
            NewNode->Prev = temp_before;
            NewNode->Next = temp;
            temp->Prev = NewNode;
        }
    }
    else
    {
        First = NewNode;
        Last = NewNode;
    }
    ++Size;
}
bool List::Remove(int Index)
{
    if(!Size)
    {
        std::cout<<"Error: [List is empty]\n";
        return false;
    }
    if(Index>=Size || Index<0) //Poza lista
    {
        std::cout<<"Error: [Element doesn't exist]\n";
        return false;
    }
    if(Size==1)
    {
        if(Index==0)
        {
            delete First;
            First = nullptr;
            Last = nullptr;
        }
    }
    else
    {
        if(Index==0)
        {
            Node *ToRemove = First;
            First = First->Next;
            First->Prev = nullptr
				;
            delete ToRemove;
        }
        else if(Index==Size-1)
        {
            Node *ToRemove = Last;
            Last = Last->Prev;
            Last->Next = nullptr;
            delete ToRemove;
        }
        else
        {
            Node *temp = First;
            while(temp->Next && Index)
            {
                temp = temp->Next;
                --Index;
            }
            Node *ToRemove = temp;
            temp->Prev->Next=temp->Next;
            temp->Next->Prev=temp->Prev;
            delete ToRemove;
        }
    }
    --Size;
    return true;
}
void List::WriteAll()
{
    if(First)
    std::cout<<"List: ";
    if(First)
    {
        Node *temp = First;
        while(temp)
        {
            std::cout<<temp->Value<<' ';
            temp = temp->Next;
        }
    }
    else std::cout<<"[Is empty]";
    std::cout<<'\n';
}
bool List::Empty()
{
    return !Size;
}
int List::GetSize()
{
    return Size;
}
double List::Front()
{
    if(Size)
    {
        return First->Value;
    }
    return 0;
}
double List::Back()
{
    if(Size)
    {
        return Last->Value;
    }
    return 0;
}



void  Queue::operator+=(double Value)
{
	Add(GetSize(), Value);
}
bool  Queue::operator--()
{
        return Remove(0);
}
void Queue::WriteAll()
{
	std::cout<<"Queue: ";
        if(GetFirst())
        {
            Node *temp = GetFirst();
            while(temp)
            {
                std::cout<<temp->Value<<' ';
                temp = temp->Next;
            }
        }
        else std::cout<<"[Is empty]";
        std::cout<<'\n';
    }
List::Node* Queue::Ready()
{
	return GetFirst();
}
List::Node* Queue::operator*()
{
	return GetFirst();
}


void Stack::operator+=(double Value)
{
      Add(GetSize(), Value);
}

bool Stack::operator--()
{
	return Remove((GetSize())-1);
}

void Stack::WriteAll()
{
	std::cout<<"Stack: ";
    if(GetFirst())
       {
           Node *temp = GetFirst();
           while(temp)
           {
               std::cout<<temp->Value<<' ';
                temp = temp->Next;
            }
        }
        else std::cout<<"[Is empty]";
        std::cout<<'\n';
	}
List::Node* Stack::Ready()
{
	    return GetLast();
}
List::Node* Stack::operator*()
{
	    return GetLast();
}


/*int main()
{
    std::cout<<"################ LIST ################\n";
    List MyList;
    std::cout<<MyList;
    MyList.Add(0, 10);
    std::cout<<MyList;
    MyList.Add(1, 20);
    std::cout<<MyList;
    MyList.Add(2, 30);
    std::cout<<MyList;
    MyList.Add(1, 40);
    std::cout<<MyList;
    MyList.Add(0, 90);
  

    std::cout<<"----------------------\n";

    while(MyList.Remove(1))
    {
        MyList.WriteAll();
    }

    std::cout<<"\n################ QUEUE ################\n";
    Queue MyQueue;
    MyQueue.WriteAll();
    MyQueue+=10;
    MyQueue.WriteAll();
    MyQueue+=20;
    MyQueue.WriteAll();
    MyQueue+=30;
    MyQueue.WriteAll();
    MyQueue+=40;
    MyQueue.WriteAll();
    MyQueue+=90;
    MyQueue.WriteAll();
	
	while (--MyQueue)
	{
		MyQueue.WriteAll();
		//if(*MyStack) std::cout<<(*MyStack)->Value<<'\n';
		if (MyQueue.Ready()) std::cout << (*MyQueue)->Value << '\n';
	}
	
	/*
    while(--MyQueue)
    {
        MyQueue.WriteAll();
    }
	
	std::cout<<"\n################ STACK ##############\n";
	Stack MyStack;
	MyStack.WriteAll();
    MyStack+=10;
    MyStack.WriteAll();
    MyStack+=20;
    MyStack.WriteAll();
    MyStack+=30;
    MyStack.WriteAll();
    MyStack+=40;
    MyStack.WriteAll();
    MyStack+=90;
    MyStack.WriteAll();

    while (--MyStack)
    {
    	MyStack.WriteAll();
    	//if(*MyStack) std::cout<<(*MyStack)->Value<<'\n';
    	if(MyStack.Ready()) std::cout<<MyStack.Ready()->Value<<'\n';
	}
    std::cin.get();
}
/*
TO DO:
+ 1. operator* (gotowy do usuniecia w queue i stacku)

2. list :
konstuktor kopiuj¹cy, konstuktor przenosz¹cy, destruktor, przypisanie kopiuj¹ce, przypisanie przenosz¹ce
oraz zaprzyjaŸniony operator pisania do strumienia

3.Node:
new, delete
*/






