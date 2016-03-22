/*
 * ScintillatorTest.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rsehgal
 */

#include "Scintillator.h"
#include <iostream>
#include <TApplication.h>

using namespace Tracking;

int main(){

  ScintillatorPlane topPlane(8,"Top-Plane");
  ScintillatorPlane bottomPlane(8,"Bottom-Plane");
  topPlane.Print();
  bottomPlane.Print();

  std::cout<<"----- Print Top Scintillator Names ------"<<std::endl;
  std::vector<Scintillator*> scintVector = topPlane.GetScintillatorPlane();
  for(int i = 0 ; i < scintVector.size() ; i++){
    std::cout<< "Name : "<< scintVector[i]->GetName() << std::endl;
  }
std::cout<<"----- Print Bottom Scintillator Names ------"<<std::endl;
  scintVector = bottomPlane.GetScintillatorPlane();
  for(int i = 0 ; i < scintVector.size() ; i++){
    std::cout<< "Name : "<< scintVector[i]->GetName() << std::endl;
  }

  std::cout<<"-------- Testing Read of Scintillator Data ----------"<<std::endl;
  scintVector = topPlane.GetScintillatorPlane();
  for(int i = 0 ; i < scintVector.size() ; i++){
    std::cout<<"Name : "<< scintVector[i]->GetName() << " : ";
    Channel *ch = scintVector[i]->GetEntry(1000);
    if(!ch->size())
      std::cout<<"No Data"<<std::endl;
    else{
    for(int j= 0 ; j < ch->size() ; j++){
    std::cout<< "Data : "<< ch->at(j) << " , ";
    }
    std::cout<<std::endl;
    }
  }
  TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  topPlane.CreateHistogram();
//  for(int i = 0 ; i < scintVector.size() ; i++){
//    scintVector[i]->CreateHistogram();
//  }
  fApp->Run();
}




