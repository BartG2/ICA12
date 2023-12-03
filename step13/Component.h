#pragma once
#include "Node.h"
#include <fstream>
#include <cmath>

using namespace std;

class Component{
private:
    static int numComponents;
    int index;
    //pointers to the two nodes at either end of the component
    Node* A;
    Node* B;
public:
//constructor and destructor
    Component();
    ~Component();

//accessors
    int getNumComponents() const;
    int getIndex() const;
    int getNodeAIndex() const;
    int getNodeBIndex() const;
    
    //returns voltage across the component
    double getTerminalVoltage() const;

//mutators
    //sets the Node the pointers A/B point to user specified Node instance
    void setNodeAPointer(Node* node);
    void setNodeBPointer(Node* node);

//other members
    //prints info about this component to outfile
    void report(ofstream& outfile);
};