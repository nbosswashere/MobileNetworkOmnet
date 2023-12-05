#ifndef MOBILENODE_H
#define MOBILENODE_H

#include <omnetpp.h>

using namespace omnetpp;

class MobileNode : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif // MOBILENODE_H
