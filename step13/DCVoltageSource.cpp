#include "DCVoltageSource.h"

using namespace std;

DCVoltageSource::DCVoltageSource(){ voltage = 0; }

//accessors
double DCVoltageSource::getVoltage() const{ return voltage; }
double DCVoltageSource::getCurrent() const{ return current; }
double DCVoltageSource::getPower() const{
    return voltage*current;
}

//mutators
void DCVoltageSource::setVoltage(double voltage){ this->voltage = voltage; }
void DCVoltageSource::setCurrent(double current){this->current = current; }

// other members
void DCVoltageSource::report(ofstream& outfile) {
    outfile << "\nComponent # " << getIndex() << " is a DC Voltage Source, Vs = " << voltage << " Volts." << endl;
    Component::report(outfile); // Call base class's report function

    double terminalVoltage = getTerminalVoltage();
    int fromNode, toNode;

    if (voltage >= 0) {
        // If voltage is positive, flow from Node A to Node B
        fromNode = getNodeAIndex();
        toNode = getNodeBIndex();
    } else {
        // If voltage is negative, the flow from Node B to Node A
        fromNode = getNodeBIndex();
        toNode = getNodeAIndex();
    }

    outfile << "The current in this DC Voltage Source = " << abs(current) << " Amps," << endl;
    outfile << "flowing from Node " << fromNode << " to Node " << toNode << "." << endl;
    outfile << "The power supplied by this DC Voltage Source = " << getPower() << " Watts." << endl;
}

