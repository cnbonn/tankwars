//includes
#include <GL/freeglut.h>

#include <iostream>
using namespace std;

//global Varables
int screenwidth = 800;
int screenheight = 500;
int interval = 1000/60;


//include files
#include "terrain.h"
#include "dash.h"

//prototypes
void initOpenGL( void );
void display( void );
void update( int value );
void reshape( int w, int h );
void otherInits( void );

int main( int argc, char *argv[] )
{
    //initilize 
    glutInit(&argc, argv);
    initOpenGL();
    otherInits();
    glutMainLoop();
    return 0;
}

void initOpenGL( void )
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( screenwidth, screenheight );
    glutInitWindowPosition( 100, 100 );
    glutCreateWindow("TANKWARS");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0);

    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutTimerFunc(interval, update, 0);

    
}

void display( void )
{
    // clear display
    glClear( GL_COLOR_BUFFER_BIT  );
    
    drawTerrain(150);
    drawDash( 1, 1, 1, screenwidth, screenheight);
    

    glutSwapBuffers();
    glFlush();
}

void update( int value )
{
    glutTimerFunc(interval, update, 0);
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2, w/2, 0 ,h);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glViewport( 0 , 0, w, h);
}

void otherInits( void )
{
    initTerrain(screenwidth, 100, .4 ,1);
}
