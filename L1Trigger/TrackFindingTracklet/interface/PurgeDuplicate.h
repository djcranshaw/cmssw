#ifndef L1Trigger_TrackFindingTracklet_interface_PurgeDuplicate_h
#define L1Trigger_TrackFindingTracklet_interface_PurgeDuplicate_h

#include "L1Trigger/TrackFindingTracklet/interface/TrackFitMemory.h"
#include "L1Trigger/TrackFindingTracklet/interface/CleanTrackMemory.h"
#include "L1Trigger/TrackFindingTracklet/interface/ProcessBase.h"

#include <vector>

namespace Trklet {

  class Settings;
  class Globals;
  class MemoryBase;
  class Stub;
  class L1TStub;
  class Track;
  class Tracklet;

  class PurgeDuplicate : public ProcessBase {
  public:
    PurgeDuplicate(std::string name, const Settings* settings, Globals* global, unsigned int iSector);

    virtual ~PurgeDuplicate() {}

    void addOutput(MemoryBase* memory, std::string output);

    void addInput(MemoryBase* memory, std::string input);

    void execute(std::vector<Track*>& outputtracks_);

  private:
    double getPhiRes(Tracklet* curTracklet, std::pair<Stub*, L1TStub*> curStub);

    std::vector<Track*> inputtracks_;
    std::vector<std::vector<std::pair<Stub*, L1TStub*>>> inputstublists_;
    std::vector<std::vector<std::pair<int, int>>> inputstubidslists_;
    std::vector<std::vector<std::pair<int, int>>> mergedstubidslists_;
    std::vector<TrackFitMemory*> inputtrackfits_;
    std::vector<Tracklet*> inputtracklets_;
    std::vector<CleanTrackMemory*> outputtracklets_;
  };

};  // namespace Trklet
#endif
