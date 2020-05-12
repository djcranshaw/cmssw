#ifndef L1Trigger_TrackFindingTracklet_interface_L1TStub_h
#define L1Trigger_TrackFindingTracklet_interface_L1TStub_h

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <vector>

namespace Trklet {

  class L1TStub {
  public:
    L1TStub();
    L1TStub(int eventid,
            std::vector<int> tps,
            int iphi,
            int iz,
            int layer,
            int ladder,
            int module,
            int strip,
            double x,
            double y,
            double z,
            double sigmax,
            double sigmaz,
            double pt,
            double bend,
            int isPSmodule,
            int isFlipped);

    virtual ~L1TStub() {}
    
    void AddInnerDigi(int ladder, int module, int irphi, int iz);
    void AddOuterDigi(int ladder, int module, int irphi, int iz);

    void write(std::ofstream& out);
    void write(std::ostream& out);

    int ptsign();

    double diphi();

    double iphiouter();

    double diz();

    unsigned int layer() const { return layer_; }
    int disk() const {
      if (z_ < 0.0) {
        return -module_;
      }
      return module_;
    }
    unsigned int ladder() const { return ladder_; }
    unsigned int module() const { return module_; }
    std::vector<std::pair<int, int> > innerdigis() const { return innerdigis_; }
    std::vector<std::pair<int, int> > outerdigis() const { return outerdigis_; }
    std::vector<std::pair<int, int> > innerdigisladdermodule() const { return innerdigisladdermodule_; }
    std::vector<std::pair<int, int> > outerdigisladdermodule() const { return outerdigisladdermodule_; }
    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }
    double r() const { return sqrt(x_ * x_ + y_ * y_); }
    double pt() const { return pt_; }
    double r2() const { return x_ * x_ + y_ * y_; }
    double bend() const { return bend_; }

    double phi() const { return atan2(y_, x_); }

    unsigned int iphi() const { return iphi_; }
    unsigned int iz() const { return iz_; }

    void setiphi(int iphi) { iphi_ = iphi; }
    void setiz(int iz) { iz_ = iz; }

    double sigmax() const { return sigmax_; }
    double sigmaz() const { return sigmaz_; }

    bool operator==(const L1TStub& other) const;

    void lorentzcor(double shift);

    int eventid() const { return eventid_; }
    std::vector<int> tps() const { return tps_; }

    void setAllStubIndex(unsigned int index) { allstubindex_ = index; }

    unsigned int allStubIndex() const { return allstubindex_; }

    unsigned int strip() const { return strip_; }

    double alpha() const;

    //Scaled to go between -1 and +1
    double alphanew() const;

    double alphatruncated() const;

    void setXY(double x, double y);

    unsigned int isPSmodule() const { return isPSmodule_; }
    unsigned int isFlipped() const { return isFlipped_; }

    bool tpmatch(int tp) const;

  private:
    int eventid_;
    std::vector<int> tps_;
    unsigned int iphi_;
    unsigned int iz_;
    unsigned int layer_;
    unsigned int ladder_;
    unsigned int module_;
    unsigned int strip_;
    double x_;
    double y_;
    double z_;
    double sigmax_;
    double sigmaz_;
    double pt_;
    double bend_;
    unsigned int allstubindex_;

    std::vector<std::pair<int, int> > innerdigis_;
    std::vector<std::pair<int, int> > innerdigisladdermodule_;
    std::vector<std::pair<int, int> > outerdigis_;
    std::vector<std::pair<int, int> > outerdigisladdermodule_;

    unsigned int isPSmodule_;
    unsigned int isFlipped_;
  };
};  // namespace Trklet
#endif
