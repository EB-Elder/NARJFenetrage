#include "Operations.h"

vector<Point>& Operations::sutherisland(const vector<Point>& windowPoint, vector<Point>& polygonPoint)
{
	for (int i = 0; i < windowPoint.size(); i+=2)
	{
		int k = i + 1;
		int ix = windowPoint[i][0];
		int iy = windowPoint[i][1];
		int kx = windowPoint[k][0];
		int ky = windowPoint[k][1];
	
		for (int j = 0; j < polygonPoint.size(); j+=2)
		{
			int x1 = polygonPoint[j][0];
			int y1 = polygonPoint[j][1];
			int x2 = polygonPoint[j+1][0];
			int y2 = polygonPoint[j+1][1];


			int i_pos = (x2 - x1) * (iy - y1) - (y2 - y1) * (ix - x1);

			int k_pos = (x2 - x1) * (ky - y1) - (y2 - y1) * (kx - x1);

			if (i_pos < 0 && k_pos < 0)
			{
				continue;
			}
			else if (i_pos >= 0 && k_pos < 0)
			{

				polygonPoint[j][0] = x_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
				polygonPoint[j][1] = y_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);

				polygonPoint[j+1][0] = kx;
				polygonPoint[j+1][1] = ky;
				continue;
			}
			else if (i_pos < 0 && k_pos >= 0)
			{
				//Only point of intersection with edge is added 
				polygonPoint[j][0] = x_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
				polygonPoint[j][1] = y_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
				continue;
			}
			else
			{
				continue;
			}
		}
	}
	return polygonPoint;
}

void Operations::clip()
{

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
