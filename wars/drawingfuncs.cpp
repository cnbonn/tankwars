#include "drawingfuncs.h"

/***************************************************************8
 *
 * Drawing functions from Dr. Weiss Opengl Demo
 *
 * *************************************************************/

// colors
const float Black[]     = { 0.0, 0.0, 0.0 };
const float Red[]       = { 1.0, 0.0, 0.0 };
const float Green[]     = { 0.0, 1.0, 0.0 };
const float Blue[]      = { 0.0, 0.0, 1.0 };
const float Magenta[]   = { 1.0, 0.0, 1.0 };
const float Cyan[]      = { 0.0, 1.0, 1.0 };
const float Yellow[]    = { 1.0, 1.0, 0.0 };
const float White[]     = { 1.0, 1.0, 1.0 };

#define M_PI

// draw a rectangle using the given RGB color value
void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_LINE_LOOP );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/******************************************************************************/

// draw a filled rectangle using the given RGB color value
void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glRectf( x1, y1, x2, y2 );
    /* or draw a polygon:
    glBegin( GL_POLYGON );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    */
    glFlush();
}

void DrawQuarterEllipse( float x1, float y1, float x2, float y2, const float color[])
{
   GLfloat points = 100.0f;
   GLfloat angle, raioX=0.3f, raioY=0.3f;

   glColor3fv( color );
   glBegin( GL_LINE_LOOP );
	glVertex2f( x1, y1 );
	glVertex2f( x2, y1 );
	glVertex2f( x2, y2 );
	for(int i=0; i < points; i++)
	{
	    angle = 2*3.1415*i/points;
	    glVertex2f(0.5+cos(angle)*raioX, 0.5+sin(angle)*raioY);
	}
   glEnd();
   glFlush();
}

/******************************************************************************/

// draw an ellipse of given radii at a specified position using the given RGB color value
void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] )
{
    float radius = xRadius < yRadius ? xRadius : yRadius;   // stretch circle into ellipse
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );    // by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 4, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/******************************************************************************/

// draw an ellipse of given radii at a specified position using the given RGB color value
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y, const float color[] )
{
    float radius = xRadius < yRadius ? xRadius : yRadius;   // stretch circle into ellipse
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );    // by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, 0, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/******************************************************************************/

// write a bitmap font text string at a specified position using the given RGB color value
void DrawBitmapString( const char *string, float x, float y, const float color[] )
{
    glColor3fv( color );
    glRasterPos2f( x, y );

    // glutBitmapString is available in freeglut
    glutBitmapString( GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)string );

    // GLUT only supports glutBitmapCharacter
    // while ( *string ) glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *string++ );
}

// write a stroke font text string at a specified position using the given RGB color value
void DrawStrokeString( const char *string, float x, float y, const float color[] )
{
    glColor3fv( color );
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef( x, y, 0 );
    // while ( *string ) glutStrokeCharacter( GLUT_STROKE_ROMAN, *string++ );
    glScalef( 0.15,0.15,1);
    glutStrokeString( GLUT_STROKE_ROMAN, (const unsigned char *)string );
    glPopMatrix();
}


