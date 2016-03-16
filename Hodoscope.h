/*
 * Hodoscope.h
 *
 *  Created on: Mar 9, 2016
 *      Author: rsehgal
 */

#ifndef INC_HODOSCOPE_H_
#define INC_HODOSCOPE_H_

#include "RPC.h"
#include <vector>
#include <algorithm>
#include "Scintillator.h"
#include <string>

namespace Tracking{

class Hodoscope{
private:
	int numOfRpcs;
	std::vector<RPC*> rpc;
	//std::vector<Scintillator> topPlane;
	//std::vector<Scintillator> bottomPlane;

public:
	Hodoscope():numOfRpcs(0){Initialize();} //Empty hodoscope
	Hodoscope(int num): numOfRpcs(num){Initialize();}
	~Hodoscope(){}
	TRACKING_INLINE
	void SetNumOfRpcs(int num){numOfRpcs=num;}
	TRACKING_INLINE
	int GetNumOfRpcs(){return numOfRpcs;}
	void Initialize(){
		for(int i=0;i<numOfRpcs;i++)
			rpc.push_back(new RPC());
	}
	void AddChamber(std::string chamber_tn,std::string chamber_tw,std::string chamber_b,
			   Precision curr1, Precision curr2, Precision curr3,
			   Precision vset1, Precision vset2, Precision vset3,
			   Precision vmon1, Precision vmon2, Precision vmon3,
			   int station,
			   Precision feb1, Precision feb2, Precision feb3, Precision feb4,
			   Precision feb5, Precision feb6, Precision feb7, Precision feb8,
			   Precision feb9, Precision feb10, Precision feb11, Precision feb12);

	void AddChamber(std::string chamber_tn,std::string chamber_tw,std::string chamber_b,
							   Precision curr1, Precision curr2, Precision curr3,
							   Precision vset1, Precision vset2, Precision vset3,
							   Precision vmon1, Precision vmon2, Precision vmon3,
							   int station);

	TRACKING_INLINE
	RPC GetChamber(int i){return *rpc[i];}

	void Print(){
		std::cout<<"Number of Rpcs : "<<rpc.size()<<std::endl;
	}

};

}// end of Tracking namespace



#endif /* INC_HODOSCOPE_H_ */
