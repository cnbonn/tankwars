#include "terrain.h"

Terrain::Terrain()
{
    width = 0;
    height = 0;
    displacement = 0;
    roughness = 0;
    smoothness = 0;
    cerr << "blank name created" << endl;
}

Terrain::~Terrain()
{
    linepoints.clear();
}

Terrain::Terrain(float w, float h, float d, float r, int s)
{
    width = w;
    height = h;
    displacement = d;
    roughness = r;
    smoothness = s;
	
    generate();
}

int Terrain::generate()
{
    //generate random number
    srand(time(NULL));
    float rstart = rand() % 20; 
    float rend = rand () % 20;

    //set 
    linepoints.push_back({0,rstart});
    linepoints.push_back({width/2,displacement});
    linepoints.push_back({width, rend});

    genpoints();

    return 1;
}

void Terrain::genpoints()
{   
    // create more points
    int size;
    int position;
    float xpoint, ypoint;

    // initilize it to beginning of vector
    vector<point>::iterator it = linepoints.begin();
    
    //create random
    srand(time(NULL));

    for(int j = 0; j < smoothness; j++)
    {
        size = linepoints.size(); //set loop to size of vector
        position = 1; // reset positon
        for(int i = 1 ; i < size ; i++)
        {
	    it++;
	    //get x value
            xpoint = (linepoints[position].x - linepoints[position-1].x)/2;
	    xpoint = xpoint + linepoints[position-1].x;
	    //get y value
	    ypoint = abs((linepoints[position].y - linepoints[position-1].y)/2);
            //tecelate
            ypoint += (rand() % int(roughness)) - roughness;
	    //save points
            linepoints.insert(it , point{xpoint,ypoint});
            it++; 
	    position += 2;	
        }
	it = linepoints.begin(); //reset it to beginning of vector
	printPoints();
    }
}

void Terrain::draw()
{
    size = linepoints.size();
    for(int i = 0; i < size; i++)
    {
	glColor3f( 1.0, 0.0, 0.0);
        glBegin( GL_LINES );
	    glVertex2f( linepoints[i].x, linepoints[i].y );
	    glVertex2f( linepoints[i+1].x, linepoints[i+1].y );
	glEnd();
    }
}


void Terrain::print()
{
    cerr << "terrain" << endl;
    cerr << "\twidth:        " << width << endl;
    cerr << "\theight:       " << height << endl;
    cerr << "\tdisplacement: " << displacement << endl;
    cerr << "\troughness:    " << roughness << endl;
}

void Terrain::printPoints()
{
    cerr << "terrain contents" << endl;
    int points = linepoints.size();
    cerr << " points: "<< points << endl;
    for(int i = 0; i < points; i++)
    {
	//cerr << "(" << i << "'" << linepoints[i] << ")";
	fprintf(stderr, "(%3i,%3i)", int(linepoints[i].x) , int(linepoints[i].y));
	if((i+1) % 10 == 0)
	{
	    cerr << endl;
        }
    }
    cerr << endl;
    
}


