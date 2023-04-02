# Part2 栈与队列

>[1. 栈的实现](#1)
>
>[2. 队列的实现](#2)
>
>[3. 单调栈与单调队列](#3)
>
>[4. 习题](#4)

<h2 id = "1">
1. 栈的实现
</h2>

### 1.1 栈的定义

*栈（Stack）是一种只能在一端进入插入或删除操作的线性表。*表中允许进行插入、删除操作的一端称为*栈顶*，表的另一端称为*栈底*。栈顶的当前位置是动态的，栈顶的当前位置由一个被称为栈顶指针的位置指示器来指示。当栈中没有数据元素时称为*空栈*。栈的插入操作通常称为*进栈*或*入栈*，栈的删除操作通常称为*出栈*或*退栈*。

栈的主要特点是“后进先出”(Last In First Out, LIFO)。

栈的抽象数据类型定义如下：

```c++
ADT Stack
{
	// 基本运算:
    InitStack(&s);  
    DestroyStack(&s);
    StackEmpty(s);
    Push(&s, e);
    Pop(&s, &e);
    GetTop(s, &e);
}
```

### 1.2 栈的顺序存储结构以及基本运算的实现

采用顺序存储结构的栈称为*顺序栈(sequential stack)*。

假设栈的元素个数最大不超过正整数`MaxSize`，所有的元素都具有同一数据类型，即`ElemType`，可用下列方法来声明顺序栈的类型`SqStack`：

```c++
typedef struct
{	ElemType data[MaxSize];   // 存放元素
	int top;                  // 栈顶指针
}SqStack;                     // 顺序栈类型
```

对于`s`所指的顺序栈，初始时设置`s->top=-1`,可以归纳如下四个要素。

* 栈空的条件：`s->top == -1`

* 栈满的条件：`s->top == MaxSize - 1`

* 元素`e`的进栈操作：先将栈顶指针`top`增`1`，再放到栈顶指针处。
* 出栈操作：先将栈顶指针`top`处的元素取出放到`e`中，然后将栈顶指针减`1`。

在顺序栈上对应栈的基本运算算法设计如下：

1. 初始化栈

```c
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizof SqStack);
	s -> top = -1;
}
```

2. 销毁栈

```c
void DestroyStack(SqStack *&s)
{
	free(s);
}
```

3. 判断空栈

```c
int StackEmpty(SqStack *s)
{
	return (s -> top == -1);
}
```

4. 进栈

```c
int Push(SqStack *&s, ElemType e)
{
	if (s -> top == MaxSize - 1) return 0;
	s -> top ++;
	s -> data[s -> top] = e;
	return 1;
}
```

5. 出栈

```c
int Pop(SqStack *&s, ElemType &e)
{
	if (s -> top == -1) return 0;
	e = s -> data[s -> top];
	s -> top --;
	return 1;
}
```

6. 取栈顶元素

```c
int GetTop(SqStack *s. ElemType &e)
{
	if (s -> top == -1) return 0;
	e = s -> data[s -> top];
	return 1;
}
```

所有的运算的时间复杂度为$O(1)$。

### 1.3 栈的链式存储结构及其基本运算的实现

