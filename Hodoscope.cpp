/*
 * Hodoscope.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: rsehgal
 */
#include "Hodoscope.h"
namespace Tracking{

void Hodoscope::AddChamber(std::string chamber_tn,std::string chamber_tw,std::string chamber_b,
						   Precision curr1, Precision curr2, Precision curr3,
						   Precision vset1, Precision vset2, Precision vset3,
						   Precision vmon1, Precision vmon2, Precision vmon3,
						   int station,
						   Precision feb1, Precision feb2, Precision feb3, Precision feb4,
						   Precision feb5, Precision feb6, Precision feb7, Precision feb8,
						   Precision feb9, Precision feb10, Precision feb11, Precision feb12){

	RPC newRpc;
	newRpc.SetGap(0,chamber_tn,curr1,vset1,vmon1,station);
	newRpc.SetGap(1,chamber_tw,curr2,vset2,vmon2,station);
	newRpc.SetGap(2,chamber_b,curr3,vset3,vmon3,station);
	newRpc.SetFeb(0,feb1,feb2,feb3,feb4);
	newRpc.SetFeb(1,feb5,feb6,feb7,feb8);
	newRpc.SetFeb(2,feb9,feb10,feb11,feb12);

	rpc.push_back(&newRpc);
}

void Hodoscope::AddChamber(std::string chamber_tn,std::string chamber_tw,std::string chamber_b,
						   Precision curr1, Precision curr2, Precision curr3,
						   Precision vset1, Precision vset2, Precision vset3,
						   Precision vmon1, Precision vmon2, Precision vmon3,
						   int station){

	RPC newRpc;
	newRpc.SetGap(0,chamber_tn,curr1,vset1,vmon1,station);
	newRpc.SetGap(1,chamber_tw,curr2,vset2,vmon2,station);
	newRpc.SetGap(2,chamber_b,curr3,vset3,vmon3,station);


	rpc.push_back(&newRpc);
}

}//end of Tracking namespace



