#ifndef L1Trigger_TrackFindingTracklet_interface_MatchEngine_h
#define L1Trigger_TrackFindingTracklet_interface_MatchEngine_h

#include "L1Trigger/TrackFindingTracklet/interface/ProcessBase.h"
#include <vector>

namespace trklet {

  class Settings;
  class Globals;
  class MemoryBase;
  class VMStubsMEMemory;
  class VMProjectionsMemory;
  class CandidateMatchMemory;

  class MatchEngine : public ProcessBase {
  public:
    MatchEngine(std::string name, const Settings* settings, Globals* global, unsigned int iSector);

    virtual ~MatchEngine() {}

    void addOutput(MemoryBase* memory, std::string output);
    void addInput(MemoryBase* memory, std::string input);

    void execute();

  private:
    VMStubsMEMemory* vmstubs_;
    VMProjectionsMemory* vmprojs_;

    CandidateMatchMemory* candmatches_;

    int layer_;
    int disk_;

    //used in the layers
    std::vector<bool> table_;

    //used in the disks
    std::vector<bool> tablePS_;
    std::vector<bool> table2S_;
  };

};  // namespace trklet
#endif
