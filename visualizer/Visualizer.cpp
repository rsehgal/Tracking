/*
 * Visualizer.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: rsehgal
 */

#include "TApplication.h"
#include "TAxis3D.h"
#include "TGeoManager.h"
#include "TGeoMatrix.h"
//#include "TGeoTranslation.h"
#include "TGeoShape.h"
#include "TPolyLine3D.h"
#include "TPolyMarker3D.h"
#include "TVirtualPad.h"
#include "TView.h"

#include <iostream>
#include <TGeoVolume.h>
#include "Visualizer.h"
#include "base/Vector3D.h"

#define kInfinity 100

namespace Tracking {
Visualizer::Visualizer():fGeoManager(0) {
  // TODO Auto-generated constructor stub
  fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
}

Visualizer::~Visualizer() {
  // TODO Auto-generated destructor stub
  delete fApp;
}

void Visualizer::Show(){
  fGeoManager = new TGeoManager("Simple", "Simple Geometry");
  TGeoVolume *top = fGeoManager->MakeBox("Top", NULL, kInfinity, kInfinity, kInfinity);
  fGeoManager->SetTopVolume(top);

  //The volumes should be Added by AddVolume function into a container.
  //Once the container is ready , we should iterate over it and keep on
  //adding the node to the top Volume
  TGeoVolume *vol = fGeoManager->MakeSphere("SPHERE", NULL, 30, 40, 0, 180, 0, 360);
  top->AddNode(vol, 1);
  fGeoManager->CloseGeometry();
  top->Draw();
  fApp->Run();
}

void Visualizer::Show(TGeoVolume *vol){
  TGeoVolume *top = gGeoManager->MakeBox("Top", NULL, kInfinity, kInfinity, kInfinity);
  gGeoManager->SetTopVolume(top);

  //The volumes should be Added by AddVolume function into a container.
  //Once the container is ready , we should iterate over it and keep on
  //adding the node to the top Volume
  //TGeoVolume *vol = fGeoManager->MakeSphere("SPHERE", NULL, 30, 40, 0, 180, 0, 360);
  top->AddNode(vol, 1);
  gGeoManager->CloseGeometry();
  top->Draw();
  fApp->Run();
}

void Visualizer::AddVolume( TGeoVolume rootVolume) {
  /*fVolumes.push_back(std::make_tuple(
      volume,
      std::unique_ptr<TGeoMatrix>(new TGeoIdentity),
      std::unique_ptr<TGeoVolume>(new TGeoVolume("", volume.get(), nullptr))));
*//*
  if (fVerbosity > 0) {
    std::cout << "Added ROOT volume to Visualizer.\n";
  }
*/
}

void Visualizer::AddVolume( TGeoVolume rootVolume, Vector3D<Precision>  &p) {
  //p is the translation vector in x, y and z.
  //For the time being considering ONLY translation, NO rotation.
 /* fVolumes.push_back(std::make_tuple(
      rootVolume,
      new TGeoTranslation(p.x(), p.y(), p.z())) ) ;
*/
}

} //end of Tracking namespace
