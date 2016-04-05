/*
 * EfficiencyTest.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: rsehgal
 */
#include "Tree.h"
#include "Scintillator.h"
#include "RPC.h"
#include "base/Global.h"
#include "Hodoscope.h"
#include <string>
#include <vector>
#include <algorithm>
#include <TH1F.h>

typedef std::vector<ScintillatorPlane*> scintPlaneVector;
typedef std::vector<RPC*> rpcVector;

 int main(){
  Tree t("3577.root","BSC_DATA_TREE");

  TH1F *clusterSize = new TH1F("clusterSize","ClusterSize",20, 1 ,20);

  Hodoscope h("TestHodoScope", 2 , 3);
  scintPlaneVector sPV = h.GetScintPlaneVector();
  rpcVector rV = h.GetRpcVector();
  int numOfEvents = t.GetNumOfEvents();
  int numOfGenuineEvents = 0 ;
  //numOfEvents = 20;
  for(int evNo = 0 ; evNo < numOfEvents ; evNo++){
  //for(int evNo = 0 ; evNo < 10 ; evNo++){

    bool isShowerEvent = false;
    for(int j = 0 ; j < sPV.size() ; j++){
        isShowerEvent |= sPV[j]->IsShowerEvent<false>(t,evNo);
    }
    if(isShowerEvent){
        //rejecting shower events
        continue;
    }
    else{
        numOfGenuineEvents++;
        //Do the stuff for calculation of Efficiency
        //std::cout<<"Processing Genuine Events....."<<std::endl;
        for(int j = 0 ; j < rV.size() ; j++){
        //for(int j = 1 ; j < 2 ; j++){
            rV[j]->EventDetected(t,evNo);
            //if(j==2 )
            //rV[j]->GetHitMap();
#define CLUSTER_SIZE
#ifdef CLUSTER_SIZE
            if(j==2 )
            clusterSize->Fill(rV[j]->GetHitCount());
#endif

           // std::cout<<std::endl<<std::endl;
        }
    }
  }

  clusterSize->Draw();
  clusterSize->Print();
  TFile::Open("ClusterSize.root", "RECREATE");
  clusterSize->Write();

  for(int j = 0 ; j < rV.size() ; j++){
    std::cout<<"Total Event count for detector : "<< j+1 <<" : "<< rV[j]->GetEventCount() << std::endl
             <<"Total Num of Genuine Events : "<< numOfGenuineEvents << std::endl
             << "Efficiency : "<< rV[j]->GetEfficiency(numOfGenuineEvents) << " %" <<std::endl;
  }

 }
