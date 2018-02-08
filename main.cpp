#include <iostream>
#include <cmath>

using std::endl;
using std::cout;

int main(int argc, char* argv[])
{
    cout << "Usage: "<< argv[0]  << " number" << endl;

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