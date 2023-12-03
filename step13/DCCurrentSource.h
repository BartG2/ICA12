#pragma once
#include "Component.h"
#include <fstream>

using namespace std;

class DCCurrentSource : public Component{
private:
    double current;

public:
//constructor
    DCCurrentSource();

//accessors
    double getCurrent() const;
    double getPower() const;

//mutators
    double setCurrent(double current);

//other members
    void report(ofstream& outfile);

};