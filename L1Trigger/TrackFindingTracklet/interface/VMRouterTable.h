#ifndef L1Trigger_TrackFindingTracklet_interface_VMRouterTable_h
#define L1Trigger_TrackFindingTracklet_interface_VMRouterTable_h

#include "L1Trigger/TrackFindingTracklet/interface/FPGAWord.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <vector>

namespace Trklet {

  class Settings;

  class VMRouterTable {
  public:
    VMRouterTable(const Settings* settings);
    VMRouterTable(const Settings* settings, unsigned int layerdisk);

    ~VMRouterTable() {}

    void init(unsigned int layerdisk);

    // negative return means that seed can not be formed
    int getLookup(unsigned int layerdisk, double z, double r, int iseed=-1);
    //int getLookupValue(const Settings* settings, int izbin, int irbin);

    int lookup(int zbin, int rbin);
    int lookupdisk(int zbin, int rbin);
    int lookupinner(int zbin, int rbin);
    int lookupinneroverlap(int zbin, int rbin);
    int lookupinnerThird(int zbin, int rbin);

  private:

    const Settings *settings_;
    
    //double rmean_;

    double rmin_;
    double rmax_;

    double zmin_;
    double zmax_;

    double dr_;
    double dz_;

    int zbits_;
    int rbits_;

    int zbins_;
    int rbins_;

    //int layer_;
    std::vector<int> vmrtable_; //used for ME and outer TE
    std::vector<int> vmrtabletedisk_; //outer disk used by D1, D2, and D4
    std::vector<int> vmrtableteinner_; //projection to next layer/disk
    std::vector<int> vmrtableteinneroverlap_; //projection to disk
    std::vector<int> vmrtableteinnerThird_; //projection to disk1 for extended - iseed=10
    
  };
};  // namespace Trklet
#endif
