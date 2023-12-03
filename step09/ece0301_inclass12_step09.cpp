#include "Node.h"
#include "Component.h"
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"

int main(){

    ofstream outfile("ECE 0301 - Electrical Network Simulation.txt");
    outfile << "ECE 0301 = Electrical Network Simulation" << endl;

    Network network(3);

    DCVoltageSource c0;
    c0.setVoltage(12);
    network.addComponent(c0, 0, 1);

    Resistor c1, c2;
    c1.setResistance(200);
    c2.setResistance(100);
    network.addComponent(c1, 1, 2);
    network.addComponent(c2, 2, 0);

    network.setVoltage(1, c0.getVoltage());
    network.setVoltage(2, c0.getVoltage()/3.0);

    //calculate what c0's current should be
    c0.setCurrent(c0.getVoltage()/(c1.getResistance()+c2.getResistance()));

    network.report(outfile);
    c0.report(outfile);
    c1.report(outfile);
    c2.report(outfile);

    outfile.close();

}