package simulations;
import ned.IBidirectionalChannel;
import ned.IUnidirectionalChannel;

module MobileNode
{
    @display("bgb=530,319");
    gates:
        input in; // For receiving commands from ServerHub
        output outLocation; // For sending location data to ServerHub
}
