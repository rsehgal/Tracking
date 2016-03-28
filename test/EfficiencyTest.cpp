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

typedef std::vector<ScintillatorPlane*> scintPlaneVector;
typedef std::vector<RPC*> rpcVector;

 int main(){
  Tree t("6147.root","BSC_DATA_TREE");

  Hodoscope h("TestHodoScope", 2 , 2);
  scintPlaneVector sPV = h.GetScintPlaneVector();
  rpcVector rV = h.GetRpcVector();
  int numOfEvents = t.GetNumOfEvents();
  int numOfGenuineEvents = 0 ;
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
            rV[j]->EventDetected(t,evNo);
            // if(rV[j]->GetRpc()->IsShowerEvent<true>(t,evNo))
            //     std::cout<<"DETECTED BY RPC....."<<std::endl;
            // rV[j]->PrintStrips();
        }
    }
  }

  for(int j = 0 ; j < rV.size() ; j++){
    std::cout<<"Total Event count for detector : "<< j+1 <<" : "<< rV[j]->GetEventCount() << std::endl
             <<"Total Num of Genuine Events : "<< numOfGenuineEvents << std::endl
             << "Efficiency : "<< rV[j]->GetEfficiency(numOfGenuineEvents) << " %" <<std::endl;
  }

 }
