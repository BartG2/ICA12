#pragma once
#include <fstream>

using namespace std;

class Node{
private:
    static int numNodes;
    int index;
    double voltage;
public:
//constructor and destructor
    Node();
    ~Node();

//accessors
    int getIndex() const;
    int getNumNodes() const;
    double getVoltage() const;

//mutators
    void setVoltage(double voltage);

//other members
    //prints info about this node to outfile
    void report(ofstream& outfile) const;
};