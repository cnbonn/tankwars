#include "terrain.h"
/************************************************8
 * init call to save values for the terrain
 *
 * ****************************************************/
void initTerrain(float w, float h, float r, int s)
{
    twidth = w;
    theight = h;
    troughness = r;
    tsmoothness = s;
	
    generate();
}
/************************************8
 *
 * starts the generation of values
 * for the terrain by seeiding 3 values
 * **********************************/
int generate()
{
    //generate random number
    srand(time(NULL));
    float rstart = rand() % 20 ; 
    float rend = rand() % 20 ;
    float mid = (rand() % int(theight - theight/2)) + theight;

    //set 5 points 
    linepoints.push_back({-twidth/2,rstart});
    linepoints.push_back({-twidth/4,rend});
    linepoints.push_back({0,mid});
    linepoints.push_back({twidth/4, rstart});
    linepoints.push_back({twidth/2, rend});

    genpoints();

    return 1;
}
/***********************************************
 * generates random points for the terrain using the
 * midpoint displacement algorithm given in the book
 *
 *
 *
 * smoothness - number of points in the terrain
 * roughness - height difference between points
 *
 *
 ************************************************/
void genpoints()
{   
    // create more points
    int size;
    int position;
    float xpoint, ypoint;

    // initilize it to beginning of vector
    vector<point>::iterator it = linepoints.begin();
    
    //create random
    srand(time(NULL));
    float random;

    for(int j = 0; j < tsmoothness; j++)
    {
	// generate roughness
	  
        size = linepoints.size(); //set loop to size of vector
        position = 1; // reset positon
        for(int i = 1 ; i < size ; i++)
        {
	    it++;
	    // find midpoint between two x values
            xpoint = (linepoints[position].x + linepoints[position-1].x)/2;
	    //xpoint = xpoint + linepoints[position-1].x;

	    //find midpoint between two y values
	    random = randomnum(linepoints[position].y, linepoints[position-1].y);
	    ypoint = (linepoints[position].y + linepoints[position-1].y)/2 + random;
	    
	    if( ypoint < 0 ) // make sure y value does not go though floor
		ypoint = 0;

	    //save points
            linepoints.insert(it , point{xpoint,ypoint});
            it++; 
	    position += 2;	
        }
	it = linepoints.begin(); //reset it to beginning of vector
    }
}
/****************************************
 * loop though the vector that contains the terrain
 * and using GL_LINE draw the terrain to the screen
 *
 * int bumpup - amount to move the bottom of the 
 * 		terrain up from the bottom of the 
 * 		screen
 * **********************************************/
void drawTerrain(int bumpup)
{
    int size = linepoints.size();
    for(int i = 0; i < size-1; i++)
    {
	glColor3f( 0.0, 1.0, 0.0);
        glBegin( GL_LINES );
	    glVertex2f( linepoints[i].x , linepoints[i].y + bumpup );
	    glVertex2f( linepoints[i+1].x , linepoints[i+1].y + bumpup);
	glEnd();
    }
}

/*********************************8
 *
 *  print points in the terrain held in the 
 *  vector line points
 *
 *  **********************************/
void printPoints()
{
    cerr << "terrain contents" << endl;
    int points = linepoints.size();
    cerr << " points: "<< points << endl;
    for(int i = 0; i < points; i++)
    {
	fprintf(stderr, "(%3i,%3i)", int(linepoints[i].x) , int(linepoints[i].y));
	if((i+1) % 10 == 0)
	{
	    cerr << endl;
        }
    }
    cerr << endl;
    
}
/*******************************
 * generate random gausian value
 *
 * ***************************/
double genrandom()
{
    //see gen 
    default_random_engine generator(rand()%10);
    normal_distribution<double> distribution(0.0,sqrt(1.0));
    double val = distribution(generator);

    return val;
}

/***************************************
 * 
 *  Generate a random value between two points
 *  given as arguments
 *
 * *************************************/

float randomnum( float x, float y )
{
    float rnum, hi, lo;
    if( x < y )
    {
	lo = x;
	hi = y;
    }
    else
    {
	lo = y;
	hi = x;
    }
    //generate random number between two values
    rnum = (rand() % int( hi - lo )) + lo; 

    return rnum;	
}

 
