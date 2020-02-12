
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
	vector<Point> inputPolygon, newPolygon;


	for (int d = 0; d < SIZE_POLY; d++)
	{
		inputPolygon.push_back(Point(0, 0));
		newPolygon.push_back(Point(0, 0));
	}

	for (int i = 0; i < subjectPolygon.size(); i++)
		newPolygon[i] = subjectPolygon[i];
		

	int newPolygonSize = subjectPolygon.size();

	for (int j = 0; j < clipPolygon.size(); j++)
	{
		// copy new polygon to input polygon & set counter to 0
		for (int k = 0; k < newPolygonSize; k++) { inputPolygon[k] = newPolygon[k]; }
		int counter = 0;

		// get clipping polygon edge
		cp1 = clipPolygon[j];
		cp2 = clipPolygon[(j + 1) % clipPolygon.size()];

		for (int i = 0; i < newPolygonSize; i++)
		{
			// get subject polygon edge
			s = inputPolygon[i];
			e = inputPolygon[(i + 1) % newPolygonSize];
			bool tst = inside(s, cp1, cp2);
			// Case 1: Both vertices are inside:
			// Only the second vertex is added to the output list
			if (inside(s, cp1, cp2) && inside(e, cp1, cp2))
				newPolygon[counter++] = e;

			// Case 2: First vertex is outside while second one is inside:
			// Both the point of intersection of the edge with the clip boundary
			// and the second vertex are added to the output list
			else if (!inside(s, cp1, cp2) && inside(e, cp1, cp2))
			{
				newPolygon[counter++] = intersection(cp1, cp2, s, e);
				newPolygon[counter++] = e;
			}

			// Case 3: First vertex is inside while second one is outside:
			// Only the point of intersection of the edge with the clip boundary
			// is added to the output list
			else if (inside(s, cp1, cp2) && !inside(e, cp1, cp2))
				newPolygon[counter++] = intersection(cp1, cp2, s, e);

			// Case 4: Both vertices are outside
			else if (!inside(s, cp1, cp2) && !inside(e, cp1, cp2))
			{
				// No vertices are added to the output list
			}
		}
		// set new polygon size
		newPolygonSize = counter;
	}

	subjectPolygon = newPolygon;

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
