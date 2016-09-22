#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
   int x, y, hi, lo, rnum;
   cout << "enter 2 numbers " << endl;
   cin >> x >> y;

   if( x  > y )
   {
	lo = y;
        hi = x;
   }
   else
   {
       hi = y;
       lo = x;
   }

   srand( time ( NULL ));
   for( int i = 0; i < 20; i++)
   {
      rnum = (rand()%(hi-lo)+lo);
      cout << rnum << endl;
   }
 
   return 0;
}
