#define NON_INIT -10.0f

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <../../common/GLShader.h>
#include <iostream>
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
	glVertex2f(pos1[0], pos1[1]);
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

