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

namespace Tracking{

class Scintillator{
private:
  //Dimension of Scintillator, not required for the time being
  //May be required in future
  double fLength;
  double fBreadth;
  double fHeight;

  bool fScintHit;

public:
  Scintillator():fLength(0),fBreadth(0),fHeight(0), fScintHit(false) {}
  Scintillator(double length, double breadth, double height=1) :
    fLength(length), fBreadth(breadth), fHeight(height), fScintHit(false) {}
  ~Scintillator(){}

};//end of Scintillator class


class ScintillatorPlane{
private:
  int fScintTotal;
  std::vector<Scintillator*> fScintillatorPlane;

public:
  ScintillatorPlane(): fScintTotal(0){}
  ~ScintillatorPlane(){}

};//end of ScintillatorPlane class

}//end of Tracking namespace


#endif /* INC_SCINTILLATOR_H_ */
