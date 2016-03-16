/*
 * Statistics.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: rsehgal
 */
#include "Statistics.h"
#include <sstream>


namespace Tracking{

Statistics::Statistics():
    strip_start(0),
    strip_finish(96),
    maxbins(100),
    hit_max(100),
    noisemaxbins(maxbins*80),
    csize_max(maxbins*3),
    cmulti_max(maxbins*3),
    timemin(trg_windows_min),
    timemax(trg_windows_max),
    framext_start(0),
    framext_finish(10),
    framext_bin(framext_finish-framext_start),
    xtmax(maxbins*2),
    xtbins(xtmax),
    max_modules(6),

    trg_windows_min(-120),
    trg_windows_max(120),
    delaytrg(100),
    scint_multiplicity_max(2),
    master_trigger_cutedge(0),
    scint_max(500),
    shower(1),
    canale_cut(0),
    reflimit(2),
    maxprocessable(0),
    site("BARC"),
    onerpctriggermultiplicity_max(10),
    tworpctriggermultiplicity_max(10) {}

void Statistics::GenerateAllTitleStrings(){
  std::stringstream ss;
  ss << fStationNum;

  std::string commonString = fStationName;
  commonString += " at station: " + ss.str();
  commonString += " TRG: ";
  commonString += fTriggerLayer;
  commonString += " (eta=";
  commonString += fEtaPartition;
  commonString += ")";

  fTitleStringStripProfile += commonString;
  fTitleStringNoiseProfile += commonString;
  fTitleStringStripClusterSize += commonString;
  fTitleStringClusterMultiplicity += commonString;
  fTitleStringCrossTalk += commonString;
  fTitleStringHitMultiplicity += commonString;

  bool verbose(false);
  if(verbose){
  std::cout<< fTitleStringStripProfile << std::endl
           << fTitleStringNoiseProfile<<std::endl
           <<fTitleStringStripClusterSize<<std::endl
           <<fTitleStringClusterMultiplicity<<std::endl
           <<fTitleStringCrossTalk<<std::endl
           <<fTitleStringHitMultiplicity<<std::endl;
  }

  //Instatiating histogram
  h_Strip = new TH1F(fTitleStringStripProfile.c_str(), fTitleStringStripProfile.c_str(), strip_bin, strip_start, strip_finish);
  h_Stripnoise = new TH1F(fTitleStringNoiseProfile.c_str(), fTitleStringNoiseProfile.c_str(), strip_bin, strip_start, strip_finish);
  h_clustersize = new TH1F(fTitleStringStripClusterSize.c_str(), fTitleStringStripClusterSize.c_str(), 10, 1, 11);
  h_clustermultiplicity = new TH1F(fTitleStringClusterMultiplicity.c_str(), fTitleStringClusterMultiplicity.c_str(), 10, 1, 11);
  h_xtalk = new TH1F(fTitleStringCrossTalk.c_str(), fTitleStringCrossTalk.c_str(), xtbins, 0, xtmax);
  h_hitmultiplicity = new TH1F(fTitleStringHitMultiplicity.c_str(), fTitleStringHitMultiplicity.c_str(), 10, 1, 11);

 }

void Statistics::GenerateStripProfile(){}

void Statistics::GenerateNoiseProfile(){}

void Statistics::GenerateClusterSize(){}

void Statistics::GenerateClusterMultiplicity(){}

void Statistics::GenerateCrossTalkProfile(){}

void Statistics::GenerateHitMultiplicity(){}

}//end of Tracking namespace


