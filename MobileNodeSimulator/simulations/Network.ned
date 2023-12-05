package simulations;

network Network
{
    submodules:
        ServerHub: ServerHub {
            @display("p=150,174");
        }
        stationaryNode1: StationaryNode {
            @display("p=100,100");
        }
        stationaryNode2: StationaryNode {
            @display("p=200,100");
        }
        mobileNode: MobileNode {
            @display("p=150,250");
        }
    connections allowunconnected:
    // Corrected connections from Stationary Nodes to ServerHub:
    stationaryNode1.out --> Firewall.in;
    Firewall.out --> ServerHub.in1;

    stationaryNode2.out --> Firewall.in;
    Firewall.out --> ServerHub.in2;
    // Corrected connection from ServerHub to MobileNode to send commands:
    ServerHub.outMobile --> mobileNode.in;  // Assuming mobileNode has an input gate named in

    // Corrected connection from MobileNode to ServerHub for location data:
    mobileNode.outLocation --> ServerHub.inLocation;  // Assuming serverHub has an input gate named inLocation

    // Corrected connections from ServerHub to Stationary Nodes for updates:
    ServerHub.out[0] --> stationaryNode1.in; // Connection to StationaryNode1
    ServerHub.out[1] --> stationaryNode2.in; // Connection to StationaryNode2 // Assuming stationaryNode2 has an input gate named in
}
