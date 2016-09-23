#include "tank.h"

const float Black[]     = { 0.0, 0.0, 0.0 };
const float Red[]       = { 1.0, 0.0, 0.0 };
const float Green[]     = { 0.0, 1.0, 0.0 };
const float Blue[]      = { 0.0, 0.0, 1.0 };
const float Magenta[]   = { 1.0, 0.0, 1.0 };
const float Cyan[]      = { 0.0, 1.0, 1.0 };
const float Yellow[]    = { 1.0, 1.0, 0.0 };
const float White[]     = { 1.0, 1.0, 1.0 };
/****************************
 *
 * initilize tanks
 *
 * **********************/
void initTank()
{
}

/**********************************
 *
 * draw tank on the screen using
 * the centerpoint of the tank
 *
 * *******************************/
void drawTank(int x, int bumpup)
{
    int y = 200;
    y = calcHeight(x);

    DrawFilledRectangle( x - 10, y - 4 + bumpup, x + 10, y + 4 + bumpup, Red );
    DrawFilledRectangle( x - 3 , y + 4 + bumpup , x + 3 , y + 10 +bumpup, Red );
    DrawLine( x , y + 6 +bumpup, x + 11, y + 11 +bumpup, Red); 
    glFlush();   
}
/************************************
 *
 * calculate height to draw the tank
 * at based off the generated terrain
 *
 * *********************************/

int calcHeight(int x)
{
    /*
    //y = screenheight;
    GLuint seedcolor;
    GLuint readcolor;
    glReadPixels( 200 , 200, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &seedcolor );

    cerr << "seed color: " << seedcolor << endl;

    for( int i = 800; i > 0; i-- )
    {
	glReadPixels( x, i, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &readcolor );
	cerr << "read color " << readcolor << endl;
    } */
    return findy( x );
}
