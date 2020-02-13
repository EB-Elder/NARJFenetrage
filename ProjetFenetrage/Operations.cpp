
#define SIZE_POLY 100
#include <iostream>
#include "Operations.h"

void Operations::clip(vector<Point>& polygonPointRef,
	int x1, int y1, int x2, int y2)
{

		
}

void Operations::sutherisland(vector<Point>& subjectPolygon, vector<Point>& clipPolygon)
{
	Point cp1, cp2, s, e;
	vector<Point> PolygonTemp, PolygonS;

	PolygonTemp = subjectPolygon;

	for (int i = 0; i < clipPolygon.size(); i++)
	{
		PolygonS.clear();
		cp1 = clipPolygon[i];
		cp2 = clipPolygon[(i + 1) % clipPolygon.size()];
		for (int j = 0; j < PolygonTemp.size(); j++)
		{
			s = PolygonTemp[j];
			e = PolygonTemp[(j + 1) % PolygonTemp.size()];

			if (inside(s, cp1, cp2) && inside(e, cp1, cp2))
			{
				PolygonS.push_back(e);
			}
			else if (!inside(s, cp1, cp2) && inside(e, cp1, cp2))
			{
				PolygonS.push_back(intersection(cp1, cp2, s, e));
				PolygonS.push_back(e);
			}
			else if (inside(s, cp1, cp2) && !inside(e, cp1, cp2))
			{
				PolygonS.push_back(intersection(cp1, cp2, s, e));
			}

		}
		if(PolygonS.size() > 0)
			PolygonTemp = PolygonS;

	}

	subjectPolygon = PolygonTemp;
	int u = 0;

	

}

Point Operations::intersection(Point cp1, Point cp2, Point s, Point e)
{
	Point dc = { cp1[0] - cp2[0], cp1[1] - cp2[1] };
	Point dp = { s[0] - e[0], s[1] - e[1] };

	float n1 = cp1[0] * cp2[1] - cp1[1] * cp2[0];
	float n2 = s[0] * e[1] - s[1] * e[0];
	float n3 = 1.0 / (dc[0] * dp[1] - dc[1] * dp[0]);

	return { (n1 * dp[0] - n2 * dc[0]) * n3, (n1 * dp[1] - n2 * dc[1]) * n3 };
} 

bool Operations::inside(Point p, Point p1, Point p2)
{
	return (p2[1]- p1[1]) * p[0] + (p1[0] - p2[0]) * p[1] + (p2[0] * p1[1] - p1[0] * p2[1]) < 0;
}

int Operations::x_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
							int Bx1, int By1, int Bx2, int By2)
{
	int num = (Ax1*Ay2 - Ay1 * Ax2) * (Bx1 - Bx2) -
		      (Ax1 - Ax2) * (Bx1*By2 - By1 * Bx2);

	int den = (Ax1 - Ax2) * (By1 - By2) - (Ay1 - Ay2) * (Bx1 - Bx2);
	return num / den;
}

int Operations::y_intersect(int Ax1, int Ay1, int Ax2, int Ay2,
							int Bx1, int By1, int Bx2, int By2)
{
	int num = (Ax1*Ay2 - Ay1 * Ax2) * (By1 - By2) -
		(Ay1 - Ay2) * (Bx1*By2 - By1 * Bx2);

	int den = (Ax1 - Ax2) * (By1 - By2) - (Ay1 - Ay2) * (Bx1 - Bx2);
	return num / den;
}
