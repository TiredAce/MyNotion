## 第6章 接口、lambda表达式与内部类

> [6.1 接口](#6.1)

<h3 id = "6.1">
6.1 接口
</h3>

#### 6.1.1 接口的概念

接口不是类，它是对希望符合这个接口的类的一组需求。

例如，`Arrays`类中的`sort`方法承诺可以对对象数组进行排序，但要求满足对象所属的类必须实现了`Comparable`接口。

```java
public interface Comparable
{
	int compareTo(Object other);
}
```

这说明任何实现`Comparable`接口的类都需要包含`compareTo`方法。

接口中的所有方法都自动是`public`方法。一个接口中可能包含多个方法。接口能定义常量，但是不会有实例字段。

提供实例字段和方法实现的任务应该由实现接口的那个类来完成。因此，接口类似没有实例字段的抽象类。但两者概念还是有一定区别的。

为了让类实现一个接口，通常需要完成以下两个步骤：

1. 将类声明为实现给定的接口
2. 对接口中的所有方法提供定义

例如如下实现`compareTo`方法：

```java
public int compareTo(Object otherObject) {
	Employee other = (Employee) otherObject;
   	return Double.compare(salary, other.salary);
}
```

另一种泛型实现方式：

```java
public int compareTo(Employee otherObject) {
    return Double.compare(salary, otherObject.salary);
}
```

为何不能在`Employee`类中直接提供一个`compareTo`方法，而必须实现`Comparable`接口。主要原因在于`Java`设计语言是一种强类型语言。在调用方法时候，编译器要能检查这个方法确实存在。

#### 6.1.2 接口的属性

接口不能生成实例，但是可以声明接口变量，并引用实现该接口的类对象。也可以用`instanceof`检查一个对象是否实现了某个特定的接口。

接口中可以包含常量，它与方法一样都是`public`，接口中的字段总是`public static final`。

#### 6.1.3 接口与抽象类

为何还需要接口来代替抽象类呢？因为`Java`中只能有一个超类。而可以拓展多个接口。`C++`中允许有多个超类，这称为多继承，`Java`不采用多继承的主要原因是多重继承会让语言变的复杂或效率低下。

接口可以提供多重继承的大多数好处，同时还能避免多重继承的复杂性和低效性。

#### 6.1.4 静态和私有方法

