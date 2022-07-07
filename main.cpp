/*
Programmer: Allister Aniceto
Purpose: Snake Game
Date Modified: 7/6/22
Compiler: MS VS 2019
*/

#include <iostream>
#include <conio.h> //console input/ouput library
#include <Windows.h> // function library to use sleep() to slow down the snake
using namespace std;

bool gameOver;
const int WIDTH = 40; //map dimensions
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() { //start of the game (default)
	gameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;

}
void draw() { //prints walls of the game
	//system("cls"); //windows clear screen
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	for (int i = 0; i < WIDTH+2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else{
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == WIDTH - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < WIDTH+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;
}
void input() { // controls of the snake
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'x':
			gameOver = true;
			break;
		}
	}
}
void logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)\
		gameOver = true;
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}
}

int main() {
	setup();

	while (!gameOver) {
		draw();
		if (dir == UP || dir == DOWN) { // to slow down the snake
			Sleep(65);
		}
		if (dir == LEFT || dir == RIGHT) {
			Sleep(55);
		}
		input();
		logic();
		//sleep(10); //slows game down (optional)
	}
	system("pause");
	return 0;
}