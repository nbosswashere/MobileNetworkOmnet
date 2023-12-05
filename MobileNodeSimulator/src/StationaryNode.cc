#include "StationaryNode.h"
#include "LocationMessage.h"

Define_Module(StationaryNode);

void StationaryNode::initialize() {
    if (strcmp("stationaryNode1", getName()) == 0) {
        // Schedule an event to send the location
        scheduleAt(simTime() + dblrand(), new cMessage("sendLocation"));
    }
}

void StationaryNode::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        LocationMessage *locMsg = new LocationMessage(targetLocation);
        locMsg->addPar("pass") = true; // Example criteria for a packet to be passed by the firewall
        send(locMsg, "out");
    }
    // Clean up received messages (if any).
    delete msg;
}
