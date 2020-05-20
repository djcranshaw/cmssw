#ifndef L1Trigger_TrackFindingTracklet_interface_VMStubsMEMemory_h
#define L1Trigger_TrackFindingTracklet_interface_VMStubsMEMemory_h

#include "L1Trigger/TrackFindingTracklet/interface/MemoryBase.h"
#include "L1Trigger/TrackFindingTracklet/interface/VMStubME.h"

#include <string>
#include <vector>

namespace trklet {

  class Settings;
  class Stub;
  class L1TStub;

  class VMStubsMEMemory : public MemoryBase {
  public:
    VMStubsMEMemory(std::string name, const Settings* const settings, unsigned int iSector);

    ~VMStubsMEMemory() override = default;

    void addStub(VMStubME stub, unsigned int bin) {
      stubs_.push_back(stub);
      binnedstubs_[bin].push_back(stub);
    }

    unsigned int nStubs() const { return stubs_.size(); }

    const VMStubME& getVMStubME(unsigned int i) const { return stubs_[i]; }
    const Stub* getFPGAStub(unsigned int i) const { return stubs_[i].stub(); }

    unsigned int nStubsBin(unsigned int bin) const {
      assert(bin < binnedstubs_.size());
      return binnedstubs_[bin].size();
    }

    const VMStubME& getVMStubMEBin(unsigned int bin, unsigned int i) const {
      assert(bin < binnedstubs_.size());
      assert(i < binnedstubs_[bin].size());
      return binnedstubs_[bin][i];
    }

    const Stub* getStubBin(unsigned int bin, unsigned int i) const {
      assert(bin < binnedstubs_.size());
      assert(i < binnedstubs_[bin].size());
      return binnedstubs_[bin][i].stub();
    }

    void clean() override {
      stubs_.clear();
      for (auto& binnedstub : binnedstubs_) {
        binnedstub.clear();
      }
    }

    void writeStubs(bool first);

  private:
    std::vector<VMStubME> stubs_;  //TODO - not used and should be removed
    std::vector<std::vector<VMStubME> > binnedstubs_;
  };

};  // namespace trklet
#endif
