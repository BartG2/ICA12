#include "Node.h"
#include "Component.h"
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
#include "VoltageDivider.h"
#include "CurrentDivider.h"
#include "DCCurrentSource.h"
#include <iostream>

using namespace std;

int main(){

    ifstream infile("ECE 0301 - Circuits to Simulate.txt");

    ofstream outfile("ECE 0301 - Electrical Network Simulation.txt");
    ofstream outfile("ECE 0301 - Electrical Network Reports.txt");
    
    outfile << "ECE 0301 - Electrical Network Simulation" << endl;

    string line;

    while(getline(infile, line)){
        if(line != "Voltage Divider" && line != "Current Divider"){
            cout << "ERROR! Invalid network type.";
            exit(-1);
        }

        if(line == "Voltage Divider"){
            double Vs, R1, R2;
            infile >> Vs >> R1 >> R2;
            VoltageDivider net(Vs, R1, R2);
            net.report(outfile);
            infile.ignore();
        }

        if(line == "Current Divider"){
            double Is, R1, R2;
            infile >> Is >> R1 >> R2;
            CurrentDivider net(Is, R1, R2);
            net.report(outfile);
            infile.ignore();
        }
    }



    outfile.close();

}
