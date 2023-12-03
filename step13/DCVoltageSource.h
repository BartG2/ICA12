#pragma once
#include "Component.h"
#include <fstream>
#include <cmath>

using namespace std;

class DCVoltageSource : public Component{
private:
    double voltage, current;

public:
    DCVoltageSource();

//accessors
    double getVoltage() const;
    double getCurrent() const;
    
    //calculate the power supplied
    double getPower() const;

//mutators
    void setVoltage(double voltage);
    void setCurrent(double current);

//other
    //prints info about this component to outfile
    void report(ofstream& outfile);

};

