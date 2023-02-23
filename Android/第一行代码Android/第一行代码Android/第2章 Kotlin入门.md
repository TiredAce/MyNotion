## 第2章 Kotlin入门

>[2.3 变量和函数](#2.3)
>
>[2.4 程序的逻辑控制](#2.4)

<h3 id="2.3">2.3 变量和函数</h3>

#### 2.3.1 变量

在`Kotlin`中只允许变量前声明两种关键字`val`和`var`。

`val：`用来声明一个不可变的变量，对应`Java`中的`final`变量。

`var：`用来声明一个可变的变量，对应`Java`中的非`final`变量。

`Kotlin`有着出色的类型推导机制，因此不需要对变量声明类型

在`Kotlin`中不需要用分号结尾。因此可以写出一下语句：

```kotlin
fun main()
{
    val a = 10
    println("a=" + a)
}
```

但是`Kotlin`的类型推导机制并不能总是正常工作，如果要对一个变量进行延迟赋值的话，`Kotlin`就无法自动推导它的类型了。这时候需要显示的声明变量的类型才行。

```kotlin
val a: Int = 10
```

可以发现在`Kotlin`中的变量类型为`Int`而非`Java`中的`int`，这是因为在`Kotlin`中完全摒弃了`Java`中的基本数据类型，全部使用了对象数据类型。

关于为何需要用`val`来约束变量，这是因为解决`Java`中`final`关键字没有被合理使用的问题。并不是每个人都会主动使用`final`关键字。因此`Kotlin`在设计的时候就采用了与之不同的方式，提供了``val`和`var`这两个关键字，必须由开发者来主动声明这个变量是可变的还是不变的。

对于该用`val`还是`var`这个问题，最好的解决办法是，优先使用`val`来定义变量，如果没有办法满足你的需求时，那么就使用`var`来定义变量，这会让你程序会更加健壮，也更符合高质量代码的编程规范。

#### 2.3.2 函数

在`Kotlin`函数的定义方式如下：

```kotlin
fun methodName(param1: Int, param2: Int): Int {
	return 0;
}
```

例如可以定义一个取大函数如下：

```kotlin
fun largerNumber(num1: Int, num2: Int): Int {
    return max(num1, num2);
}
```

当一个函数只有一行代码时，`Kotlin`允许我们不必编写函数体，可以直接将代码写在定义的尾部。

```kotlin
fun largerNumber(num1: Int, num2: Int): Int = max(num1, num2);
```

<h3 id="2.4">2.4 程序的逻辑控制</h3>

#### 2.4.1 if条件语句

`Kotlin`中的`if`语句相比于`Java`由一个额外的功能，它时可以有返回值的，返回值就是`if`语句每一个条件中最后一行代码的返回值。因此可以这样设计取大函数：

```kotlin
fun largerNumber(num1: Int, num2: Int): Int {
    return if (num1 > num2) {
        num1
    } else {
        num2
    }
}
```

或者可以更加精减代码

```kotlin
fun largerNumber(num1: Int, num2: Int): Int = if (num1 > num2) num1 else num2
```

#### 2.4.2 when条件语句

`when`条件语句于`Java`中的`switch`语句类似，但它又比`switch`语句强大的多。

举个例子，要通过输入一个学生的名字得到该学生的成绩，可以使用如下语句：

```kotlin
fun getScore(name: String) = when (name) {
    "Tom" -> 86
    "Jim" -> 77
    "Jack" -> 95
    else -> 0
}
```

`when`结构体中定义一系列的条件，格式是:

```kotlin
匹配值 -> {执行逻辑}
```

除了可以精确匹配之外，还能允许进行类型匹配。定义如下函数：

```kotlin
fun checkNumber(num: Number) {
    when (num) {
        is Int -> println("number is Int")
        is Double -> println("number is Double")
        else -> println("number not support")
    }
}
```

