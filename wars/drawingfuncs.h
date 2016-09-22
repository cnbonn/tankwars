#ifndef DRAWINGFUNCS_H
#define DRAWINGFUNCS_H

#include <iostream>
using namespace std;

#include <math.h>
#include <GL/freeglut.h>

void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] );
void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] );
void DrawQuarterEllipse(float x1, float y1, float x2, float y2, const float color[]);
void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
void DrawBitmapString( const char *string, float x, float y, const float color[] );
void DrawStrokeString( const char *string, float x, float y, const float color[] );

#endif
