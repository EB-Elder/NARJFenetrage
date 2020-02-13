//
//
//

// GLEW_STATIC force le linkage statique
// c-a-d que le code de glew est directement injecte dans l'executable
#define WINDOW_X 800.0f
#define WINDOW_Y 800.0f

#include <GL/glew.h>
#include <../../common/GLShader.h>
#include <GL/freeglut.h>




// les repertoires d'includes sont:
// ../libs/glfw-3.3/include			fenetrage
// ../libs/glew-2.1.0/include		extensions OpenGL
// ../libs/stb						gestion des images (entre autre)

// les repertoires des libs sont (en 64-bit):
// ../libs/glfw-3.3/lib-vc2015
// ../libs/glew-2.1.0/lib/Release/x64

// Pensez a copier les dll dans le repertoire x64/Debug, cad:
// glfw-3.3/lib-vc2015/glfw3.dll
// glew-2.1.0/bin/Release/x64/glew32.dll		si pas GLEW_STATIC

// _WIN32 indique un programme Windows
// _MSC_VER indique la version du compilateur VC++
#if defined(_WIN32) && defined(_MSC_VER)
#pragma comment(lib, "glew32.lib")			// glew32.lib si pas GLEW_STATIC
#pragma comment(lib, "opengl32.lib")
#elif defined(__APPLE__)
#elif defined(__linux__)
#endif

#include <iostream>
#include <time.h>
#include <vector>
#include "Point.h"
#include "Line.h"
#include "Operations.h"
#include "stb_image.h"

using namespace std;

vector<Line> polygon;
vector<Line> window;
vector<Point> polygonPoint;
vector<Point> windowPoint;
bool windowMode = false;
Line tmpLine;


void clickedScene(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float xf = -1.0f + 2 * x / WINDOW_X;
		float yf = 1.0f - 2 * y / WINDOW_Y;

		if (windowMode)
		{
			//window.push_back(tmpLine);
			windowPoint.push_back(Point(xf, yf));

		}
		else
		{
			polygonPoint.push_back(Point(xf, yf));

		}
		//if (tmpLine.isDrawable)
		//{
		//	polygon.push_back(tmpLine);
		//	cout << window.size() << endl;
		//}
		
	}

	

}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//for (int i = 0; i < polygon.size(); i++)
	//{
	//	polygon[i].drawLine();
	//}
	//for (int j = 0; j < window.size(); j++)
	//{
	//	window[j].drawLine();
	//}
	glBegin(GL_LINES);
	//Tracer de polygon
	for (int i = 0; i < polygonPoint.size(); i++)
	{
		glColor3f(255, 255, 255);
		glVertex2f(polygonPoint[i][0], polygonPoint[i][1]);
		glVertex2f(polygonPoint[(i+1)% polygonPoint.size()][0], polygonPoint[(i+1)% polygonPoint.size()][1]);
		
	}
	
	//Tracer de fenetre
	for (int j = 0; j < windowPoint.size(); j++)
	{
		glColor3f(255, 0, 0);
		glVertex2f(windowPoint[j][0], windowPoint[j][1]);
		glVertex2f(windowPoint[(j + 1) % windowPoint.size()][0], windowPoint[(j + 1) % windowPoint.size()][1]);
	}
	glEnd();
	glutSwapBuffers();
	glutMouseFunc(clickedScene);

}



void menuFunc(int id)
{
	
	switch (id)
	{

		case 1:
			tmpLine.switchColor();
			cout << "Couleur";
			break;
		case 2:
			windowMode = false;
			cout << "Tracer polygone";
			break;
		case 3:
			windowMode = true;
			tmpLine.switchColor();
			tmpLine.switchColor();
			tmpLine.switchColor();
			cout << "Tracer fenetre";
			break;
		case 4:
			Operations::sutherisland(polygonPoint, windowPoint);
			cout << "Fenêtrage";
			break;
		case 5:
			cout << "Remplissage";
			break;
	}
}

int main(int argc, char **argv)
{

	/* Initialize the library */
	glutInit(&argc, argv);
	glEnable(GL_MULTISAMPLE);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_X, WINDOW_Y);
	glutCreateWindow("Projet Fenêtrage");


	glutDisplayFunc(renderScene);
	//glutPassiveMotionFunc(motion);
	

	/* Make the window's context current */

	// toutes nos initialisations vont ici

	int menu = glutCreateMenu(menuFunc);
	//add entries to our menu
	glutAddMenuEntry("Couleur", 1);
	glutAddMenuEntry("Tracé polygone", 2);
	glutAddMenuEntry("Tracé fenêtre", 3);
	glutAddMenuEntry("Fenêtrage", 4);
	glutAddMenuEntry("Remplissage", 5);


	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	/* Loop until the user closes the window */
	

	glutMainLoop();
	return 0;
}