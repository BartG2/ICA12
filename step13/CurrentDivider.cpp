#include "CurrentDivider.h"

//constructor
CurrentDivider::CurrentDivider(double current = 1, double resistance1 = 1, double resistance2 = 1) : Network(2){
    source.setCurrent(current);
    r1.setResistance(resistance1);
    r2.setResistance(resistance2);

    addComponent(source, 0, 1);
    addComponent(r1, 0, 1);
    addComponent(r2, 0, 1);

    calculate();
}

//mutators
void CurrentDivider::setSourceCurrent(double current){
    source.setCurrent(current);
    calculate();
 }
void CurrentDivider::setBothResistors(double resistance1, double resistance2){
    r1.setResistance(resistance1);
    r2.setResistance(resistance2);
    calculate();
}

//other members
void CurrentDivider::report(ofstream& outfile){
    outfile << "\n";

    //print 48 "-"
    for(int i = 0; i < 48; i++){
        outfile << "-";
    }

    outfile << "\n\nData for Electric Network # " << getIndex() << ":" << endl;
    outfile << "Network # " << getIndex() << " is a Current Divider." << endl;
    Network::report(outfile);
    outfile << "At present, there are " << source.getNumComponents() << " components in existence." << endl;
    source.report(outfile);
    r1.report(outfile);
    r2.report(outfile);
}
void CurrentDivider::calculate(){
    setVoltage(0, 0);
    double equivalentResistance = 1/((1/r1.getResistance())+(1/r2.getResistance()));
    setVoltage(1, source.getCurrent()*equivalentResistance);
}

