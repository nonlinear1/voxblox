#ifndef SPHERESIMULATOR_H_
#define SPHERESIMULATOR_H_

#include "voxblox/core/common.h"

namespace htwfsc_benchmarks {
namespace sphere_sim {

void createSphere(const double mean, const double variance,
                  const double radius_m, const size_t num_points,
                  voxblox::Pointcloud* points_3D);

}  // namespace sphere_sim
}  // namespace htwfsc_benchmarks

#endif
