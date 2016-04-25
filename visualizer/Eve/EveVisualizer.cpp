/*
 * EveVisualizer.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: rsehgal
 */

#include "TApplication.h"
#include "TEveElement.h"
#include "TEveGeoShape.h"
#include "TEveManager.h"
#include "TGeoBBox.h"
#include "TGeoMatrix.h"
#include "Eve/EveVisualizer.h"


namespace Tracking {

EveVisualizer::EveVisualizer(){
  fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  fEveGeomList = new TEveElementList("Geometry");
}

void EveVisualizer::AddEveShape(std::string shapeName,TGeoBBox *shape, TGeoHMatrix &mat){

  fEveShape = new TEveGeoShape(shapeName.c_str());
  fEveShape->SetShape(shape);
  fEveShape->SetMainColor(kGreen);
  fEveShape->SetMainTransparency(50);
  fEveShape->SetTransMatrix(mat);
  fEveGeomList->AddElement(fEveShape);
  
}

void EveVisualizer::ShowEve(){
  // TEveManager::Create();
  gEve->AddGlobalElement(fEveGeomList);
  gEve->DoRedraw3D();
  fApp->Run();
}

}//end of Tracking namespace
