
#ifndef SERVERHUB_H
#define SERVERHUB_H

#include <omnetpp.h>

using namespace omnetpp;

class ServerHub : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
