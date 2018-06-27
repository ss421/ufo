/*
 * (C) Copyright 2018 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef UFO_LINEAROBSOPERATOR_H_
#define UFO_LINEAROBSOPERATOR_H_

#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>

#include "oops/util/Printable.h"

// Forward declarations
namespace eckit {
  class Configuration;
}

namespace oops {
  class Variables;
}

namespace ioda {
  class ObsSpace;
  class ObsVector;
}

namespace ufo {
  class GeoVaLs;
  class ObsBias;
  class ObsBiasIncrement;
  class LinearObsOperatorBase;

// -----------------------------------------------------------------------------

class LinearObsOperator : public util::Printable,
                          private boost::noncopyable {
 public:
  LinearObsOperator(const ioda::ObsSpace &, const eckit::Configuration &);
  ~LinearObsOperator();

/// Obs Operator
  void setTrajectory(const GeoVaLs &, const ObsBias &);
  void simulateObsTL(const GeoVaLs &, ioda::ObsVector &, const ObsBiasIncrement &) const;
  void simulateObsAD(GeoVaLs &, const ioda::ObsVector &, ObsBiasIncrement &) const;

/// Operator input required from Model
  const oops::Variables & variables() const;

 private:
  void print(std::ostream &) const;
  boost::scoped_ptr<LinearObsOperatorBase> oper_;
};

// -----------------------------------------------------------------------------

}  // namespace ufo

#endif  // UFO_LINEAROBSOPERATOR_H_
