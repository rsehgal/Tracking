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

#define kInfinity 10000

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

  std::cout<<"=============================================="<<std::endl;
  std::cout<<"========= Inside Expected SHOW() ============="<<std::endl;
  std::cout<<"=============================================="<<std::endl;

  TGeoVolume *top = gGeoManager->MakeBox("Top", NULL, kInfinity, kInfinity, kInfinity);
  gGeoManager->SetTopVolume(top);
  for(int i = 0 ; i < fVolumes.size() ; i++){
  top->AddNode(std::get<0>(fVolumes[i]), 1 , std::get<1>(fVolumes[i]));
  }
  gGeoManager->CloseGeometry();
  top->Draw();
  fApp->Run();
}

void Visualizer::Show(TGeoVolume *vol){
  TGeoVolume *top = gGeoManager->MakeBox("Top", NULL, kInfinity, kInfinity, kInfinity);
  gGeoManager->SetTopVolume(top);
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

void Visualizer::AddVolume( TGeoVolume *rootVolume, Vector3D<Precision> p) {

  fVolumes.push_back(std::make_tuple(
      rootVolume,
      new TGeoTranslation(p.x(), p.y(), p.z())) ) ;

}

} //end of Tracking namespace
