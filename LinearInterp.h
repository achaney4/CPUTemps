#ifndef LINEARINTERP_H_INCLUDED
#define LINEARINTERP_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class LinearInterp {

public:
    double calcSlope(int x1, double y1, int x2, int y2);
    double calcB(double slope, int x1, double y1);

};

#endif