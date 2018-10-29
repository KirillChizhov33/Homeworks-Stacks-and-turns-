//Stack
#include "Header.h"
Stack::Stack(int _Size)
{
	Size = _Size;
	Mem = new int[Size];
	Index = -1;
}
Stack::Stack(const Stack &b)
{
	Size = b.Size;
	Index = b.Index;
	for (int i = 0; i < Index; i++)
	{
		Mem[i] = b.Mem[i];
	}
}
Stack & Stack::operator =(const Stack &b)
{
	if (this == &b)	return *this;
	delete[]Mem;
	Size = b.Size;
	Index = b.Index;
	Mem = new int[Size];
	for (int i = 0; i < Index; i++)
	{
		Mem[i] = b.Mem[i];
	}
	return *this;
}
bool Stack::IsStackEmpty()
{
	return (Index == -1);
}
bool Stack::IsStackFull()
{
	return (Index == Size - 1);
}
void Stack::AddElement(int Elem)
{
	if (IsStackFull())
	{
		throw - 1;
	}
	Index++;
	Mem[Index] = Elem;
}
int Stack::DeleteElement()
{
	if (IsStackEmpty())
	{
		throw - 2;
	}
	Index--;
	return Mem[Index + 1];
}
void Stack::DeleteAllElements()
{
	Index = -1;
}
