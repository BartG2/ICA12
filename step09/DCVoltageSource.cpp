#include "DCVoltageSource.h"

using namespace std;

DCVoltageSource::DCVoltageSource(){ voltage = 0; }

//accessors
double DCVoltageSource::getVoltage() const{ return voltage; }
double DCVoltageSource::getCurrent() const{ return current; }

//mutators
void DCVoltageSource::setVoltage(double voltage){ this->voltage = voltage; }
void DCVoltageSource::setCurrent(double current){this->current = current; }

//other members
void DCVoltageSource::report(ofstream& outfile){
    outfile << "\nComponent # " << getIndex() << " is a DC Voltage Source, Vs = " << voltage << " Volts." << endl;

    //call base class's report function
    Component::report(outfile);
    outfile << "The current in this DC Voltage Source = " << abs(current) << " Amps," << endl;
    outfile << "flowing from Node " << getNodeAIndex() << " to Node " << getNodeBIndex() << "." << endl;
    outfile << "The power supplied by this DC Voltage Source = " << getPower() << " Watts." << endl;
}

double DCVoltageSource::getPower() const{
    return voltage*current;
}
