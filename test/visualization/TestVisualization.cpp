#include <TGeoVolume.h>
#include <TGeoMatrix.h>
#include <TGeoSphere.h>
#include <TApplication.h>
#include <TGeoManager.h>
#include <TGeoShape.h>
#include <TView.h>
#include <TGeoMaterial.h>
#include "base/Vector3D.h"
#include <TGeoBBox.h>
#include "Scintillator.h"
#include "RPC.h"
#include "TApplication.h"



#define kInfinity 100
#ifdef USE_EVE
#include "Eve/EveVisualizer.h"
#include "TEveManager.h"
typedef Tracking::EveVisualizer TrackingVisualizer;
#else
#include "Visualizer.h"
typedef Tracking::Visualizer TrackingVisualizer;
#endif

int main(){

  TrackingVisualizer v;
  TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);

  //Geometry creation
  TGeoShape *sphere = new TGeoSphere("SPHERE",30,40,0,180,0,300);
  TGeoShape *sphere2 = new TGeoSphere("SPHERE",30,40,0,180,0,360);

  //Material and Medium creation
  TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
  TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);

  //TGeoVolume creation
  TGeoVolume *sphVol = new TGeoVolume("SPHERE", sphere, Vacuum);
  TGeoVolume *sphVol2 = new TGeoVolume("SPHERE", sphere2, Vacuum);
  //Creation of TGeoVolume over

  //adding all the volumes to STL vector of tupple
  //v.AddVolume(sphVol2,Tracking::Vector3D<Precision>(0.,0.,0.));
  //v.AddVolume(sphVol,Tracking::Vector3D<Precision>(100.,0.,0.));


  //Adding a Shape without creating TGeoVolume, hence no need to worry about
  //Material and Medium
  TGeoBBox *box = new TGeoBBox("BOX", 1.5, 50., 0.5);
  for(int i = 0 ; i< 32 ; i++){
    //v.AddVolume(box,Tracking::Vector3D<Precision>(3*i,0.,0.));

/*
  v.AddVolume(box,Tracking::Vector3D<Precision>(3*i,0.,-100.));
  v.AddVolume(box,Tracking::Vector3D<Precision>(3*i,0.,-50.));
  v.AddVolume(box,Tracking::Vector3D<Precision>(3*i,0.,50.));
  v.AddVolume(box,Tracking::Vector3D<Precision>(3*i,0.,100.));
*/
  }


  //v.Show(sphVol);
  //Show method to display the volumes
  //ScintillatorPlane *sP = new ScintillatorPlane(1,32,"Test");

  RPC *sP = new RPC(2,32,"FirstRpc",-20.);
  RPC *rP = new RPC(3,32,"SecondRpc",20.);
  RPC *tP = new RPC(3,32,"SecondRpc",60.);

 #ifdef SHOW_VISUALIZATION
 #ifndef USE_EVE
   v.AddVolume(sP->GetPlaneTGeoVolume());
   v.AddVolume(rP->GetPlaneTGeoVolume());
   v.AddVolume(tP->GetPlaneTGeoVolume());
   v.Show();
   fApp->Run();
  #else

  //rP->Show();
   TEveManager::Create();
   sP->Show();
  #endif
 #endif




}
