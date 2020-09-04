#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void draw_ship(int x,int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}

void erase_ship(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}

int main() {
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x,y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' and x>0)  { draw_ship(--x, y); }
			if (ch == 'd' and x<80) { draw_ship(++x, y); }
			if (ch == 'w' and y>0) 
			{
				draw_ship(x, --y);
				erase_ship(x, y + 1);
			}
			if (ch == 's' and y<30) 
			{ 
				draw_ship(x, ++y); 
				erase_ship(x, y - 1);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}