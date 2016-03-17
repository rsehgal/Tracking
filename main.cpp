/*
 * main.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: rsehgal
 */
#include <iostream>
#include "base/Global.h"
#include "InputFiles.h"
#include "base/Vector3D.h"
#include "Gap.h"
#include "FEB.h"
#include "RPC.h"
#include "Hodoscope.h"
#include "OfflineAnalysis.h"
#include "Statistics.h"

using namespace Tracking;
int main(){

  InputFiles f;
  std::cout << f.GetDaqInfoFileName() << std::endl;
  std::cout << f.GetMappingFileName() << std::endl;

//  InputFiles g("raman", "sehgal", "ayush", "shachi","Gungun","abc.root");
//  std::cout << g.GetDaqInfoFileName() << std::endl;
//  std::cout << g.GetMappingFileName() << std::endl;


  Vector3D<double> t(4.,5.,6.);
  Vector3D<double> u(1.,1.,1.);
  t.Print();
  (t+u).Print();
  (t-u).Print();
  (t*2).Print();
  (t/2).Print();
  (t+2).Print();
  (t-2).Print();

  (t+=2);
  t.Print();
  (t-=1);
  t.Print();
  std::cout<<"-----------------------------"<<std::endl;
  std::cout<<t.Dot(u)<<std::endl;
  std::cout<<"---- Testing Gap Class -----"<<std::endl;
  Gap testGap;
  std::cout<<testGap<<std::endl;
  //testGap.Set("top", 10., 8000.);
  std::cout<<testGap<<std::endl;
  std::cout<<"---- Testing FEB class ---- "<<std::endl;
  FEB feb;
  std::cout<<"Num of Chips : "<<feb.CalculateNumOfChips()<<std::endl;
  std::cout<<" ----- FEB ----- "<<std::endl<<feb<<std::endl;

  std::cout<<"---- Testing RPC class -----"<<std::endl;
  RPC rpc;
  rpc.Print();

  std::cout<<"---- Testing Hodoscope ----"<<std::endl;
  Hodoscope hodo;
  hodo.Print();
  Hodoscope hodo2(10);
  hodo2.Print();

  std::cout<<std::endl;
  std::cout<<"---- starting stuff of reading different file ----"<<std::endl;
  OfflineAnalysis offAnal("6133.root");
  std::cout<<"Rpc Vector Size : "<<offAnal.fRpcVector.size()<<std::endl;

  std::cout<<" ----- Scintillator Plane Creation -----"<<std::endl;
  for(int i=0 ; i<offAnal.fScintPlaneVector.size() ; i++){
    offAnal.fScintPlaneVector[i]->Print();
  }
  //std::cout<<"Detector Name test : "<<offAnal.fRpcVector[1].GetName()<<std::endl; //Working

  //std::cout<<"---- Printing RPC's Info ----"<<std::endl;
  //for(int i=0;i<offAnal.fRpcVector.size();i++)
  //  offAnal.fRpcVector[i].Print();

  //Checking string generation
  //Statistics stat;
  //stat.GenerateAllTitleStrings();


  return 0;
}



