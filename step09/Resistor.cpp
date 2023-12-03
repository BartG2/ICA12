#include "Resistor.h"

using namespace std;

//constructor, sets resistane to 1 by default
Resistor::Resistor(){ resistance = 1; }

//accessors
double Resistor::getResistance() const{ return resistance; }
double Resistor::getCurrent() const{
    return getTerminalVoltage() / resistance;
}
double Resistor::getPower() const{
    return getCurrent()*getTerminalVoltage();
}

//mutators
void Resistor::setResistance(double resistance){this->resistance = resistance; }

//other members
void Resistor::report(ofstream& outfile){
    outfile << "\nComponent # " << getIndex() << " is a Resistor, R = " << resistance << " Ohms." << endl;
    
    //call base class's report function
    Component::report(outfile);

    outfile << "The current in this Resistor = " << abs(getCurrent()) << " Amps, " << endl;
    outfile << "flowing from Node " << getNodeAIndex() << " to Node " << getNodeBIndex() << "." << endl;
    outfile << "The power dissipated in this Resistor = " << getPower() << " Watts." << endl;
}
