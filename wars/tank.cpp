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
void drawTank(int x)
{
    int y = 200;
    DrawFilledRectangle( x - 10, y - 4 , x + 10, y + 4, Red );
    DrawFilledRectangle( x - 3 , y + 4 , x + 3 , y + 10, Red );
    DrawLine( x , y + 6, x + 11, y + 11, Red); 
    glFlush();   
}
/************************************
 *
 * calculate height to draw the tank
 * at based off the generated terrain
 *
 * *********************************/

int calcHeight()
{
    return 1;
}
