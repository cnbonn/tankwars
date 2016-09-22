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


/****************************************
 *
 * initilize the dash with screenwidth and
 * screen height
 *
 * **************************************/
void initDash(int ScreenWidth, int ScreenHeight)
{
    SWidth = ScreenWidth;
    SHeight = ScreenHeight;
}
/***************************************
 * main function of the dash. 
 * controlls the drawing of all the dash
 *
 * player - what player is active
 * velocity - velosity of shot
 * angle - angle of the shot
 * screenwidth - width of the screen
 * screenheight - height of the screen
 * ****************************************/
void drawDash( int player, int velocity, int angle)
{
    
    //main box 
    DrawRectangle( -(SWidth/2)+1, 0, SWidth/2, 100, Cyan);
    DrawRectangle(-SWidth/4, 0, SWidth/4, 100, Cyan );    
    if( player == 0 )
    {
	drawPlayer("Player 1", 1);
	drawVelocity( velocity );
	drawAngle( angle );
    }
    else if( player == 1)
    {
	drawPlayer("Player 2", 2);
	drawVelocity( velocity );
	drawAngle( angle );
    }	

    glFlush();

    
}

void drawAngle(int angle)
{
    string s = to_string(angle);
    char const *cangle = s.c_str();
    DrawStrokeString( "Angle", SWidth/4 - 50, 10, White );
    DrawStrokeString( cangle, SWidth/4 - 50, 30, White );
}

void drawVelocity(int velocity)
{
    DrawStrokeString( "Velocity", -SWidth/4 + 5, 10, White );
    string v = to_string(velocity);
    char const *cvelocity = v.c_str();
    DrawStrokeString( cvelocity, -SWidth/4 + 5, 30, White );
}
/****************************************
 *
 * draw player name. switches player upon
 * press of the space bar
 *
 * *****************************************/
void drawPlayer(const char *string, int player)
{
    DrawStrokeString( string, -40 , 80, White );
    glFlush();
}
