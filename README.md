# Caffe SegNet cuDNN7
**This is a modified version of [Caffe](https://github.com/BVLC/caffe) which supports the [SegNet architecture](http://mi.eng.cam.ac.uk/projects/segnet/)**.

As described in **SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation** Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla [http://arxiv.org/abs/1511.00561]

Please refer to Alex Kendall's caffe-segnet for tutorial and a guide how to use it (https://github.com/alexgkendall/caffe-segnet).

Since the original caffe-segnet supports just cuDNN v2, which is not supported for new pascal based GPUs, [Timo Sämann](https://github.com/TimoSaemann) was able to decrease the inference time by 25 % to 35 % with [caffe-segnet-cudnn5](https://github.com/TimoSaemann/caffe-segnet-cudnn5) using Titan X Pascal. This repository contains the changes required to run using cudNN7, however no calculation of speedup was performed.

It is recommended to use Timo Sämann's weights (trained on CityScapes) for semantic segmenation of traffic scenes, which you can find in the [SegNet Model Zoo](https://github.com/alexgkendall/SegNet-Tutorial/blob/master/Example_Models/segnet_model_zoo.md).

If you like to speed up SegNet even further, you can run the BN-absorber.py script. It merges the batch normalization layer into the convolutional layer by modifying its weights and biases. In doing so, it is possible to accelerate it by around 30 %. Please find BN-absorber.py in the script folder.

If you like to use SegNet with C++, the test_segmentation.cpp might be helpful.
https://github.com/navganti/SegNet/blob/master/scripts/example/test_segmentation.cpp

## Installation

### CMake

__This method is recommended if you wish to use Caffe with C++!__.

To install Caffe using the community-created CMake file, perform the following:

__Note: This will install Caffe to `/usr/local`.__ If you wish to install it elsewhere, set the `CMAKE_INSTALL_PREFIX`.

```bash
mkdir cmake_build
cd cmake_build
cmake ..
make
make runtest
sudo make install
```

The CMake file currently does not build the Python layer, but this can be modified inside the CMakeLists file. I have not tested this, personally. 

To use `caffe-segnet-cudnn7` in a CMake project, you can now add the following lines to your project's `CMakeLists.txt`:

```cmake
project(foo)

find_package(Caffe REQUIRED)
include_directories(${Caffe_INCLUDE_DIRS})

add_executable(foo main.cpp)
target_link_libraries(foo ${Caffe_LIBRARIES})
```

### Makefile

__This method is recommended if you wish to use Caffe with Python!__ Make sure to add the `caffe-segnet-cudnn7/python` folder to your `PYTHONPATH`.

To install, follow the instructions located [here](https://github.com/BVLC/caffe/wiki/Ubuntu-16.04-Installation-Guide).

A lot of the necessary changes to the Makefile have already been made here. The above guide does, however, provide a good reference for installation dependencies and build steps. 

Some tips for modifying the Makefile:
    - If you are using ROS and OpenCV, the location of the OpenCV (as of Ubuntu 16.04 and ROS Kinetic `/opt/ros/kinetic/include/opencv-3.3.1-dev` and `/opt/ros/kinetic/include`) needs to be appended to `INCLUDE_DIRS` and `LIBRARY_DIRS`

## News

* If SegNet is too slow for you, try out the [ENet](https://github.com/TimoSaemann/ENet) in Caffe. It's much faster! (May 30th, 2017)

* Speed up SegNet by merging batch normalization and convolutional layer with BN-absorber.py in the script folder. (May 12th, 2017)

* cuDNN v.6 has been released. I have tested it using Titan X Pascal. It doesn't bring any noticeable improvements for SegNet. For that reason will not update the repository to cuDNN6.

## Publications

If you use this software in your research, please cite their publications:

http://arxiv.org/abs/1511.02680
Alex Kendall, Vijay Badrinarayanan and Roberto Cipolla "Bayesian SegNet: Model Uncertainty in Deep Convolutional Encoder-Decoder Architectures for Scene Understanding." arXiv preprint arXiv:1511.02680, 2015.

http://arxiv.org/abs/1511.00561
Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla "SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation." arXiv preprint arXiv:1511.00561, 2015.

## License

This extension to the Caffe library is released under a creative commons license which allows for personal and research use only. For a commercial license please contact the authors. You can view a license summary here:
http://creativecommons.org/licenses/by-nc/4.0/
