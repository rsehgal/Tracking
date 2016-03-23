/*
 * ScintillatorTest.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rsehgal
 */

#include "Scintillator.h"
#include <iostream>
#include <TApplication.h>
#include "Statistics.h"

using namespace Tracking;

int main(){

  ScintillatorPlane topPlane(2,8,"Top-Plane");
  ScintillatorPlane bottomPlane(2,8,"Bottom-Plane");
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
    Channel *ch = scintVector[i]->GetEntry(839);
    if(!ch->size())
      std::cout<<"No Data"<<std::endl;
    else{
    for(int j= 0 ; j < ch->size() ; j++){
    std::cout<< "Data : "<< ch->at(j) << " , ";
    }
    std::cout<<std::endl;
    }
  }
  //TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  bottomPlane.CreateHistogram();
  topPlane.CreateHistogram2D();
  //fApp->Run();

   /*
    * Trying to create Rpc Strips using Scintillators
    */

   Scintillator::SetStartingId(31);
   ScintillatorPlane rpc1(2,96,"First-RPC");
   Scintillator::SetStartingId(31);
   ScintillatorPlane rpc2(3,96,"First-RPC");
   //Printing the name of each strip to verify the creation of 96 strips of RPCs
   std::vector<Scintillator*> scintVectorRpc = rpc1.GetScintillatorPlane();
   for(int i = 0 ; i < scintVectorRpc.size() ; i++){
     std::cout<<"Strip Name : "<< scintVectorRpc[i]->GetName() <<std::endl;
   }

   std::cout<<"--------- Printing Second Rpc -----------"<<std::endl;
   scintVectorRpc = rpc2.GetScintillatorPlane();
   for(int i = 0 ; i < scintVectorRpc.size() ; i++){
        std::cout<<"Strip Name : "<< scintVectorRpc[i]->GetName() <<std::endl;
      }


 //Statistics s;
 //s.GenerateTimingHistogram();


/*
  int numEvents = 0;
  for(int i = 0 ; i< numEvents ; i++){
    //std::cout<<"==============================================="<<std::endl;
    if(topPlane.IsShowerEvent(i)){
    std::cout<<"Event Num : "<< i << "  :: IsShowerEvent : "<< topPlane.IsShowerEvent(i) << "  :: ShowerCount : "
             <<topPlane.GetShowerCount()<<std::endl;
    }
  }
*/

/*  std::cout<<"+++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  topPlane.Create2DHistOfTimingAndChannels();
  fApp->Run();*/
}




