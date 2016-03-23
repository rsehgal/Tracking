/*
 * Scintillator.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rsehgal
 */
#include "Scintillator.h"
#include <iostream>
#include <sstream>
#include <TCanvas.h>
#include <TH2F.h>
#include <TApplication.h>
#include <TFile.h>
///#include "Tree.h"

namespace Tracking{

/*************************************************
 ******* Definition of Scintillator class ********
 *************************************************/

int Scintillator::fId=-1;

Scintillator::Scintillator():fLength(0),fBreadth(0),fHeight(0), fScintHit(false) ,fModuleId(0) {
  fId++;
  fScintId = fId;
  std::stringstream ss;
  ss << "Module" << fModuleId+2 <<"_LE_CH" << fScintId;
  fBName = ss.str();
  //t = new Tree("6133.root","BSC_DATA_TREE");
  h = new TH1F("h",fBName.c_str(),100,20000,21000);

}

Scintillator::Scintillator(double length, double breadth, double height) :
    fLength(length), fBreadth(breadth), fHeight(height), fScintHit(false), fModuleId(0) {
  fId++;
  fScintId = fId;

  std::stringstream ss;
  ss << "Module" << fModuleId <<"_LE_CH" << fScintId;
  fBName = ss.str();
}

Scintillator::~Scintillator(){//delete t;

}

void Scintillator::DetectAndSetHit(){
/*
*  For the time being hard coding the information related to
*  trigger module and channel.
*  triggerModule : 0 , triggerChannel : 31
*
*  ModuleVector variable "modVector" should be filled after reading the ROOT file
*
*/
  ModuleVector modVector; // This should come prefilled from somewhere else. Here included just
                          // to make compiler happy, should be remove later on
  Channel *trigMultiHit = modVector[0][31];
  long trig = trigMultiHit->at(0);
  Channel *scintMultiHit = modVector[fModuleId][fScintId];
  long scintillator = scintMultiHit->at(0);
  if(  scintillator > 0){
    if(abs(trig - scintillator) < scintMax) fScintHit=true;
  }
}

Channel* Scintillator::GetEntry(int evNo){

  Tree t("6133.root","BSC_DATA_TREE");
  return t.GetEntry(fBName,evNo);
}

TH1F* Scintillator::GetHistogram(){
  Tree t("6133.root","BSC_DATA_TREE");
  int numOfEvents = t.GetNumOfEvents();
  std::cout<<"NumOf Events : "<<numOfEvents<<std::endl;
  for(int evNo= 0 ; evNo < numOfEvents ; evNo++){
    //Channel *ch = t.GetEntry(fBName,evNo);
    ch = t.GetEntry(fBName,evNo);
    if(ch->size()){
      for(int i = 0 ; i < ch->size() ; i++){
        h->Fill(ch->at(i));
      }
    }
  }

  return h;
}




void Scintillator::DetectAndSetHit(int evNo){
/*
*  For the time being hard coding the information related to
*  trigger module and channel.
*  triggerModule : 0 , triggerChannel : 31
*
*  ModuleVector variable "modVector" should be filled after reading the ROOT file
*
*/
  fScintHit = false;
  ModuleVector modVector; // This should come prefilled from somewhere else. Here included just
                          // to make compiler happy, should be remove later on
  Tree t("6133.root","BSC_DATA_TREE");
  Channel *trigMultiHit = t.GetEntry("Module2_LE_CH31",evNo);
  long trig = trigMultiHit->at(0);
  ch = t.GetEntry(fBName,evNo);
  if(ch->size()){
  long scintillator = ch->at(0);
  if(  scintillator > 0){
    if(abs(trig - scintillator) < scintMax) fScintHit=true;
  }
  }

  //std::cout<<"fScintHit : "<< fScintHit <<std::endl;
}


/*************************************************
 ***** Definition of ScintillatorPlane class *****
 *************************************************/

bool ScintillatorPlane::IsShowerEvent(int evNo){
  fScintTotal = 0;

  //std::cout<<"ScintTotal Before : "<<fScintTotal<<std::endl;
  int scintPlaneSize = fScintillatorPlane.size();
  for(int i = 0 ; i < scintPlaneSize ; i++){
    fScintillatorPlane[i]->DetectAndSetHit(evNo);
  }
  DetectTotalScintFired();
  //std::cout<<"ScintTotal : "<<fScintTotal<<std::endl;
  return (fScintTotal >= scint_multiplicity_max);
}


void ScintillatorPlane::CreateHistogram(){
  int scintPlaneSize = fScintillatorPlane.size();
  TCanvas *c1 = new TCanvas("c1",fPlaneName.c_str(),200,10,700,500);
  c1->Divide(4,2);
  for(int i = 0 ; i < scintPlaneSize ; i++){
    c1->cd(i+1);
    fScintillatorPlane[i]->GetHistogram()->Draw();
  }
}

ScintillatorPlane::ScintillatorPlane():
    fNumOfScintillators(8),
    fScintTotal(0),
    fPlaneName("Test-ScintillatorPlane"){
  InitializeScintillatorPlane();
  //CreatePlaneOfScintillators();
}

void ScintillatorPlane::CreateHistogram2D(){

  int nxbins = 1000;
  int xlow = 20000;
  int xhigh = 21000;
  int nybins = 150;
  int ylow = -10;
  int yhigh = 140;
  Channel *trig = 0;
  Channel *ch = 0;

  TCanvas *c2 = new TCanvas("c2",fPlaneName.c_str(),200,10,700,500);
  c2->Divide(1,1);
  c2->cd(1);
  Tree t("6133.root","BSC_DATA_TREE");
  int numOfEvents = t.GetNumOfEvents();

  //TH1F *hTrig = new TH1F("hTrig","TEST",100,20000,21000);
  TH2F *h2d = new TH2F("h2d","Timing",nxbins,xlow,xhigh,nybins,ylow,yhigh);
  for(int evNo= 0 ; evNo < numOfEvents ; evNo++){
    trig  = t.GetEntry("Module2_LE_CH31",evNo);
    h2d->Fill(trig->at(0),31);
    for (int i = 0; i < fScintillatorPlane.size(); i++) {
      ch = t.GetEntry(fScintillatorPlane[i]->GetName(), evNo);
      if (ch->size()) {
        for (int j = 0; j < ch->size(); j++) {
          h2d->Fill(ch->at(j), fScintillatorPlane[i]->GetChannelId());
        }
      }
    }
  }
  h2d->Draw();
  h2d->Print();
  //TFile f("hTrig.root","recreate"); //Open file, then write histo to it.
  TFile::Open("hTrig.root","RECREATE");
  h2d->Write();
  c2->Modified();
  c2->Update();
}

void ScintillatorPlane::Create2DHistOfTimingAndChannels(){
 // Tree t("6133.root","BSC_DATA_TREE");
  int numOfEvents = 10; //t.GetNumOfEvents();
  int nxbins = 1000;
  int xlow = 20000;
  int xhigh = 21000;
  int nybins = 150;
  int ylow = -10;
  int yhigh= 140;
  Channel *trig = 0;
  Channel *ch = 0;

  //TApplication *fApp = new TApplication("Timing", NULL, NULL);
  //TH2F *h2d = new TH2F("h2d","Timing",nxbins,xlow,xhigh,nybins,ylow,yhigh);
  TCanvas *c1 = new TCanvas("c1",fPlaneName.c_str(),200,10,700,500);
  TH1F *h = new TH1F("h","ABCD",100,20000,21000);
  for(int evNo= 0 ; evNo < numOfEvents ; evNo++){
    //trig  = t.GetEntry("Module2_LE_CH31",evNo);
    //std::cout<<"Trig : "<< trig->at(0) <<std::endl;
    //if(trig->size())
    //h2d->Fill(trig->at(0),31);
/*
    for(int i = 0 ; i < fScintillatorPlane.size() ; i++) {
      Channel *ch = t.GetEntry(fScintillatorPlane[i]->GetName(),evNo);
      if(ch->size()){
      for(int j = 0 ; j < ch->size() ; j++){
        h2d->Fill(ch->at(j),fScintillatorPlane[i]->GetChannelId());
      }
     }
    }
*/

  }
  h->Draw();
  //h2d->Draw();
 // h2d->Write("timing.root");
 // fApp->Run();
}

ScintillatorPlane::ScintillatorPlane(int numOfScintillators,std::string planeName) :
    fNumOfScintillators(numOfScintillators),
    fScintTotal(0),
    fPlaneName(planeName) {
    InitializeScintillatorPlane();
    CreatePlaneOfScintillators();
}

void ScintillatorPlane::CreatePlaneOfScintillators(){
  for(int i = 0 ; i< fNumOfScintillators ; i++){
    fScintillatorPlane.push_back(new Scintillator());
  }
}

void ScintillatorPlane::Print(){
    std::cout<<"Plane-Name : "<<fPlaneName<<std::endl
             <<"Num Of Scintillators : "<<fNumOfScintillators<<std::endl;
}

//This function is basically used to detect shower event
void ScintillatorPlane::DetectTotalScintFired(){

  for(int i=0; i < fScintillatorPlane.size(); i++){
    if(fScintillatorPlane[i]->GetScintHit())
      fScintTotal++;
  }


}

void ScintillatorPlane::InitializeScintillatorPlane(){
  fScintTotal = 0;
}

}//end of Tracking namespace


