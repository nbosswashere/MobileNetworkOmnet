
#ifndef STATIONARYNODE_H
#define STATIONARYNODE_H

#include <omnetpp.h>

using namespace omnetpp;

class StationaryNode : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
