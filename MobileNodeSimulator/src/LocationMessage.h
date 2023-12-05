#ifndef LOCATIONMESSAGE_H
#define LOCATIONMESSAGE_H

#include <omnetpp.h>

using namespace omnetpp;

/**
 * Message class to carry location data.
 */
class LocationMessage : public cMessage {
  private:
    int location;

  public:
    LocationMessage(int loc=0) : location(loc) {}
    void setLocation(int loc) { location = loc; }
    int getLocation() const { return location; }
};

#endif
