//Stack
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
	int cnt = 0, Sum = 0;
	Stack Undo(100), Do(100);
	int op = 0;
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
			if (Undo.IsStackFull())
			{
				system("cls");
				printf("%d\n StackIsFull\n", Sum);
			}
			else
			{
				printf("Enter the number =");
				scanf("%d", &cnt);
				Undo.AddElement(cnt);
				Sum = Sum + cnt;
				Do.DeleteAllElements();
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 2:
			if (Undo.IsStackFull())
			{
				system("cls");
				printf("%d\n StackIsFull\n", Sum);
			}
			else
			{
				printf("Enter the number =");
				scanf("%d", &cnt);
				Undo.AddElement(-cnt);
				Sum = Sum - cnt;
				Do.DeleteAllElements();
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 3:
			if (Undo.IsStackEmpty())
			{
				system("cls");
				printf("%d\n StackIsEmpty\n", Sum);
			}
			else
			{
				cnt = Undo.DeleteElement();
				Do.AddElement(cnt);
				Sum = Sum - cnt;
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		case 4:
			if (Do.IsStackEmpty())
			{
				system("cls");
				printf("%d\nStackIsEmpty\n", Sum);
			}
			else
			{
				cnt = Do.DeleteElement();
				Undo.AddElement(cnt);
				Sum = Sum + cnt;
				system("cls");
				printf("%d\n", Sum);
			}
			break;
		}
	}
	return 0;
}
