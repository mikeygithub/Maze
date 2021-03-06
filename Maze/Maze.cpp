// Maze.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "iostream"
using namespace std;
const int MAX=10;
typedef struct MyStruct
{
	int i;
	int j;
	int k;
}DATA;

class Maze {
public:
	Maze(){}
	Maze(int enter1, int enter2, int export1, int export2);
	void Map(int(&map)[MAX][MAX]);
	void Map(int map[MAX][MAX]);
	void Launch();
private:
	int enter1;//入口坐标
	int enter2;
	int export1;//出口坐标
	int export2;
	int map[MAX][MAX];
};
Maze::Maze(int enter1, int enter2, int export1, int export2) {
	this->enter1 = enter1;
	this->enter2 = enter2;
	this->export1 = export1;
	this->export2 = export2;
}
void Maze::Map(int (&map)[MAX][MAX]) {
	int map[MAX][MAX] ={
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },
	{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
	};

}
int main()
{
	//Maze test();
	Maze test;
	test.Launch();
    return 0;
}

