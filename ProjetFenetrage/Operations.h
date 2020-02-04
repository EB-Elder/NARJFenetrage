#pragma once

#include <vector>
#include "Line.h"

using namespace std;

class Operations
{
	private:
		void clip();

	public:
		static vector<Point>& sutherisland(const vector<Point>& windowPoint , vector<Point>& polygonPoint);
		static int x_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
						int Bx1, int By1, int Bx2, int By2);
		static int y_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
						int Bx1, int By1, int Bx2, int By2);
};

