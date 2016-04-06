#include <TGeoVolume.h>
#include <TGeoMatrix.h>
#include <TGeoSphere.h>
#include <TApplication.h>
#include <TGeoManager.h>
#include <TGeoShape.h>
#include <TView.h>
#include <TGeoMaterial.h>


#define kInfinity 100
#include "Visualizer.h"

int main(){


/*
	TApplication *fApp = new TApplication("Tracking Visualizer", NULL, NULL);
	TGeoManager *fGeoManager = new TGeoManager("Simple", "Simple Geometry");
	TGeoVolume *top = fGeoManager->MakeBox("Top", NULL,kInfinity, kInfinity, kInfinity);
	fGeoManager->SetTopVolume(top);
	//TGeoVolume *vol = fGeoManager->MakeSphere("SPHERE",NULL, 30,40,0,180,0,360);

	  TGeoShape *sphere = new TGeoSphere("SPHERE",30,40,0,180,0,360);
	  TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
	  TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);
	  TGeoVolume *sphVol = new TGeoVolume("SPHERE", sphere, Vacuum);


	top->AddNode(sphVol,1);
	fGeoManager->CloseGeometry();
	top->Draw();
	fApp->Run();
*/

  Tracking::Visualizer v;
  TGeoShape *sphere = new TGeoSphere("SPHERE",30,40,0,180,0,300);
  TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
  TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);
  TGeoVolume *sphVol = new TGeoVolume("SPHERE", sphere, Vacuum);
  v.Show(sphVol);




}
