#pragma once


class Vecteur
{
	private:
		float direction[2];
		Point pos1;
		Point pos2;
		

	public:
		Vecteur();
		Vecteur(float x, float y);
		Vecteur(float Ax, float Ay, float Bx, float By);
		void setPos_1(float x, float y);
		void setPos_2(float x, float y);
		Point getPos1();
		Point getPos2();
		float* getDirection();
		void setDirection(float X, float Y);
};

