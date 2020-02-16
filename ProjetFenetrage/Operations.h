#define POP 100
#pragma once

#include <vector>
#include "Line.h"

using namespace std;

class Operations
{
	private:
		static bool inside(Point p, Point p1, Point p2, bool sensClick);
		static void clip(vector<Point>& polygonPoint, int x1, int y1, int x2, int y2);
		static bool isIntersect(Point cp1, Point cp2, float currentLineY);
		static Point intersection(Point cp1, Point cp2, Point s, Point e);
		static float ScreenToPixel(float point, float windowSize);
		static float PixelToScreen(float point, float windowSize);
		static Point getMinMax(const vector<Point>& polygon);
		static int x_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
			int Bx1, int By1, int Bx2, int By2);
		static int y_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
			int Bx1, int By1, int Bx2, int By2);

	public:

		
		static void sutherisland(vector<Point>& windowPoint , vector<Point>& polygonPoint, bool sensClick);
		static void filling(const vector<Point>& polygon,vector<Point>& fillingPoints , int windowWidth, int windowHeight);
		
		
};

