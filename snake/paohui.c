#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define right 40
#define botton 20
int snake[right][botton] = {0};
int tail_x, tail_y;
int head_x, head_y;
int moves ;
int foodx, foody;
int i, j;

void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // 用于隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void start()
{
	snake[right / 2][botton / 2] = 1;
	for (i = 1; i < 4;i++)
		{
			snake[right / 2 - i][botton / 2] = i + 1;
		}
	moves = 4;
	HideCursor();
	foodx = rand() % (right - 4) + 2;
	foody = rand() % (botton - 4) + 2;
	snake[foodx][foody] = -2;
}

void show()
{
	gotoxy(0,0);
	for (i = 0; i < botton;i++)
	{
		for (j = 0; j < right;j++)
		{
			if((i==0)||(i==botton-1)||(j==0)||(j==right-1))
				printf("#");
			else if(snake[j][i]==1)
				printf("@");
			else if (snake[j][i]>0)
				printf("o");
			else if(snake[j][i]==-2)
				printf("F");
			else
				printf(" ");
		}
		printf("\n");
	}
	Sleep(200);
}

void withoutinput()
{
	int max = 0;
	int newheadx, newheady;
	for (i = 0; i < botton;i++)
	{
		for (j = 0; j < right;j++)
		{
			if(snake[j][i]>0)
			{
				snake[j][i]++;
				if(max<snake[j][i])
					{
						max = snake[j][i];
						tail_y = i;
						tail_x = j;
					}
				if(snake[j][i]==2)
			    	{
						head_x = j;
				    	head_y = i;
					}
			}
		}
	}
	switch (moves)
	{
	case 1:newheadx=head_x ;
		newheady = head_y - 1;
		break;
	case 2:newheadx=head_x ;
		newheady = head_y + 1;
		break;	
	case 3:newheadx=head_x -1;
		newheady = head_y;
		break;
	case 4:newheadx=head_x +1;
		newheady = head_y ;
		break;
	}
	if(snake[newheadx][newheady]==-2)
	{
		snake[foodx][foody] = 0;
		foodx = rand() % (right - 4) + 2;
	    foody = rand() % (botton - 4) + 2;
		snake[foodx][foody] = -2;
	}
	else
		snake[tail_x][tail_y] = 0;
	if((snake[newheadx][newheady]>0)||(snake[newheadx][newheady]==-1))
	{	
		printf("任务失败!\n");
		system("pause");
		exit(0);
	}
	else
		snake[newheadx][newheady] = 1;
	
}

void withinput()
{
	char input;
	if(kbhit())
	{
		input = getch();
		if(input=='w')
			{
				moves = 1;
				withoutinput();
			}
		else if(input=='s')
			{
				moves = 2;
				withoutinput();
			}
		else if(input=='a')
			{
				moves = 3;
				withoutinput();
			}
		else if(input=='d')
			{
				moves = 4;
				withoutinput();
			}
	}
}

int main()
{
	start();
	while(1)
	{
		show();
		withoutinput();
		withinput();
	}
	return 0;
}