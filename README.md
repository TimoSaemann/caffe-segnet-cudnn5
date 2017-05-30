# Caffe SegNet cuDNN5
**This is a modified version of [Caffe](https://github.com/BVLC/caffe) which supports the [SegNet architecture](http://mi.eng.cam.ac.uk/projects/segnet/)**

As described in **SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation** Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla [http://arxiv.org/abs/1511.00561]

Please refer to Alex Kendalls caffe-segnet for tutorial and a guide how to use it (https://github.com/alexgkendall/caffe-segnet).

Since the original caffe-segnet supports just cuDNN v2, which is not supported for new pascal based GPUs, it was possible to decrease the inference time by 25 % to 35 % with caffe-segnet-cudnn5 using Titan X Pascal.

I recommend to use my trained weights (CityScapes Model) for semantic segmenation of traffic scenes, which you can find in segnet model zoo: https://github.com/alexgkendall/SegNet-Tutorial/blob/master/Example_Models/segnet_model_zoo.md

If you like to speed up SegNet even further, you can run the BN-absorber.py script. It merges the batch normalization layer into convolutional layer by modyfing its weights and biases. In doing so, it is possible to accelerate it by around 30 %. Please find BN-absorber.py in the script folder.

If you like to use SegNet with C++, the test_segmentation.cpp might be helpful. 
https://github.com/alexgkendall/SegNet-Tutorial/blob/master/Scripts/test_segmentation.cpp

## News

* If SegNet is too slow for you, try out the [ENet](https://github.com/TimoSaemann/ENet) in Caffe. It's much faster! (May the 30th, 2017)

* Speed up SegNet by merging batch normalization and convolutional layer with BN-absorber.py in the script folder. (May the 12th, 2017)

* cuDNN v.6 has been released. I have tested it using Titan X Pascal. It doesn't bring any noticeable improvements for SegNet. For that reason I will not update the repository to cuDNN6.

## Publications

If you use this software in your research, please cite their publications:

http://arxiv.org/abs/1511.02680
Alex Kendall, Vijay Badrinarayanan and Roberto Cipolla "Bayesian SegNet: Model Uncertainty in Deep Convolutional Encoder-Decoder Architectures for Scene Understanding." arXiv preprint arXiv:1511.02680, 2015.

http://arxiv.org/abs/1511.00561
Vijay Badrinarayanan, Alex Kendall and Roberto Cipolla "SegNet: A Deep Convolutional Encoder-Decoder Architecture for Image Segmentation." arXiv preprint arXiv:1511.00561, 2015. 


## License

This extension to the Caffe library is released under a creative commons license which allows for personal and research use only. For a commercial license please contact the authors. You can view a license summary here:
http://creativecommons.org/licenses/by-nc/4.0/
