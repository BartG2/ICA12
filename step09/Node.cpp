#include "Node.h"

using namespace std;

//initialize static member variable
int Node::numNodes = 0;

Node::Node(){
    //setting this node's index member to the current number of nodes in existence, then incrementing the number of nodes
    index = numNodes++;
    voltage = 0;
}
Node::~Node(){}

//accessors
int Node::getIndex() const{ return index; }
int Node::getNumNodes() const{ return numNodes; }
double Node::getVoltage() const{ return voltage; }

//mutators
void Node::setVoltage(double voltage){ this->voltage = voltage; }

//other members
void Node::report(ofstream& outfile) const{
    outfile << "Voltage at node " << index << " = " << voltage << "." << endl;
}
