#include "Node.h"
#include "Component.h"
#include "Network.h"

int main(){

    ofstream outfile("ECE 0301 - Electrical Network Simulation.txt");
    outfile << "ECE 0301 = Electrical Network Simulation" << endl;

    Network network(3);
    Component c0, c1, c2;
    network.addComponent(c0, 0, 1);
    network.addComponent(c1, 1, 2);
    network.addComponent(c2, 2, 0);

    network.setVoltage(1, -5);
    network.setVoltage(2, 1.25);

    network.report(outfile);
    c0.report(outfile);
    c1.report(outfile);
    c2.report(outfile);
    outfile.close();

}