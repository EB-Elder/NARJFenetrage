#define NON_INIT -10.0f
#define WHITE 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define PURPLE 5
#define CYAN 6
#define BLACK 7

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <../../common/GLShader.h>
#include <iostream>
#include <vector>
#include "Point.h"
#include "Line.h"


using namespace std;

Line::Line()
{
}


Line::~Line()
{
	
}

void Line::drawLine()
{

	if (!isDrawable) return;
	glBegin(GL_LINES);
	cout << pos1.getPosX()<< endl;
	glColor3fv(color.data());
	glVertex2f(pos1[0], pos1[1]);
	glColor3fv(color.data());
	glVertex2f(pos2[0], pos2[1]);
	glEnd();
}

Point Line::getPos1()
{
	return pos1;
}

Point Line::getPos2()
{
	return pos2;
}

void Line::setPos_1(float x, float y)
{
	pos1 = Point(x, y);
}

void Line::setPos_2(float x, float y)
{
	pos2 = Point(x, y);
}


void Line::setPos(float x, float y, float width, float height)
{

	x = -1.0f + 2 * x / width;
	y = 1.0f - 2 * y / height;

	if (flipFlop == false)
	{
		setPos_1(x, y);
		isDrawable = false;
		flipFlop = true;
	}
	else 
	{
		setPos_2(x, y);
		isDrawable = true;
		flipFlop = false;
		
	}
	
}

void Line::switchColor()
{
	if (colorCounter > BLACK)
	{
		colorCounter = 0;
	}
	switch (colorCounter)
	{
		case WHITE:
			color = { 1.0,1.0,1.0 };
			break;
		case RED:
			color = { 1.0,0.0,0.0 };
			break;
		case GREEN:
			color = { 0.0,1.0,0.0 };
			break;
		case BLUE:
			color = { 0.0,0.0,1.0 };
			break;
		case YELLOW:
			color = { 1.0,1.0,0.0 };
			break;
		case PURPLE:
			color = { 1.0,0.0,1.0 };
			break;
		case CYAN:
			color = { 0.0,1.0,1.0 };
			break;
		case BLACK:
			color = { 0.0,0.0,0.0 };
			break;
	}
	colorCounter++;
}

