/*
 * Hodoscope.h
 *
 *  Created on: Mar 24, 2016
 *      Author: rsehgal
 */

#include "Scintillator.h"
#include "RPC.h"
#include "base/Global.h"

#ifndef INC_HODOSCOPE_H_
#define INC_HODOSCOPE_H_

namespace Tracking{
class Hodoscope{
private:
    int fNumOfScintillatorPlane;
    int fNumOfRpc;
    std::vector<ScintillatorPlane*> fScintPlaneVector;
    std::vector<RPC*> fRpcVector;
public:
    Hodoscope();
    Hodoscope(int numOfScintillatorPlane, int numOfRpc);
    ~Hodoscope();
    //Hodoscope(int numOfHodoScope);

}; // end of Hodoscope Class
}//end of Tracking namespace

#endif /* INC_HODOSCOPE_H_ */

