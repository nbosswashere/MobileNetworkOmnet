#include "ServerHub.h"
#include "LocationMessage.h"

Define_Module(ServerHub);

void ServerHub::initialize() {
    // Any initialization if required
}

void ServerHub::handleMessage(cMessage *msg) {
    if (msg->arrivedOn("in1") || msg->arrivedOn("in2") || msg->arrivedOn("inLocation")) {
        // Assuming messages from stationaryNode1 or stationaryNode2 are location targets
        if (dynamic_cast<LocationMessage *>(msg) != nullptr) {
            // Forward the location target to the MobileNode
            send(msg->dup(), "outMobile");
        }

        // Forward location updates to both stationary nodes.
        for (int i = 0; i < gateSize("out"); ++i) {
            send(msg->dup(), "out", i);
        }
    } else {
        // Messages received from the MobileNode are to be forwarded to stationary nodes
        // Handle differently if necessary, for now, it just forwards the message.
        for (int i = 0; i < gateSize("out"); ++i) {
            send(msg->dup(), "out", i);
        }
    }

    delete msg; // Clean up the original message
}
