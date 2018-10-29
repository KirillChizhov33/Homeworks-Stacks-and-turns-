#pragma once
class Stack
{
	int Size;
	int LowIndex;
	int HighIndex;
	int * Mem;
public:
	Stack(int _Size);
	Stack(const Stack & b);
	bool IsStackEmpty(int Pointer);
	bool IsStackFull();
	void AddElement(int Elem, int Pointer);
	int DeleteElement(int Pointer);
	void DeleteAllElements();
};


