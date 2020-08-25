#include <GL\glew.h> 
#include <stdlib.h>
#include <GL\freeglut.h>   
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
using namespace std;

using namespace std;
GLint win_width = 500,
win_hight = 500;
int a = 0;
float transValueX;
float transValueY;
float transValueZ;
float nearp;
float farp;
float PMx; float PMx2;
float PMy; float PMy2;
int mouth = 33;
int LTRT = 1;
int UPDN = 1;
int x;
int y;
int control;
float color1 = 0.0f;
float color2 = 0.0f;
float color3 = 0.0f;
float gx1;
float gx2;
int c1;
int c2;

int arrPacMove[4] = { 0,0,0,0 };

int pacPosition[2] = { 1,1 };

GLuint myTexture1;
GLuint myTexture2;
GLuint myTexture3;
GLuint myTexture4;

int MAX_POINTS = 0;

int nPointsEaten = 0;

const int POINTS_GRID_W = 52;
const int POINTS_GRID_H = 52;
int PointsGrid[POINTS_GRID_W][POINTS_GRID_H] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int MoveGrid[POINTS_GRID_W][POINTS_GRID_H] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

float pointsX[POINTS_GRID_W][POINTS_GRID_H];
float pointsY[POINTS_GRID_W][POINTS_GRID_H];
bool bPointsEaten[POINTS_GRID_W][POINTS_GRID_H];

char image1Path[] = "/Users/LENOVO/Desktop/map.bmp";
char image2Path[] = "/Users/LENOVO/Desktop/VideoGame.bmp";
char image3Path[] = "/Users/LENOVO/Desktop/Win.bmp";
char image4Path[] = "/Users/LENOVO/Desktop/GameOver.bmp";



//https://stackoverflow.com/questions/28703436/how-do-i-get-color-to-change-using-glut-and-opengl
void timer(int value)
{
	if (control == 0 || control == 3) {
		//changeColor?
		color1 += 0.001f;
		color2 += 0.003f;
		color3 += color2;
		if (color1 > 1.0)
			color1 = 0;
		if (color2 > 1.0)
			color2 = 0;
		if (color3 > 1.0)
			color3 = 0;

		LTRT = 1;
		UPDN = 1;
		mouth++;

		if (mouth == 40) {
			mouth = 29;
		}

		PMx2 += 0.001;

		if (PMx2 == .40) {
			PMx2 = -.4;
		}

	}
	if (control == 1)
	{


		if (c1 == 0)
		{
			gx1 -= 0.002;
			if (gx1 <= -0.34)
			{
				c1 = 1;
			}
		}

		if (c1 == 1)
		{
			gx1 += 0.002;
			if (gx1 >= 0.36)
			{
				c1 = 0;
			}
		}
		//------------------------------------------


		if (c2 == 0)
		{
			gx2 -= 0.005;
			if (gx2 <= -0.71)
			{
				c2 = 1;
			}
		}

		if (c2 == 1)
		{
			gx2 += 0.005;
			if (gx2 >= 0.25)
			{
				c2 = 0;
			}
		}

		if (abs(PMy - -0.51) <= 0.01 && abs(PMy - -0.51) > 0)
		{
			if (abs(PMx - gx1) <= 0.01 && abs(PMx - gx1) > 0)
			{
				PlaySound(TEXT("loses.wav"), NULL, SND_ASYNC | SND_FILENAME);

				control = 3;
			}
		}


		if (PMy >= -0.12 && PMy <= -0.10)
		{
			if (abs(PMx - gx2) <= 0.002 && abs(PMx - gx2) > 0)
			{
				PlaySound(TEXT("loses.wav"), NULL, SND_ASYNC | SND_FILENAME);

				control = 3;
			}
		}

	}





	if (control == 1)
	{
		for (int i = 0; i < POINTS_GRID_W; i++)
		{
			for (int k = 0; k < POINTS_GRID_H; k++)
			{
				if (bPointsEaten[k][i] == false && (abs(PMx - pointsX[k][i]) < 0.03 && abs(PMy - pointsY[k][i]) < 0.03))
				{
					bPointsEaten[k][i] = true;
					nPointsEaten++;


				}
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}
//http://stackoverflow.com/questions/12518111/how-to-load-a-bmp-on-glut-to-use-it-as-a-texture
GLuint LoadTexture(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;


	errno_t err = fopen_s(&file, filename, "rb");
	if (file == NULL)
	{
		cout << "Unable to open the image file" << endl << "Program will exit :(" << endl;
		exit(0);
		return 0;
	}

	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);

	fclose(file);



	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	/////////////////////////////////////////

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	/////////////////////////////////////////

	free(data);

	if (glGetError() != GL_NO_ERROR)
		printf("GLError in genTexture()\n");

	return texture;
}

void init() {

	transValueX = 0.0;
	transValueY = 0.0;
	transValueZ = 2.0;
	nearp = 0.01;
	farp = 50;

	gluLookAt(transValueX, transValueY, transValueZ, 0, 0, 0, 0, 1, 0);

	//------- Texture ---------
	myTexture1 = LoadTexture(image1Path, 1060, 1114);

	if (myTexture1 == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << myTexture1 << endl;

	myTexture2 = LoadTexture(image2Path, 516, 450);



	myTexture3 = LoadTexture(image3Path, 516, 450);



	myTexture4 = LoadTexture(image4Path, 516, 450);



	if (myTexture1 == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << myTexture1 << endl;






	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(65, (win_width / win_hight), 0.01, 50);
	glMatrixMode(GL_MODELVIEW);



	float startX = -0.87;
	float startY = 0.94;
	float stepX = 0.0382;
	float stepY = 0.035;

	for (int i = 0; i < POINTS_GRID_W; i++)
	{
		for (int k = 0; k < POINTS_GRID_H; k++)
		{
			pointsX[k][i] = startX + i * stepX;
			pointsY[k][i] = startY - k * stepY;

			if (PointsGrid[k][i] == 1)
			{
				bPointsEaten[k][i] = false;
			}
			else
			{
				bPointsEaten[k][i] = true;
			}
		}
	}

}
static void play(void
)
{
	glutPostRedisplay();
}

void reshapeFunc(GLint new_width, GLint new_hight)
{
	glViewport(0, 0, new_width, new_hight);
	win_width = new_width;
	win_hight = new_hight;
}

// draw Circle REFERENCE : https://www.youtube.com/watch?v=NnutNkde5TE
void DrawPacMan() {
	glBegin(GL_POLYGON);
	glPushMatrix();

	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glVertex2d(0, 0);
	glColor4f(0.7f, 0.7f, 0.0f, 0.0f);
	for (int i = 0; i <= mouth; i++) {
		double angle = 2 * 3.1452423 * i / 40;
		double x = cos(angle);
		double y = UPDN * sin(angle);
		glVertex2d(LTRT * x, LTRT * y);
	}


	glPopMatrix();
	glEnd();
}




void PacMove(int x, int y)
{
	if (MoveGrid[pacPosition[0] + x][pacPosition[1] + y] == 1)
	{
		pacPosition[0] += x;
		pacPosition[1] += y;
	}

	PMx = pointsX[pacPosition[0]][pacPosition[1]];
	PMy = pointsY[pacPosition[0]][pacPosition[1]];
}

static void key(unsigned char keyPressed, int x, int y) // key handling
{
	switch (keyPressed)
	{

	case 'd':
		LTRT = 1;
		UPDN = 1;
		mouth++;

		if (mouth == 40) {
			mouth = 29;
		}

		if (PMy == -0.75) {
			PMx += .020;
			if (PMx >= 0.9)
			{
				PMx = 0.92;
				cout << "value x:" << PMx << endl;

			}


		}
		else if (PMy >= 0.91)
		{
			PMx += .020;
			cout << "value x:" << PMx << endl;

			if (PMx >= 0.9)
			{
				PMx = 0.92;

			}

		}
		//-----------------------(part 2)------------------------------------------------------------------------------------
		else if (PMy <= -.23 && PMy >= -.25) {
			PMy = -.23;

			PMx += .020;
			cout << "value x:" << PMx << endl;

			if (PMx >= 0.92)
			{
				PMx = 0.92;


			}

		}
		else if (PMy <= -0.49 && PMy >= -0.53) {
			PMy = -0.51;
			if (PMx >= -0.37 && PMx <= 0.36) {

				PMx += .020;
			}
			cout << "value x:" << PMx << endl;
			if (PMx >= 0.36 && PMx <= 0.38) {
				PMx = 0.36;
			}


		}
		//----------------------(part 3)---------------------------------------------------------------------------------------


		else if (PMy >= -0.11 && PMy <= -0.1) {
			PMy = -0.11;

			if (PMx >= -0.71 && PMx <= 0.27)
			{
				PMx += .020;
			}

			if (PMx >= 0.26 && PMx <= 0.27) {
				PMx = 0.27;
			}
		}
		else if (PMy <= 0.12 && PMy >= 0.1) {

			PMy = 0.11;

			if (PMx >= 0.27)
			{
				PMx += .020;

			}

			if (PMx >= 0.52 && PMx >= 0.53)
			{
				PMx = 0.53;

			}
			cout << "value x:" << PMx << endl;

		}
		else if (PMy >= -0.11 && PMy <= -0.1) {
			PMy = -0.11;

			if (PMx >= -0.71 && PMx <= 0.27)
			{
				PMx += .020;
			}

			if (PMx >= 0.26 && PMx <= 0.27) {
				PMx = 0.27;
			}

			cout << "value x:" << PMx << endl;

		}
		else if (PMy >= 0.15 && PMy <= 0.19) {
			PMy = 0.17;

			if (PMx <= 0.11 && PMx >= -0.25)
			{
				PMx += .020;
			}

			if (PMx >= 0.11 && PMx <= 0.13) {
				PMx = 0.12;
			}

			cout << "value x:" << PMx << endl;

		}
		else if (PMy >= 0.69 && PMy <= 0.81) {

			if (PMx >= -0.2 && PMx <= 0.78) {
				PMx += .020;
				cout << "value x:" << PMx << endl;
			}
			if (PMx >= 0.78 && PMx <= 0.80) {
				PMx = 0.78;
			}

		}
		else if (PMy >= 0.43 && PMy <= 0.48) {

			PMy = 0.45;
			if (PMx >= 0.11 && PMx <= 0.8) {
				PMx += .020;
				cout << "value x:" << PMx << endl;
			}
			if (PMx >= 0.79 && PMx <= 0.83) {
				PMx = 0.78;
			}
		}
		else if (PMy <= 0.58 && PMy >= 0.55) {
			cout << "value x:" << PMx << endl;
			PMy = 0.57;

			if (PMx >= 0.01 && PMx <= 0.91) {
				PMx += .020;
			}
			if (PMx <= 0.95 && PMy >= 0.9) {
				PMx = 0.91;

			}


		}



		break;



	case 'a':
		LTRT = -1;
		UPDN = 1;
		mouth++;

		if (mouth == 40) {
			mouth = 27;
		}

		if (PMy == -0.75) {
			PMx -= .020;

			if (PMx <= -0.8)
			{
				PMx = -0.83;
				cout << "value x:" << PMx << endl;

			}

		}
		if (PMy >= 0.91)
		{
			PMx -= .020;
			if (PMx <= -0.8)
			{
				PMx = -0.83;
				cout << "value x:" << PMx << endl;

			}

		}//-----------------(part 2)----------------------------------------------------------------------------------------------
		else if (PMy <= -.23 && PMy >= -.25) {
			PMy = -.23;
			PMx -= .020;

			if (PMx <= -0.8)
			{
				PMx = -0.83;
				cout << "value x:" << PMx << endl;

			}


		}
		else if (PMy <= -0.49 && PMy >= -0.53) {

			PMy = -0.51;
			if (PMx >= -0.35 && PMx <= 0.37) {

				PMx -= .020;
			}
			if (PMx <= -0.37 && PMx >= -.34) {
				PMx = -0.35;
			}


		}
		//----------------------(part 3)---------------------------------------------------------------------------------------
		else if (PMy <= 0.58 && PMy >= 0.55) {
			cout << "value x:" << PMx << endl;

			PMy = 0.57;



			if (PMx >= 0.02 && PMx <= 0.93) {
				PMx -= .020;
			}
			if (PMx <= 0.03 && PMx >= 0.02) {
				PMx = 0.02;

			}


		}

		//----------------------(part 4)---------------------------------------------------------------------------------------

		else if (PMy >= -0.11 && PMy <= -0.1) {


			PMy = -0.11;
			if (PMx >= -0.71 && PMx <= 0.28)
			{
				PMx -= .020;
			}
			if (PMx <= -0.71 && PMx <= -0.72) {
				PMx = -0.71;
			}

			cout << "value x:" << PMx << endl;

		}
		else if (PMy <= 0.12 && PMy >= 0.1) {

			PMy = 0.11;

			PMx -= .020;

			if (PMx >= 0.25 && PMx <= 0.29)
			{
				PMx = 0.27;

			}
			cout << "value x:" << PMx << endl;

		}
		else if (PMy >= 0.15 && PMy <= 0.19) {
			PMy = 0.17;

			if (PMx >= -0.23 && PMx <= 0.13)
			{
				PMx -= .020;
			}

			if (PMx <= -0.22 && PMx >= -0.24) {
				PMx = -0.23;
			}
			cout << "value x:" << PMx << endl;
		}
		else if (PMy >= 0.69 && PMy <= 0.81) {

			if (PMx >= -0.2 && PMx <= 0.9) {
				PMx -= .020;
				cout << "value x:" << PMx << endl;
			}
			if (PMx >= -0.2 && PMx <= -0.1) {
				PMx = -0.1;
			}

		}
		else if (PMy >= 0.43 && PMy <= 0.48) {

			PMy = 0.45;
			if (PMx >= 0.12 && PMx <= 0.9) {
				PMx -= .020;
				cout << "value x:" << PMx << endl;
			}
			if (PMx >= 0.1 && PMx <= 0.13) {
				PMx = 0.12;
			}
		}





		break;


	case 's':
		UPDN = -1;
		LTRT = -1;
		mouth++;
		if (mouth == 40)
		{
			mouth = 27;
		}

		if (PMx <= -0.8)
		{

			PMy -= .020;
			cout << "value y:" << PMy << endl;
			if (PMy <= -0.75)
			{
				PMy = -0.75;
				cout << "value y:" << PMy << endl;
			}
		}
		else if (PMx >= 0.9 && PMx <= .95)
		{

			PMy -= .020;
			cout << "value y:" << PMy << endl;
			if (PMy <= -0.75)
			{
				PMy = -0.75;
				cout << "value y:" << PMy << endl;
			}
		}//--------------------(part 2)---------------------------------------------------------------------------------------------
		else if (PMx >= -0.01 && PMx <= 0.021)
		{
			PMx = 0.009;

			if (PMy >= -.60 && PMy <= -0.22) {
				PMy -= .020;
			}

			if (PMy >= -0.53 && PMy <= -0.51)
			{
				PMy = -0.51;
				cout << "value y:" << PMy << endl;
			}



			//----------------------(part 4)---------------------------------------------------------------------------------------


		}
		else if (PMx <= 0.65 && PMx >= 0.62) {
			PMx = 0.635;
			if (PMy <= -0.22 && PMy >= -0.75) {
				PMy -= .020;

			}
			if (PMy <= -0.75)
				PMy = -0.75;
			cout << "value y:" << PMy << endl;

		}
		else if (PMx >= -0.61 && PMx <= -0.57) {
			PMx = -0.59;
			if (PMy <= -0.22 && PMy >= -0.75)
			{
				PMy -= .020;
			}
			if (PMy <= -0.75)
			{
				PMy = -0.75;
			}
			cout << "value y:" << PMy << endl;
			if (PMy <= 0.92 && PMy >= 0.02) {
				PMy -= .020;

			}
			if (PMy <= 0.01 && PMy >= -0.00999971)
			{
				PMy = 0.0100003;
			}
		}
		//----------------------(part 5)---------------------------------------------------------------------------------------
		else if (PMx <= -0.19 && PMx >= -0.27) {
			PMx = -0.23;

			if (PMy >= -0.11)
			{
				PMy -= .020;

			}


			if (PMy <= -0.11 && PMy >= -0.13)
			{
				PMy = -0.11;
				cout << "value y:" << PMy << endl;

			}

		}
		else if (PMx >= -0.71 && PMx <= -0.69) {
			PMx = -0.71;

			if (PMy >= -0.11 && PMy <= 0.85)
			{
				PMy -= .020;
			}


			if (PMy >= -0.13 && PMy <= -0.11) {
				PMy = -0.11;
				cout << "value y:" << PMy << endl;

			}
		}
		else if (PMx >= 0.25 && PMx <= 0.28) {

			PMx = 0.27;
			if (PMy <= 0.12 && PMy >= -0.12)
			{
				PMy -= .020;

			}

			if (PMy <= -0.11 && PMy >= -0.14) {
				PMy = -0.11;
				cout << "value y:" << PMy << endl;

			}
		}
		else if (PMx >= 0.37 && PMx <= 0.41) {

			PMx = 0.395;
			PMy -= .020;

			if (PMy <= -0.23) {
				PMy = -0.23;
				cout << "value y:" << PMy << endl;

			}

		}
		else if (PMx >= 0.51 && PMx <= 0.53) {

			PMx = 0.53;
			if (PMy <= 0.12 && PMy >= -0.12)
			{
				PMy -= .020;

			}
			if (PMy <= -0.11 && PMy >= -0.14) {
				PMy = -0.11;
				cout << "value y:" << PMy << endl;

			}
		}
		else if (PMx >= -0.12 && PMx <= -0.1) {

			PMx = -0.1;

			if (PMy <= 0.81 && PMy >= 0.17)
			{
				PMy -= .020;
				cout << "value y:" << PMy << endl;

			}
			if (PMy <= 0.18 && PMy >= 0.14) {
				PMy = 0.17;

			}
		}
		else if (PMx >= 0.1 && PMx <= 0.13) {

			PMx = 0.13;
			cout << "value y:" << PMy << endl;

			if (PMy <= 0.47 && PMy >= 0.17)
			{
				PMy -= .020;
				cout << "value y:" << PMy << endl;

			}
			if (PMy <= 0.18 && PMy >= 0.15) {
				PMy = 0.17;

			}
		}
		else if (PMx >= 0.7 && PMx <= 0.9) {

			PMx = 0.8;

			if (PMy <= 0.45 && PMy >= -0.12)
			{
				PMy -= .020;
			}
			if (PMy <= -0.1 && PMy >= -0.14) {
				PMy = -0.11;

			}
			cout << "value y:" << PMy << endl;

		}



		break;

	case 'w':
		UPDN = -1;
		LTRT = 1;
		mouth++;
		if (mouth == 40)
		{
			mouth = 27;
		}

		if (PMx <= -0.8)
		{

			PMy += .020;
			if (PMy >= 0.91)
			{
				PMy = 0.91;
				cout << "value y:" << PMy << endl;
			}
		}
		else if (PMx >= 0.9)
		{

			PMy += .020;
			if (PMy >= 0.91)
			{
				PMy = 0.91;
				cout << "value y:" << PMy << endl;
			}
		}
		//----------------------(part 2)---------------------------------------------------------------------------------------


		else if (PMx >= -0.01 && PMx <= 0.02)
		{

			PMx = 0.009;
			if (PMy <= -0.22 && PMy >= -0.57) {
				PMy += .020;
			}
			cout << "value y:" << PMy << endl;

			if (PMy >= -.23 && PMy <= -.2)
			{
				PMy = -.23;
			}
			else if (PMy >= 0.57)
			{
				PMy = 0.57;
			}
		}
		else if (PMx <= 0.69 && PMx >= 0.64) {
			PMx = 0.65;

			if (PMy >= -.60 && PMy <= -0.22) {
				PMy += .020;

			}
			if (PMy >= -0.23 && PMy <= -0.22)
				PMy = -0.23;
			cout << "value y:" << PMy << endl;
		}
		//----------------------(part 4)---------------------------------------------------------------------------------------

		else if (PMx >= -0.61 && PMx <= -0.57) {
			PMx = -0.59;
			if (PMy <= -0.25 && PMy >= -0.75) {
				PMy += .020;


			}
			cout << "value y:" << PMy << endl;

			if (PMy >= -0.23 && PMy <= -0.25)
			{

				PMy = -0.23;
			}
			if (PMy <= 0.92 && PMy >= -0.00999971) {
				PMy += .020;

				if (PMy >= 0.91)
				{
					PMy = 0.91;
				}
			}
			cout << "value y:" << PMy << endl;



		}

		else if (PMx <= 0.65 && PMx >= 0.62) {
			PMx = 0.635;
			if (PMy <= -0.22 && PMy >= -0.75) {
				PMy += .020;

			}
			if (PMy >= -0.23 && PMy >= -0.25)
				PMy = -0.23;
			cout << "value y:" << PMy << endl;

		}
		//----------------------(part 4)---------------------------------------------------------------------------------------
		else if (PMx <= -0.19 && PMx >= -0.27) {
			PMx = -0.23;

			if (PMy <= 0.91 && PMy >= -0.12)
			{
				PMy += .020;
			}
			if (PMy >= 0.91)
			{
				PMy = 0.91;
			}
			cout << "value y:" << PMy << endl;

		}
		else if (PMx >= -0.71 && PMx <= -0.69) {
			PMx = -0.71;

			PMy += .020;

			cout << "value y:" << PMy << endl;

			if (PMy >= 0.79 && PMy >= 0.81) {
				PMy = 0.81;
				cout << "value y:" << PMy << endl;

			}
		}
		else if (PMx >= 0.25 && PMx <= 0.28) {

			PMx = 0.27;
			if (PMy >= -0.12 && PMy <= 0.12)
			{
				PMy += .020;
			}

			cout << "value y:" << PMy << endl;

			if (PMy >= 0.12 && PMy >= 0.11) {
				PMy = 0.11;
				cout << "value y:" << PMy << endl;

			}

		}
		else if (PMx >= 0.37 && PMx <= 0.41) {

			PMx = 0.395;
			PMy += .020;
			cout << "value y:" << PMy << endl;

			if (PMy >= 0.12 && PMy >= 0.11) {
				PMy = 0.11;
				cout << "value y:" << PMy << endl;

			}

		}
		else if (PMx >= 0.51 && PMx <= 0.53) {

			PMx = 0.53;
			if (PMy <= 0.12 && PMy >= -0.12)
			{
				PMy += .020;

			}
			if (PMy >= 0.12 && PMy >= 0.11) {
				PMy = 0.11;
				cout << "value y:" << PMy << endl;

			}
		}
		else if (PMx >= -0.12 && PMx <= -0.1) {

			PMx = -0.1;

			if (PMy <= 0.81 && PMy >= 0.17)
			{
				PMy += .020;
				cout << "value y:" << PMy << endl;

			}
			if (PMy <= 0.84 && PMy >= 0.8) {
				PMy = 0.8;

			}
		}

		else if (PMx >= 0.1 && PMx <= 0.13) {

			PMx = 0.13;
			cout << "value y:" << PMy << endl;

			if (PMy <= 0.47 && PMy >= 0.17)
			{
				PMy += .020;
				cout << "value y:" << PMy << endl;

			}
			if (PMy <= 0.47 && PMy >= 0.45) {
				PMy = 0.45;

			}
		}
		else if (PMx >= 0.7 && PMx <= 0.9) {

			if (PMy >= -0.12)
			{
				PMx = 0.8;
			}
			if (PMy <= 0.46 && PMy >= -0.12)
			{
				PMy += .020;
			}
			if (PMy <= 0.47 && PMy >= 0.45) {
				PMy = 0.45;

			}
			cout << "value y:" << PMy << endl;


		}
		break;


	case '1':
		control = 1;

		break;
	case '0':
		PlaySound(TEXT("Starting.wav"), NULL, SND_ASYNC | SND_FILENAME);

		PMx = 0;
		PMy = -0.75;
		mouth = 29;
		control = 0;


		break;



	default:
		fprintf(stderr, "Please press q|Q,or w|W,or e|E");
		break;
	}
}


void circle() {
	float radius = 0.20;
	float towpI = 2 * 3.14;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= 40; i++) {
		glVertex2d(radius*cosf(i*towpI / 40), radius*sinf(i*towpI / 40));
	}
	glEnd();

}


void circle2() {
	float radius = 0.10;
	float towpI = 2 * 3.14;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= 40; i++) {
		glVertex2d(radius*cosf(i*towpI / 40), radius*sinf(i*towpI / 40));
	}
	glEnd();


}
void squer() {
	glBegin(GL_POLYGON); {
		glVertex2f(-0.2, -0.2);
		glVertex2f(-0.2, 0.2);
		glVertex2f(0.2, 0.2);
		glVertex2f(0.2, -0.2);
	} glEnd();

}

void gost1() {





	glPushMatrix();
	glScalef(0.5, 0.6, 1);
	glColor3f(1.0, 0.0, 0);
	glTranslatef(-0.05, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.2, 1);
	glTranslatef(-0.05, -0.2, 0.0);
	glColor3f(1.0, .0, 0);
	squer();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.15, 0.2, 1);
	glColor3f(1.0, 1.0, 1);
	glTranslatef(0.1, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.15, 0.2, 1);
	glColor3f(1.0, 1.0, 1);
	glTranslatef(-0.5, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 0.1, 1);
	glColor3f(0.0, 0.0, 0);
	glTranslatef(0.1, 0, 0.0);
	circle();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.1, 0.1, 1);
	glColor3f(0.0, 0.0, 0);
	glTranslatef(-0.7, 0, 0.0);
	circle();
	glPopMatrix();


}

void gost2() {





	glPushMatrix();
	glScalef(0.5, 0.6, 1);
	glColor3f(0.0, 1.0, 0);
	glTranslatef(-0.05, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.2, 1);
	glTranslatef(-0.05, -0.2, 0.0);
	glColor3f(0.0, 1.0, 0);
	squer();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.15, 0.2, 1);
	glColor3f(1.0, 1.0, 1);
	glTranslatef(0.1, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.15, 0.2, 1);
	glColor3f(1.0, 1.0, 1);
	glTranslatef(-0.5, 0, 0.0);
	circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 0.1, 1);
	glColor3f(0.0, 0.0, 0);
	glTranslatef(0.1, 0, 0.0);
	circle();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.1, 0.1, 1);
	glColor3f(0.0, 0.0, 0);
	glTranslatef(-0.7, 0, 0.0);
	circle();
	glPopMatrix();


}
static void motion(int	x, int	y)
{
}

void pacman() {
	glPushMatrix();

	glTranslatef(PMx, PMy, 0.0);
	glRotatef(20, 0.0, 0.0, 1.0);
	glScalef(0.033, 0.033, 1);

	DrawPacMan();

	glPopMatrix();
}
void pacman2() {
	glPushMatrix();

	glTranslatef(PMx2, PMy2, 0.0);
	glRotatef(20, 0.0, 0.0, 1.0);
	glScalef(0.06, 0.06, 1);

	DrawPacMan();

	glPopMatrix();
}


void output(int x, int y, const char* string, void* font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}
}

void displayPoint(float x, float y)
{
	//glBindTexture(GL_TEXTURE_2D, texturePoint);
	glPointSize(7.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x, y);
	glEnd();
}

void display()
{
	if (nPointsEaten >= 275)
	{
		control == 2;
		PlaySound(TEXT("Wins.wav"), NULL, SND_ASYNC | SND_FILENAME);

	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(transValueX, transValueY, transValueZ, 0, 0, 0, 0, 1, 0);

	if (control == 0)
	{
		glBindTexture(GL_TEXTURE_2D, myTexture2);
	}
	glEnable(GL_TEXTURE_2D);
	if (control == 1)
	{
		glBindTexture(GL_TEXTURE_2D, myTexture1);
	}

	if (control == 2)
	{
		glBindTexture(GL_TEXTURE_2D, myTexture3);
	}
	if (control == 3)
	{
		glBindTexture(GL_TEXTURE_2D, myTexture4);
	}
	glBegin(GL_QUADS);
	glPushMatrix();
	glTexCoord2f(0, 0); glVertex2f(-1.0f, -1.0f);
	glTexCoord2f(1, 0); glVertex2f(1.0f, -1.0f);
	glTexCoord2f(1, 1); glVertex2f(1.0f, 1.0f);
	glTexCoord2f(0, 1); glVertex2f(-1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	if (control == 0) {
		glPushMatrix();
		glTranslatef(-.38, -1.1, 0.0);
		glColor3f(color1, color2, color3);
		output(0, 0, "PRESS '1' TO START THE GAME", GLUT_BITMAP_TIMES_ROMAN_24);
		glPopMatrix();



		pacman2();
		PMy2 = 1;

	}
	if (control == 3)
	{
		glPushMatrix();
		glTranslatef(-.44, -1.1, 0.0);
		glColor3f(color1, color2, color3);
		output(0, 0, "PRESS '0' TO RESTART THE GAME", GLUT_BITMAP_TIMES_ROMAN_24);
		glPopMatrix();
	}

	if (control == 1)
		for (int i = 0; i < POINTS_GRID_W; i++)
		{
			for (int k = 0; k < POINTS_GRID_H; k++)
			{
				if (!bPointsEaten[k][i])
					displayPoint(pointsX[k][i], pointsY[k][i]);
			}
		}


	if (control == 1) {


		glPushMatrix();
		glTranslatef(gx1, -0.51, 0);
		glScalef(0.4, 0.4, 0.0);
		gost1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(gx2, -0.11, 0);
		glScalef(0.4, 0.4, 0.0);
		gost2();
		glPopMatrix();

		pacman();

		stringstream strs;
		strs << nPointsEaten;
		string temp_str = strs.str();
		char* char_type = (char*)temp_str.c_str();



		glPushMatrix();
		glTranslatef(-.6, -.91, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		output(0, 0, char_type, GLUT_BITMAP_9_BY_15);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-.9, -.91, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		output(0, 0, " SCORE: ", GLUT_BITMAP_HELVETICA_18);
		glPopMatrix();
	}
	glFlush();
	//glutSwapBuffers();
}

////////////////
//    Main    //
////////////////
int main(int argc, char** argv)
{

	PMx = -.4;

	PMx2 = -.4;
	PMy = -0.75;
	PMy2 = -0.75;
	control = 0;
	gx1 = 0.36;
	c1 = 0;
	c2 = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("Packman");
	init();
	glutIdleFunc(play);
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeFunc);
	glutMotionFunc(motion);
	glutKeyboardFunc(key);

	glutTimerFunc(0, timer, 0); // this func will do loop 
	PlaySound(TEXT("Starting.wav"), NULL, SND_ASYNC | SND_FILENAME);
	glutMainLoop();

	return 0;
}