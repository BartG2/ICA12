#pragma once
#include "Component.h"
#include <fstream>
#include <cmath>

using namespace std;

class Resistor : public Component{
private:
    double resistance;

public:
//constructor
    Resistor();

//accessors
    double getResistance() const;
    double getCurrent() const;
    double getPower() const;

//mutators
    void setResistance(double resistance);

//other
    //prints info about this component to outfile
    void report(ofstream& outfile);

};

