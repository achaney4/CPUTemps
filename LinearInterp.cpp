#include "LinearInterp.h"
#include "DataProc.h"
#include <iostream>
#include <vector>
using namespace std;
/**
 * function to calculate the slope for the line
 * 
 * @param x1 int parameter for lower bound timeStep vector values 0 <= x
 * @param y1 double parameter for core temp values
 * @param x2 int parameter for upper bound timeStep vector values x > 30
 * @param y2 int parameter for the next core temp value
 * @return the calculated slope
 */
double LinearInterp::calcSlope(int x1, double y1, int x2, int y2){
        
            
            double slope = (y2-y1)/(x2-x1);  // m = (y1-y0/x1-x0)
            return slope;  
}

/**
 * function to calculate the y-intercept of the line (b)
 * 
 * @param slope the calculated slope from the previous function 
 * @param x1 int parameter for lower bound timeStep vector values 0 <= x
 * @param y1 y1 double parameter for core temp values
 * @return the y-intercept (b)
 */
double LinearInterp::calcB(double slope, int x1, double y1){
        
        double b = y1 - (slope * x1); 
        return b; 
}