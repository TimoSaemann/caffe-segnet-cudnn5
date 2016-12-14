#ifndef CAFFE_BN_LAYER_HPP_
#define CAFFE_BN_LAYER_HPP_

#include <algorithm>
#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/common.hpp"
#include "caffe/syncedmem.hpp"
#include "caffe/util/math_functions.hpp"
#include "caffe/filler.hpp"

/**
* @brief Batch Normalization per-channel with scale & shift linear transform.
*
*/
namespace caffe {

template <typename Dtype>
class BNLayer : public Layer<Dtype> {
 public:
  explicit BNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int MinTopBlobs() const { return 1; }
  // if the BNMode is "LEARN" mamximum 3 top blobs are available
  virtual inline int MaxTopBlobs() const {
    return (this->layer_param_.bn_param().bn_mode() ==
            BNParameter_BNMode_LEARN) ? 3 : 1;
  }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  // spatial mean & variance
  Blob<Dtype> spatial_mean_, spatial_variance_;
  // batch mean & variance
  Blob<Dtype> batch_mean_, batch_variance_;
  // buffer blob
  Blob<Dtype> buffer_blob_;

  Blob<Dtype> x_norm_;
  // x_sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> spatial_sum_multiplier_, batch_sum_multiplier_;

  // dimension
  int N_;
  int C_;
  int H_;
  int W_;
  // eps
  Dtype var_eps_;
};

}  // namespace caffe

#endif  
