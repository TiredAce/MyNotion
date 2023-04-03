## 第1章 邂逅OpenCV

> [1.5 快速上手OpenCV图像处理](#1.5)
>
> [1.6 OpenCV视频操作基础](#1.6)

<h3 id="1.5">1.5 快速上手OpenCV图像处理
</h3>

#### 1.5.1 第一个程序：图像显示

在`OpenCV`中，图像显示过程非常简单，只需用`imread`函数载入到新版本的图像存储数据结构`Mat`中，然后用`imshow`函数显示即可。

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat img = imread("F:\\master.jpg"); //载入图片
	imshow("[载入的图片]", img);        //显示图片 
	waitKey(6000);
}
```

效果图如下：

<img src="./../assets/blog_res/第1章 邂逅OpenCV.assets/1677845326530.png" alt="1677845326530" style="zoom:50%;" />

#### 1.5.2 第二个程序：图像腐蚀

`OpenCV`实现最基础的形态学运算之一——**腐蚀**，即用图像中的暗色部分腐蚀掉图像中的高亮部分。代码如下：

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat img = imread("F:\\master.jpg");    //载入图片
	imshow("[原图] 腐蚀操作", img);        //显示图片
    // 进行腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15)); 
	Mat dstImage;
	erode(img, dstImage, element);
	// 显示效果图
    imshow("[效果图] 腐蚀操作", dstImage);
	waitKey(0);
	return 0;
}
```

定义一个`Mat`类型的变量来获取`getStructuringElement`函数的返回值，该返回值表示指定形状和尺寸的结构元素（内核矩阵）。参数准备完毕，接着便可以调用`erode`函数进行图像腐蚀操作，最后调用`imshow`函数进行显示。

效果图如下：

<img src="./../assets/blog_res/第1章 邂逅OpenCV.assets/image-20230303200953796.png" alt="image-20230303200953796" style="zoom:50%;" />

#### 1.5.3 第三个程序：图像模糊

使用`OpenCV`对图像进行均值滤波操作，模糊一副图像的代码，主要使用进行均值滤波操作的`blur`函数：

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat img = imread("F:\\master.jpg");    //载入图片
	imshow("[原图] 图像模糊", img);        //显示图片
	// 进行图像模糊函数
	Mat dstImage;
	blur(img, dstImage, Size(7, 7));
	imshow("[效果图] 图像模糊", dstImage);
	waitKey(0);
	return 0;
}
```

载入原图后，调用一次`blur`函数，最后显示效果图。

<img src="./../assets/blog_res/第1章 邂逅OpenCV.assets/image-20230303201027426.png" alt="image-20230303201027426" style="zoom:50%;" />

#### 1.5.4 第四个程序：canny边缘检测

使用`OpenCV`进行`canny`边缘检测。载入图像，并将其转成灰度图，再用`blur`函数进行图像模糊以降噪，然后用`canny`函数进行边缘检测，最后进行显示。

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("F:\\master.jpg");    //载入图片
	imshow("[原图] 边缘检测", srcImage);        //显示图片
	// 定义参数
	Mat dstImage, edge, grayImage;
	// 创建与src同类型和大小的矩阵
	dstImage.create(srcImage.size(), srcImage.type());
	// 将原图转换为灰度图像
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	// 使用3x3内核降噪
	blur(grayImage, edge, Size(3, 3));
	// 运行Canny算子
	Canny(edge, edge, 3, 9, 3);
	imshow("[效果图] 边缘检测", edge);
	waitKey(0);
	return 0;
}
```

  效果图如下：

<img src="./../assets/blog_res/第1章 邂逅OpenCV.assets/image-20230303201827892.png" alt="image-20230303201827892" style="zoom:50%;" />

<h3 id="1.6">
1.6 OpenCV视频操作基础
</h3>

#### 1.6.1 读取并播放视频

通过对`VideoCapture`类的分析，可以发现利用它读入视频的方法一般有如下两种。比如读入的视频为"01.avi"的视频文件，那么可以有一下两种写法：

1. 先实例化再初始化

```c++
VideoCapture capture;
capture.open("01.avi");
```

2. 在实例化的同时初始化

```c++
VideoCapture capture("01.avi");
```

视频读入到类对象之后，紧接着可以用一个循环将每一帧显示出来，相关代码如下：

```c++
while (1)
{
	Mat frame;   // 用于存储每一帧
	capture >> frame;   // 读取当前帧
	imshow("读取视频", frame); // 显示当前帧
	waitKey(30);
}
```

将上述代码串联起来即可播放视频：

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	// 读入视频
	VideoCapture capture("F:\\01.mp4");
	// 循环显示每一帧
	while (1)
	{
		Mat frame;   // 用于存储每一帧
		capture >> frame;   // 读取当前帧
		imshow("读取视频", frame); // 显示当前帧
		waitKey(30);
	}
	return 0;
}
```

#### 1.6.2 调用摄像头采集图像

如果我们要调用摄像头进行视频采集的化，将代码`VideoCapture capture("F:\\01.mp4")`中的参数换为`0`就可以了，表示调用摄像头不再从文件中读取视频。

```c++
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	// 读入视频
	VideoCapture capture(0);
	// 循环显示每一帧
	while (1)
	{
		Mat frame;   // 用于存储每一帧
		capture >> frame;   // 读取当前帧
		imshow("读取视频", frame); // 显示当前帧
		waitKey(30);  // 延迟30ms
	}
	return 0;
}
```

