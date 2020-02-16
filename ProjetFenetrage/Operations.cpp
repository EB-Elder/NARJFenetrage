
#define SIZE_POLY 100
#include <iostream>
#include <algorithm>
#include "Operations.h"

void Operations::clip(vector<Point>& polygonPointRef,
	int x1, int y1, int x2, int y2)
{

		
}

void Operations::filling(const vector<Point>& polygon, vector<Point>& fillingPoints, int windowWidth, int windowHeight)
{
	fillingPoints.clear();
	//Coord screen
	Point min_max_Y = getMinMax(polygon);
	Point pixel_min_max_Y(ScreenToPixel(min_max_Y[0], windowHeight), ScreenToPixel(min_max_Y[1], windowHeight));
	for (int i = pixel_min_max_Y[0]; i < pixel_min_max_Y[1]; i++)
	{
		vector<float> tmpX;
		float currentScreenY = PixelToScreen(i, windowHeight);
		Point rayStart(-1, currentScreenY);
		Point rayEnd(1, currentScreenY);
		for (int j = 0; j < polygon.size(); j++)
		{
			int indexNext = (j + 1) % polygon.size();
			if (!isIntersect(polygon[j], polygon[indexNext], currentScreenY)) continue;
			Point intersectionPoint;
			intersectionPoint = intersection(rayStart, rayEnd, polygon[j], polygon[indexNext]);
			bool isExistInTmp = false;
			for (int k = 0; k < tmpX.size(); k++)
			{
				if (tmpX[k] == intersectionPoint[0])
				{
					isExistInTmp = true;
					break;
				}
			}
			if (!isExistInTmp)
			{
				tmpX.push_back(intersectionPoint[0]);
			}
		}
		sort(tmpX.begin(), tmpX.end());
		for (int l = 0; l < tmpX.size(); l++)
		{
			fillingPoints.push_back(Point(tmpX[l], currentScreenY));
		}
	}

}

float Operations::ScreenToPixel(float point, float windowSize)
{
	return (point + 1 ) * 0.5 * windowSize;
}

float Operations::PixelToScreen(float point, float windowSize)
{
	float res = point / windowSize;
	res = ((res * 2) - 1);
	return res;
}


Point Operations::getMinMax(const vector<Point>& polygon)
{
	//X = min_Y
	//Y = max_Y
	Point res(999999.f, -9999999.f);
	for (int i = 0; i < polygon.size(); i++)
	{
		if (polygon[i][1] < res[0])
		{
			res[0] = polygon[i][1];
		}

		if (polygon[i][1] > res[1])
		{
			res[1] = polygon[i][1];
		}
	}

	return res;
}

void Operations::sutherisland(vector<Point>& subjectPolygon, vector<Point>& clipPolygon, bool sensClick)
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

			if (inside(s, cp1, cp2, sensClick) && inside(e, cp1, cp2, sensClick))
			{
				PolygonS.push_back(e);
			}
			else if (!inside(s, cp1, cp2, sensClick) && inside(e, cp1, cp2, sensClick))
			{
				PolygonS.push_back(intersection(cp1, cp2, s, e));
				PolygonS.push_back(e);
			}
			else if (inside(s, cp1, cp2, sensClick) && !inside(e, cp1, cp2, sensClick))
			{
				PolygonS.push_back(intersection(cp1, cp2, s, e));
			}

		}
		if(PolygonS.size() > 0)
			PolygonTemp = PolygonS;

	}

	subjectPolygon = PolygonTemp;

}

bool Operations::isIntersect(Point cp1, Point cp2, float currentLineY)
{
	float maxY = std::fmaxf(cp1[1], cp2[1]);
	float minY = std::fminf(cp1[1], cp2[1]);

	if (maxY > currentLineY && minY < currentLineY)
	{
		return true;
	}
	return false;
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

bool Operations::inside(Point p, Point p1, Point p2, bool sensClick)
{
	if(sensClick)
		return (p2[1]- p1[1]) * p[0] + (p1[0] - p2[0]) * p[1] + (p2[0] * p1[1] - p1[0] * p2[1]) < 0;
	return (p2[1]- p1[1]) * p[0] + (p1[0] - p2[0]) * p[1] + (p2[0] * p1[1] - p1[0] * p2[1]) > 0;
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
