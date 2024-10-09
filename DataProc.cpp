#include "DataProc.h"
#include "LinearInterp.h"

#include <iostream>
#include <vector>
#include <fstream>
#include<iomanip>

using namespace std;

/**
 * @function to output each core to its own text file based on the vector given
 * 
 * @param outText output file stream variable
 * @param coreVec vector parameter
 */
void DataProc::textOutput(ofstream& outText, vector<double> coreVec){
    if(coreVec == core0){
    outText.open("tempData-core-0.txt");
    }
    else if(coreVec == newCore1){
        outText.open("tempData-core-1.txt");
    }
    else if(coreVec == newCore2){
        outText.open("tempData-core-2.txt");
    }
    else if (coreVec == core3){
        outText.open("tempData-core-3.txt");
    }

    LinearInterp li;
    int y=-1;
    
    for(int i=0; i<timeStep.size()-1; i++) {
        y++;
        int x1 = timeStep[i];
        double y1 = coreVec[i];
        int x2 = timeStep[i]+30;
        int y2 = coreVec[i+1];

        double slope = li.calcSlope(x1,y1,x2,y2);
        double b = li.calcB(slope, x1, y1); // calculate y intercept
        outText << timeStep[i] << " = x < " << x2 << "; y_" << y 
        << "   =   " << b << "  + " << slope << "x" << endl;

        }

    

    

        outText.close();

        
}

/**
 * 
 * function to push core 4 values into core3 vector
 * 
 * @param tFour variable to represent double temp values
 */
void DataProc::addtoCore3(double tFour){ 
    core3.push_back(tFour);
}

/**
 * function to edit original core vector and insert core 3 values into new vector
 * 
 */
void DataProc::addtoCore2(){ //function to retrieve 3rd core
     orgCore2.erase(orgCore2.begin(), orgCore2.begin()+2);
     orgCore2.erase(orgCore2.begin()+1);
     newCore2.insert(newCore2.end(), orgCore2.begin(),orgCore2.end());
   
}

/**
 * function to edit original core vector and insert core 2 values into new vector
 * 
 */
void DataProc::addtoCore1(){ // function to retrieve the 2nd core

   
    orgCore1.erase(orgCore1.begin()+2, orgCore1.begin()+4);
    orgCore1.erase(orgCore1.begin(), orgCore1.begin()+1);
    newCore1.insert(newCore1.end(), orgCore1.begin(),orgCore1.end());

}

/**
 * function to retrieve core 1 values and push to core0 vector
 * 
 * @param tZero variable to represent double temp values
 */
void DataProc::addToCore0(double tZero){
   core0.push_back(tZero);
}

/**
 * function to push time step values to timeStep vector
 * 
 * @param reading variable to represent int time step values
 */
void DataProc::addToTime(int reading){
    timeStep.push_back(reading);
}