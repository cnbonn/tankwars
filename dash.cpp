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
    cerr << "drawing dash" << endl;
    
    //main box 
    DrawRectangle( 0+1, 0, ScreenWidth, 100, Red);
    //inner box
    DrawRectangle( ScreenWidth/9 , 0, (ScreenWidth/9)*8, 100, Red);    
    
    if( player == 1 )
    {
	DrawStrokeString( "Player 1", (ScreenWidth/2)-50, 80, Green);
	DrawQuarterEllipse( 300, 200, 400, 300, Blue);
    }
    else
    {
    }	

    glFlush();

    
}


