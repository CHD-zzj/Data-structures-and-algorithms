# 左式堆

任意节点的0路径长X Npl（X）定义为从X到一个没有两个儿子的的节点的最短路径的长，其中有一个儿子或者没儿子的节点的Npl=0，Npl（NULL）=-1，任意节点的路径长比他的诸儿子节点的零路径长的最小值多1.

左式堆的性质:对于堆中每一个节点X，左儿子的零路径长＞=右儿子的零路径长

左式堆的主要操作是合并

插入过程:

​	Merge（H1,H2）H1为插入的单节点

​	如果H1为空 返回H2  H2为空 返回H1

​	都不为空

​		如果H1.element<H2.element 执行merge1（H1，H2）

​		反之 执行merge1(H2,H1)

---

merge1(H1,H2)操作//H1.ELEMENT<H2.ELEMENT

如果H1左子树为空 ：将H2插入H1左子树

否则 ：

​	H1右子树=Merge（H1右子树，H2）

​	如果Npl不符合要求

​		swapchildren（H1）

​		H1.Npl=右子树Npl+1

通过多次插入合并操作可以自行构建想要的左式堆

# 斜堆

斜堆是左式堆的自调节形式，除了右路径最大的节点不交换左右儿子外，其他节点是无条件交换的 

# 二项队列

二项队列不是一颗堆序的树，而是树的集合，称为森林。

Bn有2的n次方个节点
