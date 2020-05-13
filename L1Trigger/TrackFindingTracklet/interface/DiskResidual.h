#ifndef L1Trigger_TrackFindingTracklet_interface_DiskResidual_h
#define L1Trigger_TrackFindingTracklet_interface_DiskResidual_h

#include "L1Trigger/TrackFindingTracklet/interface/FPGAWord.h"

#include <cassert>

namespace trklet {

  class Settings;
  class Stub;
  class L1TStub;

  class DiskResidual {
  public:
    DiskResidual() { valid_ = false; }

    ~DiskResidual() = default;
    
    void init(const Settings* settings,
              int disk,
              int iphiresid,
              int irresid,
              int istubid,
              double phiresid,
              double rresid,
              double phiresidapprox,
              double rresidapprox,
              double zstub,
              double alpha,
              FPGAWord ialpha,
              std::pair<const Stub*, const L1TStub*> stubptrs);

    bool valid() const { return valid_; }

    const FPGAWord& fpgaphiresid() const {
      assert(valid_);
      return fpgaphiresid_;
    };

    const FPGAWord& fpgarresid() const {
      assert(valid_);
      return fpgarresid_;
    };

    const FPGAWord& fpgastubid() const {
      assert(valid_);
      return fpgastubid_;
    };

    double phiresid() const {
      assert(valid_);
      return phiresid_;
    };

    double rresid() const {
      assert(valid_);
      return rresid_;
    };

    double phiresidapprox() const {
      assert(valid_);
      return phiresidapprox_;
    };

    double rresidapprox() const {
      assert(valid_);
      return rresidapprox_;
    };

    double zstub() const {
      assert(valid_);
      return zstub_;
    };

    double alpha() const {
      assert(valid_);
      return alpha_;
    };

    const FPGAWord& ialpha() const {
      assert(valid_);
      return ialpha_;
    };

    std::pair<const Stub*, const L1TStub*> stubptrs() const {
      assert(valid_);
      return stubptrs_;
    };

  protected:
    bool valid_;

    int disk_;

    FPGAWord fpgaphiresid_;
    FPGAWord fpgarresid_;
    FPGAWord fpgastubid_;

    double phiresid_;
    double rresid_;

    double phiresidapprox_;
    double rresidapprox_;

    double zstub_;
    double alpha_;
    FPGAWord ialpha_;
    std::pair<const Stub*, const L1TStub*> stubptrs_;
  };

};  // namespace trklet
#endif
