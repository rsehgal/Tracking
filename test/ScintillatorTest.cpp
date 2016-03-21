/*
 * ScintillatorTest.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rsehgal
 */

#include "Scintillator.h"
#include <iostream>

using namespace Tracking;

int main(){

  ScintillatorPlane topPlane(4,"Top-Plane");
  ScintillatorPlane bottomPlane(8,"Bottom-Plane");
  topPlane.Print();
  bottomPlane.Print();

}




