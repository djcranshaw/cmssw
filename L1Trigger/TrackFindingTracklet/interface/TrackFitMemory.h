#ifndef L1Trigger_TrackFindingTracklet_interface_TrackFitMemory_h
#define L1Trigger_TrackFindingTracklet_interface_TrackFitMemory_h

#include "L1Trigger/TrackFindingTracklet/interface/MemoryBase.h"

#include <vector>

namespace trklet {

  class Settings;
  class Stub;
  class L1TStub;
  class Tracklet;
  class L1SimTrack;

  class TrackFitMemory : public MemoryBase {
  public:
    TrackFitMemory(std::string name, const Settings* const settings, unsigned int iSector, double phimin, double phimax);

    ~TrackFitMemory() {}

    void addTrack(Tracklet* tracklet) { tracks_.push_back(tracklet); }
    void addStubList(std::vector<std::pair<Stub*, L1TStub*>> stublist) { stublists_.push_back(stublist); }
    void addStubidsList(std::vector<std::pair<int, int>> stubidslist) { stubidslists_.push_back(stubidslist); }

    unsigned int nTracks() const { return tracks_.size(); }
    unsigned int nStublists() const { return stublists_.size(); }
    unsigned int nStubidslists() const { return stubidslists_.size(); }

    Tracklet* getTrack(unsigned int i) const { return tracks_[i]; }
    std::vector<std::pair<Stub*, L1TStub*>> getStublist(unsigned int i) const { return stublists_[i]; }
    std::vector<std::pair<int, int>> getStubidslist(unsigned int i) const { return stubidslists_[i]; }

    void clean() {
      tracks_.clear();
      stublists_.clear();
      stubidslists_.clear();
    }

    bool foundTrack(std::ofstream& outres, L1SimTrack simtrk);

    void writeTF(bool first);

  private:
    double phimin_;
    double phimax_;
    std::vector<Tracklet*> tracks_;
    std::vector<std::vector<std::pair<Stub*, L1TStub*>>> stublists_;
    std::vector<std::vector<std::pair<int, int>>> stubidslists_;
  };

};  // namespace trklet
#endif
