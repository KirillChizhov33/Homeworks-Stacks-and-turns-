#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
	int cnt = 0, Sum = 0;
	Stack Test(100);
	int op = 0;
	int First = 0;
	int Second = 1;
	while (op != 5)
	{
		printf("1.Add(+)\n");
		printf("2.Subtract(-)\n");
		printf("3.Undo\n");
		printf("4.Do\n");
		printf("5.Exit\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (Test.IsStackFull())
			{
				system("cls");
				printf("%d\n StackIsFull\n", Sum);
			}
			else
			{
				printf("Enter the number =");
				scanf("%d", &cnt);
				Test.AddElement(cnt, First);
				Sum = Sum + cnt;
				Test.DeleteAllElements();
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 2:
			if (Test.IsStackFull())
			{
				system("cls");
				printf("%d\n StackIsFull\n", Sum);
			}
			else
			{
				printf("Enter the number =");
				scanf("%d", &cnt);
				Test.AddElement(-cnt, First);
				Sum = Sum - cnt;
				Test.DeleteAllElements();
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 3:
			if (Test.IsStackEmpty(First))
			{
				system("cls");
				printf("%d\n StackIsEmpty\n", Sum);
			}
			else
			{
				cnt = Test.DeleteElement(First);
				Test.AddElement(cnt, Second);
				Sum = Sum - cnt;
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 4:
			if (Test.IsStackEmpty(Second))
			{
				system("cls");
				printf("%d\nStackIsEmpty\n", Sum);
			}
			else
			{
				cnt = Test.DeleteElement(Second);
				Test.AddElement(cnt, First);
				Sum = Sum + cnt;
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		}
	}
	return 0;
}

