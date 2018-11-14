#pragma once
#include <iostream>
using namespace std;
class Task
{
	int ID;
	int time;
public:
	Task()
	{
		ID = rand() % 50;
		time = (rand() % 15) + 1;
	}
	Task(int _ID, int _time)
	{
		ID = _ID;
		time = _time;
		if (time <= 0)
		{
			throw - 1;
		}
	}
	int GetId()
	{
		return ID;
	}
	int GetTime()
	{
		return time;
	}
	void TimeStep()
	{
		time--;
	}
	void TimeAdd()
	{
		time++;
	}
	Task & operator=(const Task &b)
	{
		if (this == &b) return *this;
		ID = b.ID;
		time = b.time;
		return *this;
	}
	bool operator == (const Task &b)
	{
		if (ID != b.ID && time != b.time)
			return 0;
		return 1;
	}
	friend ostream & operator<<(ostream &os, const Task &v)
	{
		os << "  ID: " << v.ID << " time: " << v.time << ";";
		return os;
	}
};
class Turn
{
	Task * Mem;
	int Size;
	int LowIndex;
	int HighIndex;
public:
	Turn() {};
	Turn(int _Size);
	Turn(const Turn &b);
	bool IsTurnEmpty();
	bool IsTurnFull();
	void AddElement(Task Elem);
	Task DeleteElement();
	Task & operator [](int index)
	{
		return Mem[index];
	}
	friend ostream & operator<<(ostream &os, const Turn &v)
	{
		for (int i = 0; i < v.Size; i++)
		{
			cout << v.Mem[i];
		}
		return os;
	}
};

