/*
 * Scintillator.h
 *
 *  Created on: Mar 9, 2016
 *      Author: rsehgal
 */

#ifndef INC_SCINTILLATOR_H_
#define INC_SCINTILLATOR_H_


#define scint_top1 0
#define scint_top2 1
#define scint_top3 2
#define scint_top4 3
#define scint_top5 4
#define scint_top6 5
#define scint_top7 6
#define scint_top8 7

#define scint_bot1 8
#define scint_bot2 9
#define scint_bot3 10
#define scint_bot4 11
#define scint_bot5 12
#define scint_bot6 13
#define scint_bot7 14
#define scint_bot8 15

#include <vector>
#include <algorithm>
#include"base/Global.h"

namespace Tracking{

class Scintillator{
private:
  //Dimension of Scintillator, not required for the time being
  //May be required in future
  double fLength;
  double fBreadth;
  double fHeight;

  int fModuleId; //represents the id of Module at which it is connected
  int fScintId; //represents it id of channel on a Module
  static int fId;//Static variable to increase whenever a new object is created.
  bool fScintHit;


public:
  Scintillator();//:fLength(0),fBreadth(0),fHeight(0), fScintHit(false) {}
  Scintillator(double length, double breadth, double height=1);// :
    //fLength(length), fBreadth(breadth), fHeight(height), fScintHit(false) {}
  ~Scintillator(){}


  TRACKING_INLINE
  void SetModuleId(int moduleId){fModuleId = moduleId;}
  TRACKING_INLINE
  int GetModuleId(){return fModuleId;}
  TRACKING_INLINE
  void SetChannelId(int channelId){fScintId = channelId;}
  TRACKING_INLINE
  int GetChannelId(){return fScintId;}
  TRACKING_INLINE
  bool GetScintHit(){return fScintHit;}

  void DetectAndSetHit();



};//end of Scintillator class


class ScintillatorPlane{
private:
  int fScintTotal;
  int fNumOfScintillators;
  std::vector<Scintillator*> fScintillatorPlane;
  std::string fPlaneName;

public:
  ScintillatorPlane();//: fScintTotal(0), fNumOfScintillators(8){}
  ScintillatorPlane(int numOfScintillators, std::string planeName="Test-ScintillatorPlane");

  ~ScintillatorPlane(){}

  void CreatePlaneOfScintillators();
  void ReadScintMapFileAndCreatePlane();

  TRACKING_INLINE
  void SetNumOfScintillators(int numOfScintillators){fNumOfScintillators = numOfScintillators;}

  TRACKING_INLINE
  int GetNumOfScintillators(){return fNumOfScintillators;}

  TRACKING_INLINE
  void SetPlaneName(std::string planeName){fPlaneName = planeName;}

  TRACKING_INLINE
  std::string GetPlaneName(){return fPlaneName;}

  void Print();

  void DetectTotalScintFired();

};//end of ScintillatorPlane class

}//end of Tracking namespace


#endif /* INC_SCINTILLATOR_H_ */
