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


#define kInfinity 100
#include "Visualizer.h"

int main(){

  Tracking::Visualizer v;

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
  v.AddVolume(sphVol2,Tracking::Vector3D<Precision>(0.,0.,0.));
  v.AddVolume(sphVol,Tracking::Vector3D<Precision>(100.,0.,0.));


  //Adding a Shape without creating TGeoVolume, hence no need to worry about
  //Material and Medium
  v.AddVolume(new TGeoBBox("BOX", 20., 30., 40.),Tracking::Vector3D<Precision>(0.,100.,0.));


  //v.Show(sphVol);
  //Show method to display the volumes
  v.Show();




}
