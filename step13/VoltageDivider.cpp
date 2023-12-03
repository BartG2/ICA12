#include "VoltageDivider.h"

//constructor
VoltageDivider::VoltageDivider(double voltage = 1, double resistance1 = 1, double resistance2 = 1) : Network(3){
    source.setVoltage(voltage);
    r1.setResistance(resistance1);
    r2.setResistance(resistance2);
    addComponent(source, 0, 1);
    addComponent(r1, 1, 2);
    addComponent(r2, 2, 0);

    calculate();
}

//mutators
void VoltageDivider::setSourceVoltage(double voltage){
    source.setVoltage(voltage);
    calculate();
 }
void VoltageDivider::setBothResistors(double resistance1, double resistance2){
    r1.setResistance(resistance1);
    r2.setResistance(resistance2);
    calculate();
}

//other members
void VoltageDivider::report(ofstream& outfile){
    outfile << "\n";

    //print 48 "-"
    for(int i = 0; i < 48; i++){
        outfile << "-";
    }

    outfile << "\n\nData for Electric Network # " << getIndex() << ":" << endl;
    outfile << "Network # " << getIndex() << " is a Voltage Divider." << endl;
    Network::report(outfile);
    outfile << "At present, there are " << source.getNumComponents() << " components in existence." << endl;
    source.report(outfile);
    r1.report(outfile);
    r2.report(outfile);
}
void VoltageDivider::calculate(){
    setVoltage(0, 0);
    setVoltage(1, source.getVoltage());

    double totalResistance = r1.getResistance() + r2.getResistance();
    double loopCurrent = source.getVoltage() / totalResistance;

    source.setCurrent(loopCurrent);
    setVoltage(2, loopCurrent*r2.getResistance());
}

