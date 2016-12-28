# Caffe SegNet cuDNN5
**This is a modified version of [Caffe](https://github.com/BVLC/caffe) which supports the [SegNet architecture](http://mi.eng.cam.ac.uk/projects/segnet/)**

As described in **SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation** Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla [http://arxiv.org/abs/1511.00561]

Please refer to Alex Kendalls caffe-segnet for tutorial and a guide how to use it (https://github.com/alexgkendall/caffe-segnet).

Since the original caffe-segnet supports just cuDNN v2, which is not supported for new pascal based GPUs, it was possible to decrease the inference time by 25 % to 35 % with caffe-segnet-cudnn5 using Titan X Pascal.

I recommend to use my trained weights (CityScapes Model) for semantic segmenation of traffic scenes, which you can find in segnet model zoo: https://github.com/alexgkendall/SegNet-Tutorial/blob/master/Example_Models/segnet_model_zoo.md

## Publications

If you use this software in your research, please cite their publications:

http://arxiv.org/abs/1511.02680
Alex Kendall, Vijay Badrinarayanan and Roberto Cipolla "Bayesian SegNet: Model Uncertainty in Deep Convolutional Encoder-Decoder Architectures for Scene Understanding." arXiv preprint arXiv:1511.02680, 2015.

http://arxiv.org/abs/1511.00561
Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla "SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation." arXiv preprint arXiv:1511.00561, 2015. 


## License

This extension to the Caffe library is released under a creative commons license which allows for personal and research use only. For a commercial license please contact the authors. You can view a license summary here:
http://creativecommons.org/licenses/by-nc/4.0/
