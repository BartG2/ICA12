#pragma once
#include "Component.h"
#include <fstream>

using namespace std;

class Network{
private:
    static int numNetworks;
    int index, numNodes;
    Node* nodes;            //each network "has a" array of nodes

public:
//constructor and destructor
    Network(int numNodes);
    ~Network();

//accessors
    int getIndex() const;
    int getNumNodesInNetwork() const;
    int getNumNodesTotal() const;
    Node* getNodePointer(int nodeIndex) const;

//mutators
    void setVoltage(int targetNode, double voltage);

//other members
    //prints info about this network to outfile
    void report(ofstream& outfile) const;
    
    //add a component to the network connected between two Nodes specified by the indices
    void addComponent(Component& component, int indexOne, int indexTwo);
};