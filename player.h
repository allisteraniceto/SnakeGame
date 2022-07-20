#pragma once
#include <iostream>
using namespace std;

const int SIZE=50;

class player
{
private:
	char nickname[SIZE]; //user defined player name
	int score; //score of snake game
public:
	//default constructor
	player() {
		this->nickname[SIZE - 1] = { 'x' };
		this->score = 0;
	}
	//overloaded constructor
	player(string nickname,int score) {
		strcpy_s(this->nickname, nickname.c_str()); //makes string nickname into a c string and copies it over
		this->score = score;
	}
	//set functions
	void setName(string nickname) {
		strcpy_s(this->nickname, nickname.c_str());
	}
	void setScore(int score) {
		this->score = score;
	}
	//get functions
	char* getNickname() {
		return nickname;
	}
	int getScore() {
		return score;
	}
};

