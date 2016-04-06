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
#include "TGeoShape.h"
#include "TPolyLine3D.h"
#include "TPolyMarker3D.h"
#include "TVirtualPad.h"
#include "TView.h"

#include <iostream>

#include "Visualizer.h"

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
  TGeoVolume *vol = fGeoManager->MakeSphere("SPHERE", NULL, 30, 40, 0, 180, 0, 360);
  top->AddNode(vol, 1);
  fGeoManager->CloseGeometry();
  top->Draw();
  fApp->Run();
}

} //end of Tracking namespace
