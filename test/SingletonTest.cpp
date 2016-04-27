/*
 * SingletonTest.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: rsehgal
 */

#include <iostream>
#include "Singleton.h"
#include <TEveGeoShape.h>
#include <TApplication.h>
#include <TEveManager.h>
#include <TGeoTube.h>

int main(){

  Singleton::instance()->set_value(1);
  std::cout << "foo: global_ptr is " << Singleton::instance()->get_value() << '\n';
  Singleton::instance()->set_value(5);
  std::cout << "foo: global_ptr is " << Singleton::instance()->get_value() << '\n';

  TApplication *fApp = new TApplication("VecGeom Visualizer", NULL, NULL);
  TEveManager::Create();
  TEveGeoShape *b = new TEveGeoShape("Barell 1");
  b->SetShape(new TGeoTube(10, 15, 20));
  b->SetMainColor(kRed);
  b->SetMainTransparency(60);
  Singleton::instance()->AddElement(b);

  b = new TEveGeoShape("Barell 2");
  b->SetShape(new TGeoTube(5, 6, 20));
  b->SetMainColor(kGreen);
  b->SetMainTransparency(50);
  Singleton::instance()->AddElement(b);

  gEve->AddGlobalElement(Singleton::instance()->GetList());
  gEve->Redraw3D(kTRUE);
  fApp->Run();
}


