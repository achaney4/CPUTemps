#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <utility>
#include<bits/stdc++.h>

#include "parseTemps.h"
#include "DataProc.h"
#include "LinearInterp.h"

using namespace std;

int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    // vector
    auto readings = parse_raw_temps<std::vector<CoreTempReading>>(input_temps);

    
    DataProc dP; //DataProc object
    // Output everything to match the Python version
    for (const CoreTempReading& theReading : readings) {
             
         dP.addToTime(theReading.first);   

        const vector<double>& coreTemps = theReading.second;
        
        //retrieve the first core
        double cZero = coreTemps.front();
        dP.addToCore0(cZero); 

        // retrieve the 2nd core
        dP.orgCore1 = coreTemps;
        dP.addtoCore1();


        //retrieve 3rd core
        dP.orgCore2 = coreTemps;
        dP.addtoCore2();

        // retrieve 4th core
        double cThree = coreTemps.back();
        dP.addtoCore3(cThree);
       
    }
        
     ofstream outFile;
    dP.textOutput(outFile, dP.core0); 
    dP.textOutput(outFile, dP.newCore1);
    dP.textOutput(outFile, dP.newCore2);
    dP.textOutput(outFile, dP.core3);
        
    

    return 0;
}


