# Data Structures

**author：陈碧辉**

**time:2023-05-16**

## 1. 栈与队列

### 1.1 顺序栈的实现（Sequential Stack）

#### 1.1.1 **栈的定义**

 ```c
 #define MaxSize 1000
 
 typedef struct {
     int data[MaxSize];
     int top;
 }SqStack;
 ```

#### 1.1.2 **六个操作**

**初始化栈（InitStack）** 

```c
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s -> top = -1;
}
```

**销毁栈（DestoryStack）**

```c
void DestroyStack(SqStack *&s)
{
    free(s);
}
```

**判断空栈（StackEmpty）**

```c
int StackEmpty(SqStack *&s)
{
    return s -> top == -1;
}
```

**进栈（Push）**

```c
bool Push(SqStack *&s, int e)
{
    if (s -> top == MaxSize - 1) return false;
    ++ s -> top = e;
    return true;
}
```

**出栈（Pop）**

```c
bool Pop(SqStack *&s, int $e)
{
    if (s -> top == -1) return false;
    e = s -> data[s -> top --];
    return true;
}
```

**取栈顶元素（GetTop）**

```c
bool GetTop(SqStack *&s, int &e)
{
    if (s -> top == -1) return false;
    e = s -> data[s -> top];
    return true;
}
```



> **细节**：
>
> 1. 引用传参与输出参数：**引用栈（初始化栈，栈未初始化时指向随机的地址），引用元素（出栈，取栈顶元素）**
> 2. $malloc$函数的参数与返回值：参数是所需要的空间字节数，返回指向开辟的指针，指针类型为$void *$
> 3. $free$函数的参数表示什么意思：释放参数指向的空间内存
> 5. 是否一定需要SqStack指针？

### 1.2 栈的链式实现（Linked Stack）
#### 1.2.1 **链表结点的定义**
```c
typedef struct linkNode{
    int data;
    linkNode* next;
}LinkedSt;
```

#### 1.2.2 六个操作

**初始化栈**

链表头指针与等效的“头结点”（数据域空着不用，指针域当做头指针用）

```c
void InitStack(LinkedSt *& head)
{
    head = (LinkedSt *)malloc(sizeof(LinkedSt));
}
```

**销毁栈**

递归销毁栈

```c
void DestoryStack1(LinkedSt *& s)
{
    if (s-> next != NULL) DestoryStack1(s -> next);
    free(s);
}
```

双指针销毁栈

```c
void DestoryStack2(LinkedSt *& s)
{
    linkNode* pre = s, *p = s -> next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p -> next;
    }
    free(pre);
}

```

**判断空栈**

```c
bool StackEmpty(LinkedSt *& head)
{
    if (head -> next == NULL) return true;
    return false;
}
```

**进栈**

```c
bool Push(LinkedSt *& head, int e)
{
    linkNode* node = (linkNode *)malloc(sizeof(linkNode));
    if (node == NULL) return false;  // 节点创建失败
    node -> data = e;
    node -> next = head -> next;
    head -> next = node;
    return true;
}
```

**出栈**

```c
bool Pop(LinkedSt *& head, int &e)
{
    if (head -> next == NULL) return false;
    e = head -> next -> data;
    linkNode* tmp = head -> next;
    head -> next = head -> next -> next;
    free(tmp);
    return true;
}
```

**取栈顶元素**

```c
bool GetTop(LinkedSt *& head, int &e)
{
    if (head -> next == NULL) return false;
    e = head -> next -> data;
    return true;
}
```

**体会与比较：**

教材中代码是将**头指针当做链栈本身**。这与**把头指针当做结构体栈的一个属性**出现，有什么区别？后者**封装性**体现的更好，它真正与顺序栈是同等地位。而头指针是与顺序栈中的两个属性同一地位。**头顶点的实现代码**更简洁。无需对头指针是否为空再做判断。

#### 1.3 课程作业

1. 运行课堂上的程序，《实验教材》第三章实验题1（p.59-61）；用这个顺序栈检查一个字符串中的括号是否配对。例如"a*(b*(c+d)-e)"中的括号是配对的；"a*(b*(c+d)-e"中的括号不是配对的；"(a*)b*(c+d)-e)"中的括号不是配对的。

**answer：**

```c
bool check(const char* str)
{
    LinkedSt* head;
    InitStack(head);
    int tmp;
    while (*str != '\0')
    {
        // 用0表示“（”
        if (*str == '(') Push(head, 0);
        else if (* str == ')')
        {
            // 如果没有 ）则无法配对
            if (head -> next == NULL) return false;
            else Pop(head, tmp);
        }
        str ++;
    }
    // 如果多出了（，则无法配对
    if (head -> next != NULL) return false;
    return true;
}
```

2.阅读程序：《实验教材》第三章实验题7（p.76-78），栈元素排序问题。

### 1.3 顺序队列的实现（Sequential Queue）

#### 1.3.1 顺序队列的定义

```c
typedef struct{
    int data[MaxSize];
    int front, rear;
}SqQueue;
```

#### 1.3.2 五个操作

**初始化队列（InitQueue）**

```c
void InitQueue(SqQueue *& q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q -> front = q -> rear = -1;  // 两者相同表示队空
}
```

**销毁栈（DestoryQueue）**

```c
void DestoryQueue(SqQueue *& q)
{
    free(q);
}
```

**判断栈是否为空（QueueEmpty）**

```c
bool QueueEmpty(SqQueue *& q)
{
    return q -> front == q -> rear;
}
```

**进队（PushQueue）**

```c
bool PushQueue(SqQueue *& q, int e)
{
    if (q -> rear == MaxSize - 1) return false;
    q -> data[++ q -> rear] = e;
    return true;
}
```

**出栈（PopQueue）**

````c
bool PopQueue(SqQueue *& q, int &e)
{
    if (q -> rear == q -> front) return false;
    e = q -> data[++ q -> front];
    return true;
}
````

#### 1.3.3 循环队列空间优化

只需要改以下三个函数

**初始化队列**

```c
void InitQueue(SqQueue *& q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q -> front = q -> rear = 0; 
}
```

**进队（PushQueue）**

```c
bool PushQueue(SqQueue *& q, int e)
{
    // 满队条件， 队尾在队头前一个位置
    if ((q -> rear + 1) % MaxSize == q -> front) return false;
    ++ q -> rear %= MaxSize;
    q -> data[q -> rear] = e;
    return true;
}
```

**出栈（PopQueue）**

````c
bool PopQueue(SqQueue *& q, int &e)
{
    if (q -> rear == q -> front) return false;
    ++ q -> front %= MaxSize;
    e = q -> data[q -> front];
    return true;
}
````

### 1.4 链式队列实现

#### 1.4.1 链式队列的定义

```c
typedef struct Node
{
    int data;
    Node* next;
}DataNode;

typedef struct
{
    DataNode *front;
    DataNode *rear;
}LinkedQueue;
```

#### 1.4.2 五个操作

**初始化队列**

```c
void InitQueue(LinkedQueue *& q)
{
    q = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    q -> front = q -> rear = NULL;
}
```

**销毁队列**

非递归销毁

```c
void DestoryQueue(LinkedQueue *& q)
{
    DataNode* pre = q -> front, *p;
    if (pre != NULL)
    {
        p = pre -> next;
        while (p != NULL)
        {
            free(pre);
            pre = p;
            p = pre -> next;
        }
        free(pre);
    }
    free(q);
}
```

递归销毁

```c
void DestoryNode(DataNode* node)
{
    if (node -> next != NULL) DestoryNode(node -> next);
    free(node);
}

void DestoryQueue(LinkedQueue *& q)
{
    DestoryNode(q -> front);
    free(q);
}
```

**判断是否为空队列**

```c
bool QueueEmpty(LinkedQueue *& q)
{
    return q -> rear == NULL;
}
```

**入队**

```c
bool PushQueue(LinkedQueue *& q, int e)
{
    DataNode* node = (DataNode *)malloc(sizeof(DataNode));
    if (node == NULL) return false;
    node -> data = e;
    node -> next = NULL;
    if (q -> rear == NULL)  // 空队
    {
        q -> front = q -> rear = node;
    }
    else
    {
        q -> rear -> next = node;
        q -> rear = node;
    }
    return true;
}
```

**出队**

```c
bool PopQueue(LinkedQueue *& q, int &e)
{
    if (q -> front == NULL) return false;
    e = q -> front -> data;
    if (q -> front == q -> rear) // 一个元素
    {
        free(q -> front);
        q -> front = q -> rear = NULL;
    }
    else
    {   
        DataNode* tmp = q -> front;
        q -> front = q -> front -> next;
        free(tmp);
    }
    return true;
}
```

### 1.5 栈与队列的应用

**表达式求值问题**

**dfs与bfs迷宫问题**

## 2. 线性表

### 2.1 顺序线性表的实现

#### 2.1.1 线性表的定义

顺序表的两个属性【数组data，顺序表目前元素个数length】

```c
typedef struct {
    int data[MaxSize];
    int length;
}SqList;
```

#### 2.1.2 线性表的操作

**建立线性表**

```c++
/**
 * Create SqList
 * @param L SqList
 * @param a array 
 * @param n array's length
 */
void CreateList(SqList *&L, int a[], int n)
{
    L = (SqList *)malloc(sizeof (SqList));
    for (int i = 0; i < n; i ++)
    {
        L -> data[i] = a[i];
    }
    L -> length = n;
}
```

**销毁线性表**

```c
void DestroyList(SqList *L)
{
    free(L);
}
```

**输出线性表**

```c
void DispList(SqList *L)
{
    for (int i = 0; i < L -> length; i ++)
    {
        printf("%d ", L -> data[i]);
    }
    printf("\n");
}
```

**查找某个数据元素**

```c
bool GetElem(SqList *& L, int i, int &e)
{
    if (i < 1 || i > L -> length) return false;
    e = L -> data[i - 1];
    return true;
}
```

**按照元素查找**

```c
int LocateElem(SqList *&L, int e)
{
    for (int i = 0; i < L -> length; i ++)
    {
        if (L -> data[i] == e) return i + 1;
    }
    return 0;
}
```

**插入元素**

```c
bool InsertList(SqList *&L, int i, int e)
{
    if (i < 1 || i > L -> length + 1 || L -> length == MaxSize) 
        return false;
    for (int j = L -> length - 1; j >= i; j --)
    {
        L -> data[j + 1] = L -> data[j];
    }
    L -> data[i] = e;
    L -> length ++;
    return true;
}
```

**删除元素**

```c
bool DeleteList(SqList *&L, int i, int &e)
{
    if (i < 1 || i > L -> length) return false;
    i --;
    e = L -> data[i];
    for (int j = i + 1; j < L -> length; j ++)
    {
        L -> data[j - 1] = L -> data[j];    
    }
    L -> length --;
    return true;
}
```

### 2.2 单链表

实现方式参考链栈

## 3. 查找

### 3.1 顺序查找

### 3.2 二分查找

### 3.3 分块查找

### 3.4 Hash映射

#### 3.4.1 开放寻址法

#### 3.4.2 拉链法

## 4. 递归

定义【自己调用自己】、调用特征【向终止条件靠近】、好处【解决复杂问题】。

### 4.1 汉诺塔问题

### 4.2 迷宫问题

## 5. 二叉树

### 5.1 二叉树的遍历

#### 5.1.1 DFS

先序，中序，后续遍历，使用递归或栈



#### 5.1.2 BFS

层序遍历，使用队列





#### 5.1.3 根据遍历序建立树

给出某个二叉树遍历的先根序列、中根序列，构造二叉树的方法，唯一。
给出某个二叉树遍历的后根序列、中根序列，构造二叉树的方法，唯一。
给出某个二叉树遍历的先根序列、后根序列，构造二叉树的方法，可能不唯一。

### 5.2 BST

当前根的关键字小的值，往左侧插入；比当前根的关键字大的值，往右侧插入；与当前根的关键字相等的值，不再插入。形成二叉查找树。

#### 5.2.1 BST的操作



### 5.3 AVL

在不太平衡的时候，就把树形通过旋转整理一下，调整成平衡的，这样查找效率就会保证在比较高的状态。

### 5.4 哈夫曼树

思路：常用的文字二进制编码短一些、不常用的文字二进制编码长一些

### 5.5 二叉线索树

二叉线索树有什么作用？【对遍历的结果进行存储，使用初始时为空的指针域存储当前结点在遍历结果中“直接前驱”和/或“直接后继”，有助于其后在遍历时效率有一定的提高。】

二叉树中有多少个空指针域？【结点数N+1：N个顶点共有2N个指针域，N-1个顶点的前驱通过指针域指向它们，所以有N-1个非空指针域，因此空指针域是N+1个】

### 5.6 Trie树

Trie树（26叉树）解决编程语言中高效存储保留字的问题。注意与Hash表存储的对比，需要精心设计Hash函数：算法简单且Hash冲突小，因此实现Hash函数算法的设计可能门槛较高。但是Trie树比较直观。

### 5.7 并查集

用于维护集合，包括2个主要操作：子集树的合并、查找某个结点所属的子集树；1个附属操作是：并查集的初始化（每个结点各自为政）。
