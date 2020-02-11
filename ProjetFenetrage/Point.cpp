#include <GL/glew.h>
#include <GL/freeglut.h>
#include <../../common/GLShader.h>
#include <iostream>
#include "Point.h"

using namespace std;


float Point::getPosX() 
{
	return coord[0];
}

float Point::getPosY()
{
	return coord[1];
}

void Point::setCoord(float x, float y)
{
	coord[0] = x;
	coord[1] = y;
}

float* Point::getCoord()
{
	return coord;
}

void Point::drawPoint()
{
	glBegin(GL_POINTS);
	glVertex2f(coord[0], coord[1]);
	glEnd();
}

Point::Point(float x, float y)
{
	coord[0] = x;
	coord[1] = y;
}

Point::Point()
{
	coord[0] = 0;
	coord[1] = 0;
}


Point::~Point()
{
	
}

float Point::operator[] (int index) const
{
	if (index != 0 && index != 1)
	{
		throw std::out_of_range("Use 0 for X and 1 for Y");
	}

	return coord[index];
}

float& Point::operator[] (int index)
{
	if (index != 0 && index != 1)
	{
		throw std::out_of_range("Use 0 for X and 1 for Y");
	}
	
	return coord[index];
}
