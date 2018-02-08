#include <iostream>
#include <cmath>
#include "TutorialConfig.h"

using std::endl;
using std::cout;

int main(int argc, char* argv[])
{
    cout << "Usage: "<< argv[0]  << " number" << endl;
    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << endl;

    double inputValue;
    if(argc == 2)
    {
        inputValue = atof(argv[1]);
    }
    else
    {
        inputValue = 4;
    }

    double outputValue = sqrt(inputValue);
    cout << "The square root of "<<  inputValue << " is " << outputValue << endl;
    return 0;
}