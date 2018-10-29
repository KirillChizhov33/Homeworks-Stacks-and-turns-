#include "Header.h"
Stack::Stack(int _Size)
{
	Size = _Size;
	Mem = new int[Size];
	LowIndex = -1;
	HighIndex = Size;
}
Stack::Stack(const Stack & b)
{
	Size = b.Size;
	Mem = new int[Size];
	LowIndex = b.LowIndex;
	HighIndex = b.HighIndex;
	for (int i = 0; i < LowIndex; i++)
	{
		Mem[i] = b.Mem[i];
	}
	for (int j = HighIndex; j < Size; j++)
	{
		Mem[j] = b.Mem[j];
	}
}
bool Stack::IsStackEmpty(int Pointer)
{
	if (Pointer != 0 && Pointer != 1)
	{
		throw - 1;
	}
	if (Pointer == 0) return LowIndex == -1;
	if (Pointer == 1) return HighIndex == Size - 1;
}
bool Stack::IsStackFull()
{
	return (LowIndex + 1 == HighIndex);
}
void Stack::AddElement(int Elem, int Pointer)
{
	if (IsStackFull())
	{
		throw - 2;
	}
	if (Pointer == 0)
	{
		LowIndex++;
		Mem[LowIndex] = Elem;
	}
	if (Pointer == 1)
	{
		HighIndex--;
		Mem[HighIndex] = Elem;
	}
	if (Pointer != 0 && Pointer != 1)
	{
		throw - 3;
	}
}
int Stack::DeleteElement(int Pointer)
{
	if (IsStackEmpty(Pointer))
	{
		throw - 4;
	}
	if (Pointer == 0)
	{
		LowIndex--;
		return Mem[LowIndex + 1];
	}
	if (Pointer == 1)
	{
		HighIndex++;
		return Mem[HighIndex - 1];
	}
	if (Pointer != 0 && Pointer != 1)
	{
		throw - 3;
	}
}
void Stack::DeleteAllElements()
{
	HighIndex = Size - 1;
}
