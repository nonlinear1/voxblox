#ifndef VOXBLOX_CORE_OCCUPANCY_MAP_H_
#define VOXBLOX_CORE_OCCUPANCY_MAP_H_

#include <glog/logging.h>
#include <memory>
#include <utility>

#include "voxblox/core/common.h"
#include "voxblox/core/layer.h"
#include "voxblox/core/voxel.h"

namespace voxblox {

class OccupancyMap {
 public:
  typedef std::shared_ptr<OccupancyMap> Ptr;

  struct Config {
    float occupancy_voxel_size = 0.2;
    float occupancy_voxels_per_side = 16;
  };

  explicit OccupancyMap(Config config)
      : occupancy_layer_(new Layer<OccupancyVoxel>(
            config.occupancy_voxel_size, config.occupancy_voxels_per_side)) {
    block_size_ =
        config.occupancy_voxel_size * config.occupancy_voxels_per_side;
  }

  virtual ~OccupancyMap() {}

  Layer<OccupancyVoxel>* getOccupancyLayerPtr() {
    return occupancy_layer_.get();
  }
  const Layer<OccupancyVoxel>& getOccupancyLayerPtr() const {
    return *occupancy_layer_;
  }

  FloatingPoint block_size() const { return block_size_; }

 protected:
  FloatingPoint block_size_;

  // The layers.
  Layer<OccupancyVoxel>::Ptr occupancy_layer_;
};

}  // namespace voxblox

#endif  // VOXBLOX_CORE_OCCUPANCY_MAP_H_
