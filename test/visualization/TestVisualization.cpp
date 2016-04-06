#include <TGeoVolume.h>
#include <TGeoMatrix.h>
#include <TGeoSphere.h>
#include <TApplication.h>
#include <TGeoManager.h>
#include <TGeoShape.h>
#include <TView.h>

#define kInfinity 100

int main(){
	TApplication *fApp = new TApplication("Tracking Visualizer", NULL, NULL);
	TGeoManager *fGeoManager = new TGeoManager("Simple", "Simple Geometry");
	TGeoVolume *top = fGeoManager->MakeBox("Top", NULL,kInfinity, kInfinity, kInfinity);
	fGeoManager->SetTopVolume(top);
	TGeoVolume *vol = fGeoManager->MakeSphere("SPHERE",NULL, 30,40,0,180,0,360);
	top->AddNode(vol,1);
	fGeoManager->CloseGeometry();
	top->Draw();
	fApp->Run();


}
