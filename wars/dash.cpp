#include "dash.h"



// colors
const float Black[]     = { 0.0, 0.0, 0.0 };
const float Red[]       = { 1.0, 0.0, 0.0 };
const float Green[]     = { 0.0, 1.0, 0.0 };
const float Blue[]      = { 0.0, 0.0, 1.0 };
const float Magenta[]   = { 1.0, 0.0, 1.0 };
const float Cyan[]      = { 0.0, 1.0, 1.0 };
const float Yellow[]    = { 1.0, 1.0, 0.0 };
const float White[]     = { 1.0, 1.0, 1.0 };


void drawDash( int player, int velocity, int angle, int ScreenWidth, int ScreenHeight)
{
    
    //main box 
    DrawRectangle( -(ScreenWidth/2)+1, 0, ScreenWidth/2, 100, Red);
    DrawRectangle(-ScreenWidth/4, 0, ScreenWidth/4, 100, Red );    
    if( player == 1 )
    {
    }
    else
    {
    }	

    glFlush();

    
}

void drawAngle()
{
}

void drawVelocity()
{
}

void drawPlayer();
