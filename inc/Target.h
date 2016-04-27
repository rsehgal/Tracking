/*
 * Target.h
 *
 *  Created on: Apr 27, 2016
 *      Author: rsehgal
 */

#ifndef INC_TARGET_H_
#define INC_TARGET_H_

#include <iostream>
#include "Singleton.h"
#include <TEveGeoShape.h>
#include <TGeoBBox.h>

namespace Tracking{
 class Target{

 public:

   Target(){
     TEveGeoShape *b = new TEveGeoShape("Target");
     b->SetShape(new TGeoBBox(10, 10, 10));
     b->SetMainColor(kRed);
     b->SetMainTransparency(60);
     Singleton::instance()->AddElement(b);
   }
 };


}//end of Tracking namespace



#endif /* INC_TARGET_H_ */
