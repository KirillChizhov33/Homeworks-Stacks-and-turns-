#include "Header.h"
int main()
{
	Turn CPU1(100);
	Turn CPU2(100);
	Turn A(100);
	Task temp1, temp2, M;
	int k = 1;
	for (int i = 0; i < 100 - 1; i++)
	{
		Task test(i + 1, (rand() % 15) + 1);
		A.AddElement(test);
		cout << A[i] << endl;
	}
	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (A.IsTurnEmpty())
			{
				cout << "Turn is empty" << endl;
			}
			if (CPU1.IsTurnEmpty())
			{
				temp1 = A[i];
				CPU1.AddElement(temp1);
				temp1.TimeAdd(); //Если выборка задачи занимает 1 такт
			}
			if (temp1.GetTime() == 0)
			{
				CPU1.DeleteElement();
				break;
			}
			if (CPU2.IsTurnEmpty())
			{
				if (i == 0)
				{
					temp2 = A[i + 1];
					i++;
				}
				else
				if (A[i] == temp2)
				{
					temp2 = A[i + 1];
					i++;
				}
				else temp2 = A[i];
				CPU2.AddElement(temp2);
				temp2.TimeAdd();
			}
			if (temp2.GetTime() == 0)
			{
				M = temp2;
				CPU2.DeleteElement();
				break;
			}
			temp1.TimeStep();
			temp2.TimeStep();
			cout << "CPU1: " << temp1 << "  ||  ";
			cout << "CPU2: " << temp2 << endl;
		}
	}
	return 0;
}
