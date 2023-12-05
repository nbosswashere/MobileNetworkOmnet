#ifndef FIREWALL_H
#define FIREWALL_H

#include <omnetpp.h>

using namespace omnetpp;

class Firewall : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // FIREWALL_H
