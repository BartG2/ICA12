#include "DCCurrentSource.h"

using namespace std;

//constructor
DCCurrentSource::DCCurrentSource(){ current = 0; }

//accessors
double DCCurrentSource::getCurrent() const { return current; }
double DCCurrentSource::getPower() const{ return current * getTerminalVoltage(); }

//mutators
double DCCurrentSource::setCurrent(double current){ this->current = current; }

// other members
void DCCurrentSource::report(ofstream& outfile){
    outfile << "\nComponent # " << getIndex() << " is a DC Current Source, Is = " << current << " Amps." << endl;
    Component::report(outfile);

    int fromNode, toNode;

    if (current >= 0) {
        // If current is positive, flow is from Node A to Node B
        fromNode = getNodeAIndex();
        toNode = getNodeBIndex();
    } else {
        // If current is negative, reverse the direction
        fromNode = getNodeBIndex();
        toNode = getNodeAIndex();
    }

    outfile << "The current in this DC Current Source = " << abs(current) << " Amps," << endl;
    outfile << "flowing from Node " << fromNode << " to Node " << toNode << "." << endl;
    outfile << "The power supplied by this DC Current Source = " << getPower() << " Watts." << endl;
}
