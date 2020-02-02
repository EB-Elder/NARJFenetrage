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
#include "stb_image.h"

using namespace std;

float red = 0.0f;
float blue = 0.0f;
float green = 0.0f;
vector<Line> test;
vector<Point> polygon;
Line tmpLine;
Point tmpPoint;

int** array2D(int N, int M, int V = 0)
{
	int ** tab = new int*[N];
	
	return tab;
}

void motion(int x, int y)
{
	cout << x;
}


void clickedScene(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		tmpLine.setPos(x, y, WINDOW_X, WINDOW_Y);
		if (tmpLine.isDrawable)
		{
			polygon.push_back(tmpLine.getPos1());
			test.push_back(tmpLine);
		}
	}

	

}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < test.size(); i++)
	{
		test[i].drawLine();
	}
	glutSwapBuffers();
	glutMouseFunc(clickedScene);

}



void menuFunc(int id)
{
	switch (id)
	{

	case 1:
		glClearColor(1.0f, 0.0f, 0.f, 1.0f);
		break;
	case 2:
		glClearColor(0.0f, 1.0f, 0.f, 1.0f); 
		break;
	case 3:
		glClearColor(0.0f, 0.0f, 1.f, 1.0f); 
		break;
	case 4:
		cout << "Fenetre";
		break;

	case 5:
		cout << "Polygon";
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
	glutCreateWindow("Projet Fenetrage");


	glutDisplayFunc(renderScene);
	//glutPassiveMotionFunc(motion);
	

	/* Make the window's context current */

	// toutes nos initialisations vont ici

	int menu = glutCreateMenu(menuFunc);
	//add entries to our menu
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Fenetre", 4);
	glutAddMenuEntry("Polygon", 5);


	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	/* Loop until the user closes the window */
	

	glutMainLoop();
	return 0;
}