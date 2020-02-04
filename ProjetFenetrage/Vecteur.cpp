
#include "Point.h"
#include "Vecteur.h"

using namespace std;

Vecteur::Vecteur()
{
	direction[0] = 0;
	direction[1] = 0;
}

Vecteur::Vecteur(float x, float y)
{
	direction[0] = x;
	direction[1] = y;
}

Vecteur::Vecteur(float Ax, float Ay, float Bx, float By)
{
	direction[0] = Bx - By;
	direction[1] = x - Bx;
}

void Vecteur::setPos_1(float x, float y)
{
	pos1.setCoord(x,y);
}

void Vecteur::setPos_2(float x, float y)
{
	pos2.setCoord(x,y);
}

Point& Vecteur::getPos1()
{
	return pos1;
}

Point& Vecteur::getPos2()
{
	return pos2;
}

float* Vecteur::getDirection()
{
	return direction;
}

void Vecteur::setDirection(float X, float Y)
{
	direction[0] = X;
	direction[1] = Y;
}
