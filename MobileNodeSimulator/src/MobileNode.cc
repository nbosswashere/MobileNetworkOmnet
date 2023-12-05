#include "MobileNode.h"
#include "LocationMessage.h"

Define_Module(MobileNode);

void MobileNode::initialize() {
    currentLocation = 0; // Assuming starting location is always 0
}

void MobileNode::handleMessage(cMessage *msg) {
    LocationMessage *locMsg = dynamic_cast<LocationMessage *>(msg);
    if (locMsg) {
        int targetLocation = locMsg->getLocation();
        if (currentLocation != targetLocation) {
            // Begin movement towards target location, for simplicity, we move 1 unit per step
            currentLocation += (currentLocation < targetLocation) ? 1 : -1;

            // Create and send an update about the new location
            LocationMessage *updateMsg = new LocationMessage(currentLocation);
            send(updateMsg, "outLocation"); // Send the update back to the ServerHub

            // Schedule the next movement step if we haven't arrived yet
            scheduleAt(simTime() + 1.0, new cMessage("moveStep"));
        } else {
            // Target reached, send acknowledgment
            cMessage *ackMsg = new cMessage("TargetReached");
            send(ackMsg, "outLocation");
        }
    }

    if (msg->isSelfMessage()) {
        // Trigger another move step
        handleMessage(new LocationMessage(currentLocation));
    }

    delete msg;
}

void MobileNode::finish() {
    // Clean up if necessary (e.g., cancel any pending self-messages)
}
