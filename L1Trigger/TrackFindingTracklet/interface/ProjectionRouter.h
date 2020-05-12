#ifndef L1Trigger_TrackFindingTracklet_interface_ProjectionRouter_h
#define L1Trigger_TrackFindingTracklet_interface_ProjectionRouter_h

#include "L1Trigger/TrackFindingTracklet/interface/ProcessBase.h"
#include "L1Trigger/TrackFindingTracklet/interface/ProjectionRouterBendTable.h"
#include "L1Trigger/TrackFindingTracklet/interface/TrackletProjectionsMemory.h"
#include "L1Trigger/TrackFindingTracklet/interface/AllProjectionsMemory.h"
#include "L1Trigger/TrackFindingTracklet/interface/VMProjectionsMemory.h"

namespace Trklet {

  class Settings;
  class Globals;
  class MemoryBase;

  class ProjectionRouter : public ProcessBase {
  public:
    ProjectionRouter(std::string name, const Settings* settings, Globals* global, unsigned int iSector);

    virtual ~ProjectionRouter() {}

    void addOutput(MemoryBase* memory, std::string output);
    void addInput(MemoryBase* memory, std::string input);

    void execute();

  private:
    unsigned int layerdisk_;

    int nrbits_;
    int nphiderbits_;

    std::vector<TrackletProjectionsMemory*> inputproj_;

    AllProjectionsMemory* allproj_;
    std::vector<VMProjectionsMemory*> vmprojs_;
  };

};  // namespace Trklet
#endif
