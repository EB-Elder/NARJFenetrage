#pragma once

using namespace std;

class Line
{
	public:
		Line();
		virtual ~Line();
		void drawLine();
		Point getPos1();
		Point getPos2();
		void setPos(float x, float y, float width, float height);
		void switchColor();
		bool isDrawable;

		
	private:
		Point pos1;
		Point pos2;
		int colorCounter = 0;
		bool flipFlop = false;
		void setPos_1(float x, float y);
		void setPos_2(float x, float y);
		vector <GLfloat> color = { 1.0,0.0,0.0 };
		
};

