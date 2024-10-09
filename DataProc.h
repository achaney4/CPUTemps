#ifndef DATAPROC_H_INCLUDED
#define DATAPROC_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class DataProc {
    
    public:

    void textOutput(ofstream& outText, vector<double> coreVec);
    void addtoCore3(double tFour);
    void addtoCore2();
    void addtoCore1();
    void addToCore0(double tZero);
    void addToTime(int reading);

    vector<double> newCore2;
    vector<double> newCore1;
    vector<double> core3;
    vector<double> orgCore2;
    vector<double> orgCore1;
    vector<double> core0;
    vector<int> timeStep;
    
};

#endif
