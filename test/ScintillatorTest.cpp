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

  std::vector<Scintillator*> scintVector = topPlane.GetScintillatorPlane();
  for(int i = 0 ; i < scintVector.size() ; i++){
    std::cout<< "Name : "<< scintVector[i]->GetName() << std::endl;
  }

  scintVector = bottomPlane.GetScintillatorPlane();
  for(int i = 0 ; i < scintVector.size() ; i++){
    std::cout<< "Name : "<< scintVector[i]->GetName() << std::endl;
  }

}




