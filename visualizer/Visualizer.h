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
class TGeoShape;
class TGeoVolume;
class TPolyLine3D;
#include "TPolyMarker3D.h"

namespace Tracking {

class Visualizer {
private:
  TApplication *fApp;      // ROOT application used for visualization
  TGeoManager *fGeoManager; // ROOT geometry manager


public:
  Visualizer();
  virtual ~Visualizer();
  void Show();
  void AddVolume();
  void AddPoint();
  void AddLine();
};

} //end of Tracking namespace

#endif /* INC_VISUALIZER_H_ */
