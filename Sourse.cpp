#include "Header.h"
Turn::Turn(int _Size)
{
	Size = _Size;
	if (Size <= 0)
	{
		throw - 1;
	}
	Mem = new Task[Size];
	LowIndex = 0;
	HighIndex = Size - 1;
}
Turn::Turn(const Turn &b)
{
	Size = b.Size;
	LowIndex = b.LowIndex;
	HighIndex = b.HighIndex;
	Mem = new Task[Size];
	int i = LowIndex;
	while (i != HighIndex + 1)
	{
		Mem[i] = b.Mem[i];
		i = (i + 1) % Size;
	}
}
bool Turn::IsTurnEmpty()
{
	return (LowIndex == (HighIndex + 1) % Size);
}
bool Turn::IsTurnFull()
{
	return (LowIndex == (HighIndex + 2) % Size);
}

void Turn::AddElement(Task Elem)
{
	if (IsTurnFull())
	{
		throw - 2;
	}
	HighIndex = (HighIndex + 1) % Size;
	Mem[HighIndex] = Elem;
}
Task Turn::DeleteElement()
{
	if (IsTurnEmpty())
	{
		throw - 3;
	}
	Task k = Mem[LowIndex];
	LowIndex = (LowIndex + 1) % Size;
	return k;
}