#include "root.h"
#include <cmath> 


double root(double a) {
    if (a < 0) return -1; 
    return std::sqrt(a);
}
