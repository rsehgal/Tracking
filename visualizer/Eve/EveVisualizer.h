/*
 * EveVisualizer.h
 *
 *  Created on: Apr 24, 2016
 *      Author: rsehgal
 */

#ifndef VISUALIZER_EVE_EVEVISUALIZER_H_
#define VISUALIZER_EVE_EVEVISUALIZER_H_
#include <list>
#include <memory>
#include <utility>
class TEveElementList;
class TEveGeoShape;
class TApplication;
class TGeoBBox;
class TGeoMatrix;

namespace Tracking {

class EveVisualizer{
private:
  TApplication *fApp;
  TEveElementList *fEveGeomList;
  TEveGeoShape *fEveShape;

public:
  EveVisualizer();
  void AddEveShape(std::string shapeName,TGeoBBox *shape, TGeoHMatrix &mat);
  void ShowEve();  

};

} //end of Tracking namespace
#endif