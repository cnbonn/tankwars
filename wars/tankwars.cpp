//includes
#include <GL/freeglut.h>

#include <iostream>
using namespace std;

//global Varables
int screenwidth = 800;
int screenheight = 500;
int interval = 1000/60;

//global player vars { left/player 1, right/player 2 }
int player = 0; // player interval;
int velosity[]={200,200}; //player velosity
int angle[]={45,45}; // player angles
int position[]={-screenwidth/2 + 50, screenwidth/2 - 50}; // starting position of tanks

//include files
#include "terrain.h"
#include "dash.h"
#include "tank.h"

//prototypes
void initOpenGL( void );
void display( void );
void update( int value );
void reshape( int w, int h );
void otherInits( void );
void keyboard( unsigned char key, int x, int y);
void special( int key, int x, int y);

//keypress
const int EscapeKey = 27;
const int SpaceKey = 32;
const int PlusKey = 61;  // 43 is acitally plus key but who wants to press shift
const int MinusKey = 45;


/***********************************************88
 *
 * main function.
 * calls init functions and goes into the opengl
 * main loop
 *
 * ******************************************/
int main( int argc, char *argv[] )
{
    //initilize 
    glutInit(&argc, argv);
    initOpenGL();
    otherInits();
    glutMainLoop();
    return 0;
}
/*******************************************8
 *
 *
 * calls main inits of opengl
 *
 * *****************************************/
void initOpenGL( void )
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( screenwidth, screenheight );
    glutInitWindowPosition( 100, 100 );  // init window size
    glutCreateWindow("TANKWARS");        // window name

    glClearColor(0.0f, 0.0f, 0.0f, 1.0);  // clear color

    glutDisplayFunc( display );     // how to redisplay window
    glutReshapeFunc( reshape );     // how to resize the window
    glutKeyboardFunc( keyboard );   // how to handle key presses
    glutSpecialFunc( special );     //how to handle special key presses
    glutTimerFunc(interval, update, 0); // timer for animation

    
}
/******************************************8
 *
 * main display loop, calls terrain, tanks, dash
 * and projectiles
 *
 * *******************************************/
void display( void )
{
    // clear display
    glClear( GL_COLOR_BUFFER_BIT  );
    
    drawTerrain(150);
    drawDash( player, velosity[player], angle[player]);
    drawTank( position[0] );   //draw player 1
    drawTank( position[1] );   //draw player 2

    glutSwapBuffers();
    glFlush();
}
/**************************************************
 *
 * posts times for animation
 *
 * **********************************************/
void update( int value )
{
    glutTimerFunc(interval, update, 0);
    glutPostRedisplay();
}
/**********************************************
 *
 * calls for reshaping with window
 *
 * ******************************************/
void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2, w/2, 0 ,h);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glViewport( 0 , 0, w, h);
}
/*************************************
 *
 * initilises terrain and tanks
 *
 * **********************************/
void otherInits( void )
{
    initTerrain(screenwidth, 100, .4 ,1);
    initDash(screenwidth, screenheight);
}
/***************************************
 *
 * handles keyboard presses
 *
 * ***********************************/
void keyboard( unsigned char key, int x, int y)
{
    cerr << "keypress: " << key << endl;
   
    switch( key )
    {
	case EscapeKey: // exit
	    exit( 0 );
	    break;
	case SpaceKey: // fire and switch players
	    player = player^1;
	    break;
	case PlusKey: // incrase velosity
            if( velosity[ player ] < 600 )
	        velosity[player]++;
	    break;
	case MinusKey: // decerease velosity
	    if( velosity[player] > 0)
		velosity[player]--;
	    break;
	default:
	    glutPostRedisplay();
	    break;
    }
}

/****************************************
 *
 * handles special key presses
 *
 * **************************************/
void special( int key, int x, int y)
{
    //process key press
    switch( key )
    {
    	case GLUT_KEY_LEFT: // move tank left
	    if( position[ player ] > (-screenwidth/2) + 10 )
		position[ player ]--;
	    break;
	case GLUT_KEY_RIGHT: // move tank right
	    if( position[ player ] < (screenwidth/2) - 10)
		position[ player ]++;
	    break;
	case GLUT_KEY_UP: // increase angle
	    if( angle[ player ] < 180 )
		angle[ player ]++;
	    break;
        case GLUT_KEY_DOWN: // decrease angle
	    if( angle[ player ] > 0 )
		angle[ player ]--;
	    break;
    }
    glutPostRedisplay();
}
