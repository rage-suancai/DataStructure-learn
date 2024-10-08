<img src="https://s2.loli.net/2022/08/01/QjFzq4LHObBxhKl.png"/>

## 树形结构篇

前面我们学习了线性相关的数据结构 了解了顺序表和链表两种类型 我们接着来看树形结构 这一章会更加考验各位小伙伴的数学功底以及逻辑思维 难度会更大一些

### 树与森林

树是一种全新的数据结构 它就像一棵树的树枝一样 不断延伸

<img src="https://s2.loli.net/2022/08/08/NajFZzXHxUCDQBW.png"/>

#### 树结构介绍

一棵树就像下面这样连接:

<img src="https://s2.loli.net/2022/08/01/aoBjrR5bPqWzCel.png"/>

可以看到 现在一个结点下面可能会连接多个节点 并不断延伸 就像树枝一样 每个结点都有可能是一个分支点 延伸出多个分支 从位于最上方的结点开始不断向下 而这种数据结构 我们就称为**树**(Tree) 注意分支只能向后单独延伸 之后就分道扬镳了 **不能与其他分支上的结点相交**

- 我们一般称位于最上方的结点为树的**根结点**(Root) 因为整棵树正是从这里开始延伸出去的

- 每个结点连接的子结点数目(分支的数目) 我们称为结点的**度**(Degree) 而各个结点度的最大值称为树的度

- 每个结点延伸下去的下一个结点都可以称为一棵**子树**(SubTree) 比如结点`B`及其之后延伸的所有分支合在一起 就是一棵`A`的子树

- 每个**结点的层次**(Level) 按照从上往下的顺序 树的根结点为`1` 每向下一层`+1` 比如`G`的层次就是`3` 整棵树中所有结点的最大层次 就是这颗**树的深度**(Depth) 比如上面这棵树的深度为4 因为最大层次就是4

由于整棵树错综复杂 所以说我们需要先规定一下结点之间的称呼 就像族谱那样:

- 与当前结点直接向下相连的结点 我们称为**子结点**(Child) 比如`B, C, D`结点 都是`A`的子结点 就像族谱中的父子关系一样 下一代一定是子女 相反的 那么`A`就是`B, C, D`的**父结点**(Parent) 也可以叫双亲结点

- 如果某个节点没有任何的子结点(结点度为0时) 那么我们称这个结点为**叶子结点** (因为已经到头了 后面没有分支了 这时就该树枝上长叶子了那样) 比如`K, L, F, G, M, I, J`结点 都是叶子结点

- 如果两个结点的父结点是同一个 那么称这两个节点为**兄弟结点**(Sibling) 比如`B`和`C`就是兄弟结点 因为都是`A`的孩子

- 从根结点开始一直到某个结点的整条路径的所有结点 都是这个结点的**祖先结点**(Ancestor) 比如`L`的祖先结点就是`A, B, E`

那么在了解了树的相关称呼之后 相信各位就应该对树有了一定的了解 虽然概念比较多 但是还请各位一定记住 不然后面就容易听懵

#### 森林

森林其实很好理解 一片森林肯定是是由很多棵树构成的 比如下面的三棵树:

<img src="https://s2.loli.net/2022/08/01/VnblyMgQXkC6cBu.png"/>

它们共同组成了一片森林 因此 m (m≥0) 棵树的集合我们称为**森林**(Forest)

### 二叉树

前面我们给大家介绍了树的概念 而我们本章需要着重讨论的是**二叉树**(Binary Tree\) 它是一种特殊的树 它的度最大只能为`2` 所以我们称其为二叉树 一棵二叉树大概长这样:

<img src="https://s2.loli.net/2022/08/01/QGLfnYWFby37deP.png"/>

并且二叉树任何结点的子树是有左右之分的 不能颠倒顺序 比如A结点左边的子树 称为左子树 右边的子树称为右子树

二叉树有5种基本形态 分别是:

<img src="https://s2.loli.net/2022/08/01/8ncvzo6aLem14ju.png"/>

当然 对于某些二叉树我们有特别的称呼 比如 在一棵二叉树中 所有分支结点都存在左子树和右子树 且叶子结点都在同一层:

<img src="https://s2.loli.net/2022/08/01/btfjlJhDuWrSXYi.png"/>

这样的二叉树我们称为**满二叉树** 可以看到整棵树都是很饱满的 没有出现任何度为1的结点 当然 还有一种特殊情况:

<img src="https://s2.loli.net/2022/08/01/QGLfnYWFby37deP.png"/>

可以看到只有最后一层有空缺 并且所有的叶子结点是按照从左往右的顺序排列的 这样的二叉树我们一般称其为**完全二叉树** 所以 一棵满二叉树 一定是一棵完全二叉树

#### 树和森林的转换

二叉树和树, 森林之间是可以相互转换的

我们可以使用下面的规律将一棵普通的树转换为一棵二叉树:

1. 最左边孩子结点 -> 左子树结点(左孩子)

2. 兄弟结点 -> 右子树结点(右孩子)

我们以下面的这棵树为例:

<img src="https://s2.loli.net/2022/08/06/y51pTzhrQV3GPCJ.png"/>

我们优先从左边开始看 B, F, G都是A的子结点 根据上面的规律 我们将B作为左子树:

<img src="https://s2.loli.net/2022/08/06/g4XfmiQHaOy6JhG.png"/>

接着继续从左往右看 由于F是B的兄弟结点 那么根据规律 F作为B的右子树:

<img src="https://s2.loli.net/2022/08/06/6wqO4iErjQpyKzP.png"/>

接着是G G是F的兄弟结点 那么G继续作为F的右子树:

<img src="https://s2.loli.net/2022/08/06/DfBsxVHlSotn6I3.png"/>

我们接着来看第三排 依然是从左往右 C是B的子结点 所以C作为B的左子树:

<img src="https://s2.loli.net/2022/08/06/93zFJGyx2SBLHC4.png"/>

接着 D是C的兄弟节点 那么D就作为C的右子树了:

<img src="https://s2.loli.net/2022/08/06/YO5zf2TVHqBdnX6.png"/>

此时还有一个H结点 它是G的子结点 所以直接作为G的左子树:

<img src="https://s2.loli.net/2022/08/06/oHcAM6d2SFrveaE.png"/>

现在只剩下最后一排了 E是D的子结点 K是H的子结点 所以最后就像这样了:

<img src="https://s2.loli.net/2022/08/06/6JxYP2CXSyZdGa4.png"/>

按照规律 我们就将一棵树转换为了二叉树 当然还有一种更简单的方法 我们可以直接将所有的兄弟结点连起来(橙色横线):

<img src="https://s2.loli.net/2022/08/07/OSZ71J6CVEzeNiW.png"/>

接着擦掉所有结点除了最左边结点以外的连线:

<img src="https://s2.loli.net/2022/08/07/y62Z3UlaWdemI7v.png"/>

所有的黑色连线偏向左边 橙色连线偏向右边:

<img src="https://s2.loli.net/2022/08/07/yzA2uLqhYDnbZcJ.png"/>

效果是一样的 这两种方式都可以 你觉得哪一种简单就使用哪一种就行了 我们会发现 无论一棵树长成啥样 转换为二叉树后 **根节点一定没有右子树**

**思考: **那二叉树咋变回普通的树呢? 实际上我们只需要反推回去就行了

那么森林呢 森林如何转换为一棵二叉树呢? 其实很简单:

<img src="https://s2.loli.net/2022/08/08/QCIaYTcEv2NO47G.png"/>

首先我们还是按照二叉树转换为树的规则 将森林中所有树转换为二叉树 接着我们只需要依次连接即可:

<img src="https://s2.loli.net/2022/08/08/O3xnhv85WLPzJpq.png"/>

注意连接每一棵树的时候 一律从根结点的右边开始 不断向右连接

我们发现 相比树转换为二叉树 森林转换为二叉树之后 根节点就存在右子树了 右子树连接的都是森林中其他的树

**思考: **现在有一棵二叉树 我们想要转回去 我们怎么知道到底是将其转换为森林还是转换为树呢?

#### 二叉树的性质

由于二叉树结构特殊 我们可以总结出以下的五个性质:

- **性质一**: 对于一颗二叉树 第`i`层的最大结点数量为 $2^{𝑖 − 1}$ 个 比如二叉树的第一层只有一个根节点 也就是 $2^0=1 $ 而二叉树的第三层可以有 $2^2=4$ 个结点
- **性质二**: 对于一棵深度为`k`的二叉树 可以具有的最大结点数量为:

$$
n=2^0+2^1+2^2+...+2^{k-1}
$$

​	我们发现 实际上每一层的结点数量 组成了一个等比数列 公比`q`为`2` 结合等比数列求和公式 我们可以将其简化为:
$$
S_n= \frac {a_1 \times (1 - q^n)} {1 - q} = \frac {1 \times (1 - 2^k)} {1 - 2} = - (1 - 2^k) = 2^k - 1
$$
​	所以一棵深度为`k`的二叉树最大结点数量为 $𝑛 = 2^𝑘 − 1$ 顺便得出 结点的边数为 $𝐸 = 𝑛 − 1$

- **性质三**: 假设一棵二叉树中度为0, 1, 2的结点数量分别为 $𝑛_0$, $𝑛_1$, $𝑛_2$ 由于一棵二叉树中只有这三种类型的结点 那么可以直接得到结点总数

$$
n=n_0+n_1+n_2
$$

​	我们不妨换一个思路 我们从二叉树的边数上考虑 因为每个结点有且仅有一条边与其父结点相连 那么边数之和就可以表示为:
$$
E=n_1+2n_2
$$
​	度为1的结点有一条边 度为2的结点有两条边 度为0的结点没有 加在一起就是整棵二叉树的边数之和 结合我们在**性质二**中推导的结果 可以得到另一种计算结点总数的方式:
$$
E=n−1=n_1+2n_2
$$

$$
n=n_1+2n_2+1
$$

​	再结合我们第一个公式:
$$
n=n_0+n_1+n_2=n_1+2n_2+1
$$
​	综上 对于任何一棵二叉树 如果其叶子结点个数为 $𝑛_0$ 度为2的结点个数为 $𝑛_2$ 那么两者满足以下公式:
$$
n_0=n_2+1
$$
​	*(性质三的推导过程比较复杂 如果觉得麻烦推荐直接记忆)*

- **性质四**: 完全二叉树除了最后一层有空缺外 其他层数都是饱满的 假设这棵二叉树为满二叉树 那么根据我们前面得到的性质 假设层数为`k` 那么结点数量为: 𝑛 = 2𝑘 − 1 根据完全二叉树的性质 最后一层可以满可以不满 那么一棵完全二叉树结点数`n`满足:
  $$
  2^{k−1}−1<n<=2^k−1
  $$
  因为`n`肯定是一个整数 那么可以写为:
  $$
  2^{k−1}<=n<=2^k−1
  $$
  现在我们只看左边的不等式 我们对不等式两边同时取对数 得到:
  $$
  k−1<=log_2n
  $$
  综上所述 一棵具有`n`个结点的完全二叉树深度为 $𝑘 = ⌊𝑙𝑜𝑔_2𝑛⌋ + 1$

​	*(性质四的推导过程比较复杂 如果觉得麻烦推荐直接记忆)*

- **性质五: **一颗有`n`个结点的完全二叉树 由性质四得到深度为 $𝑘 = ⌊𝑙𝑜𝑔_2𝑛⌋ + 1$ 现在对于任意一个结点`i` 结点的顺序为从上往下 从左往右:

  - 对于一个拥有左右孩子的结点来说 其左孩子为`2i` 右孩子为`2i + 1`

  - 如果`i = 1` 那么此结点为二叉树的根结点 如果`i > 1` 那么其父结点就是⌊𝑖/2⌋ 比如第3个结点的父结点为第1个节点 也就是根结点

  - 如果`2i > n` 则结点`i`没有左孩子 比如下面图中的二叉树 n为5 假设此时`i = 3` 那么`2i = 6 > n = 5`说明第三个结点没有左子树

  - 如果`2i + 1 > n` 则结点`i`没有右孩子

    <img src="https://s2.loli.net/2022/08/05/uan6A3ZRLykt289.png"/>

以上五条二叉树的性质一般是笔试重点内容 还请务必牢记 如果觉得推导过程比较麻烦 推荐直接记忆结论

**二叉树练习题:**

1. **由三个结点可以构造出多少种不同的二叉树？**

​	*这个问题我们可以直接手画得到结果 一共是五种 当然 如果要求N个结点的话 可以利用动态规划求解 如果这道题是求N个结点可以构造多少二叉树 我们可以分析一下*:

- 假设现在只有一个结点或者没有结点 那么只有一种 $ℎ(0) = ℎ(1) = 1$

- 假设现在有两个结点 那么其中一个拿来做根结点 剩下这一个可以左边可以右边 要么左边零个结点右边一个结点 要么左边一个结点右边零个结点 所以说 $ℎ(2) = ℎ(1) × ℎ(0) + ℎ(0) × ℎ(1) = 2$

- 假设现在有三个结点 那么依然是其中一个拿来做根节点 剩下的两个结点情况就多了 要么两个都在左边 两个都在右边 或者一边一个 所以说 $ℎ(3) = ℎ(2) × ℎ(0) + ℎ(1) × ℎ(1) + ℎ(0) × ℎ(2)$

​	*我们发现 它是非常有规律的 N每+1 项数多一项 所以我们只需要按照规律把所有情况的结果相加就行了 我们按照上面推导的结果 编写代码*:

```c
                            int main() {
                                
                                int size;
                                scanf("%d", &size); // 读取需要求的N
                                int dp[size + 1];
                                dp[0] = dp[1] = 1; // 没有结点或是只有一个结点直接得到1
                                for (int i = 2; i <= size; ++i) {
                                    dp[i] = 0; // 一开始先等于0再说
                                    for (int j = 0; j < i; ++j) { // 内层循环是为了计算所有情况 比如i等于3 那么就从j = 0开始 计算dp[0]和dp[2]的结果 再计算dp[1]和dp[1]...
                                        dp[i] += dp[j] * dp[i - j - 1];
                                    }
                                }
                                printf("%d", dp[size]); // 最后计算的结果就是N个结点构造的二叉树数量了
                                
                            }
```

<img src="https://s2.loli.net/2022/08/08/DIHPQcxgbVXLaYK.png"/>

成功得到结果 当然 实际上我们根据这个规律 还可以将其进一步简化 求出的结果序列为: 1, 1, 2, 5, 14, 42, 132... 这种类型的数列我们称为**卡特兰数** 以中国蒙古族数学家明安图(1692-1763)和比利时的数学家欧仁·查理·卡塔兰(1814–1894)的名字来命名 它的通项公式为*:
$$
Cn=\frac{1}{n+1}C_2nn=\frac{1}{n+1}×\frac{(2n)!}{n!×(2n-n)!}=\frac{(2n)!}{n!×(n+1)!}
$$
所以说不需要动态规划了 直接一个算式解决问题:

```c
                            int factorial(int n) {
                                
                                int res = 1;
                                for (int i = 2; i <= n; ++i) res *= i;
                                return res;
                                
                            }

                            int main() {
                                
                                int n;
                                scanf("%d", &n);
                                printf("%d", factorial(2*n) / (factorial(n) * factorial(n + 1)));
                                
                            }
```

*只不过这里用的是int 运算过程中如果数字太大的话就没办法了*

2. **一棵完全二叉树有1001个结点 其中叶子结点的个数为?**

   *既然是完全二叉树 那么最下面这一排肯定是按顺序排的 并且上面各层应该是排满了的 那么我们先求出层数 根据性质四*:
   $$
   k=⌊log_2n⌋+1=9+1=10
   $$
   *所以此二叉树的层数为10 也就是说上面9层都是满满当当的 最后一层不满 那么根据性质二 我们求出前9层的结点数*:
   $$
   n=2^k−1=511
   $$
   *那么剩下的结点就都是第十层的了 得到第十层所有叶子结点数量 $ = 1001 - 511 = 490 因为第十层并不满 剩下的叶子第九层也有 所以最后我们还需要求出第九层的叶子结点数量 先计算第九层的所有结点数量*:
   $$
   n=2^{i−1}=256
   $$
   *接着我们需要去掉那些第九层度为一和度为二的结点 其实只需要让第十层都叶子结点除以2就行了*:
   $$
   n=(490+1)/2=245
   $$
   *注意在除的时候+1 因为有可能会出现一个度为1的结点 此时也需要剔除 所以说+1变成偶数这样才可以正确得到结果 最后剔除这些结点 得到最终结果*:
   $$
   n0=256−245+490=501
   $$
   *所以这道题的答案为501*

3. **深度为h的满m叉树的第k层有多少个结点?**

   *这道题只是看着复杂 但是实际上我们把之前推导都公式带进来就行了 但是注意 难点在于 这道题给的是满m叉树 而不是满二叉树 满二叉树根据性质一我们已经知道*:
   $$
   n=2^i−1
   $$
   那m叉树呢? 实际上也是同理的 我们以三叉树为例 每向下一层 就划分三个孩子结点出来:

   <img src="https://s2.loli.net/2022/08/08/XvH4At8Q93nkFIR.png"/>

   每一层的最大结点数依次为: 1, 3, 9, 27....

   我们发现 实际上每一层的最大结点数 正好是3的次方 所以说无论多少叉树 实际上变化的就是底数而已 所以说深度为h(h在这里没卵用 障眼法罢了)的满m叉树第k层的结点数:
   $$
   n=m^k−1
   $$

4. **一棵有1025个结点的二叉树的层数k的取值范围是?**

   *这个问题比较简单 层数的最小值实际上就是为完全二叉树的情况 层数的最大值实际上就是连成一根线的情况 结点数就是层数 所以说根据性质四得到最小深度为11 最大深度就直接1025了 k的范围是11 - 1025*

5. **将一棵树转换为二叉树时 根节点的右边连接的是?**

   *根据我们前面总结得到的性质 树转换为二叉树之后 根结点一定没有右子树 所以为空*

#### 二叉树的构建

前面我们介绍了二叉树的几个重要性质 那么现在我们就来尝试在程序中表示和使用一棵二叉树

二叉树的存储形式也可以使用我们前面的两种方式 一种是使用数组进行存放 还有一种就是使用链式结构 只不过之前链式结构需要强化一下才可以表示为二叉树

首先我们来看数组形式的表示方式 利用前面所推导的性质五 我们可以按照以下顺序进行存放:

<img src="https://s2.loli.net/2022/08/05/uan6A3ZRLykt289.png"/>

这颗二叉树的顺序存储:

<img src="https://s2.loli.net/2022/08/06/jTtvWahxI9VUKuG.png"/>

从左往右 编号`i`从1开始 比如现在我们需要获取A的右孩子 那么就需要根据性质五进行计算 因为右孩子为`2i + 1` 所以A的右边孩子的编号就是3 也就是结点C

这种表示形式使用起来并不方便 而且存在大量的计算 所以说我们只做了解即可 我们的重点是下面的链式存储方式

我们在前面使用链表的时候 每个结点不仅存放对应的数据 而且会存放一个指向下一个结点的指针:

<img src="https://s2.loli.net/2022/07/23/ruemiRQplVy7q9s.png"/>

而二叉树也可以使用这样的链式存储形式 只不过现在一个结点需要存放一个指向左子树的指针和一个指向右子树的指针了:

<img src="https://s2.loli.net/2022/08/06/H9MqkghmAjFJnuO.png"/>

通过这种方式 我们就可以通过连接不同的结点形成一颗二叉树了 这样也更便于我们去理解它 我们首先定义一个结构体:

```c
                            typedef char E;

                            struct tree_node {
                                
                                E element; // 存放元素
                                struct tree_node *left; // 指向左子树的指针
                                struct tree_node *right; // 指向右子树的指针
                                
                            };
                            typedef struct tree_node *Node;
```

比如我们现在想要构建一颗像这样的二叉树:

<img src="https://s2.loli.net/2022/08/05/uan6A3ZRLykt289.png"/>

首先我们需要创建好这几个结点:

```c
                            int main() {
                                
                                Node a = malloc(sizeof(struct tree_node)); // 依次创建好这五个结点
                                Node b = malloc(sizeof(struct tree_node));
                                Node c = malloc(sizeof(struct tree_node));
                                Node d = malloc(sizeof(struct tree_node));
                                Node e = malloc(sizeof(struct tree_node));
                                a->element = 'A';
                                b->element = 'B';
                                c->element = 'C';
                                d->element = 'D';
                                e->element = 'E';
                                
                            }
```

接着我们从最上面开始 挨着进行连接 首先是A这个结点:

```c
                            int main() {
                                
                                ...

                                a->left = b; // A的左孩子是B
                                a->right = c; // A的右孩子是C
                                
                            }
```

然后是B这个结点:

```c
                            int main() {
                                
                                ...

                                b->left = d; // B的左孩子是D
                                b->right = e; // B的右孩子是E

                                // 别忘了把其他的结点改为NULL
                                ...
                                    
                            }
```

这样的话 我们就成功构建好了这棵二叉树:

```c
                            int main() {
                                
                                ...

                                printf("%c", a->left->left->element); // 比如现在我想要获取A左孩子的左孩子 那么就可以直接left二连
                                
                            }
```

断点调试也可以看的很清楚:

<img src="https://s2.loli.net/2022/08/06/oTPeUpBlmNsZWE1.png"/>

#### 二叉树的遍历

前面我们通过使用链式结构 成功构建出了一棵二叉树 接着我们来看看如何遍历一棵二叉树 也就是说我们想要访问二叉树的每一个结点 由于树形结构特殊 遍历顺序并不唯一 所以一共有四种访问方式: **前序遍历, 中序遍历, 后序遍历, 层序遍历 **不同的访问方式输出都结点顺序也不同

首先我们来看最简单的前序遍历:

<img src="https://s2.loli.net/2022/08/06/G6ujstSVZ2XWJLE.png"/>

前序遍历是一种勇往直前的态度 走到哪就遍历到那里 先走左边再走右边 比如上面的这个图 首先会从根节点开始:

<img src="https://s2.loli.net/2022/08/06/qCFMosHtujEZ3U6.png"/>

从A开始 先左后右 那么下一个就是B 然后继续走左边 是D 现在ABD走完之后 B的左边结束了 那么就要开始B的右边了 所以下一个是E E结束之后 现在A的左子树已经全部遍历完成了 然后就是右边 接着就是C C没有左子树了 那么只能走右边了 最后输出F 所以上面这个二叉树的前序遍历结果为: ABDECF

1. 打印根结点
2. 前序遍历左子树
3. 前序遍历右子树

我们不难发现规律 整棵二叉树(包括子树)的根结点一定是出现在最前面的 比如A在最前面 A的左子树根结点B也是在最前面的

接着我们来通过代码实现一下 首先先把咱们这棵二叉树组装好:

```c
                            int main() {
                                
                                Node a = malloc(sizeof(struct tree_node));
                                Node b = malloc(sizeof(struct tree_node));
                                Node c = malloc(sizeof(struct tree_node));
                                Node d = malloc(sizeof(struct tree_node));
                                Node e = malloc(sizeof(struct tree_node));
                                Node f = malloc(sizeof(struct tree_node));
                                a->element = 'A';
                                b->element = 'B';
                                c->element = 'C';
                                d->element = 'D';
                                e->element = 'E';
                                f->element = 'F';

                                a->left = b;
                                a->right = c;
                                b->left = d;
                                b->right = e;
                                c->right = f;
                                c->left = NULL;
                                d->left = e->right = NULL;
                                e->left = e->right = NULL;
                                f->left = f->right = NULL;
                                
                            }
```

组装好之后 我们来实现一下前序遍历的函数:

```c
                            void pre_order(Node root) { // 传入的是二叉树的根结点

                            }
```

那么现在我们拿到根结点之后该怎么去写呢? 既然是走到哪里打印到哪里 那么我们就先打印一下当前结点的值:

```c
                            void pre_order(Node root) {
                                printf("%c", root->element); // 不多bb先打印再说
                            }
```

打印完成之后 我们就按照先左后右的规则往后遍历下一个结点 这里我们就直接使用递归来完成:

```c
                            void pre_order(Node root) {
                                
                                printf("%c", root->element);
                                pre_order(root->left); // 将左孩子结点递归交给下一级
                                pre_order(root->right); // 等上面的一系列向左递归结束后 再以同样的方式去到右边
                                
                            }
```

不过还没结束 我们的递归肯定是需要一个终止条件的 不可能无限地进行下去 如果已经走到底了 那么就不能再往下走了 所以:

```c
                            void pre_order(Node root) {
                                
                                if (root == NULL) return; // 如果走到NULL了 那就表示已经到头了 直接返回
                                printf("%c", root->element);
                                pre_order(root->left);
                                pre_order(root->right);
                                
                            }
```

最后我们来测试一下吧:

```c
                            int main() {
                                
                               ...

                                pre_order(a);
                                
                            }
```

可以看到结果为:

<img src="https://s2.loli.net/2022/08/06/hZ8qEfWaP5o6L2j.png"/>

这样我们就通过一个简单的递归操作完成了对一棵二叉树的前序遍历 如果不太好理解 建议结合调试进行观察

当然也有非递归的写法 我们使用循环 但是就比较麻烦了 我们需要使用栈来帮助我们完成(实际上递归写法本质上也是在利用栈) 我们依然是从第一个结点开始 先走左边 每向下走一步 先输出节点的值 然后将对应的结点丢到栈中 当走到尽头时 表示左子树已经遍历完成 接着就是从栈中依次取出栈顶节点 如果栈顶结点有右子树 那么再按照同样的方式遍历其右子树 重复执行上述操作 直到栈清空为止

- 一路向左 不断入栈 直到尽头
- 到达尽头后 出栈 看看有没有右子树 如果没有就继续出栈 直到遇到有右子树的为止
- 拿到右子树后 从右子树开始 重复上述步骤 直到栈清空

比如我们还是以上面的这棵树为例:

<img src="https://s2.loli.net/2022/08/06/G6ujstSVZ2XWJLE.png"/>

首先我们依然从根结点A出发 不断遍历左子树 沿途打印结果并将结点丢进栈中:

<img src="https://s2.loli.net/2022/08/06/e1Nf5WhQdY9VGOD.png"/>

当遍历到D结点时 没有左子树了 此时将栈顶结点D出栈 发现没有右结点 继续出栈 得到B结点 接着得到当前结点的右孩子E结点 然后重复上述步骤:

<img src="https://s2.loli.net/2022/08/06/pZ6FRWn9wNg1JhY.png"/>

接着发现E也没有左子树了 同样的 又开始出栈 此时E没有右子树 接着看A A有右子树 所以继续从C开始 重复上述步骤:

<img src="https://s2.loli.net/2022/08/06/K73cGsRUP6WO5iu.png"/>

由于C之后没有左子树 那么就出栈获取右子树 此时得到结点F 继续重复上述步骤:

<img src="https://s2.loli.net/2022/08/06/zkZisVY9H2qAafL.png"/>

最后F出栈 没有右子树了 栈空 结束

按照这个思路 我们来编写一下程序吧:

```c
                            typedef char E;
                            struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                
                            };
                            typedef struct tree_node *Node;

                            // ------------- 栈 -------------------
                            typedef Node T; // 这里栈内元素类型定义为上面的Node 也就是二叉树结点指针
                            struct stack_node {
                                
                                T element;
                                struct stack_node *next;
                                
                            };
                            typedef struct stack_node *SNode; // 这里就命名为SNode 不然跟上面冲突了就不好了

                            void init_stack(SNode head) {
                                head->next = NULL;
                            }

                            _Bool push_stack(SNode head, T element) {
                                
                                SNode node = malloc(sizeof(struct stack_node));
                                if (node == NULL) return 0;
                                node->next = head->next;
                                node->element = element;
                                head->next = node;
                                return 1;
                                
                            }

                            _Bool is_empty(SNode head) {
                                return head->next == NULL;
                            }

                            T pop_stack(SNode head) {
                                
                                SNode top = head->next;
                                head->next = head->next->next;
                                T e = top->element;
                                free(top);
                                return e;
                                
                            }

                            // -------------------------------------

                            void pre_order(Node root) {
                                
                                struct stack_node stack; // 栈先搞出来
                                init_stack(&stack);
                                while (root || !is_empty(&stack)){ // 两个条件 只有当栈空并且节点为NULL时才终止循环
                                    while (root) { // 按照我们的思路 先不断遍历左子树 直到没有为止
                                        push_stack(&stack, root); // 途中每经过一个结点 就将结点丢进栈中
                                        printf("%c", root->element); // 然后打印当前结点元素值
                                        root = root->left; // 继续遍历下一个左孩子结点
                                    }
                                    root = pop_stack(&stack); // 经过前面的循环 明确左子树全部走完了 接着就是右子树了
                                    root = root->right; // 得到右孩子 如果有右孩子 下一轮会重复上面的步骤 如果没有右孩子那么这里的root就被赋值为NULL了 下一轮开始会直接跳过上面的while 继续出栈下一个结点再找右子树
                                }
                                
                            }
```

这样 我们就通过非递归的方式实现了前序遍历 可以看到代码是相当复杂的 也不推荐这样编写

那么前序遍历我们了解完了 接着就是中序遍历了 中序遍历在顺序上与前序遍历不同 前序遍历是走到哪就打印到哪 而中序遍历需要先完成整个左子树的遍历后再打印 然后再遍历其右子树

我们还是以上面的二叉树为例:

<img src="https://s2.loli.net/2022/08/06/W6Yb5M92gQApNJa.png"/>

首先需要先不断遍历左子树 走到最底部 但是沿途并不进行打印 而是到底之后 再打印 所以第一个打印的是D 接着由于没有右子树 所以我们回到B 此时再打印B 然后再去看B的右结点E 由于没有左子树和右子树了 所以直接打印E 左边遍历完成 接着回到A 打印 然后对A的右子树重复上述操作 所以说遍历的基本规则还是一样的 只是打印值的时机发生了改变

1. 中序遍历左子树
2. 打印结点
3. 中序遍历右子树

所以这棵二叉树的中序遍历结果为: DBEACF 我们可以发现一个规律 就是在某个结点的左子树中所有结点 其中序遍历结果也是按照这样的规律排列的 比如A的左子树中所有结点 中序遍历结果中全部都在A的左边 右子树中所有的结点 全部都在A的右边(这个规律很关键 后面在做一些算法题时会用到)

那么怎么才能将打印调整到左子树全部遍历结束之后呢? 其实很简单:

```c
                            void in_order(Node root) {
                                
                                if (root == NULL) return;
                                in_order(root->left); // 先完成全部左子树的遍历
                                printf("%c", root->element); // 等待左子树遍历完成之后再打印
                                in_order(root->right); // 然后就是对右子树进行遍历
                                
                            }
```

我们只需要将打印放到左子树遍历之后即可 这样打印出来的结果就是中序遍历的结果了:

<img src="https://s2.loli.net/2022/08/06/6Vx9fmSUcqw51Mp.png"/>

同样的 如果采用的是非递归 那么我也只需要稍微改动一个地方即可:

```c
                            ...

                            void in_order(Node root) {
                                
                                struct stack_node stack;
                                init_stack(&stack);
                                while (root || !is_empty(&stack)){ // 其他都不变
                                    while (root) {
                                        push_stack(&stack, root);
                                        root = root->left;
                                    }
                                    root = pop_stack(&stack);
                                    printf("%c", root->element); // 只需要将打印时机延后到左子树遍历完成
                                    root = root->right;
                                }
                                
                            }
```

这样 我们就实现了二叉树的中序遍历 实际上还是很好理解的

接着我们来看一下后序遍历 后序遍历继续将打印的时机延后 需要等待左右子树全部遍历完成 才会去进行打印

<img src="https://s2.loli.net/2022/08/06/YE2rODdqpCInUa9.png"/>

首先还是一路向左 到达结点D 此时结点D没有左子树了 接着看结点D还有没有右子树 发现也没有 左右子树全部遍历完成 那么此时再打印D 同样的 D完事之后就回到B了 此时接着看B的右子树 发现有结点E 重复上述操作 E也打印出来了 接着B的左右子树全部OK 那么再打印B 接着A的左子树就完事了 现在回到A 看到A的右子树 继续重复上述步骤 当A的右子树也遍历结束后 最后再打印A结点

1. 后序遍历左子树
2. 后序遍历右子树
3. 打印结点

所以最后的遍历顺序为: DEBFCA 不难发现 整棵二叉树(包括子树) 根结点一定是在后面的 比如A在所有的结点的后面 B在其子结点D, E的后面 这一点恰恰和前序遍历相反(注意不是得到的结果相反 是规律相反)

所以 按照这个思路 我们来编写一下后序遍历:

```c
                            void post_order(Node root) {
                                
                                if (root == NULL) return;
                                post_order(root->left);
                                post_order(root->right);
                                printf("%c", root->element); // 时机延迟到最后
                                
                            }
```

结果如下:

<img src="https://s2.loli.net/2022/08/06/6Vx9fmSUcqw51Mp.png"/>

不过难点来了 后序遍历使用非递归貌似写不了啊? 因为按照我们之前的思路 最多也就实现中序遍历 我们没办法在一次循环中得知右子树是否完成遍历 难点就在这里 那么我们就要想办法先让右子树完成遍历 由于一个结点需要左子树全部完成+右子树全部完成 而目前只能明确左子树完成了遍历(也就是内层while之后 左子树一定结束了) 所以我们可以不急着将结点出栈 而是等待其左右都完事了再出栈 这里我们需要稍微对结点的结构进行修改 添加一个标记变量 来表示已经完成左边还是左右都完成了:

```c
                            struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                int flag; // 需要经历左右子树都被遍历才行 这里用flag存一下状态 0表示左子树遍历完成 1表示右子树遍历完成
                                
                            };
```

```c
                            T peek_stack(SNode head) { // 这里新增一个peek操作 用于获取栈顶元素的值 但是不出栈 仅仅是值获取
                                return head->next->element;
                            }
```

```c
                            void post_order(Node root) {
                                
                                struct stack_node stack;
                                init_stack(&stack);
                                while (root || !is_empty(&stack)){ // 其他都不变
                                    while (root) {
                                        push_stack(&stack, root);
                                        root->flag = 0; // 首次入栈时 只能代表左子树遍历完成 所以flag置0
                                        root = root->left;
                                    }
                                    root = peek_stack(&stack); // 注意这里只是获取到结点 并没有进行出栈操作 因为需要等待右子树遍历完才能出栈
                                    if (root->flag == 0) { // 如果仅仅遍历了左子树 那么flag就等于0
                                        root->flag = 1; // 此时标记为1表示遍历右子树
                                        root = root->right; // 这里跟之前是一样的
                                    } else {
                                        printf("%c", root->element); // 当flag为1时走这边 此时左右都遍历完成了 这时再打印值出来
                                        pop_stack(&stack); // 这时再把对应的结点出栈 因为左右都完事了
                                        root = NULL; // 置为NULL 下一轮直接跳过while 然后继续取栈中剩余的结点 重复上述操作
                                    }
                                }
                                
                            }
```

所以 后序遍历的非递归写法的最大区别是将结点的出栈时机和打印时机都延后了

最后我们来看层序遍历 实际上这种遍历方式是我们人脑最容易理解的 它是按照每一层在进行遍历:

<img src="https://s2.loli.net/2022/08/07/ywF6r9MU1JSPIge.png"/>

层序遍历实际上就是按照从上往下每一层 从左到右的顺序打印每个结点 比如上面的这棵二叉树 那么层序遍历的结果就是: ABCDEF 像这样一层一层的挨个输出

虽然理解起来比较简单 但是如果让你编程写出来 该咋搞? 是不是感觉有点无从下手?

我们可以利用队列来实现层序遍历 首先将根结点存入队列中 接着循环执行以下步骤:

- 进行出队操作 得到一个结点 并打印结点的值
- 将此结点的左右孩子结点依次入队

不断重复以上步骤 直到队列为空

我们来分析一下 首先肯定一开始A在里面:

<img src="https://s2.loli.net/2022/08/07/ZsNpeVUivEjCymt.png"/>

接着开始不断重复上面的步骤 首先是将队首元素出队 打印A 然后将A的左右孩子依次入队:

<img src="https://s2.loli.net/2022/08/07/v8yXWNato3sfeUn.png"/>

现在队列中有B, C两个结点 继续重复上述操作 B先出队 打印B 然后将B的左右孩子依次入队:

<img src="https://s2.loli.net/2022/08/07/Qkprfi5RhAXP7Cd.png"/>

现在队列中有C, D, E这三个结点 继续重复 C出队并打印 然后将F入队:

<img src="https://s2.loli.net/2022/08/07/MxQTArlWK2gDjqi.png"/>

我们发现 这个过程中 打印的顺序正好就是我们层序遍历的顺序 所以说队列还是非常有用的

那么现在我们就来上代码吧:

```c
                            typedef char E;
                            struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                int flag;
                                
                            };
                            typedef struct tree_node *Node;

                            // --------------- 队列 ----------------
                            typedef Node T; // 还是将Node作为元素
                            struct queue_node {
                                
                                T element;
                                struct queue_node *next;
                                
                            };
                            typedef struct queue_node *QNode;
                            struct Queue {
                                QNode front, rear;
                            };
                            typedef struct Queue *inked_queue;

                            _Bool init_queue(linked_queue queue) {
                                
                                QNode node = malloc(sizeof(struct queue_node));
                                if (node == NULL) return 0;
                                queue->front = queue->rear = node;
                                return 1;
                                
                            }

                            _Bool offer_queue(linked_queue queue, T element) {
                                
                                QNode node = malloc(sizeof(struct queue_node));
                                if (node == NULL) return 0;
                                node->element = element;
                                queue->rear->next = node;
                                queue->rear = node;
                                return 1;
                                
                            }

                            _Bool is_empty(linked_queue queue) {
                                return queue->front == queue->rear;
                            }

                            T poll_queue(linked_queue queue) {
                                
                                T e = queue->front->next->element;
                                QNode node = queue->front->next;
                                queue->front->next = queue->front->next->next;
                                if (queue->rear == node) queue->rear = queue->front;
                                free(node);
                                return e;
                                
                            }
                            //--------------------------------

                            void level_order(Node root) {
                                
                                struct Queue queue; // 先搞一个队列
                                init_queue(&queue);
                                offer_queue(&queue, root); // 先把根结点入队
                                
                                while (!is_empty(&queue)) {  // 不断重复 直到队列空为止
                                    Node node = poll_queue(&queue); // 出队一个元素 打印值
                                    printf("%c", node->element);
                                    if (node->left) // 如果存在左右孩子的话
                                        offer_queue(&queue, node->left); // 记得将左右孩子入队 注意顺序 先左后右
                                    if (node->right)
                                        offer_queue(&queue, node->right);
                                }
                                
                            }
```

可以看到结果就是层序遍历的结果:

<img src="https://s2.loli.net/2022/08/07/YlUfDhPoQrg9TkB.png"/>

当然 使用递归也可以实现 但是需要单独存放结果然后单独输出 不是很方便 所以说这里就不演示了

**二叉树练习题:**

1. 现在有一棵二叉树前序遍历结果为: ABCDE 中序遍历结果为: BADCE 那么请问该二叉树的后序遍历结果为?

2. 对二叉树的结点从1开始连续进行编号 要求每个结点的编号大于其左右孩子的编号 那么请问需要采用哪种遍历方式来实现?

   A. 前序遍历

   B. 中序遍历

   **C. 后序遍历**

   D. 层序遍历

### 高级树结构

高级树结构是对树结构的延伸扩展 有着特殊的定义和性质 在编写上可能会比较复杂 所以这一部分对于那些太过复杂的结构 就不进行代码编写了 只进行理论讲解

#### 线索化二叉树

前面我们学习了二叉树 我们知道一棵二叉树实际上可以由多个结点组成 每个结点都有一个左右指针 指向其左右孩 我们在最后也讲解了二叉树的遍历 包括前序, 中序, 后序以及层序遍历 只不过在遍历时实在是太麻烦了 我们需要借助栈来帮助我们完成这项遍历操作

实际上我们发现 一棵二叉树的某些结点会存在NULL的情况 我们可以利用这些为NULL的指针 将其线索化为某一种顺序遍历的指向下一个按顺序的结点的指针 这样我们在进行遍历的时候 就会很方便了

例如 一棵二叉树的前序遍历顺序如下:

<img src="https://s2.loli.net/2022/08/14/ZRjFywa6kWHrbJY.png"/>

我们就可以将其进行线索化 首先还是按照前序遍历的顺序依次寻找:

<img src="https://s2.loli.net/2022/08/14/Wu954jeLJhbxXDr.png"/>

线索化的规则为:

- 结点的左指针 指向其当前遍历顺序的前驱结点
- 结点的右指针 指向其当前遍历顺序的后继结点

所以在线索化之后 G的指向情况如下:

<img src="https://s2.loli.net/2022/08/14/ExhJStz4eMoCRF1.png"/>

这样 G原本两个为NULL的指针就被我们利用起来了 但是现在有一个问题 我们怎么知道 某个结点的指针到底是指向的其左右孩子 还是说某种遍历顺序下的前驱或是后继结点呢? 所以 我们还需要分别为左右添加一个标志位 来表示左右指针到底指向的是孩子还是遍历线索:

```c
                            typedef char E;
                            typedef struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                int leftTag, rightTag; // 标志位 如果为1表示这一边指针指向的是线索 不为1就是正常的孩子结点
                                
                            } *Node;		
```

接着是H结点 同样的 因为H结点的左右指针都是NULL 那么我们也可以将其线索化:

<img src="https://s2.loli.net/2022/08/14/pVo6FHquyBWmS7f.png"/>

接着我们来看结点E 这个结点只有一个右孩子 没有左孩子 左孩子指针为NULL 我们也可以将其线索化:

<img src="https://s2.loli.net/2022/08/14/2nUPAuVOvcQKw7L.png"/>

最后 整棵二叉树完成线索化之后 除了遍历顺序的最后一个结点没有后续之外 其他为NULL的指针都被利用起来了:

<img src="https://s2.loli.net/2022/08/14/SpWPAbzXRFcOgZJ.png"/>

我们可以发现 在利用上那些为NULL的指针之后 当我们再次进行前序遍历时 我们不需要再借助栈了 而是可以一路向前

这里我们弄一个简单一点的线索化二叉树 来尝试对其进行遍历:

<img src="https://s2.loli.net/2022/08/14/E1YyemquOdasTRi.png"/>

首先我们要对这棵二叉树进行线索化 将其变成一棵线索化二叉树:

```c
                            Node create_node(E element) { // 单独写了个函数来创建结点
                                
                                Node node = malloc(sizeof(struct tree_node));
                                node->left = node->right = NULL;
                                node->rightTag = node->leftTag = 0;
                                node->element = element;
                                return node;
                                
                            }

                            int main() {
                                
                                Node a = create_node('A');
                                Node b = create_node('B');
                                Node c = create_node('C');
                                Node d = create_node('D');
                                Node e = create_node('E');

                                a->left = b;
                                b->left = d;
                                a->right = c;
                                b->right = e;
                                
                            }
```

实际上要将其进行线索化 我们只需要正常按照对应的遍历顺序进行即可 不过在遍历过程中需要留意那些存在空指针的结点 我们需要修改其指针的指向:

```c
                            void pre_order_Threaded(Node root) { // 前序遍历线索化函数
                                
                                if (root == NULL) return;
                                // 别急着写打印
                                pre_order_Threaded(root->left);
                                pre_order_Threaded(root->right);
                                
                            }
```

首先还是老规矩 先把前序遍历写出来 然后我们需要进行判断 如果存在指针指向为NULL 那么就将其线索化:

```c
                            Node pre = NULL; // 这里我们需要一个pre来保存后续结点的指向

                            void pre_order_Threaded(Node root) { // 前序遍历线索化函数
                                
                                if (root == NULL) return;

                                if (root->left == NULL) { // 首先判断当前结点左边是否为NULL 如果是 那么指向上一个结点
                                    root->left = pre;
                                    root->leftTag = 1; // 记得修改标记
                                }
                                if (pre && pre->right == NULL) { // 然后是判断上一个结点的右边是否为NULL 如果是那么进行线索化 指向当前结点
                                    pre->right = root;
                                    pre->rightTag = 1; // 记得修改标记
                                }

                                pre = root; // 每遍历完一个 需要更新一下pre 表示上一个遍历的结点

                                if (root->leftTag == 0) // 注意只有标志位是0才可以继续向下 否则就是线索了
                                    pre_order_Threaded(root->left);
                                if (root->rightTag == 0)
                                    pre_order_Threaded(root->right);
                                
                            }
```

这样 在我们进行二叉树的遍历时 会自动将其线索化 线索化完成之后就是一棵线索化二叉树了

<img src="https://s2.loli.net/2022/08/14/kxhAsiWCSYMdB7q.png"/>

可以看到结点D的左右标记都是1 说明都被线索化了 并且D的左边指向的是其前一个结点B 右边指向的是后一个结点E 这样我们就成功将其线索化了

现在我们成功得到了一棵线索化之后的二叉树 那么怎么对其进行遍历呢? 我们只需要一个简单的循环就可以了:

```c
                            void pre_order(Node root) { // 前序遍历一棵线索化二叉树非常简单
                                
                                while (root) { // 到头为止
                                    printf("%c", root->element); // 因为是前序遍历 所以直接按顺序打印就行了
                                    if (root->leftTag == 0) 
                                        root = root->left; // 如果是左孩子 那么就走左边
                                    else
                                        root = root->right; // 如果左边指向的不是孩子 而是线索 那么就直接走右边 因为右边无论是线索还是孩子 都要往这边走了
                                }
                                
                            }
```

我们接着来看看中序遍历的线索化二叉树 整个线索化过程我们只需要稍微调整位置就行了:

```c
                            Node pre = NULL; // 这里我们需要一个pre来保存后续结点的指向

                            void in_order_threaded(Node root) { // 前序遍历线索化函数
                                
                                if (root == NULL) return;
                                if (root->leftTag == 0)
                                    in_order_threaded(root->left);

                                // ------  线索化 -------  现在放到中间去 其他的还是一样的
                                if (root->left == NULL) {
                                    root->left = pre;
                                    root->leftTag = 1;
                                }
                                if (pre && pre->right == NULL) {
                                    pre->right = root;
                                    pre->rightTag = 1;
                                }
                                pre = root;
                                // --------------------

                                if (root->rightTag == 0)
                                    in_order_threaded(root->right);
                                
                            }
```

最后我们线索化完成之后 长这样了:

<img src="https://s2.loli.net/2022/08/14/tsEJLRFCYVaTOP8.png"/>

那么像这样的一棵树 我们怎么对其进行遍历呢? 中序遍历要稍微麻烦一些:

```c
                            void in_order(Node root) {
                                
                                while (root) { // 因为中序遍历需要先完成左边 所以说要先走到最左边才行
                                    while (root && root->leftTag == 0) // 如果左边一直都不是线索 那么就一直往左找 直到找到一个左边是线索的为止 表示到头了
                                        root = root->left;

                                    printf("%c", root->element); // 到最左边了再打印 中序开始

                                    while (root && root->rightTag == 1) { // 打印完就该右边了 右边如果是线索化之后的结果 表示是下一个结点 那么就一路向前 直到不是为止
                                        root = root->right;
                                        printf("%c", root->element); // 注意按着线索往下就是中序的结果 所以说沿途需要打印
                                    }
                                    root = root->right; // 最后继续从右结点开始 重复上述操作
                                }
                                
                            }
```

最后我们来看看后序遍历的线索化 同样的 我们只需要在线索化时修改为后序就行了

```c
                            Node pre = NULL; // 这里我们需要一个pre来保存后续结点的指向

                            void in_order_threaded(Node root) { // 前序遍历线索化函数
                                
                                if (root == NULL) return;
                                
                                if (root->leftTag == 0)
                                    in_order_threaded(root->left);
                                if (root->rightTag == 0)
                                    in_order_threaded(root->right);
                                // ------  线索化 -------   现在这一坨移到最后 就是后序遍历的线索化了
                                if (root->left == NULL) {
                                    root->left = pre;
                                    root->leftTag = 1;
                                }
                                if (pre && pre->right == NULL) {
                                    pre->right = root;
                                    pre->rightTag = 1;
                                }
                                pre = root;
                                // --------------------
                                
                            }
```

线索化完成之后 变成一颗后续线索化二叉树:

<img src="https://s2.loli.net/2022/08/14/Smqt1UKjeWXFRPu.png"/>

后序遍历的结果看起来有点怪怪的 但是这就是后序 那么怎么对这棵线索化二叉树进行后续遍历呢? 这就比较复杂了 首先后续遍历需要先完成左右 左边还好说 关键是右边 右边完事之后我们并不一定能找到对应子树的根结点 比如我们按照上面的线索 先从D开始 根据线索找到E 然后继续跟据线索找到B 但是此时B无法找到其兄弟结点C 所以说这样是行不通的 因此要完成后续遍历 我们只能对结点进行改造:

```c
                            typedef struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                struct tree_node *parent; // 指向双亲(父)结点
                                int leftTag, rightTag;
                                
                            } *Node;

```

现在每个结点都保存其父结点 这样就可以顺利地找上去了 现在我们来编写一下吧:

```c
                            Node pre = NULL; // 这里我们需要一个pre来保存后续结点的指向

                            void post_order_threaded(Node root){ // 前序遍历线索化函数
                                
                                if (root == NULL) return;
                                
                                if (root->leftTag == 0) {
                                    post_order_threaded(root->left);
                                    if (root->left) root->left->parent = root; // 左边完事之后 如果不为空 那么就设定父子关系
                                }
                                if (root->rightTag == 0) {
                                    post_order_threaded(root->right);
                                    if (root->right) root->right->parent = root; // 右边完事之后 如果不为空 那么就设定父子关系
                                }
                                
                                // ------  线索化 -------
                                if (root->left == NULL) {
                                    root->left = pre;
                                    root->leftTag = 1;
                                }
                                if (pre && pre->right == NULL) {
                                    pre->right = root;
                                    pre->rightTag = 1;
                                }
                                pre = root;
                                // --------------------
                                
                            }
```

后序遍历代码如下:

```c
                            void post_order(Node root) {
                                
                                Node last = NULL, node = root; // 这里需要两个暂存指针 一个记录上一次遍历的结点 还有一个从root开始
                                while (node) {
                                    while (node->left != last && node->leftTag == 0) // 依然是从整棵树最左边结点开始 和前面一样 只不过这里加入了防无限循环机制 看到下面就知道了
                                        node = node->left;
                                    while (node && node->rightTag == 1) { // 左边完了还有右边 如果右边是线索 那么直接一路向前 也是跟前面一样的
                                        printf("%c", node->element); // 沿途打印
                                        last = node;
                                        node = node->right;
                                    }
                                    if (node == root && node->right == last) {
                                        // 上面的操作完成之后 那么当前结点左右就结束了 此时就要去寻找其兄弟结点了 我们可以
                                        // 直接通过parent拿到兄弟结点 但是如果当前结点是根结点 需要特殊处理 因为根结点没有父结点了
                                        printf("%c", node->element);
                                        return; // 根节点一定是最后一个 所以说直接返回就完事
                                    }
                                    while (node && node->right == last) { // 如果当前结点的右孩子就是上一个遍历的结点 那么一直向前就行
                                        printf("%c", node->element); // 直接打印当前结点
                                        last = node;
                                        node = node->parent;
                                    }
                                    // 到这里只有一种情况了 是从左子树上来的 那么当前结点的右边要么是线索要么是右子树 所以直接向右就完事
                                    if (node && node->rightTag == 0) { // 如果不是线索 那就先走右边 如果是 等到下一轮再说
                                        node = node->right;
                                    }
                                }
                                
                            }
```

至此 有关线索化二叉树 我们就了解到这样

#### 二叉查找树

还记得我们开篇讲到的二分搜索算法吗? 通过不断缩小查找范围 最终我们可以以很高的效率找到有序数组中的目标位置 而二叉查找树则利用了类似的思想 我们可以借助其来像二分搜索那样快速查找

**二叉查找树**也叫二叉搜索树或是二叉排序树 它具有一定的规则:

- 左子树中所有结点的值 均小于其根结点的值
- 右子树中所有结点的值 均大于其根结点的值
- 二叉搜索树的子树也是二叉搜索树

一棵二叉搜索树长这样:

<img src="https://s2.loli.net/2022/08/14/k9G7Ad2cqezgEtJ.png"/>

这棵树的根结点为18 而其根结点左边子树的根结点为10 包括后续结点 都是满足上述要求的 二叉查找树满足左边一定比当前结点小 右边一定比当前结点大的规则 比如我们现在需要在这颗树种查找值为15的结点:

1. 从根节点18开始 因为15小于18 所以从左边开始找
2. 接着来到10 发现10比15小 所以继续往右边走
3. 来到15 成功找到

实际上 我们在对普通二叉树进行搜索时 可能需要挨个进行查看比较 而有了二叉搜索树 查找效率就大大提升了 它就像我们前面的二分搜索那样

因为二叉搜索树要求比较严格 所以我们在插入结点时需要遵循一些规律 这里我们来尝试编写一下:

```c
                            #include <stdio.h>
                            #include <stdlib.h>

                            typedef int E;
                            typedef struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                
                            } *Node;

                            Node create_node(E element) {
                                
                                Node node = malloc(sizeof(struct tree_node));
                                node->left = node->right = NULL;
                                node->element = element;
                                return node;
                                
                            }

                            int main() {

                            }
```

我们就以上面这颗二叉查找树为例 现在我们想要依次插入这些结点 我们需要编写一个特殊的插入操作 这里需要注意一下 二叉查找树不能插入重复元素 如果出现重复直接忽略:

```c
                            Node insert(Node root, E element) {
                                
                                if (root) {
                                    if (root->element > element) // 如果插入结点值小于当前结点 那么说明应该放到左边去
                                        root->left = insert(root->left, element);
                                    else if (root->element < element) // 如果插入结点值大于当前结点 那么说明应该放到右边去
                                        root->right = insert(root->right, element);
                                } else { // 当结点为空时 说明已经找到插入的位置了 创建对应结点
                                    root = create_node(element);
                                }
                                return root; // 返回当前结点
                                
                            }
```

这样我们就可以通过不断插入创建一棵二叉查找树了:

```c
                            void in_order(Node root) {
                                
                                if (root == NULL) return;
                                in_order(root->left);
                                printf("%d ", root->element);
                                in_order(root->right);
                                
                            }

                            int main() {
                                
                                Node root = insert(NULL, 18); // 插入后 得到根结点
                                in_order(root); // 用中序遍历查看一下结果
                                
                            }
```

我们按照顺序来 首先是根结点的左右孩子 分别是10和20 那么这里我们就依次插入一下:

```c
                            int main() {
                                
                                Node root = insert(NULL, 18); // 插入后 得到根结点
                                insert(root, 10);
                                insert(root, 20);
                                in_order(root);
                                
                            }
```

可以看到中序结果为:

<img src="https://s2.loli.net/2022/08/15/FlLRBprEezot5Z8.png"/>

比18小的结点在左边 大的在右边 满足二叉查找树的性质 接着是7, 15, 22:

<img src="https://s2.loli.net/2022/08/15/chEUaOBzCTl4N8G.png"/>

最后再插入9就是我们上面的这棵二叉查找树了 当然我们直接写成控制台扫描的形式 就更方便了:

```c
                            int main() {
                                
                                Node root = NULL;
                                while (1) {
                                    E element;
                                    scanf("%d", &element);
                                    root = insert(root, element);
                                    in_order(root);
                                    putchar('\n');
                                }
                                
                            }
```

那么插入写好之后 我们怎么找到对应的结点呢? 实际上也是按照规律来就行了:

```c
                            Node find(Node root, E target) {
                                
                                while (root) {
                                    if (root->element > target) // 如果要找的值比当前结点小 说明肯定在左边
                                        root = root->left;
                                    else if (root->element < target) // 如果要找的值比当前结点大 说明肯定在右边
                                        root = root->right;
                                    else
                                        return root; // 等于的话 说明找到了 就直接返回
                                }
                                return NULL; // 都找到底了还没有 那就是真没有了
                                
                            }

                            Node find_max(Node root) { // 查找最大值就更简单了 最右边的一定是最大的
                                
                                while (root && root->right) 
                                    root = root->right;
                                return root;
                                
                            }
```

我们来尝试查找一下:

```c
                            int main() {
                                
                                Node root = insert(NULL, 18); // 插入后 得到根结点
                                insert(root, 10);
                                insert(root, 20);
                                insert(root, 7);
                                insert(root, 15);
                                insert(root, 22);
                                insert(root, 9);

                                printf("%p\n", find(root, 17));
                                printf("%p\n", find(root, 9));
                                
                            }
```

<img src="https://s2.loli.net/2022/08/15/lFOaUphkbB3wxIC.png"/>

搜索17的结果为NULL 说明没有这个结点 而9则成功找到了

最后我们来看看二叉查找树的删除操作 这个操作就比较麻烦了 因为可能会出现下面的几种情况:

1. 要删除的结点是叶子结点
2. 要删除的结点只有一个孩子结点
3. 要删除的结点有两个孩子结点

首先我们来看第一种情况 这种情况实际上最好办 直接删除就完事了:

<img src="https://s2.loli.net/2022/08/15/7RWkPXh6po2HjNz.png"/>

而第二种情况 就有点麻烦了 因为有一个孩子 就像一个拖油瓶一样 你离开了还不行 你还得对他负责才可以 当移除后 需要将孩子结点连接上去:

<img src="https://s2.loli.net/2022/08/15/4IZVf3SaCugD8Qc.png"/>

可以看到在调整后 依然满足二叉查找树的性质 最后是最麻烦的有两个孩子的情况 这种该怎么办呢? 前面只有一个孩子直接上位就完事 但是现在两个孩子 到底谁上位呢? 这就不好办了 为了保持二叉查找树的性质 现在有两种选择:

1. 选取其左子树中最大结点上位
2. 选择其右子树中最小结点上位

这里我们以第一种方式为例:

<img src="https://s2.loli.net/2022/08/15/jPRG68tru4bvIFa.png"/>

现在我们已经分析完三种情况了 那么我们就来编写一下代码吧:

```c
                            Node delete(Node root, E target) {
                                
                                if (root == NULL) return NULL; // 都走到底了还是没有找到要删除的结点 说明没有 直接返回空
                                if (root->element > target) // 这里的判断跟之前插入是一样的 继续往后找就完事 直到找到为止
                                    root->left = delete(root->left, target);
                                else if (root->element < target)
                                    root->right = delete(root->right, target);
                                else { // 这种情况就是找到了
                                    if (root->left && root->right) {   // 先处理最麻烦的左右孩子都有的情况
                                        Node max = find_max(root->left);  // 寻找左子树中最大的元素
                                        root->element = max->element; // 找到后将值替换
                                        root->left = delete(root->left, root->element); // 替换好后 以同样的方式去删除那个替换上来的结点
                                    } else { // 其他两种情况可以一起处理 只需要删除这个结点就行 然后将root指定为其中一个孩子 最后返回就完事
                                        Node tmp = root;
                                        if (root->right) { // 不是左边就是右边
                                            root = root->right;
                                        } else {
                                            root = root->left;
                                        }
                                        free(tmp); // 开删
                                    }
                                }
                                return root; // 返回最终的结点
                                
                            }
```

这样 我们就完成了二叉查找树的各种操作 当然目前为止我们了解的二叉树高级结构还比较简单 后面就开始慢慢复杂起来了

#### 平衡二叉树

前面我们介绍了二叉查找树 利用二叉查找树 我们在搜索某个值的时候 效率会得到巨大提升 但是虽然看起来比较完美 也是存在缺陷的 比如现在我们依次将下面的值插入到这棵二叉树中:

```
20 15 13 8 6 3
```

在插入完成后 我们会发现这棵二叉树竟然长这样:

<img src="https://s2.loli.net/2022/08/15/E1Pf2pGv4b9Lj7t.png"/>

因为根据我们之前编写的插入规则 小的一律往左边放 现在正好来的就是这样一串递减的数字 最后就组成了这样的一棵只有一边的二叉树 这种情况 与其说它是一棵二叉树 不如说就是一个链表 如果这时我们想要查找某个结点 那么实际上查找的时间并没有得到任何优化 直接就退化成线性查找了

所以 二叉查找树只有在理想情况下 查找效率才是最高的 而像这种极端情况 就性能而言几乎没有任何的提升 我们理想情况下 这样的效率是最高的:

<img src="https://s2.loli.net/2022/08/15/k1jzXPoOMp9caHy.png"/>

所以 我们在进行结点插入时 需要尽可能地避免这种一边倒的情况 这里就需要引入**平衡二叉树**的概念了 实际上我们发现 在插入时如果不去维护二叉树的平衡 某一边只会无限制地延伸下去 出现极度不平衡的情况 而我们理想中的二叉查找树左右是尽可能保持平衡的 **平衡二叉树**(AVL树)就是为了解决这样的问题而生的

它的性质如下:

- 平衡二叉树一定是一棵二叉查找树
- 任意结点的左右子树也是一棵平衡二叉树
- 从根结点开始 左右子树都高度差不能超过1 否则视为不平衡

可以看到 这些性质规定了平衡二叉树需要保持高度平衡 这样我们的查找效率才不会因为数据的插入而出现降低的情况 二叉树上结点的左子树高度减去右子树高度  得到的结果称为该结点的**平衡因子**(Balance Factor) 比如:

<img src="https://s2.loli.net/2022/08/15/vaI9qji1KYOP8kt.png"/>

通过计算平衡因子 我们就可以快速得到是否出现失衡的情况 比如下面的这棵二叉树 正在执行插入操作:

<img src="https://s2.loli.net/2022/08/15/DMnPqGhawy5Z92V.png"/>

根据插入结点的不同偏向情况 分为LL型, LR型, RR型, RL型 针对于上面这几种情况 我们依次来看一下如何进行调整 使得这棵二叉树能够继续保持平衡:

动画网站: https://www.cs.usfca.edu/~galles/visualization/AVLtree.html (实在不理解可以看看动画是怎么走的)

1. **LL型调整** (右旋)	<img src="https://s2.loli.net/2022/08/15/KqBaWLJwOj34Ec8.png"/>

   首先我们来看这种情况 这是典型的LL型失衡 为了能够保证二叉树的平衡 我们需要将其进行**旋转**来维持平衡 去纠正最小不平衡子树即可 那么怎么进行旋转呢? 对于LL型失衡 我们只需要进行右旋操作 首先我们先找到最小不平衡子树 注意是最小的那一个:

   <img src="https://s2.loli.net/2022/08/15/q4aYvzrnjdTgAtK.png"/>

   可以看到根结点的平衡因子是2 是目前最小的出现不平衡的点 所以说从根结点开始向左的三个结点需要进行右旋操作 右旋需要将这三个结点中间的结点作为新的根结点 而其他两个结点现在变成左右子树:

   <img src="https://s2.loli.net/2022/08/15/fJKz3FWclm9orVT.png"/>

   这样 我们就完成了右旋操作 可以看到右旋之后 所有的结点继续保持平衡 并且依然是一棵二叉查找树

2. **RR型调整** (左旋)

   前面我们介绍了LL型以及右旋解决方案 相反的 当遇到RR型时 我们只需要进行左旋操作即可:

   <img src="https://s2.loli.net/2022/08/15/kIl8ZT6Psr7mNSg.png"/>

   操作和上面是一样的 只不过现在反过来了而已:

   <img src="https://s2.loli.net/2022/08/15/LB9DOJpyIlxQWTm.png"/>

   这样 我们就完成了左旋操作 使得这棵二叉树继续保持平衡状态了

3. **RL型调整** (先右旋 再左旋)

   剩下两种类型比较麻烦 需要旋转两次才行 我们来看看RL型长啥样:

   <img src="https://s2.loli.net/2022/08/15/fwcrEIgBxWLVGXs.png"/>

   可以看到现在的形状是一个回旋镖形状的 先右后左的一个状态 也就是RL型 针对于这种情况 我们需要先进行右旋操作 注意这里的右旋操作针对的是后两个结点:

   <img src="https://s2.loli.net/2022/08/15/ukK6C4PNBwoaJbc.png"/>

   其中右旋和左旋的操作 与之前一样 该怎么分配左右子树就怎么分配 完成两次旋转后 可以看到二叉树重新变回了平衡状态

4. **LR型调整** (先左旋 再右旋)

   和上面一样 我们来看看LR型长啥样 其实就是反着的:

   <img src="https://s2.loli.net/2022/08/15/6Cj8VlgGekULXvP.png"/>

   形状是先向左再向右 这就是典型的LR型了 我们同样需要对其进行两次旋转:

   <img src="https://s2.loli.net/2022/08/15/y6WscFPxHuzTiaI.png"/>

   这里我们先进行的是左旋 然后再进行的右旋 这样二叉树就能继续保持平衡了

这样 我们只需要在插入结点时注意维护整棵树的平衡因子 保证其处于稳定状态 这样就可以让这棵树一直处于高度平衡的状态 不会再退化了 这里我们就编写一个插入结点代码来实现一下吧 首先还是结点定义:

```c
                            typedef int E;

                            typedef struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                int height; // 每个结点需要记录当前子树的高度 便于计算平衡因子
                                
                            } *Node;

                            Node create_node(E element) {
                                
                                Node node = malloc(sizeof(struct tree_node));
                                node->left = node->right = NULL;
                                node->element = element;
                                node->height = 1; // 初始化时 高度写为1就可以了
                                return node;
                                
                            }
```

接着我们需要先将左旋, 右旋等操作编写出来 因为一会插入时可能需要用到:

```c
                            int max(int a, int b) {
                                return a > b ? a : b;
                            }

                            int get_height(Node root) {
                                
                                if (root == NULL) return 0;
                                return root->height;
                                
                            }

                            Node left_rotation(Node root) { // 左旋操作 实际上就是把左边结点拿上来
                                
                                Node new_root = root->right; // 先得到左边结点
                                root->right = new_root->left; // 将左边结点的左子树丢到原本根结点的右边去
                                new_root->left = root; // 现在新的根结点左边就是原本的跟结点了

                                root->height = max(get_height(root->right), get_height(root->left)) + 1;
                                new_root->height = max(get_height(new_root->right), get_height(new_root->left)) + 1;
                                return new_root;
                                
                            }

                            Node right_rotation(Node root) {
                                
                                Node new_root = root->left;
                                root->left = new_root->right;
                                new_root->right = root;

                                root->height = max(get_height(root->right), get_height(root->left)) + 1;
                                new_root->height = max(get_height(new_root->right), get_height(new_root->left)) + 1;
                                return new_root;
                                
                            }

                            Node left_right_rotation(Node root) {
                                
                                root->left = left_rotation(root->left);
                                return right_rotation(root);
                                
                            }

                            Node right_left_rightRotation(Node root) {
                                
                                root->right = right_rotation(root->right);
                                return left_rotation(root);
                                
                            }
```

最后就是我们的插入操作了 注意在插入时动态计算树的高度 一旦发现不平衡 那么就立即采取对应措施:

```c
                            Node insert(Node root, E element) {
                                
                                if (root == NULL) { // 如果结点为NULL 说明找到了插入位置 直接创建新的就完事
                                    root = create_node(element);
                                } else if (root->element > element) { // 和二叉搜索树一样 判断大小 该走哪边走哪边 直到找到对应插入位置
                                    root->left = insert(root->left, element);
                                    if (get_height(root->left) - get_height(root->right) > 1) { // 插入完成之后 需要计算平衡因子 看看是否失衡
                                        if (root->left->element > element) // 接着需要判断一下是插入了左子树的左边还是右边 如果是左边那边说明是LL 如果是右边那说明是LR
                                            root = right_rotation(root); // LL型得到左旋之后的结果 得到新的根结点
                                        else
                                            root = left_right_rotation(root); // LR型得到先左旋再右旋之后的结果 得到新的根结点
                                    }
                                } else if (root->element < element){
                                    root->right = insert(root->right, element);
                                    if (get_height(root->left) - get_height(root->right) < -1){
                                        if (root->right->element < element)
                                            root = left_rotation(root);
                                        else
                                            root = right_left_rightRotation(root);
                                    }
                                }
                                // 前面的操作完成之后记得更新一下树高度
                                root->height = max(get_height(root->left), get_height(root->right)) + 1;
                                return root; // 最后返回root到上一级
                                
                            }
```

这样 我们就完成了平衡二叉树的插入操作 当然删除操作比较类似 也是需要在删除之后判断是否平衡 如果不平衡同样需要进行旋转操作 这里就不做演示了

#### 红黑树

**注意: **本小节内容作为选学内容 不强制要求掌握 很多人都说红黑树难 其实就那几条规则 跟着我推一遍其实还是很简单的 当然前提是一定要把前面的平衡二叉树搞明白

前面我们讲解了二叉平衡树 通过在插入结点时维护树的平衡 这样就不会出现极端情况使得整棵树的查找效率急剧降低了 但是这样是否开销太大了一点 因为一旦平衡因子的绝对值超过1那么就失衡 这样每插入一个结点 就有很大的概率会导致失衡 我们能否不这么严格 但同时也要在一定程度上保证平衡呢? 这就要提到红黑树了

在线动画网站: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

红黑树也是二叉查找树的一种 它大概长这样 可以看到结点有红有黑:

<img src="https://s2.loli.net/2022/08/15/t86B7sxvYeP9TiR.png"/>

它并不像平衡二叉树那样严格要求高度差不能超过1 而是只需要满足五个规则即可 它的规则如下:

- 规则1: 每个结点可以是黑色或是红色
- 规则2: 根结点一定是黑色
- 规则3: 红色结点的父结点和子结点不能为红色 也就是说不能有两个连续的红色
- 规则4: 所有的空结点都是黑色(空结点视为NIL 红黑树中是将空节点视为叶子结点)
- 规则5: 每个结点到空节点(NIL)路径上出现的黑色结点的个数都相等

它相比平衡二叉树 通过不严格平衡和改变颜色 就能在一定程度上减少旋转次数 这样的话对于整体性能是有一定提升的 只不过我们在插入结点时 就有点麻烦了 我们需要同时考虑变色和旋转这两个操作了 但是会比平衡二叉树更简单

那么什么时候需要变色 什么时候需要旋转呢? 我们通过一个简单例子来看看:

<img src="https://s2.loli.net/2022/08/16/wIj5qnhxFAHcyG7.png"/>

首先这棵红黑树只有一个根结点 因为根结点必须是黑色 所以说直接变成黑色 现在我们要插入一个新的结点了 所有新插入的结点 默认情况下都是红色:

<img src="https://s2.loli.net/2022/08/16/yHRXgbsvOM27xLr.png"/>

所以新来的结点7根据规则就直接放到11的左边就行了 然后注意7的左右两边都是NULL 那么默认都是黑色 这里就不画出来了 同样的 我们往右边也来一个:

<img src="https://s2.loli.net/2022/08/16/kJiA71fQuKHnIdb.png"/>

现在我们继续插入一个结点:

<img src="https://s2.loli.net/2022/08/16/VEQLu5mb1tcTyzd.png"/>

插入结点4之后 此时违反了红黑树的规则3 因为红色结点的父结点和子结点不能为红色 此时为了保持以红黑树的性质 我们就需要进行**颜色变换**才可以 那么怎么进行颜色变换呢? 我们只需要直接将父结点和其兄弟结点同时修改为黑色(为啥兄弟结点也需要变成黑色? 因为要满足性质5) 然后将爷爷结点改成红色即可:

<img src="https://s2.loli.net/2022/08/16/kuc1B3lqhNUwaSM.png"/>

当然这里还需注意一下 因为爷爷结点正常情况会变成红色 相当于新来了个红色的 这时还得继续往上看有没有破坏红黑树的规则才可以 直到没有为止 比如这里就破坏了性质一 爷爷结点现在是根结点(不是根结点就不需要管了) 必须是黑色 所以说还要给它改成黑色才算结束:

<img src="https://s2.loli.net/2022/08/16/dpRX5DGsfWVwnQi.png"/>

接着我们继续插入结点:

<img src="https://s2.loli.net/2022/08/16/4ZAhv7R9YusI8q6.png"/>

此时又来了一个插在4左边的结点 同样是连续红色 我们需要进行变色才可以讲解问题 但是我们发现 如果变色的话 那么从11开始到所有NIL结点经历的黑色结点数量就不对了:

<img src="https://s2.loli.net/2022/08/16/n3M6Kfsb4jHtIci.png"/>

所以说对于这种**父结点为红色 父结点的兄弟结点为黑色**(NIL视为黑色)的情况 变色无法解决问题了 那么我们只能考虑旋转了 旋转规则和我们之前讲解的平衡二叉树是一样的 这实际上是一种LL型失衡:

<img src="https://s2.loli.net/2022/08/16/POTaBfosmQiceWk.png"/>

同样的 如果遇到了LR型失衡 跟前面一样 先左旋在右旋 然后进行变色即可:

<img src="https://s2.loli.net/2022/08/16/XqFr7hJwe38AakK.png"/>

而RR型和RL型同理 这里就不进行演示了 可以看到 红黑树实际上也是通过颜色规则在进行旋转调整的 当然旋转和变色的操作顺序可以交换 所以 在插入时比较关键的判断点如下:

- 如果整棵树为NULL 直接作为根结点 变成黑色
- 如果父结点是黑色 直接插入就完事
- 如果父结点为红色 且父结点的兄弟结点也是红色 直接变色即可(但是注意得继续往上看有没有破坏之前的结构)
- 如果父结点为红色 但父结点的兄弟结点为黑色 需要先根据情况(LL, RR, LR, RL)进行旋转 然后再变色

在了解这些步骤之后 我们其实已经可以尝试去编写一棵红黑树出来了 当然代码太过复杂 这里就不演示了 其实红黑树难点并不在于如何构建和使用 而是在于 到底是怎么设计出来的 究竟要多么丰富的知识储备才能想到如此精妙的规则

红黑树的发明者:

> 红黑树(Red Black Tree)是一种自平衡二叉查找树 是在[计算机](https://zh.wikipedia.org/wiki/%E8%A8%88%E7%AE%97%E6%A9%9F)科学中用到的一种[数据结构](https://zh.wikipedia.org/wiki/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84) 典型的用途是实现[关联数组](https://zh.wikipedia.org/wiki/%E5%85%B3%E8%81%94%E6%95%B0%E7%BB%84)
>
> 红黑树是在1972年由[Rudolf Bayer](https://en.wikipedia.org/wiki/Rudolf_Bayer)发明的 当时被称为平衡二叉B树(symmetric binary B-trees) 后来 在1978年被 Leo J. Guibas 和 Robert Sedgewick 修改为如今的“红黑树”

在了解了后面的B树之后 相信我们就能揭开这层神秘面纱了

### 其他树结构

前面我们介绍了各种各样的二叉树 其实还是比较简单的 我们接着来看一下其他的一些树结构 这一部分我们只做了解即可

#### B树和B+树

前面我们介绍了多种多样的二叉树 有线索化二叉树, 平衡二叉树等等 这些改造版二叉树无疑都是为了提高我们的程序运行效率而生的 我们接着来看一种同样为了提升效率的树结构

这里首先介绍一下B树(Balance Tree) 它是专门为磁盘数据读取设计的一种度为 m 的查找树(多用于数据库) 它同样是一棵平衡树 但是不仅限于二叉了 之前我们介绍的这些的二叉树都是基于内存读取的优化 磁盘读取速度更慢 它同样需要优化 一棵度为4的(4阶) B树大概长这样:

<img src="https://s2.loli.net/2022/08/17/lH9YBVIASQJe26d.png"/>

第一眼看上去 感觉好像没啥头绪 不能发现啥规律 但是只要你仔细观察 你会发现 它和二叉查找树很相似 左边的一定比根节点小 右边的一定比根节点大 并且我们发现 每个结点现在可以保存多个值 每个结点可以连接多个子树 这些值两两组合划分了一些区间 比如60左边 一定是比60小的 60和80之间那么就是大于60小于80的值 以此类推 所以值有N个 就可以划分出N+1个区间 那么子树最多就可以有N+1个 它的详细规则如下:

1. 树中每个结点最多含有m个孩子(m >= 2) 比如上面就是m为4的4阶B树 最多有4个孩子
2. 除根结点和叶子结点外 其它每个结点至少有⌈m/2⌉个孩子 同理键值数量至少有⌈m/2⌉-1个
3. 若根结点不是叶子结点 则至少有2个孩子
4. 所有叶子结点都出现在同一层
5. 一个结点的包含多种信息(P0, K1, P1, K2，…, Kn, Pn) 其中P为指向子树的指针 K为键值(关键字)
   1. Ki (i=1...n)为键值 也就是每个结点保存的值 且键值按顺序升序排序K(i-1)< Ki
   2. Pi为指向子树的指针 且指针Pi指向的子树中所有结点的键值均小于Ki 但都大于K(i-1)
   3. 键值的个数n必须满足: ⌈m/2⌉-1 <= n <= m-1

在线动画网站: https://www.cs.usfca.edu/~galles/visualization/BTree.html

是不是感觉怎么要求这么多呢? 我们通过感受一下B树的插入和删除就知道了 首先是B树的插入操作 这里我们以度为3的B树为例:

<img src="https://s2.loli.net/2022/08/17/CqwaR1s2OyeIVLc.png"/>

插入1之后 只有一个结点 我们接着插入一个2 插入元素满足以下规则:

- 如果该结点上的元素数未满 则将新元素插入到该结点 并保持结点中元素的顺序

所以 直接放进去就行 注意顺序:

<img src="https://s2.loli.net/2022/08/17/HoamJkqwvP2ZlBb.png"/>

接着我们再插入一个3进去 但是此时因为度为3 那么键值最多只能有两个 肯定是装不下了:

- 如果该结点上的元素已经满 则需要将该节点平均地分裂成两个节点:
  1. 首先从该结点中的所有元素和新元素中先出一个中位数作为**分割值**
  2. 小于中位数的元素作为左子树划分出去 大于中位数的元素作为右子树划分
  3. 分割值此时上升到父结点中 如果没有父结点 那么就创建一个新的(这里的上升不太好理解 一会我们推过去就明白了)

所以 当3来了之后 直接进行分裂操作:

<img src="https://s2.loli.net/2022/08/17/aEJxSUlY1t6nVWM.png"/>

就像爱情一样 两个人的世界容不下第三者 如果来了第三者 那么最后的结果大概率就是各自分道扬镳 接着我们继续插入4, 5看看会发生什么 注意插入还是按照小的走左边 大的走右边的原则 跟我们之前的二叉查找树是一样的:

<img src="https://s2.loli.net/2022/08/17/Az8pmnsXvZaNl6q.png"/>

此时4, 5来到了右边 现在右边这个结点又被撑爆了 所以说需要按照上面的规则 继续进行分割:

<img src="https://s2.loli.net/2022/08/17/odNZMzeUGWQObtA.png"/>

可能各位看着有点奇怪 为啥变成这样了 首先3, 4, 5三个都分开了 然后4作为分割值 3, 5变成两个独立的树 此时4需要上升到父结点 所以直接跑到上面去了 然后3和5出现在4的左右两边 注意这里不是向下划分 反而有点向上划分的意思 为什么不向下划分呢? 因为要满足B树第四条规则: 所有叶子结点都出现在同一层

此时我们继续插入6, 7 看看会发生什么情况:

<img src="https://s2.loli.net/2022/08/17/U3ExLbOdD9tpAGW.png"/>

此时右下角结点又被挤爆了 右下角真是多灾多难啊 那么依然按照我们之前的操作进行分裂:

<img src="https://s2.loli.net/2022/08/17/nVFhBQoy7w195Sz.png"/>

我们发现当新的分割值上升之后最上面的结点又被挤爆了 此时我们需要继续分裂:

<img src="https://s2.loli.net/2022/08/17/kQJZDBbrgyHnac1.png"/>

在2, 4, 6中寻找一个新的分割值 分裂后将其上升到新的父结点中 就像上图那样了 在了解了B树的插入操作之后 是不是有一点感受到这种结构带来的便捷了?

我们再来看看B树的删除操作 这个要稍微麻烦一些 这里我们以一颗5阶B树为例 现在我们想删除16结点:

<img src="https://s2.loli.net/2022/08/17/VsiQvCfEJ92oLch.png"/>

删除后 依然满足B树的性质 所以说什么都不管用:

<img src="https://s2.loli.net/2022/08/17/CzTIN2GeREP7lVU.png"/>

此时我们接着去删除15结点:

<img src="https://s2.loli.net/2022/08/17/ypYEDR7gIL4fZ8X.png"/>

删除后 现在结点中只有14了 不满足B树的性质: 除根结点和叶子结点外 其它每个结点至少有⌈m/2⌉个孩子 同理键值数量至少有⌈m/2⌉-1个 现在只有一个肯定是不行的 此时我们需向兄弟(注意只能找左右两边的兄弟) 借一个过来:

<img src="https://s2.loli.net/2022/08/17/dZVwpNlRzKxHerA.png"/>

此时我们继续删掉17 但是兄弟已经没办法再借给我们一个元素了 此时只能采取方案二 合并兄弟节点与分割键 这里我们就合并左边的这个兄弟吧:

<img src="https://s2.loli.net/2022/08/17/wxhF2bJUHlEMGXW.png"/>

<img src="https://s2.loli.net/2022/08/17/Xp3l8AiDU6Bebwo.png"/>

现在他们三个又合并回去了 这下总满足了吧? 但是我们发现 父结点此时只有一个元素了 又出问题了 同样的 还是先去找兄弟结点借一个 但是兄弟结点也借不了了 此时继续采取我们的方案二 合并:

<img src="https://s2.loli.net/2022/08/17/E2RzTW5XOJjHdQm.png"/>

<img src="https://s2.loli.net/2022/08/17/E2RzTW5XOJjHdQm.png"/>

OK 这样才算是满足了B树的性质 现在我们继续删除4结点:

<img src="https://s2.loli.net/2022/08/17/TBrynM7Ge2lfz31.png"/>

这种情况会导致失去分割值 那么我们得找一个新的分割值才行 这里取左边最大的:

<img src="https://s2.loli.net/2022/08/17/pLZJNEyzHAVjfU4.png"/>

不过此时虽然解决了分割值的问题 但是新的问题来了 左边结点不满足性质了 元素数量低于限制 于是需要找兄弟结点借 但是没得借了 兄弟也没有多的可以借了所以被迫合并了:

<img src="https://s2.loli.net/2022/08/17/jhT5SNFXwq9niYk.png"/>

可以看到整个变换过程中 这颗B树所有子树的高度是一直维持在一个稳定状态的 查找效率能够持续保持

删除操作可以总结为两大类:

- 若删除的叶子结点中的元素:
  - 正常情况下直接删除
  - 如果删除后 键值数小于最小值 那么需要找兄弟借一个
  - 要是没得借了 直接跟兄弟结点 对应的分割值合并

- 若删除的是某个根结点中的元素:
  - 一般情况会删掉一个分割值 删掉后需要重新从左右子树中找一个新分割值的拿上来
  - 要是拿上来之后左右子树中出现键值数小于最小值的情况 那么就只能合并了

- 上述两个操作执行完后 还要继续往上看上面的结点是否依然满足性质 否则继续处理 直到稳定

在了解了B树的相关操作之后 是不是感觉还是挺简单的 依然是动态维护树的平衡 正是得益于B树这种结点少 高度平衡且有序的性质 而硬盘IO速度远低于内存 我们希望能够花费尽可能少的时间找到我们想要的数据 减少IO次数 B树就非常适合在硬盘上的保存数据 它的查找效率是非常高的

**注意: 以下内容为选学部分:**

此时此刻 我们回想一下之前提到的红黑树 我们来看看它和B树有什么渊源 这是一棵很普通的红黑树:

<img src="https://s2.loli.net/2022/08/17/XorTHWdJEt24Zci.png"/>

此时我们将所有红色节点上移到与父结点同一高度

<img src="https://s2.loli.net/2022/08/17/VkJmwZI8XFz9Yl2.png"/>

还是没看出来? 没关系 我们来挨个画个框:

<img src="https://s2.loli.net/2022/08/17/2TgcNMdztpOEXk6.png"/>

woc 这不就是B树吗? 没错 **红黑树**和**4阶B树**(2-3-4树)具有等价性 其中黑色结点就是中间的(黑色结点一定是父结点) 红色结点分别位于两边 通过将黑色结点与它的红色子节点融合在一起 形成1个B树节点 最后就像这样:

<img src="https://s2.loli.net/2022/08/17/MJiErSB4p856mjd.png"/>

你会发现 红黑树的黑色节点个数总是与4阶B树的节点数相等  我们可以对比一下之前的红黑树插入和4阶B树的插入 比如现在我们想要插入一个新的14结点进来:

<img src="https://s2.loli.net/2022/08/17/mNS8zRofZCM6quE.png"/>

经过变色 最后得到如下的红黑树 此时又出现两个红色结点连续 因为父结点的兄弟结点依然是红色 继续变色:

<img src="https://s2.loli.net/2022/08/17/DE5UTIkbdBvAoL9.png"/>

最后因为根结点必须是黑色 所以说将60变为黑色 这样就插入成功了:

<img src="https://s2.loli.net/2022/08/17/4nqCNJeFxQbmRGy.png"/>

我们再来看看与其等价的B树插入14后会怎么样:

<img src="https://s2.loli.net/2022/08/17/ltno5TuiHAb3QNj.png"/>

由于B树的左边被挤爆了 所以说需要分裂 因为是偶数个 需要选择中间偏右的那个数作为分割值 也就是25:

<img src="https://s2.loli.net/2022/08/17/jZ4EvWynm5aQelq.png"/>

分裂后 分割值上升 又把父结点给挤爆了 所以说需要继续分裂:

<img src="https://s2.loli.net/2022/08/17/7SRHOMucikbnml3.png"/>

现在就变成了这样 我们来对比一下红黑树:

<img src="https://s2.loli.net/2022/08/17/arxhpI1ytvq7wO9.png"/>

不能说很像 只能说是一模一样啊 为什么? 明明这两种树是不同的规则啊 为什么会出现等价的情况呢?

- B树叶节点等深实际上体现在红黑树中为任一叶节点到达根节点的路径中 黑色路径所占的长度是相等的 因为黑色结点就是B树的结点分割值
- B树节点的键值数量不能超过N实际上体现在红黑树约定相邻红色结点接最多2条 也就是说不可能出现B树中元素超过3的情况 因为是4阶B树

所以说红黑树跟4阶B树是有一定渊源的 甚至可以说它就是4阶B树的变体

前面我们介绍了B树 现在我们就可以利用B树来高效存储数据了 当然我们还可以让它的查找效率更高 这里我们就要提到B+树了 B+树是B树的一种变体 有着比B树更高的查询性能

1. 有k个子树的中间结点包含有k个元素(B树中是k-1个元素) 每个元素不保存数据 只用来索引 所有数据(卫星数据 就是具体需要保存的内容)都保存在叶子结点
2. 所有的叶子结点中包含了全部元素的信息 及指向含这些元素记录的指针 且叶子结点按照从小到大的顺序连接
3. 所有的根结点元素都同时存在于子结点中 在子节点元素中是最大(或最小)元素

我们来看看一棵B+树长啥样:

<img src="https://s2.loli.net/2022/08/17/C4utSmNvKPAaZ35.png"/>

其中最后一层形成了一个有序链表 在我们需要顺序查找时 提供了极大的帮助 可以看到现在除了最后一层之外 其他结点中存放的值仅仅充当了一个指路人的角色 来告诉你你需要的数据在哪一边 比如根节点有10和18 因为这里是取得最大值 那么整棵树最大的元素就是18了 我们现在需要寻找一个小于18大于10的数 就可以走右边去查找 而具体的数据会放到最下面的叶子结点中 比如数据库就是具体的某一行数据(卫星数据)存放在最下面:

<img src="https://s2.loli.net/2022/08/17/pW5SiDqmNY2PXfZ.png"/>

当然 目前可能你还没有接触过数据库 在以后的学习中 你一定会接触到它的 到时你就会发现新世界

它不像B树那样 B树并不是只有最后一行会存储卫星数据 此时比较凌乱 因为只有最后一行存储卫星数据 使用B+树 同样大小的磁盘页可以容纳更多的节点元素 这就意味着 数据量相同的情况下B+树比B树高度更低 减小磁盘IO的次数 其次 B+树的查询必须最终查找到叶子节点 而B树做的是值匹配 到达结点之后并不一定能够匹配成功 所以B树的查找性能并不稳定 最好的情况是只查根节点即可 而最坏的情况则需要查到叶子节点 但是B+树每一次查找都是稳定的 因为一定在叶子结点

并且得益于最后一行的链表结构 B+树在做范围查询时性能突出 很多数据库都在采用B+树作为底层数据结构 比如MySQL就默认选择B+Tree作为索引的存储数据结构

至此 有关B树和B+树相关内容 就到这里

#### 哈夫曼树

最后我们来介绍一个比较重要的的树形结构 在开篇之前 我想问下 各位了解文件压缩吗? 它是怎么做到的呢? 我们都会在这一节进行探讨

> 给定N个权值作为N个叶子结点 构造一棵二叉树 若该树的带权路径长度达到最小 称这样的二叉树为最优二叉树 也称为哈夫曼树(Huffman Tree)

乍一看好像没看懂 啥叫带权路径长度达到最小? 就是树中所有的叶结点的权值乘上其到根结点根结点的路径长度(若根结点为0层 叶结点到根结点的路径长度为叶结点的层树)

<img src="https://s2.loli.net/2022/08/17/goKnFtErpiNQebU.png"/>

这里我们分别将叶子结点ABCD都赋予一个权值 我们来尝试计算一下 计算公式如下:
$$
WPL= 
i=1
∑
n
​
 (value(i)×depth(i))
$$
那么左右两边的计算结果为:

- 左图： $WPL=5×2+7×2+2×2+13×2=54$
- 右图：$WPL=5×3+2×3+7×2+13×1=48$

通过计算结果可知 右图的带权路径长度最小 实际上右图是一棵哈夫曼树

那么现在给了我们这些带权的叶子结点 我们怎么去构建一颗哈夫曼树呢? 首先我们可以将这些结点视为4棵树 他们共同构成了一片森林:

<img src="https://s2.loli.net/2022/08/17/V1E4tZsnGbWFzjo.png"/>

首先我们选择两棵权值最小的树作为一颗新的树的左右子树 左右顺序不重要(因为哈夫曼编码不唯一 后面会说) 得到的树根结点权值为这两个结点之和

<img src="https://s2.loli.net/2022/08/17/ZCyj1PVwsqiWz4e.png"/>

接着 我们需要将这这棵树放回到森林中 重复上面的操作 继续选择两个最小的出来组成一颗新的树 此时得到:

<img src="https://s2.loli.net/2022/08/17/G5EyArvMhJ9CQNS.png"/>

继续重复上述操作 直到森林里面只剩下一棵树为止:

<img src="https://s2.loli.net/2022/08/17/ywuA6pRPrboE51S.png"/>

这样 我们就得到了一棵哈夫曼树 因为只要保证越大的值越靠近根结点 那么出来的一定是哈夫曼树 所以 我们辛辛苦苦把这棵树构造出来干嘛呢? 实际上哈夫曼树的一个比较重要应用就是对数据进行压缩 它是现代压缩算法的基础 我们常常可以看到网上很多文件都是以压缩包(zip, 7z, rar等格式)形式存在的 我们将文件压缩之后

比如这一堆字符串: ABCABCD 现在我们想要将其进行压缩然后保存到硬盘上 此时就可以使用哈夫曼编码 那么怎么对这些数据进行压缩呢? 这里我们就可以采用刚刚构建好的哈夫曼树 我们需要先对其进行标注:

<img src="https://s2.loli.net/2022/08/17/oRuOayXEKFkPs3d.png"/>

向左走是0 向右走是1 比如现在我们要求出A的哈夫曼编码 那么就是根结点到A整条路径上的值拼接:

- A: 110
- B: 0
- C: 111
- D: 10

这些编码看起来就像二进制的一样 也便于我们计算机的数据传输和保存 现在我们要对上面的这个字符串进行压缩 那么只需要将其中的每一个字符翻译为对应编码就行了:

- ABCABCD = 110 0 111 110 0 111 10

这样我们就得到了一堆压缩之后的数据了 那怎么解码回去呢 也很简单 只需要对照着写回去就行了:

- 110 0 111 110 0 111 10 = ABCABCD

我们来尝试编写一下代码实现一下哈夫曼树的构建和哈夫曼编码的获取吧 因为构建哈夫曼树需要选取最小的两个结点 这里需要使用到优先级队列

优先级队列与普通队列不同 它允许VIP插队(权值越大的元素优先排到前面去) 当然出队还是一律从队首出来

<img src="https://s2.loli.net/2022/08/17/xySEK5OZ8Q3IbNz.png"/>

比如一开始4和9排在队列中 这时又来了个7 那么由于7比4大 所以说可以插队 直接排到4的前面去 但是由于9比7大 所以说不能再往前插队了:

<img src="https://s2.loli.net/2022/08/17/bv4cD8GTgo2qPEQ.png"/>

这就是优先级队列 VIP插队机制 要实现这样的优先级队列 我们只需要修改一下入队操作即可:

```c
                            _Bool init_queue(linked_queue queue) {
                                
                                LNode node = malloc(sizeof(struct LNode));
                                if(node == NULL) return 0;
                                queue->front = queue->rear = node;
                                node->next = NULL; // 因为下面用到了判断结点的下一个为NULL 所以说记得默认设定为NULL
                                return 1;
                                
                            }

                            _Bool offer_queue(linked_queue queue, T element) {
                                
                                LNode node = malloc(sizeof(struct LNode));
                                if(node == NULL) return 0;
                                node->element = element;
                                node->next = NULL; // 因为下面用到了判断结点的下一个为NULL 所以说记得默认设定为NULL
                                LNode pre = queue->front; // 我们从头结点开始往后挨个看 直到找到第一个小于当前值的结点 或者到头为止
                                while (pre->next && pre->next->element >= element)
                                    pre = pre->next;
                                if(pre == queue->rear) { // 如果说找到的位置已经是最后了 那么直接插入就行 这里跟之前是一样的
                                    queue->rear->next = node;
                                    queue->rear = node;
                                } else { // 否则开启VIP模式 直接插队
                                    node->next = pre->next;
                                    pre->next = node;
                                }
                                return 1;
                                
                            }
```

我们来测试一下吧:

```c
                            int main() {
                                
                                struct Queue queue;
                                init_queue(&queue);

                                offer_queue(&queue, 9);
                                offer_queue(&queue, 4);
                                offer_queue(&queue, 7);
                                offer_queue(&queue, 3);
                                offer_queue(&queue, 13);

                                print_queue(&queue);
                                
                            }
```

<img src="https://s2.loli.net/2022/08/17/cw6QCUSgDjotKbl.png"/>

这样我们就编写好了一个优先级队列 然后就可以开始准备构建哈夫曼树了:

```c
                            typedef char E;

                            typedef struct tree_node {
                                
                                E element;
                                struct tree_node *left;
                                struct tree_node *right;
                                int value; // 存放权值
                                
                            } *Node;
```

首先按照我们前面的例子 构建出这四个带权值的结点:

```c
                            Node create_node(E element, int value) { // 创建一个结点
                                
                                Node node = malloc(sizeof(struct tree_node));
                                node->element = element;
                                node->left = node->right = NULL;
                                node->value = value;
                                return node;
                                
                            }
```

```c
                            _Bool offer_queue(linked_queue queue, T element) {
                                
                                LNode node = malloc(sizeof(struct LNode));
                                if(node == NULL) return 0;
                                node->element = element;
                                node->next = NULL;
                                LNode pre = queue->front;
                                while (pre->next && pre->next->element->value <= element->value) // 注意这里改成权重的比较 符号改成小于
                                    pre = pre->next;
                                if(pre == queue->rear) {
                                    queue->rear->next = node;
                                    queue->rear = node;
                                } else {
                                    node->next = pre->next;
                                    pre->next = node;
                                }
                                return 1;
                                
                            }
```

现在我们来测试一下吧:

```c
                            int main() {
                                
                                struct Queue queue;
                                initQueue(&queue);

                                offerQueue(&queue, createNode('A', 5));
                                offerQueue(&queue, createNode('B', 16));
                                offerQueue(&queue, createNode('C', 8));
                                offerQueue(&queue, createNode('D', 13));

                                printQueue(&queue);
                                
                            }
```

<img src="https://s2.loli.net/2022/08/17/IU9RYEVl7GytZmQ.png"/>

已经是按照权重顺序在排队了 接着我们就可以开始构建哈夫曼树了:

```c
                            int main() {
                                
                                struct Queue queue;
                                initQueue(&queue);

                                offerQueue(&queue, createNode('A', 5));
                                offerQueue(&queue, createNode('B', 16));
                                offerQueue(&queue, createNode('C', 8));
                                offerQueue(&queue, createNode('D', 13));

                                while (queue.front->next != queue.rear) { // 如果front的下一个就是rear那么说明队列中只有一个元素了
                                    Node left = pollQueue(&queue);
                                    Node right = pollQueue(&queue);
                                    Node node = createNode(' ', left->value + right->value); // 创建新的根结点
                                    node->left = left;
                                    node->right = right;
                                    offerQueue(&queue, node); // 最后将构建好的这棵树入队
                                }

                                Node root = pollQueue(&queue); // 最后出来的就是哈夫曼树的根结点了
                                
                            }
```

现在得到哈夫曼树之后 我们就可以对这些字符进行编码了 当然注意我们这里面只有ABCD这几种字符:

```c
                            char * encode(Node root, E e) {
                                
                                if(root == NULL) return NULL; // 为NULL肯定就是没找到
                                if(root->element == e) return ""; // 如果找到了就返回一个空串
                                char * str = encode(root->left, e); // 先去左边找
                                char * s = malloc(sizeof(char) * 10);
                                if(str != NULL) {
                                    s[0] = '0';
                                    str = strcat(s, str); // 如果左边找到了 那么就把左边的已经拼好的字符串拼接到当前的后面
                                } else { // 左边不行那再看看右边
                                    str = encode(root->right, e);
                                    if(str != NULL) {
                                        s[0] = '1';
                                        str = strcat(s, str); // 如果右边找到了 那么就把右边的已经拼好的字符串拼接到当前的后面
                                    }
                                }
                                return str; // 最后返回操作好的字符串给上一级
                                
                            }

                            void printEncode(Node root, E e) {
                                
                                printf("%c 的编码为：%s", e, encode(root, e)); // 编码的结果就是了
                                putchar('\n');
                                
                            }
```

最后测试一下吧:

```c
                            int main() {
                                
                                struct Queue queue;
                                initQueue(&queue);

                                ...

                                Node root = pollQueue(&queue);
                                printEncode(root, 'A');
                                printEncode(root, 'B');
                                printEncode(root, 'C');
                                printEncode(root, 'D');
                                
                            }
```

成功得到对应的编码:

<img src="https://s2.loli.net/2022/08/17/zx2cXns73yQThaV.png"/>

#### 堆和优先级队列

前面我们在讲解哈夫曼树时了解了优先级队列 它提供一种可插队的机制 允许权值大的结点排到前面去 但是出队顺序还是从队首依次出队 我们通过对前面的队列数据结构的插入操作进行改造 实现了优先级队列

这节课我们接着来了解一下**堆**(Heap) 它同样可以实现优先级队列

首先必须是一棵完全二叉树 树中父亲都比孩子小的我们称为**小根堆**(小顶堆) 树中父亲都比孩子大则是**大根堆**(注意不要跟二叉查找树搞混了 二叉查找树是左小右大 而堆只要是孩子一定小或者大) 它是一颗具有特殊性质的完全二叉树 比如下面就是一个典型的大根堆:

<img src="https://s2.loli.net/2022/08/18/1ULKRiAeZcI2hJm.png"/>

因为完全二叉树比较适合使用数组来存储(因为是按序的) 所以说一般堆都是以数组形式存放:

<img src="https://s2.loli.net/2022/08/18/XpYVN2gslOfWLSr.png"/>

那么它是怎么运作的呢? 比如现在我们想要往堆中插入一个新的元素8 那么:

<img src="https://s2.loli.net/2022/08/18/mcq2wjLvxHUu6R7.png"/>

因为是一颗完全二叉树 那么必须按照顺序 继续在当前这一行从左往右插入新的结点 其实就相当于在数组的后面继续加一个新的进来 是一样的 但是因为要满足大顶堆的性质 所以此时8加入之后 破坏了规则 我们需要进行对应的调整(堆化) 很简单 我们只需要将其与父结点交换即可:

<img src="https://s2.loli.net/2022/08/18/T187nAaRBV9jJed.png"/>

同样的 数组的形式的话 我们就行先计算出它的父结点 然后进行交换即可:

<img src="https://s2.loli.net/2022/08/18/tp81Tlr6LzFeaXQ.png"/>

当然 还没完 我们还需要继续向上比较 直到稳定为止 此时7依然是小于8的 所以说需要继续交换:

<img src="https://s2.loli.net/2022/08/18/FP5LhdDZ9zVBYfl.png"/>

现在满足性质了 堆化结束 可以看到最大的元素被排到了最前面 这不就是我们前面的优先级队列吗

现在我们来试试看删除队首元素 也就相当于出队操作 删除最顶上的元素:

<img src="https://s2.loli.net/2022/08/18/XxivcLFwebrUKf2.png"/>

现在需要删除最顶上的元素但是我们需要保证删除之后依然是一棵完全二叉树 所以说我们先把排在最后面的拿上来顶替一下:

<img src="https://s2.loli.net/2022/08/18/MmtNHQla3zej6FC.png"/>

<img src="https://s2.loli.net/2022/08/18/OWGiYxKb71o249T.png"/>

接着我们需要按照与插入相反的方向 从上往下进行堆化操作 规则是一样的 遇到大的就交换 直到不是为止:

<img src="https://s2.loli.net/2022/08/18/BqTkxDov8AXtwCZ.png"/>

这样 我们发现 即使完成了出队操作 依然是最大的元素排在队首 并且整棵树依然是一棵完全二叉树

按照上面的操作 我们来编写一下代码吧 这里还是以大顶堆为例:

```c
                            typedef int E;
                            typedef struct max_heap {
                                
                                E *arr;
                                int size;
                                int capacity;
                                
                            } *Heap;

                            _Bool init_heap(Heap heap) { // 初始化都是老套路了 不多说了
                                
                                heap->size = 0;
                                heap->capacity = 10;
                                heap->arr = malloc(sizeof (E) * heap->capacity);
                                return heap->arr != NULL;
                                
                            }

                            int main() {
                                
                                struct max_heap heap;
                                init_heap(&heap);
                                
                            }
```

接着就是插入操作 首先还是需要判断是否已满:

```c
                            _Bool insert(Heap heap, E element) {
                                
                                if(heap->size == heap->capacity) return 0; // 满了就不处理了 主要懒得写扩容了
                                int index = ++heap->size; // 先计算出要插入的位置 注意要先自增 因为是从1开始的
                                // 然后开始向上堆化 直到符合规则为止
                                while (index > 1 && element > heap->arr[index / 2]) {
                                    heap->arr[index] = heap->arr[index / 2];
                                    index /= 2;
                                }
                                // 现在得到的index就是最终的位置了
                                heap->arr[index] = element;
                                return 1;
                                
                            }
```

我们来测试一下吧:

```c
                            void print_heap(Heap heap) {
                                for (int i = 1; i <= heap->size; ++i) printf("%d ", heap->arr[i]);
                            }

                            int main() {
                                
                                struct max_heap heap;
                                init_heap(&heap);
                                insert(&heap, 5);
                                insert(&heap, 2);
                                insert(&heap, 3);
                                insert(&heap, 7);
                                insert(&heap, 6);

                                print_heap(&heap);
                                
                            }
```

最后结果为:

<img src="https://s2.loli.net/2022/08/18/bFS9KEPNxRdnYas.png"/>

插入完成之后 我们接着来写一下删除操作 删除操作实际上就是出队的操作:

```c
                            E delete(Heap heap) {
                                
                                E max = heap->arr[1], e = heap->arr[heap->size--];
                                int index = 1;
                                while (index * 2 <= heap->size) { // 跟上面一样，开找 只不过是从上往下找
                                    int child = index * 2; // 先找到左孩子
                                    // 看看右孩子和左孩子哪个大 先选一个大的出来
                                    if(child < heap->size && heap->arr[child] < heap->arr[child + 1])
                                        child += 1;
                                    if(e >= heap->arr[child]) break; // 如果子结点都不大于新结点 那么说明就是这个位置 结束就行了
                                    else heap->arr[index] = heap->arr[child];  // 否则直接堆化 换上去
                                    index = child; // 最后更新一下index到下面去
                                }
                                heap->arr[index] = e; // 找到合适位置后 放进去就行了
                                return max;
                                
                            }
```

<img src="https://s2.loli.net/2022/08/18/x8YDojfnp2yBqvA.png"/>

可以看到结果就是优先级队列的出队结果 这样 我们就编写好了大顶堆的插入和删除操作了

当然 堆在排序上也有着非常方便的地方 在后面的排序算法篇中 我们还会再次说起它

至此 有关树形结构篇的内容 我们就全部讲解完毕了 请务必认真掌握前面的二叉树和高级二叉树结构 这些都是重点内 下一章我们将继续探讨**散列表**

### 算法实战

二叉树相关的算法实战基本都是与递归相关的 因为它实在是太适合用分治算法了

#### (简单) 二叉查找树的范围和

本题来自LeetCode: [938. 二叉搜索树的范围和](https://leetcode.cn/problems/range-sum-of-bst/)

给定**二叉搜索树**的根结点root 返回值位于范围 [low, high] 之间的所有结点的值的和

示例1:

> <img src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg"/>
>
> 输入: root = [10,5,15,3,7,null,18], low = 7, high = 15 (注意力扣上的输入案例写的是层序序列 含空节点)
> 输出: 32

示例2:

> <img src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg"/>
>
> 输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
> 输出：23

这道题其实就是考察我们对于二叉查找树的理解 利用二叉查找树的性质 这道题其实很简单 只需要通过递归分治就可以解决了

代码如下:

```c
                            int range_sum_BST(struct tree_node* root, int low, int high) {
                                
                                if(root == NULL) return 0;
                                if(root->val > high) // 如果最大的值都比当前结点值小 那么肯定在左边才能找到
                                    return range_sum_BST(root->left, low, high);
                                else if(root->val < low) // 如果最小值都比当前结点大 那么肯定在右边才能找到
                                    return range_sum_BST(root->right, low, high);
                                else
                                    // 这种情况肯定是在范围内了 将当前结点值加上左右的 再返回
                                    return root->val + range_sum_BST(root->right, low, high) + range_sum_BST(root->left, low, high);
                                
                            }
```

这种问题比较简单 直接四行就解决了

#### (中等) 重建二叉树

本题来自LeetCode: [剑指 Offer 07. 重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)

输入某二叉树的前序遍历和中序遍历的结果 请构建该二叉树并返回其根节点

假设输入的前序遍历和中序遍历的结果中都不含重复的数字

示例1:

> <img src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg"/>
>
> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
> Output: [3,9,20,null,null,15,7]

示例2:

> Input: preorder = [-1], inorder = [-1]
> Output: [-1]

实际上这道题就是我们前面练习题的思路 现在给到我们的是前序和中序遍历的结果 我们只需要像之前一样逐步推导即可

1. 由于前序遍历首元素为根节点值 首先可以得到根节点值
2. 在中序遍历序列中通过根节点的值 寻找根节点的位置
3. 将左右两边的序列分割开来 并重构为根节点的左右子树 (递归分治)
4. 在新的序列中 重复上述步骤 通过前序遍历再次找到当前子树的根节点 再次进行分割
5. 直到分割到仅剩下一个结点时 开始回溯 从而完成整棵二叉树的重建

解题代码如下:

```c
                            struct tree_node* create_node(int val) { // 这个就是单纯拿来创建结点的函数
                                
                                struct tree_node* node = malloc(sizeof(struct tree_node));
                                node->left = node->right = NULL;
                                node->val = val;
                                return node;
                                
                            }

                            // 核心递归分治实现
                            struct tree_node* build_tree_core(int* preorder, int* inorder, int start, int end, int index){
                                
                                if(start > end) return NULL; // 如果都超出范围了 肯定不行
                                if(start == end) return createNode(preorder[index]); // 如果已经到头了 那么直接创建结点返回即可
                                struct tree_node * node = createNode(preorder[index]); // 先从前序遍历中找到当前子树的根结点值 然后创建对应的结点
                                int pos = 0;   
                                while (inorder[pos] != preorder[index]) pos++; // 找到中序的对应位置 从这个位置开始左右划分
                                node->left = build_tree_core(preorder, inorder, start, pos - 1, index+1);   
                                // 当前结点的左子树按照同样的方式建立
                                // 因为前序遍历的下一个结点就是左子树的根结点，所以说这里给index+1
                                node->right = build_tree_core(preorder, inorder, pos+1, end, index+(pos-start)+1);  
                                // 当前结点的右子树按照同样的方式建立
                                // 最后一个index需要先跳过左子树的所有结点 才是右子树的根结点 所以说这里加了个pos-start 就是中序划分出来 左边有多少就减去多少
                                return node; // 向上一级返回当前结点
                                
                            }

                            struct tree_node* build_tree(int* preorder, int preorderSize, int* inorder, int inorderSize){
                                return build_tree_core(preorder, inorder, 0, preorderSize - 1, 0);
                                // 这里传入了前序和中序序列 并且通过start和end指定当前中序序列的处理范围 最后的一个index是前序遍历的对应头结点位置
                            }
```

#### (中等) 验证二叉搜索树

本题来自LeetCode: [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/) (先说 这题老六行为过多 全站通过率只有36.5% 但是题目本身很简单)

给你一个二叉树的根节点root 判断其是否是一个有效的二叉搜索树

有效 二叉搜索树定义如下:

1. 节点的左子树只包含 小于 当前节点的数
2. 节点的右子树只包含 大于 当前节点的数
3. 所有左子树和右子树自身必须也是二叉搜索树

示例1:

> <img src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg"/>
>
> 输入: root = [2,1,3]
> 输出: true

示例2:

> <img src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg"/>
>
> 输入: root = [5,1,4,null,null,3,6]
> 输出: false
> 解释: 根节点的值是5 但是右子节点的值是4

这种题看起来好像还挺简单的 我们可以很快地写出代码

```c
                            bool is_valid_BST(struct tree_node* root) {
                                
                                if(root == NULL) return true; // 到头了就直接返回真
                                if(root->left != NULL && root->left->val >= root->val) return false; // 如果左边不是空 并且左边还比当前结点值小的话 那肯定不是了
                                if(root->right != NULL && root->right->val <= root->val) return false; // 同上
                                return is_valid_BST(root->left) && is_valid_BST(root->right); // 接着向下走继续判断左右两边子树 必须同时为真才是真
                                
                            }
```

然后直接上力扣测试 嗯 没问题 提交 这把必过! 于是光速打脸:

<img src="https://s2.loli.net/2022/08/17/EQdvDtlnSgU7kWC.png"/>

不可能啊 我们的逻辑判断没有问题的 我们的算法不可能被卡的啊? (这跟我当时打ACM一样的感觉 我这天衣无缝的算法不可能错的啊，哪个老六测试用例给我卡了）这其实是因为我们没有考虑到右子树中左子树比根结点值还要小的情况

<img src="https://s2.loli.net/2022/08/17/AjU1G2nXytRCKoW.png"/>

虽然这样错的很明显 但是按照我们上面的算法 这种情况确实也会算作真 所以说我们需要改进一下 对其上界和下界进行限定 不允许出现这种低级问题:

```c
                            bool is_valid(struct tree_node* root, long min, long max) { // 这里上界和下界用long表示 因为它的范围给到整个int 真是个老六
                                if(root == NULL) return true;
                                
                                // 这里还需要判断是否正常高于下界
                                if(root->left != NULL && (root->left->val >= root->val || root->left->val <= min)) return false;
                                // 这里还需判断一下是否正常低于上界
                                if(root->right != NULL && (root->right->val <= root->val || root->right->val >= max)) return false;
                                return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
                                // 注意往左走更新上界 往右走更新下界
                                
                            }

                            bool is_valid_BST(struct tree_node* root) {
                                return is_valid(root, -2147483649, 2147483648); // 下界刚好比int少1 上界刚好比int多1
                            }
```

这样就没问题了

#### (中等) 求根到叶数字之和

本题来自LeetCode: [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers/)

给你一个二叉树的根节点root 树中每个节点都存放有一个 0 到 9 之间的数字 每条从根节点到叶节点的路径都代表一个数字

例如 从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 计算从根节点到叶节点生成的 所有数字之和

叶节点 是指没有子节点的节点

示例1:

> <img src="https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg"/>
>
> 输入: root = [1,2,3]
> 输出: 25
> 解释:
> 从根到叶子节点路径 1->2 代表数字 12
> 从根到叶子节点路径 1->3 代表数字 13
> 因此 数字总和 = 12 + 13 = 25

示例 2:

> <img src="https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg"/>
>
> 输入: root = [4,9,0,5,1]
> 输出: 1026
> 解释:
> 从根到叶子节点路径 4->9->5 代表数字 495
> 从根到叶子节点路径 4->9->1 代表数字 491
> 从根到叶子节点路径 4->0 代表数字 40
> 因此 数字总和 = 495 + 491 + 40 = 1026

这道题其实也比较简单 直接从上向下传递当前路径上已经组装好的值即可 到底时返回最终的组装结果:

```c
                            int sum_numbers_impl(struct tree_node* root, int parent) {
                                
                                if(root == NULL) return 0; // 如果到头了 直接返回0
                                int sum = root->val + parent * 10; // 因为是依次向后拼接 所以说直接将之前的值x10然后加上当前值即可
                                if(!root->left && !root->right) // 如果是叶子结点 那么直接返回结果
                                    return sum;
                                // 否则按照同样的方式将左右的结果加起来
                                return sumNumbersImpl(root->left, sum) + sumNumbersImpl(root->right,  sum);
                                
                            }

                            int sum_numbers(struct tree_node* root) {
                                return sum_numbers_impl(root, 0);
                            }
```

#### (困难) 结点之和的最大路径

本题来自LeetCode: [剑指 Offer II 051. 节点之和最大的路径](https://leetcode.cn/problems/jC7MId/) (这是一道Hard难度的题目 但是其实还好)

路径被定义为一条从树中任意节点出发 沿父节点-子节点连接达到任意节点的序列 同一个节点在一条路径序列中至多出现一次该路径 至少包含一个 节点 且不一定经过根节点

路径和是路径中各节点值的总和

给定一个二叉树的根节点root  返回其最大路径和 即所有路径上节点值之和的最大值

示例1:

> <img src="https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg"/>
>
> 输入: root = [1,2,3]
> 输出: 6
> 解释: 最优路径是 2 -> 1 -> 3 路径和为 2 + 1 + 3 = 6

示例2:

> <img src="https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg"/>
>
> 输入: root = [-10,9,20,null,null,15,7]
> 输出: 42
> 解释: 最优路径是 15 -> 20 -> 7 路径和为 15 + 20 + 7 = 42

首先 我们要知道 路径有很多种可能 要么从上面下来 要么从左边上来往右边走 要么只走右边 要么只走左边... 我们需要寻找一个比较好的方法在这么多种可能性之间选择出最好的那一个

```c
                            int result = -2147483648; // 使用一个全局变量来存储一下当前的最大值

                            int max(int a, int b) { // 不想多说了
                                return a > b ? a : b;
                            }

                            int max_value(struct tree_node* root) {
                                
                                if(root == NULL) return 0;
                                // 先把左右两边走或是不走的情况计算一下 取出值最大的情况
                                int leftMax = max(maxValue(root->left), 0);
                                int rightMax = max(maxValue(root->right), 0);
                                // 因为要么只走左边 要么只走右边 要么左右都走 所以说我们计算一下最大情况下的结果
                                int maxTmp = leftMax + rightMax + root->val;
                                result = max(maxTmp, result); // 更新一下最大值
                                // 然后就是从上面下来的情况了 从上面下来要么左要么右 此时我们只需要返回左右最大的一个就行了
                                return max(leftMax, rightMax) + root->val; // 注意还要加上当前结点的值 因为肯定要经过当前结点
                                
                            }

                            int maxPathSum(struct TreeNode* root) {
                                
                                maxValue(root);
                                return result; // 最后返回完事之后最终得到的最大值
                                
                            }
```

这样 我们就成功解决了这种问题
