#ifndef L1Trigger_TrackFindingTracklet_interface_VMStubTE_h
#define L1Trigger_TrackFindingTracklet_interface_VMStubTE_h

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <vector>

#include "L1Trigger/TrackFindingTracklet/interface/L1TStub.h"
#include "L1Trigger/TrackFindingTracklet/interface/Stub.h"
#include "L1Trigger/TrackFindingTracklet/interface/FPGAWord.h"

namespace trklet {

  class VMStubTE {
  public:
    VMStubTE() {}

    VMStubTE(std::pair<Stub*, L1TStub*> stub, FPGAWord finephi, FPGAWord bend, FPGAWord vmbits, FPGAWord allstubindex);

    ~VMStubTE() {}

    FPGAWord finephi() const { return finephi_; }

    FPGAWord bend() const { return bend_; }

    FPGAWord vmbits() const { return vmbits_; }

    std::pair<Stub*, L1TStub*> stub() const { return stub_; }

    bool isPSmodule() const { return stub_.first->isPSmodule(); }

    FPGAWord stubindex() const { return allStubIndex_; }

    //return binary string for memory printout
    std::string str() const;

  private:
    FPGAWord finephi_;
    FPGAWord finerz_;
    FPGAWord bend_;
    FPGAWord vmbits_;
    FPGAWord allStubIndex_;
    std::pair<Stub*, L1TStub*> stub_;
  };
};  // namespace trklet
#endif
