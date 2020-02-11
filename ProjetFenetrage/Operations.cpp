

#include <iostream>
#include "Operations.h"

vector<Point> Operations::clip(vector<Point>& polygonPoint,
	int x1, int y1, int x2, int y2)
{
		int poly_size = polygonPoint.size();
		vector<Point> newPolygon;
		int new_poly_size = 0;

		// (ix,iy),(kx,ky) are the co-ordinate values of 
		// the points 
		for (int i = 0; i < poly_size; i++)
		{
			// i and k form a line in polygon 
			int k = (i + 1) % poly_size;
			int ix = polygonPoint[i][0], iy = polygonPoint[i][1];
			int kx = polygonPoint[k][0], ky = polygonPoint[k][1];

			// Calculating position of first point 
			// w.r.t. clipper line 
			int i_pos = (x2 - x1) * (iy - y1) - (y2 - y1) * (ix - x1);

			// Calculating position of second point 
			// w.r.t. clipper line 
			int k_pos = (x2 - x1) * (ky - y1) - (y2 - y1) * (kx - x1);

			// Case 1 : When both points are inside 
			if (i_pos < 0 && k_pos < 0)
			{
				//Only second point is added 
				newPolygon.push_back(Point(kx, ky));
				new_poly_size++;
			}

			// Case 2: When only first point is outside 
			else if (i_pos >= 0 && k_pos < 0)
			{
				// Point of intersection with edge 
				// and the second point is added 
				newPolygon.push_back(Point(
					(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky)),
					(y_intersect(x1,y1, x2, y2, ix, iy, kx, ky))));

				new_poly_size++;

				newPolygon.push_back(Point(kx, ky));
				new_poly_size++;
			}

			// Case 3: When only second point is outside 
			else if (i_pos < 0 && k_pos >= 0)
			{
				//Only point of intersection with edge is added 
				newPolygon.push_back(Point(
					(x_intersect(x1, y1, x2, y2, ix, iy, kx, ky)),
					(y_intersect(x1, y1, x2, y2, ix, iy, kx, ky))));
				new_poly_size++;
			}

			// Case 4: When both points are outside 
			else
			{
				//No points are added 
			}
		}

		// Copying new points into original array 
		// and changing the no. of vertices 
		poly_size = new_poly_size;
		for (int i = 0; i < 20; i++)
		{
				polygonPoint.push_back(Point(0, 0));
		}
		for (int i = 0; i < poly_size; i++)
		{	
			polygonPoint[i][0] = newPolygon[i][0];
			polygonPoint[i][1] = newPolygon[i][1];
		}

		return polygonPoint;
}

vector<Point> Operations::sutherisland(const vector<Point>& windowPoint, vector<Point>& polygonPoint)
{
	int clipper_size = windowPoint.size();
	//i and k are two consecutive indexes 
	for (int i = 0; i < clipper_size; i++)
	{
		int k = (i + 1) % clipper_size;

		// We pass the current array of vertices, it's size 
		// and the end points of the selected clipper line 
		polygonPoint = clip(polygonPoint, windowPoint[i][0],
			windowPoint[i][1], windowPoint[k][0],
			windowPoint[k][1]);
	} 

	// Printing vertices of clipped polygon 
	for (int i = 0; i < polygonPoint.size(); i++)
		cout << '(' << polygonPoint[i][0] <<
		", " << polygonPoint[i][1] << ") ";

	return polygonPoint;
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
