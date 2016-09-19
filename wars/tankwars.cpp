//includes
#include <GL/freeglut.h>

#include <iostream>
using namespace std;

//global Varables
int width = 800;
int height = 500;
int interval = 1000/60;


//include files
#include "terrain.h"

//prototypes
void initOpenGL( void );
void display( void );
void update( int value );
void enable2D( int width, int height );

int main( int argc, char *argv[] )
{
    //initilize 
    glutInit(&argc, argv);
    initOpenGL();

    glutMainLoop();
    return 0;
}

void initOpenGL( void )
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize( width, height );
    glutCreateWindow("TANKWARS");

    glutDisplayFunc( display );
    glutTimerFunc(interval, update, 0);

    enable2D(width, height);
    glColor3f(0.0f, 0.0f, 0.0f);
}

void display( void )
{
    // clear display
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    
    glutSwapBuffers();
    glFlush();
}

void update( int value )
{
    glutTimerFunc(interval, update, 0);
    glutPostRedisplay();
}

void enable2D(int width, int height)
{
    glViewport( 0 , 0 , width , height );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

