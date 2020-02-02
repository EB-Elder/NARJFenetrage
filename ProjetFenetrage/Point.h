#pragma once
class Point
{

	private:
		float coord[2] = { 0,0 };

	public:
		float getPosX();
		float getPosY();
		void setCoord(float x, float y);
		float* getCoord();
		void drawPoint();
		Point(float x, float y);
		Point();
		~Point();
		float operator[] (int index) const;
		float& operator[] (int index);
};

