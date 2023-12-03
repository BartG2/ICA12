#pragma once
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"

class VoltageDivider : public Network{
private:
    DCVoltageSource source;
    Resistor r1, r2;

public:
//constructor
    VoltageDivider(double voltage, double resistance1, double resistance2);

//accessors


//mutators
    void setSourceVoltage(double voltage);
    void setBothResistors(double resistance1, double resistance2);

//other members
    void report(ofstream& outfile);
    void calculate();

};

