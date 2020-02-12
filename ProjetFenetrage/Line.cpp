#define NON_INIT -10.0f
#define WHITE 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define PURPLE 5
#define CYAN 6
#define BLACK 7
#define _USE_MATH_DEFINES

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <../../common/GLShader.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "Vecteur.h"
#include "Line.h"


using namespace std;

Line::Line()
{

}

Line::Line(float P1x, float P1y, float P2x, float P2y, float width, float height)
{
	setPos(P1x, P1y, width, height);
	setPos(P2x, P2y, width, height);
}

Line::~Line()
{
	
}

void Line::drawLine()
{


	if (!isDrawable) return;
	glBegin(GL_LINES);
	
	cout << endl;
	glColor3fv(color.data());
	glVertex2f(lineVec.getPos1()[0], lineVec.getPos1()[1]);
	glColor3fv(color.data());
	glVertex2f(lineVec.getPos2()[0], lineVec.getPos2()[1]);

	if (lineDebug)
	{
		cout << "___x0___" << lineVec.getPos1()[0];
		cout << "___y0___" << lineVec.getPos1()[1];
		cout << "___x1___" << lineVec.getPos2()[0];
		cout << "___y1___" << lineVec.getPos2()[1];
	}



	if (normalDebug) 
	{
		float x = lineVec.getPos2()[0] - normalVec.getPos1()[0];
		float y = normalVec.getPos2()[1] - normalVec.getPos1()[1];

		float offsetX = (normalVec.getPos2()[0] + normalVec.getPos1()[0]) / 2;
		float offsetY = (normalVec.getPos2()[1] + normalVec.getPos1()[1]) / 2;


		glVertex2f(offsetX, offsetY);
		glVertex2f(y + offsetX, -x + offsetY);
	}
	glEnd();
}

Vecteur Line::getVecteur()
{
	return lineVec;
}

Vecteur Line::getNormal()
{
	return normalVec;
}




void Line::setPos(float x, float y, float width, float height)
{

	x = -1.0f + 2 * x / width;
	y = 1.0f - 2 * y / height;

	if (flipFlop == false)
	{
		lineVec.setPos_1(x, y);
		isDrawable = false;
		flipFlop = true;
	}
	else 
	{
		lineVec.setPos_2(x, y);
		isDrawable = true;
		flipFlop = false;
		lineVec.setDirection(lineVec.getPos2()[0] - lineVec.getPos1()[0], lineVec.getPos2()[1] - lineVec.getPos1()[1]);
		normalVec.setDirection(lineVec.getPos2()[0] - lineVec.getPos1()[0], -(lineVec.getPos2()[1] - lineVec.getPos1()[1]));
		
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


