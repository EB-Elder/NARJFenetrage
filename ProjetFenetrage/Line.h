#pragma once

#include "Vecteur.h"

class Line
{
	public:
		Line();
		virtual ~Line();
		void drawLine();
		Vecteur getVecteur();
		Vecteur getNormal();
		void switchColor();
		bool isDrawable;
		void setPos(float x, float y, float width, float height);

		
	private:
		
		Vecteur normalVec;
		Vecteur lineVec;
		int colorCounter = 0;
		bool flipFlop = false;
		bool normalDebug = false;
		bool lineDebug = false;
		std::vector <float> color = { 1.0,0.0,0.0 };
		
};

