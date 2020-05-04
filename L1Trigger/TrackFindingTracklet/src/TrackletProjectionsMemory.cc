#include "L1Trigger/TrackFindingTracklet/interface/TrackletProjectionsMemory.h"
#include "L1Trigger/TrackFindingTracklet/interface/Tracklet.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

using namespace std;
using namespace Trklet;

TrackletProjectionsMemory::TrackletProjectionsMemory(string name, const Settings* const settings, unsigned int iSector):
  MemoryBase(name, settings, iSector) {

    string subname = name.substr(11, 2);
    if (subname[0] == '_')
      subname = name.substr(12, 2);
    if (settings_->extended()) {
      subname = name.substr(14, 2);
      if (subname[0] == '_')
        subname = name.substr(15, 2);
    }

    layer_ = 0;
    disk_ = 0;
    if (subname == "L1")
      layer_ = 1;
    if (subname == "L2")
      layer_ = 2;
    if (subname == "L3")
      layer_ = 3;
    if (subname == "L4")
      layer_ = 4;
    if (subname == "L5")
      layer_ = 5;
    if (subname == "L6")
      layer_ = 6;
    if (subname == "D1")
      disk_ = 1;
    if (subname == "D2")
      disk_ = 2;
    if (subname == "D3")
      disk_ = 3;
    if (subname == "D4")
      disk_ = 4;
    if (subname == "D5")
      disk_ = 5;

    subname = name.substr(11, 2);
    if (subname[0] == '_')
      subname = name.substr(14, 2);

    if (subname == "D1")
      disk_ = 1;
    if (subname == "D2")
      disk_ = 2;
    if (subname == "D3")
      disk_ = 3;
    if (subname == "D4")
      disk_ = 4;
    if (subname == "D5")
      disk_ = 5;

    if (layer_ == 0 && disk_ == 0) {
      edm::LogProblem("Tracklet") << name << " subname = " << subname << " " << layer_ << " " << disk_;
      edm::LogProblem("Tracklet") << "Please check that right *.dat files are included in TrackFindingTracklet/python/Tracklet_cfi.py";
    }
    assert((layer_ != 0) || (disk_ != 0));
}

void TrackletProjectionsMemory::addProj(Tracklet* tracklet) {
  if (layer_ != 0 && disk_ == 0)
    assert(tracklet->validProj(layer_));
  if (layer_ == 0 && disk_ != 0)
    assert(tracklet->validProjDisk(disk_));
  if (layer_ != 0 && disk_ != 0)
    assert(tracklet->validProj(layer_) || tracklet->validProjDisk(disk_));
  
  for (unsigned int i = 0; i < tracklets_.size(); i++) {
    if (tracklets_[i] == tracklet) {
      edm::LogPrint("Tracklet") << "Adding same tracklet " << tracklet << " twice in " << getName();
    }
    assert(tracklets_[i] != tracklet);
  }
  
  tracklets_.push_back(tracklet);
}

void TrackletProjectionsMemory::clean() {
  tracklets_.clear();
}

void TrackletProjectionsMemory::writeTPROJ(bool first) {
  std::string fname = "../data/MemPrints/TrackletProjections/TrackletProjections_";
  fname += getName();
  fname += "_";
  ostringstream oss;
  oss << iSector_ + 1;
  if (iSector_ + 1 < 10)
    fname += "0";
  fname += oss.str();
  fname += ".dat";
  if (first) {
    bx_ = 0;
    event_ = 1;
    out_.open(fname.c_str());
  } else
    out_.open(fname.c_str(), std::ofstream::app);
  
  out_ << "BX = " << (bitset<3>)bx_ << " Event : " << event_ << endl;
  
  for (unsigned int j = 0; j < tracklets_.size(); j++) {
    string proj = (layer_ > 0 && tracklets_[j]->validProj(layer_)) ? tracklets_[j]->trackletprojstrlayer(layer_)
      : tracklets_[j]->trackletprojstrdisk(disk_);
    out_ << "0x";
    if (j < 16)
      out_ << "0";
    out_ << hex << j << dec;
    out_ << " " << proj << "  " << Trklet::hexFormat(proj) << endl;
  }
  out_.close();
  
  bx_++;
  event_++;
  if (bx_ > 7)
    bx_ = 0;
}
