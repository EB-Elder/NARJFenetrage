#include <GL/glew.h>
#include <GL/freeglut.h>
#include <../../common/GLShader.h>
#include <iostream>
#include "Point.h"



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



/* TODO: drawPoints inside of a polygon

function inside(point, vs) {
	// ray-casting algorithm based on
	// http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html

	var x = point[0], y = point[1];

	var inside = false;
	for (var i = 0, j = vs.length - 1; i < vs.length; j = i++) {
		var xi = vs[i][0], yi = vs[i][1];
		var xj = vs[j][0], yj = vs[j][1];

		var intersect = ((yi > y) != (yj > y))
			&& (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
		if (intersect) inside = !inside;
	}

	return inside;
};

*/