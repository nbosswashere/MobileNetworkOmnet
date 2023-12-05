package simulations;
module ServerHub
{
    gates:
        input in1; // For StationaryNode1
        input in2; // For StationaryNode2
        input inLocation; // For location data from MobileNode
        output outMobile; // For sending commands to MobileNode
        output out[2]; // For sending updates to StationaryNode1 and StationaryNode2 as an array
}
