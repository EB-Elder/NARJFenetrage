#pragma once

#include "Vecteur.h"

using namespace std;

class Line
{
	public:
		Line();
		Line(float P1x, float P1y, float P2x, float P2y, float width, float height);
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
		vector<Point> pointsTab;
		int colorCounter = 0;
		bool flipFlop = false;
		bool normalDebug = false;
		bool lineDebug = false;
		std::vector <float> color = { 1.0,0.0,0.0 };
		
};

