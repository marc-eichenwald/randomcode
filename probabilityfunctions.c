#ifndef _STDIO_
#define _STDIO_
#include <stdio.h>
#endif

#ifndef _MATH_
#define _MATH_
#include <math.h>
#endif

/* calculates the probability of an event not occuring recursively 
ie. for i chances with p probability of occuring the chance none occur is
(1-p)^i
*/
float recursive_no_occur(int i, float p){
if (i >= 1)
    return recursive_no_occur(i-1, p)*(1-p);
else if (i == 1)
    return 1-p;
}

