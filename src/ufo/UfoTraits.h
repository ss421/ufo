/*
 * (C) Copyright 2017 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_UFOTRAITS_H_
#define UFO_UFOTRAITS_H_

#include <string>


#include "GeoVaLs.h"
#include "Locations.h"
#include "ObsSpace.h"
#include "ObsVector.h"
#include "Variables.h"

namespace ufo {

struct UfoTraits {
  static std::string name() {return "UFO";}

  typedef ufo::GeoVaLs             GeoVaLs;
  typedef ufo::Locations           Locations;
  typedef ufo::ObsSpace            ObsSpace;
  typedef ufo::ObsVector           ObsVector;
  typedef ufo::Variables           Variables;
};

}  // namespace ufo

#endif  // UFO_UFOTRAITS_H_