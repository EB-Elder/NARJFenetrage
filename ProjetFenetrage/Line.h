#pragma once
class Line
{
	public:
		Line();
		virtual ~Line();
		void drawLine();
		Point getPos1();
		Point getPos2();
		void setPos(float x, float y, float width, float height);
		bool isDrawable;

		
	private:
		Point pos1;
		Point pos2;
		bool flipFlop = false;
		void setPos_1(float x, float y);
		void setPos_2(float x, float y);
		
};

