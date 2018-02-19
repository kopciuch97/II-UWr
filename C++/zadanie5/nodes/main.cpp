#include "nodes.h"
#include <iostream>



int main()
{
	std::cout << "################ LIST ################\n";
	List MyList;
	std::cout << MyList;
	MyList.Add(0, 10);
	std::cout << MyList;
	MyList.Add(1, 20);
	std::cout << MyList;
	MyList.Add(2, 30);
	std::cout << MyList;
	MyList.Add(1, 40);
	std::cout << MyList;
	MyList.Add(0, 90);


	std::cout << "----------------------\n";

	while (MyList.Remove(1))
	{
		MyList.WriteAll();
	}

	std::cout << "\n################ QUEUE ################\n";
	Queue MyQueue;
	MyQueue.WriteAll();
	MyQueue += 10;
	MyQueue.WriteAll();
	MyQueue += 20;
	MyQueue.WriteAll();
	MyQueue += 30;
	MyQueue.WriteAll();
	MyQueue += 40;
	MyQueue.WriteAll();
	MyQueue += 90;
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
	*/
	std::cout << "\n################ STACK ##############\n";
	Stack MyStack;
	MyStack.WriteAll();
	MyStack += 10;
	MyStack.WriteAll();
	MyStack += 20;
	MyStack.WriteAll();
	MyStack += 30;
	MyStack.WriteAll();
	MyStack += 40;
	MyStack.WriteAll();
	MyStack += 90;
	MyStack.WriteAll();

	while (--MyStack)
	{
		MyStack.WriteAll();
		//if(*MyStack) std::cout<<(*MyStack)->Value<<'\n';
		if (MyStack.Ready()) std::cout << MyStack.Ready()->Value << '\n';
	}
	std::cin.get();
}