#pragma once
#include "SparseGrid.h"
#include "types.h"
#include "Rng.h"
#include <armadillo>
#include <string>
#include <vector>

class OffSurfaceModelPicture {
private:
  arma::mat points;
  std::vector<std::vector<int>>
      surfaces; // Will assume all surfaces are triangles for now
public:
  int renderSize;
  int label;
  bool is_loaded;
  std::string picture_path;
  OffSurfaceModelPicture(std::string filename, int renderSize, int label_ = -1);
  ~OffSurfaceModelPicture();
  void loadPicture();
  void normalize(); // Fit centrally in the cube [-scale_n/2,scale_n/2]^3
  void random_rotation(RNG &rng);
  std::string identify();
  void jiggle(RNG &rng, float alpha);
  void affineTransform(RNG &rng, float alpha);
  void codifyInputData(SparseGrid &grid, std::vector<float> &features,
                       int &nSpatialSites, int spatialSize);
  OffSurfaceModelPicture *distort(RNG &rng, batchType type = TRAINBATCH);
};
