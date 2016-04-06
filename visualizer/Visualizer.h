/*
 * Visualizer.h
 *
 *  Created on: Apr 6, 2016
 *      Author: rsehgal
 */

#ifndef INC_VISUALIZER_H_
#define INC_VISUALIZER_H_
#include <list>
#include <memory>
#include <utility>

class TApplication;
class TGeoManager;
class TGeoMatrix;
class TGeoTranslation;
class TGeoShape;
class TGeoVolume;
class TPolyLine3D;

#include "TPolyMarker3D.h"
#include "base/Global.h"
#include "base/Vector3D.h"

namespace Tracking {

class Visualizer {
private:
  TApplication *fApp;       // ROOT application used for visualization
  TGeoManager *fGeoManager; // ROOT geometry manager
  std::vector<std::tuple<TGeoVolume*, TGeoTranslation*> > fVolumes;


public:
  Visualizer();
  virtual ~Visualizer();
  void Show();
  void Show(TGeoVolume *);
  void AddVolume();
  void AddPoint();
  void AddLine();
  void AddVolume( TGeoVolume rootVolume);
  void AddVolume( TGeoVolume *rootVolume, Vector3D<Precision> p);
};

} //end of Tracking namespace

#endif /* INC_VISUALIZER_H_ */
