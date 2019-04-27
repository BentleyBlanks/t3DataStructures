# t3DataStructure

本数据结构为学习《数据结构-C语言版》练手之作

内部将会使用C++重现书上经典算法，具体包括稀疏矩阵，线性表，字符串，树，图，排序里等非常经典的算法。

本程序在实际实现中不依赖外部成熟的数据结构，而是选择重现。因此不依赖任何外部库

## Dependency
1.依赖Google的测试框架[gTest](https://code.google.com/p/googletest/)(没有包含在仓库中)

## How to build
1.包含文件方面只需```./t3DataStructures/```即可，若有对依赖项额外依赖可手动包含

## How to use
1.  已更新CMake,支持多平台IDE工程直接生成(XCode, VS2013已测试)

2.  在测试上t3DataStructure做的较为完善。支持Log，errorLog，未来将会增加日志文件的Log，目前而言这些基础Log已经足够在运行时使用。（```t3PrintError，t3PrintErrorArg，t3Log与printf等价```）

3.  计时器方面借鉴[Nadeau](http://nadeausoftware.com/articles/2012/04/c_c_tip_how_measure_elapsed_real_time_benchmarking)的跨平台获取realTime的方法，使用方式如下

```cpp
t3Timer timer;

timer.start();
// do something...
timer.end();

t3Log("Cost Time: %lf\n", timer.difference());
```

4.  String方面由于设计上的疏忽，导致KMP算法实现的findFast将会```稍慢于```检测末端标记的算法find。需要注意的是在进行匹配测试之前，需要预先给定模式字符串。

```cpp
t3StringADT s;

s.create("Who's Your Daddy");
// 需要预先给定模式字符串
s.setPattern("our");

// 末端标记
s.find();
// KMP
s.findFast();
```

5.  LinearList方面，只有一点需要注意，就是一旦超出数组最大容纳数量即刻重新申请内存数据迁移，这将会带来性能上的极大降低
    推荐在```Common/t3DataStructuresSettings.h```上设定好自行需要的容量大小。

```cpp
// 线性表默认长度
#define T3_STACK_DEFAULT_LENGTH 16
#define T3_QUEUE_DEFAULT_LENGTH 4
```
一旦超出容量，那么Tatty会自行分配两倍于目前长度的新空间。其中Queue较为特殊，循环队列在重新分配了之后，首尾指针会归位，因此建议不要在外部保存两者的副本。

6.  表达式部分需要注意的是，若给定的是后表达式

```cpp
t3Expression exp;
exp.create("42/1-12*+22*- ");
// 求后缀表达式的值，因此当前可直接求值
exp.evaluate();
```

若给定的是中缀表达式
```cpp
t3Expression exp;
exp.create("((((4/2)-1)+(1*2))-(2*2)) ");
// 转为后缀表达式
exp.toPostfix();
// 此时可以求后缀表达式的值
exp.evaluate();
```

7.  即将更新树部分(基本二叉树，二叉线索树，二叉查找树，堆)

## Debug
Tatty在线性表这边都给定了默认的print

```cpp
// 栈
stack.print();
// 队列这里会指出front,rear指针的位置，较为方便
queue.print();
// 稀疏矩阵
m.print();
```

## About

```cpp
int 官某某 = "Bingo";

char[] 个人博客 = "http://bentleyblanks.github.io";
```







