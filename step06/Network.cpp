#include "Network.h"
#include "Node.h"
#include "Component.h"

using namespace std;

int Network::numNetworks = 0;

Network::Network(int numNodes = 2){
    //setting this network's index member to the current number of networks in existence, then incrementing the number of networks in existence
    index = numNetworks++;

    //initializes this networks numNodes to user specified number, defaults to 2
    this->numNodes = numNodes;
    nodes = new Node[this->numNodes];   //dynamically allocated array of Nodes
}

Network::~Network(){
    delete[] nodes;     //frees memory allocated in constructor
}

//accessors
int Network::getIndex() const{ return index; }
int Network::getNumNodesInNetwork() const{ return numNodes; }
int Network::getNumNodesTotal() const{ return nodes[0].getNumNodes(); }

//mutators
void Network::setVoltage(int targetNode, double voltage){
    nodes[targetNode].setVoltage(voltage);
}

//other members
void Network::report(ofstream& outfile) const{
    outfile << "\n";

    //print 48 "-"
    for(int i = 0; i < 48; i++){
        outfile << "-";
    }

    outfile << "\nData for Electric Network # " << index << ":" << endl;
    outfile << "At present, there are " << numNetworks << " Networks in existence." << endl;
    outfile << "At present, there are " << getNumNodesTotal() << " nodes in existence." << endl;
    outfile << "Network # " << index << " contains " << numNodes << " nodes." << endl;
    
    //go through all nodes of this network and report their info
    for(int i = 0; i < numNodes; i++){
        nodes[i].report(outfile);
    }
}
void Network::addComponent(Component& component, int indexOne, int indexTwo){
    component.setNodeAPointer(&nodes[indexOne]);
    component.setNodeBPointer(&nodes[indexTwo]);
}
