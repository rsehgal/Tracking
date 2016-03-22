/*
 * Scintillator.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rsehgal
 */
#include "Scintillator.h"
#include <iostream>
#include <sstream>

namespace Tracking{

/*************************************************
 ******* Definition of Scintillator class ********
 *************************************************/

int Scintillator::fId=-1;

Scintillator::Scintillator():fLength(0),fBreadth(0),fHeight(0), fScintHit(false) ,fModuleId(0) {
  fId++;
  fScintId = fId;
  std::stringstream ss;
  ss << "Module" << fModuleId <<"_LE_CH" << fScintId;
  fBName = ss.str();

}

Scintillator::Scintillator(double length, double breadth, double height) :
    fLength(length), fBreadth(breadth), fHeight(height), fScintHit(false), fModuleId(0) {
  fId++;
  fScintId = fId;

  std::stringstream ss;
  ss << "Module" << fModuleId <<"_LE_CH" << fScintId;
  fBName = ss.str();
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

void Scintillator::DetectAndSetHit(bool t){
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


/*************************************************
 ***** Definition of ScintillatorPlane class *****
 *************************************************/


ScintillatorPlane::ScintillatorPlane():
    fNumOfScintillators(8),
    fScintTotal(0),
    fPlaneName("Test-ScintillatorPlane"){
  InitializeScintillatorPlane();
  //CreatePlaneOfScintillators();
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


