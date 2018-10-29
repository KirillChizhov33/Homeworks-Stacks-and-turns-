#pragma once
class Stack
{
	int Size;
	int Index;
	int * Mem;
	Stack() {};
public:
	Stack(int _Size);
	Stack(const Stack &b);
	Stack & operator =(const Stack &b);
	bool IsStackEmpty();
	bool IsStackFull();
	void AddElement(int Elem);
	int DeleteElement();
	void DeleteAllElements();
};

