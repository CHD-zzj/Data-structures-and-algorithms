# 本周学习内容如下

## 1.搞清楚了typedef的用法

①typedef int Index //给整型变量int 起一个别名Index

typedef a b；给a起别名b

②typedef struct HashTbl *HashTable 

Hashtable是指针，他指向的是Hashtbl结构体

③typedef struct HashEntry Cell

给结构体HashEntry起别名Cell

## 2.头文件的建立与用法

## 3.完善了上周没有调试好的分离链接散列法的代码

## 4.开放定址散列法

在发生冲突时通过给定的函数去寻找下一个解决冲突的地址 然后存放元素

还有Rehash操作，如果当前哈希表太小或者将要用完的话通过Rehash操作可以把元素再散列到一个二倍大小的新的哈希表中

## 5.优先队列（小根堆）

堆的结构性质:完全被填满的二叉树，底上元素从左到右依次填入，这样的二叉树称为完全二叉树

使用数组进行实现，对于二叉树中任意位置i的元素（i=0的数组元素记为-1，二叉树元素从i=1开始）

其父节点为i/2，子节点位置为2i与2i+1，并且每个节点都比它的子节点小

