#pragma once
#include "Network.h"
#include "DCCurrentSource.h"
#include "Resistor.h"

class CurrentDivider : public Network{
private:
    DCCurrentSource source;
    Resistor r1, r2;

public:
//constructor
    CurrentDivider(double voltage, double resistance1, double resistance2);

//accessors


//mutators
    void setSourceCurrent(double current);
    void setBothResistors(double resistance1, double resistance2);

//other members
    //prints info about this network to outfile
    void report(ofstream& outfile);
    void calculate();

};

