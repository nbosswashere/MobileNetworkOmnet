#include <string>
#include <omnetpp.h>

using namespace omnetpp;

class Firewall : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Firewall);

void Firewall::initialize() {
    // Initialization can be done here
}

void Firewall::handleMessage(cMessage *msg) {
    // Simple rule: Check if the message has a "pass" control info attached to it
    if (msg->hasPar("pass") && msg->par("pass").boolValue() == true) {
        EV << "Firewall passed message\n";
        send(msg, "out");
    } else {
        EV << "Firewall blocked message\n";
        delete msg;
    }
}
