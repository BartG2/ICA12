#include "Component.h"

using namespace std;

int Component::numComponents = 0;

Component::Component(){
    //setting this components's index member to the current number of components in existence, then incrementing the number of components in existence
    index = numComponents++;
    //initialize Node pointers A/B to nullptr
    A = nullptr;
    B = nullptr;
}

Component::~Component(){}

//accessors
int Component::getNumComponents() const{ return numComponents; }
int Component::getIndex() const{ return index; }
int Component::getNodeAIndex() const{ return A->getIndex(); }
int Component::getNodeBIndex() const{ return B->getIndex(); }

//mutators
void Component::setNodeAPointer(Node* node){ A = node; }
void Component::setNodeBPointer(Node* node){ B = node; }

//other members
void Component::report(ofstream& outfile){
    outfile << "Component # " << index << " is connected between node " << A->getIndex() << " and node " << B->getIndex() << "." << endl;
    //voltages always reported positive
    outfile << "The Voltage across Component # " << index << " = " << abs(this->getTerminalVoltage()) << " Volts," << endl;
    //negative terminal node is the more negative of the two, identified through ternary operator
    outfile << "with the negative terminal at node " << (A->getVoltage() < B->getVoltage() ? A->getIndex() : B->getIndex()) << "." << endl;
}
double Component::getTerminalVoltage() const{ return B->getVoltage() - A->getVoltage(); }
