#pragma once
#include <iostream>


class List
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
	bool Remove(int Index = 0);
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
	Node() :Next(nullptr), Prev(nullptr) { ; }

	void* operator new(size_t MemSize);
	void operator delete(void* ToRemove);
};

class Queue:private List
{
public:
	void operator+=(double Value);
	bool operator--();
	void WriteAll();
	Node* Ready();
	Node* operator*();
};

class Stack:private List
{
public:
	void operator+=(double Value);
	bool operator--();
	void WriteAll();
	Node* Ready();
	Node* operator*();

};






