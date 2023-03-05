## 第3章 HighGUI图形用户界面初步

>[3.1 图像载入、显示和输入到文件](#3.1)

<h3 id="3.1">
3.1 图像载入、显示和输入到文件
</h3>

#### 3.1.1 OpenCV的命名空间

有两种方法可以访问：第一种方式是在合适的地方加上`using namespace cv`；另外一种，是在使用`OpenCV`的每一个类和函数时，都加上`cv::`的命名空间。在写简单的`OpenCV`程序时候，以下三句能作为标配：

```c++
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
```

#### 3.1.2 Mat类简析

`Mat`类时用于保存图像以及其他矩阵数据的数据结构，默认情况它的尺寸为`0`，也可以指定其初始尺寸。主要用于存放图像的数据结构：

```c++
Mat srcImage = imread("dota.jpg");
```

#### 3.1.3 图像的载入与显示概述

最简单的图像载入和显示只需要两句代码，非常便捷，这两个函数时`imread()`和`imshow()`。

#### 3.1.4 图像的载入：imread()函数

其函数原型为：

```c++
Mat imread(const string& filename, int flags = 1);
```

第一个参数填入我们需要载入的图像路径名。

第二个参数，它指定一个加载图像的颜色类型。如果忽略这个参数就是载入三通道的彩色图像。可以在`higui_c.h`中发现这个枚举的定义是这样的：

* 取值为`0`时，去这个标识的话，始终将图像转换为灰度再返回。
* 取值为`1`时，转换图像到彩色再返回。
* 取值为`2`时，载入的图像深度为`16`位或者`32`位，就返回对用深度的图像，否则，转换为`8`位图像再返回。

`flags`是一个`int`型变量，若我们不在这个枚举值中取固定值，可以这样进行：

* `flags > 0` 返回与一个`3`通道的彩色图像。
* `flags = 0` 返回灰度图像。
* `flags < 0` 返回包含`Alpha`通道的载入图像。

看几个载入实例：

``` c++
Mat image0 = imread("1.jpg", 2 | 4);   // 无损载入
Mat image1 = imread("1.jpg", 0);       // 载入灰度图
Mat image2 = imread("1.jpg", 199);     // 载入三通道图像
```

#### 3.1.5 图像的显示:imshow()函数

其函数原型为：

```c++
void imshow(const string& winname, InputArray mat);
```

