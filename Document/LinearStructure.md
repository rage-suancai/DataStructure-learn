<img src="https://s2.loli.net/2022/07/09/otEZIiDc3WX9h4f.png"/>

## 线性结构篇

**注意: **开始本篇学习之前 请确保你完成了**C语言程序设计**篇 否则无法进行学习

我们本系列课程分为基础知识和算法实战两部分 其中算法实战在LeetCode上进行: https://leetcode.cn/ 各位可以提前在平台上注册好相关账号

学习完数据结构 各位小伙伴可以尝试参加算法相关的学科竞赛 如ICPC-ACM, 蓝桥杯等 算法类的比赛含金量相比项目类比赛更高, 也更有价值 相应的 算法类竞赛难道会更大一些 尤其是ICPC-ACM大学生程序设计竞赛 一般都是各个高校内顶尖级队伍进行参赛 甚至还有中学队伍(这类学生预定清华, 北大) 因为算法更加考验个人的思维能力和天赋水平 相比其他计算机基础课程 数据结构和算法是难度最高的 也是各大高校考研的重点内容

不过虽然很难 并且考验个人天赋 但是大部分人通过努力学习是完全能够掌握基础部分的 在应对80%的题目时 是完全有机会解决的 所以 不要怀疑自己 说不定你就是下一个大佬

这里也说一下面试推荐书籍 内含多种常用算法以及解题分析 值得一看:

<img src="https://s2.loli.net/2022/07/09/TurKEpDHmvlgJhZ.png"/>

本篇内容虽然继续以C语言为基础进行讲解 但是将不再涉及到C语言的语言层面相关内容 更多的是数据结构和算法的思想 实际上用任意一种语言都可以实现

### 什么是数据结构与算法

回顾我们之前的C语言程序设计阶段 我们已经接触过基本数据类型 并且能够使用结构体对数据进行组织 我们可以很轻松地使用一个结构体来存放一个学生的完整数据 在数据结构学习阶段 我们还会进一步地研究

#### 数据结构

那么 我们来看看 什么是数据结构呢?

> 数据结构(data structure)是带有结构特性的数据元素的集合 它研究的是数据的[逻辑结构](https://baike.baidu.com/item/逻辑结构/9663235)和数据的物理结构以及它们之间的相互关系

比如现在我们需要保存100个学生的数据 那么你首先想到的肯定是使用数组吧 没错 没有什么比数组更适合存放这100个学生的数据了 但是如果我们现在有了新的需求呢? 我们不仅仅是存放这些数据 我们还希望能够将这些数据按顺序存放 支持在某个位置插入一条数据, 删除一条数据, 修改一条数据等 这时候 数组就显得有些乏力了

<img src="https://s2.loli.net/2022/07/10/9RwL7pxgyfoB3WT.png"/>

我们需要一种更好的数据表示和组织方式 才能做到类似于增删改查这样的操作 而完成这些操作所用到的方法 我们称其为"算法" 所以数据结构和算法 一般是放在一起进行讲解的

#### 算法

比如现在我们希望你求出1-100所有数字的和 请通过程序来实现:

```c
                            int main() {
                                
                                int sum = 0;
                                for (int i = 1; i <= 100; ++i) sum += i;
                                printf("%d", sum);
                                
                            }
```

我们很容易就能编写出这样的程序 实际上只需要一个for循环就能搞定了 而这就是我们设计的算法

<img src="https://s2.loli.net/2022/07/09/srPn4baDXWZ9qcJ.png"/>

在之前的C语言程序设计阶段 我们其实已经学习了许多算法 包括排序算法, 动态规划等

当然 解决问题的算法并不是只有一种 实际上我们上面的方式并不是最优的算法 如果想要求得某一段整数的和 其实使用**高斯求和公式**能够瞬间得到结果:
$$
∑= 
2
(首项+末项)×项数
​
 
$$
所以 我们完全没必要循环那么多次进行累加计算 而是直接使用数学公式:

```c
                            int main() {
                                printf("%d", (1 + 100) * 100 / 2);
                            }
```

所以 算法的尽头还得是数学啊

可见 不同的算法 执行的效率也是有很大差别的 这里我们就要提到算法的复杂度了 衡量一个算法的复杂程度需要用到以下两个指标:

- 时间复杂度`T(n)`: 算法程序在执行时消耗的时间长度 一般与输入数据的规模n有关
- 空间复杂度`S(n)`: 算法程序在执行时占用的存储单元长度 同样与数据的输入规模n有关 大部分情况下 我们都是采取空间换时间的算法

比如我们上面的两种算法 第一种需要执行n次循环 每轮循环进行一次累加操作 而第二种只需要进行一次计算即可 实际中我们计算时间复杂度时 其实并不一定要计算精确的执行次数 而只需要大概执行次数 那么这里我们使用`O`渐进表示法

- **大O符号（Big O notation）**: 是用于描述函数渐进行为的数学符号

而这里的循环次数 实际上就是我们需要知道的大致执行次数 所以第一种算法的时间复杂度为`O(n)`其中n就是项数 因为它需要执行n次计算才能得到最后的结果 而第二种算法的时间复杂度为: `O(1)`因为它只需要执行一次计算(更准确的说它的执行次数是一个常数 跟项数n毫无关系) 显然 当n变得非常大时 第二种方法的计算速度远超第一种

再比如我们之前使用的冒泡排序算法 需要进行两轮循环 而循环的次数在经过优化之后为`(n - 1)(n - 1)/2` 得到的结果中包含了一个`n`的平方 此时这种算法的时间复杂度就来到`O(n^2)`了

在不同的空间复杂度下 可能n小的时候还没什么感觉 但是当n变得非常大时 差距就不是一点半点了 我们来看看常用函数的增长曲线:

<img src="https://s2.loli.net/2022/07/09/Tr6jI5uPzy2NeDd.png"/>

所以我们在设计算法的时候 一定要考虑到时间和空间复杂度的问题 这里列出常用函数的增长表:

|     函数      |    类型    |                             解释                             |
| :-----------: | :--------: | :----------------------------------------------------------: |
|     O(1)      |   常数阶   |    如果算法能够优化到这个程度 那么基本上算是最快的算法了     |
|  O(log2*n*)   |   对数阶   | 仅次于常数阶的速度 我们后面会介绍的二分搜索算法 就能够到达这个级别 |
|    O(*n*)     |   线性阶   | 我们后面介绍的线性表插入, 删除数据 包括动态规划类算法能够达到线性阶 |
| O(*n*log2*n*) | 线性对数阶 |           相当于在对数阶算法外层套了一层线性阶循环           |
|    O(*n*2)    |   平方阶   |   我们前面学习的冒泡排序 需要进行两重循环 实际上就是平方阶   |
|    O(*n*3)    |   立方阶   |          从立方阶开始 时间复杂度就开始变得有点大了           |
|    O(2*n*)    |   指数阶   | 我们前面介绍的斐波那契数列递归算法 就是一个指数阶的算法 因为它包含大量的重复计算 |
|    O(*n*!)    |    阶乘    | 这个增长速度比指数阶还恐怖 但是一般很少有算法能达到这个等级  |

我们在编写算法时 一定要注意算法的时间复杂度 当时间复杂度太大时 可能计算机就很难在短时间内计算出结果了

#### 案例: 二分搜索算法

现在有一个从小到大排序的数组 给你一个目标值`target` 现在请你找到这个值在数组中的对应下标 如果没有 请返回`-1`:

```c
                            int search(int *nums, int nums_size, int target) {
                                // 请实现查找算法
                            }

                            int main() {
                                
                                int arr[] = {1, 3, 4, 6, 7,8, 10, 11, 13, 15}, target = 3;
                                printf("%d", search(arr, 10, target));
                                
                            }
```

此时 最简单的方法就是将数组中的元素一个一个进行遍历 总有一个是 如果遍历完后一个都没有 那么就结束:

```c
                            int search(int *nums, int nums_size, int target) {
                                
                                for (int i = 0; i < len; ++i) {
                                    if(nums[i] == target) return i; // 循环n次 直到找到为止
                                }
                                return -1;
                                
                            }
```

虽然这样的算法简单粗暴 但是并不是最好的 我们需要遍历n次才能得到结果 时间复杂度为O(*n*) 我们可以尝试将其优化到更低的时间复杂度 这里我们利用它有序的特性 实际上当我们查找到大于目标`target`的数时 就没必要继续寻找了:

```c
                            int search(int *nums, int nums_size, int target) {
                                
                                for (int i = 0; i < len; ++i) {
                                    if(nums[i] == target) return i;
                                    if(nums[i] > target) break;
                                }
                                return -1;
                            }
```

这样循环进行的次数也许就会减小了 但是如果我们要寻找的目标`target`刚好是最后几个元素呢? 这时间复杂度又来到了O(*n*) 那么有没有更好的办法呢? 我们依然可以继续利用数组有序的特性 既然是有序的 那么我们不妨随机在数组中找一个数 如果这个数大于目标 那么就不再考虑右边的部分 如果小于目标 那么就考虑左边的部分 然后继续在另一部分中再次随机找一个数 这样每次都能将范围缩小 直到找到为止(其思想就比较类似于**牛顿迭代法**再次强调数学的重要性)

<img src="https://s2.loli.net/2022/07/10/CczrjdlmBgPSRIb.png"/>

而二分思想就是将一个有序数组不断进行平分 直到找到为止 这样我们每次寻找的范围会不断除以2 所以查找的时间复杂度就降到了O(log⁡2𝑛)O(log2*n*) 相比一个一个比较 效率就高了不少:

<img src="https://s2.loli.net/2022/07/10/FSDcHgG3sOo789z.png"/>

好了 那么现在我们就可以利用这种思想 编写出二分搜索算法了 因为每一轮都在进行同样的搜索操作 只是范围不一样 所以这里直接采用递归分治算法:

```c
                            int binary_search(int *nums, int target, int left, int right) { // left代表左边界 right代表右边界
                                
                                if(left > right) return -1; // 如果左边大于右边 那么肯定就找完了 所以直接返回
                                int mid = (left + right) / 2; // 这里计算出中间位置
                                if(nums[mid] == target) return mid; // 直接比较 如果相等就返回下标
                                if(nums[mid] > target) // 这里就是大于或小于的情况了 这里mid+1和mid-1很多人不理解 实际上就是在下一次寻找中不算上当前的mid 因为这里已经比较过了 所以说左边就-1 右边就+1
                                    return binary_search(nums, target, left, mid - 1); // 如果大于 那么说明肯定不在右边 直接去左边找
                                else
                                    return binary_search(nums, target, mid + 1, right); // 如果小于 那么说明肯定不在左边 直接去右边找
                                
                            }

                            int search(int *nums, int nums_size, int target) {
                                return binary_search(nums, target, 0, nums_size - 1);
                            }
```

当然也可以使用`while`循环来实现二分搜索 如果需要验证自己的代码是否有问题 可以直接在力扣上提交代码：https://leetcode.cn/problems/binary-search/

### 线性表

那么作为数据结构的开篇 我们就从最简单的线性表开始介绍

还记得我们开篇提了一个问题吗?

我们还希望能够将这些数据按顺序存放 支持在某个位置插入一条数据, 删除一条数据, 修改一条数据等 这时候 数组就显得有些乏力了

数组无法做到这么高级的功能 那么我们就需要定义一种更加高级的数据结构来做到 我们可以使用线性表(Linear List)

线性表是由同一类型的数据元素构成的有序序列的线性结构 线性表中元素的个数就是线性表的长度 表的起始位置称为表头 表的结束位置称为表尾 当一个线性表中没有元素时 称为空表

线性表一般需要包含以下功能:

- **初始化线性表:** 将一个线性表进行初始化 得到一个全新的线性表
- **获取指定位置上的元素:** 直接获取线性表指定位置`i`上的元素
- **获取元素的位置:** 获取某个元素在线性表上的位置`i`
- **插入元素:** 在指定位置`i`上插入一个元素
- **删除元素:** 删除指定位置`i`上的一个元素
- **获取长度:** 返回线性表的长度

也就是说 现在我们需要设计的是一种功能完善的表结构 它不像是数组那么低级 而是真正意义上的表:

<img src="https://s2.loli.net/2022/07/23/Ve6dlqROzhumD5o.png"/>

简单来说它就是列表 比如我们的菜单 我们在点菜时就需要往菜单列表中添加菜品或是删除菜品 这时列表就很有用了 因为数组长度固定, 操作简单 而我们添加菜品, 删除菜品这些操作又要求长度动态变化, 操作多样

那么 如此高级的数据结构 我们该如何去实现呢? 实现线性表的结构一般有两种 一种是顺序存储实现 还有一种是链式存储实现 我们先来看第一种 也是最简单的的一种

#### 顺序表

前面我们说到 既然数组无法实现这样的高级表结构 那么我就基于数组 对其进行强化 也就是说 我们存放数据还是使用数组 但是我们可以为其编写一些额外的操作来强化为线性表 像这样底层依然采用顺序存储实现的线性表 我们称为顺序表

<img src="https://s2.loli.net/2022/07/24/elBvx4Zo1AJ2WqT.png"/>

这里我们可以先定义一个新的结构体类型 将一些需要用到的数据保存在一起 这里我们以`int`类型的线性表为例:

```c
                            typedef int E; // 这里我们的元素类型就用int为例吧 先起个别名

                            struct List {
                                
                                E array[10]; // 实现顺序表的底层数组
                                int capacity; // 表示底层数组的容量
                                
                            };
```

为了一会使用方便 我们可以给其起一个别名:

```c
						  typedef struct List *array_list; // 因为是数组实现 所以就叫ArrayList 这里直接将List的指针起别名
```

然后我们就可以开始编写第一个初始化操作了:

```c
                            void init_list(array_list list) {
                                list->capacity = 10; // 直接将数组的容量设定为10即可
                            }
```

但是我们发现一个问题 这样的话我们的顺序表长度不就是固定为10了吗? 而前面我们线性表要求的是长度是动态增长的 那么这个时候怎么办呢? 我们可以直接使用一个指针来指向底层数组的内存区域 当装不下的时候 我们可以创建一个新的更大的内存空间来存放数据 这样就可以实现扩容了 所以我们来修改一下

```c
                            struct List {
                                
                                E* array; // 指向顺序表的底层数组
                                int capacity; // 数组的容量
                                
                            };
```

接着我们修改一下初始化函数:

```c
                            void init_list(array_list list) { // 这里就默认所有的顺序表初始大小都为10吧 随意
                                
                                list->array = malloc(sizeof(E) * 10); // 使用malloc函数申请10个int大小的内存空间 作为底层数组使用
                                list->capacity = 10; // 容量同样设定为10
                                
                            }
```

但是还没完 因为我们的表里面 默认情况下是没有任何元素的 我们还需要一个变量来表示当前表中的元素数量:

```c
                            struct List {
                                
                                E *array; // 指向顺序表的底层数组
                                int capacity; // 数组的容量
                                int size; // 表中的元素数量
                                
                            };

                            typedef struct List *array_list;

                            void init_list(array_list list) { // 这里就默认所有的顺序表初始大小都为10吧 随意
                                
                                list->array = malloc(sizeof(int) * 10); // 使用malloc函数申请10个int大小的内存空间 作为底层数组使用
                                list->capacity = 10; // 容量同样设定为10
                                list->size = 0;  // 元素数量默认为0
                                
                            }
```

还有一种情况我们需要考虑 也就是说如果申请内存空间失败 那么需要返回一个结果告诉调用者:

```c
                            _Bool init_list(array_list list) {
                                
                                list->array = malloc(sizeof(int) * 10);
                                if(list->array == NULL) return 0; // 需要判断如果申请的结果为NULL的话表示内存空间申请失败
                                list->capacity = 10;
                                list->size = 0;
                                return 1; // 正常情况下返回true也就是1
                                
                            }
```

这样 一个比较简单的顺序表就定义好了 我们可以通过`initList`函数对其进行初始化:

```c
                            int main() {
                                
                                struct List list; // 创建新的结构体变量
                                if(init_list(&list)) { // 对其进行初始化 如果失败就直接结束
                                    ...
                                } else{
                                    printf("顺序表初始化失败 无法启动程序!");
                                }
                                
                            }
```

接着我们来编写一下插入和删除操作 对新手来说也是比较难以理解的操作:

<img src="https://s2.loli.net/2022/07/23/DdlNcI8rykQsZif.png"/>

我们先设计好对应的函数:

```c
                            void insert_list(array_list list, E element, int index) {
                                    // list就是待操作的表 element就是需要插入的元素 index就是插入的位置(注意顺序表的index是按位序计算的 从1开始 一般都是第index个元素)
                            }
```

我们按照上面的思路来编写一下代码:

```c
                            void insert_list(array_list list, E element, int index) {
                                
                                for (int i = list->size; i > index - 1; --i) // 先使用for循环将待插入位置后续的元素全部丢到后一位
                                    list->array[i] = list->array[i - 1];
                                list->array[index - 1] = element; // 挪完之后 位置就腾出来了 直接设定即可
                                list->size++; // 别忘了插入之后相当于多了一个元素 记得size + 1
                                
                            }
```

现在我们可以来测试一下了:

```c
                            void print_list(array_list list) { // 编写一个函数用于打印表当前的数据
                                
                                for (int i = 0; i < list->size; ++i) // 表里面每个元素都拿出来打印一次
                                    printf("%d ", list->array[i]);
                                printf("\n");
                                
                            }
```

```c
                            int main() {
                                
                                struct List list;
                                if(init_list(&list)) {
                                    print_list(&list, 666, 1); // 每次插入操作后都打印一下表 看看当前的情况 
                                    print_list(&list);
                                    print_list(&list, 777, 1);
                                    print_list(&list);
                                    print_list(&list, 888, 2);
                                    print_list(&list);
                                } else{
                                    printf("顺序表初始化失败 无法启动程序!");
                                }
                                
                            }
```

运行结果如下:

<img src="https://s2.loli.net/2022/07/23/nbSVp2yMqKlJQI6.png"/>

虽然这样看起来没什么问题了 但是如果我们在非法的位置插入元素会出现问题:

```c
                            insert_list(&list, 666, -1); // 第一个位置就是0 怎么可能插入到-1这个位置呢 这样肯定是不正确的 所以我们需要进行判断
                            print_list(&list);
```

我们需要检查一下插入的位置是否合法:

<img src="https://s2.loli.net/2022/07/23/H67F1crBhqQiXxg.png"/>

转换成位序 也就是[1, size + 1]这个闭区间 所以我们在一开始的时候进行判断:

```c
                            _Bool insert_list(array_list list, E element, int index) {
                                
                                if(index < 1 || index > list->size + 1) return 0; // 如果在非法位置插入 返回0表示插入操作执行失败
                                for (int i = list->size; i > index - 1; --i)
                                    list->array[i] = list->array[i - 1];
                                list->array[index - 1] = element;
                                list->size++;
                                return 1; // 正常情况返回1
                                
                            }
```

我们可以再来测试一下:

```c
                            if(insert_list(&list, 666, -1)) {
                                print_list(&list);
                            } else{
                                printf("插入失败!");
                            }
```

<img src="https://s2.loli.net/2022/07/23/7Q4IxSd2RDKmzBZ.png"/>

不过我们还是没有考虑到一个情况 那么就是如果我们的表已经装满了 也就是说size已经达到申请的内存空间最大的大小了 那么此时我们就需要考虑进行扩容了 否则就没办法插入新的元素了:

```c
                            _Bool insert_list(array_list list, E element, int index) {
                                
                                if(index < 1 || index > list->size + 1) return 0;
                                if(list->size == list->capacity) { // 如果size已经到达最大的容量了 肯定是插不进了 那么此时就需要扩容了
                                    int new_capacity = list->capacity + (list->capacity >> 1); // 我们先计算一下新的容量大小 这里我取1.5倍原长度 当然你们也可以想扩多少扩多少
                                    E *newArray = realloc(list->array, sizeof(E) * new_capacity); // 这里我们使用新的函数realloc重新申请更大的内存空间
                                    if(newArray == NULL) return 0; // 如果申请失败 那么就确实没办法插入了 只能返回0表示插入失败了
                                    list->array = new_array;
                                    list->capacity = new_capacity;
                                }
                                for (int i = list->size; i > index - 1; --i)
                                    list->array[i] = list->array[i - 1];
                                list->array[index - 1] = element;
                                list->size++;
                                return 1;
                                
                            }
```

> realloc函数可以做到控制动态内存开辟的大小 重新申请的内存空间大小就是我们指定的新的大小 并且原有的数据也会放到新申请的空间中 所以非常方便 当然如果因为内存不足之类的原因导致内存空间申请失败 那么会返回NULL 所以别忘了进行判断

这样 我们的插入操作就编写完善了 我们可以来测试一下:

```c
                            int main() {
                                
                                struct List list;
                                if(init_list(&list)) {
                                    for (int i = 0; i < 30; ++i)
                                        insert_list(&list, i, i);
                                    print_list(&list);
                                } else{
                                    printf("顺序表初始化失败 无法启动程序!");
                                }
                                
                            }
```

成功得到结果:

<img src="https://s2.loli.net/2022/07/23/IqvG1xsUQOo5KwC.png"/>

这样 我们就完成了顺序表的插入操作 接着我们来编写一下删除操作 其实删除操作也比较类似 也需要对元素进行批量移动 但是我们不需要考虑扩容问题 我们先设计好函数:

```c
                            void delete_list(array_list list, int index) {
                                    // list就是待操作的表 index是要删除的元素位序
                            }
```

按照我们上面插入的思路 我们反过来想一想然后实现删除呢? 首先是删除的范围:

<img src="https://s2.loli.net/2022/07/23/uHBjUfKpd9ygScW.png"/>

换算成位序就是[1, size + 1]这个闭区间内容 所以我们先来限定一下合法范围:

```c
                            _Bool delete_list(array_list list, int index) {
                                
                                if(index < 1 || index > list->size) return 0;

                                return 1; // 正常情况返回1
                                
                            }
```

接着就是删除元素之后 我们还需要做什么呢? 我们应该将删除的这个元素后面的全部元素前前移一位:

<img src="https://s2.loli.net/2022/07/23/dgGCcL7q9Pf41tF.png"/>

我们按照这个思路 来编写一下删除操作:

```c
                            _Bool delete_list(array_list list, int index) {
                                
                                if(index < 1 || index > list->size) return 0;
                                for (int i = index - 1; i < list->size - 1; ++i)
                                    list->array[i] = list->array[i + 1]; // 实际上只需要依次把后面的元素覆盖到前一个即可
                                list->size--; // 最后别忘了size - 1
                                return 1;
                                
                            }
```

删除相比插入要简单一些 我们来测试一下吧:

```c
                            for (int i = 0; i < 10; ++i) // 先插10个
                                insert_list(&list, i, i);
                            delete_list(&list, 5); // 这里删除5号元素
                            print_list(&list);
```

成功得到结果:

<img src="https://s2.loli.net/2022/07/23/q2UrtVlh1RJWKQd.png"/>

OK 那么插入和删除操作我们就成功完成了 还有一些比较简单的功能 我们这里也来依次实现一下 首先是获取长度:

```c
                            int size_list(array_list list) {
                                return list->size; // 直接返回size就完事
                            }
```

接着是按位置获取元素和查找指定元素的位置:

```c
                            E *get_list(array_list list, int index) {
                                
                                if(index < 1 || index > list->size) return NULL; // 如果超出范围就返回NULL
                                return &list->array[index - 1];
                                
                            }
```

```c
                            int find_list(array_list list, E element) {
                                
                                for (int i = 0; i < list->size; ++i) { // 一直遍历 如果找到那就返回位序
                                    if(list->array[i] == element) return i + 1;
                                }
                                return -1; // 如果遍历完了都没找到 那么就返回-1
                                
                            }
```

这样 我们的线性表就实现完成了 完整代码如下:

```c
                            #include <stdio.h>
                            #include <stdlib.h>

                            typedef int E;

                            struct List {
                                
                                E *array;
                                int capacity;
                                int size;
                                
                            };

                            typedef struct List *array_list;

                            _Bool init_list(array_list list) {
                                
                                list->array = malloc(sizeof(E) * 10);
                                if(list->array == NULL) return 0;
                                list->capacity = 10;
                                list->size = 0;
                                return 1;
                                
                            }

                            _Bool insert_list(array_list list, E element, int index) {
                                
                                if(index < 1 || index > list->size + 1) return 0;

                                if(list->size == list->capacity) {
                                    int new_capacity = list->capacity + (list->capacity >> 1);
                                    E * new_crray = realloc(list->array, new_capacity * sizeof(E));
                                    if(new_array == NULL) return 0;
                                    list->array = new_array;
                                    list->capacity = new_capacity;
                                }

                                for (int i = list->size; i > index - 1; --i)
                                    list->array[i] = list->array[i - 1];
                                list->array[index - 1] = element;
                                list->size++;
                                return 1;
                                
                            }

                            _Bool delete_list(array_list list, int index) {
                                
                                if(index < 1 || index > list->size) return 0;
                                for (int i = index - 1; i < list->size - 1; ++i)
                                    list->array[i] = list->array[i + 1];
                                list->size--;
                                return 1;
                                
                            }

                            int size_list(array_list list) { 
                                return list->size;
                            }

                            E *get_list(array_list list, int index) {
                                
                                if(index < 1 || index > list->size) return NULL;
                                return &list->array[index - 1];
                                
                            }

                            int find_list(array_list list, E element) {
                                
                                for (int i = 0; i < list->size; ++i) {
                                    if(list->array[i] == element) return i + 1;
                                }
                                return -1;
                                
                            }
```

**问题: **请问顺序实现的线性表 插入, 删除, 获取元素操作的时间复杂度为?

- 插入: 因为要将后续所有元素都向后移动 所以平均时间复杂度为𝑂(𝑛)
- 删除: 同上 因为要将所有元素向前移动 所以平均时间复杂度为𝑂(𝑛)
- 获取元素: 因为可以利用数组特性直接通过下标访问到对应元素 所以时间复杂度为𝑂(1)

**顺序表习题: **

1. 在一个长度为`n`的顺序表中 向第`i`个元素前插入一个新的元素时 需要向后移动多少个元素?

   A. `n-i`

   B. `n-i+1`

   C. `n-i-1`

   D. `i`

   *注意这里要求的是向第`i`个元素前插入(第`i`个表示的是位序 不是下标 不要搞混了 第1个元素下标就为0) 这里我们假设`n`为3 `i`为2 那么也就是说要在下标为1的这个位置上插入元素 那么就需要移动后面的2个元素 所以答案是B*

2. 顺序表是一种()的存储结构?

   A. 随机存取

   B. 顺序存取

   C. 索引存取

   D. 散列存取

   首先顺序表底层是基于数组实现的 那么它肯定是支持随机访问的 因为我们可以直接使用下标想访问哪一个就访问哪一个 所以选择A 不要看到名字叫做顺序表就选择顺序存取 因为它并不需要按照顺序来进行存取链表才是 这里也没有建立索引去访问元素 也更不可能是散列存取了 散列存取我们会在后面的哈希表中进行介绍

#### 链表

前面我们介绍了如何使用数组实现线性表 我们接着来看第二种方式 我们可以使用链表来实现 那么什么是链表呢?

<img src="https://s2.loli.net/2022/07/23/ruemiRQplVy7q9s.png"/>

链表不同于顺序表 顺序表底层采用数组作为存储容器 需要分配一块连续且完整的内存空间进行使用 它通过一个指针来连接各个分散的结点 形成了一个链状的结构 每个结点存放一个元素 以及一个指向下一个结点的指针 通过这样一个一个相连 最后形成了链表 它不需要申请连续的空间 只需要按照顺序连接即可 虽然物理上可能不相邻 但是在逻辑上依然是每个元素相邻存放的 这样的结构叫做链表(单链表)

链表分为带头结点的链表和不带头结点的链表 带头结点的链表就是会有一个头结点指向后续的整个链表 但是头结点不存放数据:

<img src="https://s2.loli.net/2022/07/23/gRUEfOqbtrGN2JZ.png"/>

而不带头结点链表就像上面那样 第一个节点就是存放数据的结点 一般设计链表都会采用带头结点的结构 因为操作更加方便

那么我们就来尝试编写一个带头结点的链表:

```c
                            typedef int E; // 这个还是老样子

                            struct list_node {
                                
                                E element; // 保存当前元素
                                struct list_node *next; // 指向下一个结点的指针
                                
                            };

                            typedef struct list_node *Node; // 这里我们直接为结点指针起别名 可以直接作为表实现
```

同样的 我们先将初始化函数写好:

```c
                            void init_list(Node head) {
                                head->next = NULL; // 头结点默认下一个为NULL
                            }

                            int main() {
                                
                                struct list_node head; // 这里创建一个新的头结点 头结点不存放任何元素 只做连接 连接整个链表
                                init_list(&head); // 先进行初始化
                                
                            }
```

接着我们来设计一下链表的插入和删除 我们前面实现了顺序表的插入 那么链表的插入该怎么做呢?

<img src="https://s2.loli.net/2022/07/23/71dgFSWDfoELiXB.png"/>

我们可以先修改新插入的结点的后继结点(也就是下一个结点)指向 指向原本在这个位置的结点:

<img src="https://s2.loli.net/2022/07/23/8MNURYiacWZqwu6.png"/>

接着我们可以将前驱结点(也就是上一个结点)的后继结点指向修改为我们新插入的结点:

<img src="https://s2.loli.net/2022/07/23/ysETUJb6cgBz2Qx.png"/>

这样 我们就成功插入了一个新的结点 现在新插入的结点到达了原本的第二个位置上:

<img src="https://s2.loli.net/2022/07/23/Kb7jCiWa3o4AN8D.png"/>

按照这个思路 我们来实现一下 首先设计一下函数:

```c
                            void insert_list(Node head, E element, int index) {
                                    // head是头结点 element为待插入元素 index是待插入下标
                            }
```

接着我们需要先找到待插入位置的前驱结点:

```c
                            _Bool insert_list(Node head, E element, int index) {
                                
                                if(index < 1) return 0; // 如果插入的位置小于1 那肯定是非法的
                                while (--index) { // 通过--index的方式不断向后寻找前驱结点
                                    head = head->next; // 正常情况下继续向后找
                                    if(head == NULL) return 0;  
                                    // 如果在寻找的过程中发型已经没有后续结点了 那么说明index超出可插入的范围了 也是非法的 直接润
                                }

                                return 1;
                                
                            }
```

在循环操作完成后 如果没问题那么会找到对应插入位置的前驱结点 我们只需要按照上面分析的操作来编写代码即可:

```c
                            _Bool insert_list(Node head, E element, int index) {
                                
                                if(index < 1) return 0;
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                Node node = malloc(sizeof (struct list_node));
                                if(node == NULL) return 0; // 创建一个新的结点 如果内存空间申请失败返回0
                                node->element = element; // 将元素保存到新创建的结点中
                                node->next = head->next; // 先让新插入的节点指向原本位置上的这个结点
                                head->next = node; // 接着将前驱结点指向新的这个结点
                                return 1;
                                
                            }
```

这样 我们就编写好了链表的插入操作了 我们可以来测试一下:

```c
                            void print_list(Node head) {
                                
                                while (head->next) {
                                    head = head->next;
                                    printf("%d ", head->element); // 因为头结点不存放数据 所以从第二个开始打印
                                }
                                
                            }

                            int main() {
                                
                                struct list_node head;
                                init_list(&head);
                                for (int i = 0; i < 3; ++i) {
                                    insert_list(&head, i * 100, i); // 依次插入3个元素
                                }
                                print_list(&head); // 打印一下看看
                                
                            }
```

成功得到结果:

<img src="https://s2.loli.net/2022/07/23/1D94PILFxC52vRQ.png"/>

那么链表的插入我们研究完了 接着就是结点的删除了 那么我们如何实现删除操作呢? 实际上也会更简单一些 我们可以直接将待删除节点的前驱结点指向修改为待删除节点的下一个:

<img src="https://s2.loli.net/2022/07/23/N5sZx9T2a8lOzoC.png"/>

这样 在逻辑上来说 待删除结点其实已经不再链表中了 所以我们只需要释放掉待删除结点占用的内存空间就行了:

<img src="https://s2.loli.net/2022/07/23/tNYnBJe9pczUq1Z.png"/>

那么我们就按照这个思路来编写一下程序 首先还是设计函数:

```c
                            void delete_list(Node head, int index) {
                                // head就是头结点 index依然是待删除的结点位序
                            }
```

首先我们还是需要找到待删除结点的前驱结点:

```c
                            _Bool delete_list(Node head, int index) {
                                
                                if(index < 1) return 0; // 大体和上面是一样的
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                if(head->next == NULL) return 0; // 注意删除的范围 如果前驱结点的下一个已经是NULL了 那么也说明超过了范围

                                return 1;
                                
                            }
```

最后就是按照我们上面说的删除结点了:

```c
                            _Bool delete_list(Node head, int index) {
                                
                                if(index < 0) return 0;
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                if(head->next == NULL) return 0;
                                Node tmp = head->next; // 先拿到待删除结点
                                head->next = head->next->next; // 直接让前驱结点指向下一个的下一个结点
                                free(tmp); // 最后使用free函数释放掉待删除结点的内存
                                return 1;
                                
                            }
```

这样 我们就成功完成了链表的删除操作:

```c
                            int main() {
                                
                                struct list_node head;
                                init_list(&head);
                                for (int i = 0; i < 3; ++i) {
                                    insert_list(&head, i * 100, i);
                                }
                                delete_list(&head, 0); // 这里我们尝试删除一下第一个元素
                                print_list(&head);
                                
                            }
```

最后得到结果也是正确的:

<img src="https://s2.loli.net/2022/07/23/jnOKy6ls8wAqrHJ.png"/>

接着就是链表的一些其他操作了 这里我们也来实现一下 首先是获取对应位置上的元素:

```c
                            E *get_list(Node head, int index) {
                                
                                if(index < 1) return NULL; // 如果小于0那肯定不合法 返回NULL
                                do {
                                    head = head->next; // 因为不算头结点 所以使用do-while语句
                                    if(head == NULL) return NULL; // 如果已经超出长度那肯定也不行
                                } while (--index); // 到达index就结束
                                return &head->element;
                                
                            }
```

接着是查找对应元素的位置:

```c
                            int find_list(Node head, E element) {
                                
                                head = head->next; // 先走到第一个结点
                                int i = 1; // 计数器
                                while (head) {
                                    if(head->element == element) return i; // 如果找到 那么就返回i
                                    head = head->next; // 没找到就继续向后看
                                    ++i; // i记住要自增
                                }
                                return -1; // 都已经走到链表尾部了 那么就确实没找到了 返回-1
                                
                            }
```

接着来是求链表的长度 这个太简单了:

```c
                            int size_list(Node head) {
                                
                                int i = 0; // 从0开始
                                while (head->next) { // 如果下一个为NULL那就停止
                                    head = head->next;
                                    ++i; // 每向后找一个就+1
                                }
                                return i;
                                
                            }
```

这样 我们的链表就编写完成了 整个代码如下:

```c
                            #include <stdio.h>
                            #include <stdlib.h>

                            typedef int E;

                            struct list_node {
                                
                                E element;
                                struct list_node *next;
                                
                            };

                            typedef struct list_node *Node;

                            void init_list(Node node) {
                                node->next = NULL;
                            }

                            _Bool insert_list(Node head, E element, int index) {
                                
                                if(index < 1) return 0;
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }

                                Node node = malloc(sizeof(struct list_node));
                                if(node == NULL) return 0;
                                node->element = element;
                                node->next = head->next;
                                head->next = node;
                                return 1;
                                
                            }

                            _Bool delete_list(Node head, int index) {
                                
                                if(index < 1) return 0; // 大体和上面是一样的
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                if(head->next == NULL) return 0;

                                Node tmp = head->next;
                                head->next = head->next->next;
                                free(tmp);
                                return 1;
                                
                            }

                            E *get_list(Node head, int index) {
                                
                                if(index < 1) return 0;
                                do {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                } while (--index);
                                return &head->element;
                                
                            }

                            int find_list(Node head, E element) {
                                
                                head = head->next;
                                int i = 1;
                                while (head) {
                                    if(head->element == element) return i;
                                    head = head->next;
                                    ++i;
                                }
                                return -1;
                                
                            }

                            int size_list(Node head) {
                                
                                int i = -1;
                                while (head) {
                                    head = head->next;
                                    ++i;
                                }
                                return i;
                                
                            }
```

**问题:** 请问链式实现的线性表 插入, 删除, 获取元素操作的时间复杂度为?

- **插入:** 因为要寻找对应位置的前驱结点 所以平均时间复杂度为𝑂(𝑛) 但是不需要做任何的移动操作 效率肯定是比顺序表要高的
- **删除: **同上 所以平均时间复杂度为𝑂(𝑛)
- **获取元素: ** 由于必须要挨个向后寻找 才能找到对应的结点 所以时间复杂度为𝑂(𝑛) 不支持随机访问 只能顺序访问 比顺序表慢

**问题:** 什么情况下使用顺序表 什么情况下使用链表呢?

- 通过分析顺序表和链表的特性我们不难发现 链表在随机访问元素时 需要通过遍历来完成 而顺序表则利用数组的特性直接访问得到 所以 当我们读取数据多于插入或是删除数据的情况下时 使用顺序表会更好
- 而顺序表在插入元素时就显得有些鸡肋了 因为需要移动后续元素 整个移动操作会浪费时间 而链表则不需要 只需要修改结点 指向即可完成插入 所以在频繁出现插入或删除的情况下 使用链表会更好

**链表练习题:**

1. 在一个长度为`n (n>1)`的单链表上 设有头和尾两个指针 执行()操作与链表的长度有关?

   A. 删除单链表中的第一个元素

   B. 删除单链表中的最后一个元素

   C. 在单链表第一个元素前插入一个新元素

   D. 在单链表最后一个元素后插入一个新元素

   *注意题干 现在有指向链表头尾的两个指针 那么A, C肯定是可以直接通过头结点找到的 无论链表长度如何都不影响 D也可以直接通过尾指针进行拼接 只有B需要尾指针的前驱结点 此时只能从头开始遍历得到 所以选择B*

2. 在一个单链表HL中(HL为头结点指针) 若要向表头插入一个由指针p指向的结点 则执行?

   A. HL＝p; p->next＝HL;

   B. p->next＝HL; HL＝p;

   C. p->next＝HL; p＝HL;

   D. p->next＝HL->next; HL->next＝p;

   *既然要在表头插入一个数据 也就是说要在第一个位置插入 那么根据我们之前讲解的链表的插入 只需要将头结点指向新的结点 再让新的结点指向原本的第一个结点即可 所以选择D*

3. 链表不具备的特点是?

   A. 可随机访问任一结点

   B. 插入删除不需要移动元素

   C. 不必事先估计存储空间

   D. 所需空间与其长度成正比

   *我们前面说了 链表由于是链式存储结构 无法直接访问到对应下标的元素 所以我们只能通过遍历去找到对应位置的元素 故选择A*

#### 双向链表和循环链表

前面我们介绍了单链表 通过这样的链式存储 我们不用再像顺序表那样一次性申请一段连续的空间 而是只需要单独为结点申请内存空间 同时在插入和删除的速度上也比顺序表轻松 不过有一个问题就是 如果我们想要操作某一个结点 比如删除或是插入 那么由于单链表的性质 我们只能先去找到它的前驱结点 才能进行

为了解决这种查找前驱结点非常麻烦的问题 我们可以让结点不仅保存指向后续结点的指针 同时也保存指向前驱结点的指针:

<img src="https://s2.loli.net/2022/07/24/oeXm6nyW7I9lPMf.png"/>

这样我们无论在哪个结点 都能够快速找到对应的前驱结点 就很方便了 这样的链表我们成为双向链表(双链表)

这里我们也来尝试实现一下 首先定义好结构体:

```c
                            typedef int E;

                            struct list_node {
                                
                                E element; // 保存当前元素
                                struct list_node *next; //指向下一个结点的指针
                                struct list_node *prev; // 指向上一个结点的指针
                                
                            };

                            typedef struct list_node *Node;
```

接着是初始化方法 在初始化时需要将前驱和后继都设置为NULL:

```c
                            void init_node(Node node) {
                                node->next = node->prev = NULL;
                            }

                            int main() {
                                
                                struct list_node head;
                                init_node(&head);
                                
                            }
```

接着是双向链表的插入操作 这就比单链表要麻烦一些了 我们先来分析一下:

<img src="https://s2.loli.net/2022/07/24/MYwlVZ2fXB6icPt.png"/>

首先我们需要考虑后继结点 当新的结点插入之后 新的结点的后继结点就是原本在此位置上的结点 所以我们可以先将待插入结点的后继指针指向此位置上的结点:

<img src="https://s2.loli.net/2022/07/24/IDYwp5gdPcSyFQO.png"/>

由于是双向链表 所以我们需要将原本在此位置上的结点的前驱指针指向新的结点:

<img src="https://s2.loli.net/2022/07/24/5CKQ6LnzxGm4pYd.png"/>

接着我们来处理一下前驱结点 首先将前驱结点的后继指针修改为新的结点:

<img src="https://s2.loli.net/2022/07/24/vmEViApU36FonJz.png"/>

最后我们将新的结点的前驱指针指向前驱结点即可:

<img src="https://s2.loli.net/2022/07/24/C65IuomOVdAaWZ8.png"/>

这样 我们就完成了双向链表中结点的插入操作 按照这个思路 我们来设计一下函数吧:

```c
                            _Bool insert_list(Node head, E element, int index) {
                                
                                if(index < 1) return 0; // 跟单链表一样 还是先找到对应的位置
                                
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                
                                Node node = malloc(sizeof (struct list_node)); // 创建新的结点
                                
                                if(node == NULL) return 0;
                                	node->element = element;

                                if(head->next) { // 首先处理后继结点 现在有两种情况 一种是后继结点不存在的情况 还有一种是后继结点存在的情况
                                    head->next->prev = node; // 如果存在则修改对应的两个指针
                                    node->next = head->next;
                                } else {
                                    node->next = NULL; // 不存在直接将新结点的后继指针置为NULL
                                }

                                head->next = node; // 接着是前驱结点 直接操作就行
                                node->prev = head;
                                return 1;
                                
                            }
```

这样 我们就编写好了双向链表表的插入操作 来测试一下吧:

```c
                            int main() {
                                
                                struct list_node head;
                                init_node(&head);
                                for (int i = 0; i < 5; ++i) // 插5个元素吧
                                    insert_list(&head, i * 100, i);

                                Node node = &head; // 先来正向遍历一次
                                do {
                                    node = node->next;
                                    printf("%d -> ", node->element);
                                } while (node->next != NULL);

                                printf("\n");  // 再来反向遍历一次
                                do {
                                    printf("%d -> ", node->element);
                                    node = node->prev;
                                } while (node->prev != NULL);
                                
                            }
```

可以看到结果没有问题:

<img src="https://s2.loli.net/2022/07/24/DZ7zStdGB4EsvaW.png"/>

无论是正向遍历还是反向遍历 都可以正常完成 相比单链表的灵活度肯定是更大的 我们接着来看删除操作 其实删除操作也是差不多的方式:

<img src="https://s2.loli.net/2022/07/24/WgxjXBDAalYFGSH.png"/>

我们只需将前驱结点和后继结点的指向修改即可:

<img src="https://s2.loli.net/2022/07/24/3aU7zV1N5Mox2Qk.png"/>

接着直接删除对应的结点即可:

<img src="https://s2.loli.net/2022/07/24/L1zCq26k5BaGOlm.png"/>

现在我们就来编码吧:

```c
                            _Bool delete_list(Node head, int index) {
                                
                                if(index < 1) return 0; // 跟单链表一样 还是先找到对应的位置
                                
                                while (--index) {
                                    head = head->next;
                                    if(head == NULL) return 0;
                                }
                                
                                if(head->next == NULL) return 0;

                                Node tmp = head->next; // 先拿到待删除结点
                                if(head->next->next) { // 这里有两种情况待删除结点存在后继结点或是不存在
                                    head->next->next->prev = head;
                                    head->next = head->next->next; // 按照上面分析的来
                                }else{
                                    head->next = NULL; // 相当于删的是最后一个结点 所以直接后继为NULL就完事
                                }
                                free(tmp); // 最后释放已删除结点的内存
                                return 1;
                                
                            }
```

这样 我们就实现了双向链表的插入和删除操作 其它操作这里就不演示了

接着我们再来简单认识一下另一种类型的链表 循环链表 这种链表实际上和前面我们讲的链表是一样的 但是它的最后一个结点 是与头结点相连的 双向链表和单向链表都可以做成这样的环形结构 我们这里以单链表为例:

<img src="https://s2.loli.net/2022/07/24/KZl4SJVYQ5cfv7b.png"/>

这种类型的链表实际上与普通链表的唯一区别就在于最后是否连接到头结点 因此循环链表支持从任意一个结点出发都可以到达任何的结点 而普通的链表则只能从头结点出发才能到达任意结点 同样也是为了更灵活而设计的

**链表练习题:**

1. 与单链表相比 双链表的优点之一是?

   A. 插入, 删除操作更简单

   B. 可以进行随机访问

   C. 可以省略表头指针或表尾指针

   D. 顺序访问相邻结点更灵活

   *首先插入删除操作并没有更简单 反而更复杂了 随机访问肯定也是不行的 省略表头表尾指针实际上单链表也可以 所以直接冲D就完事了*

2. 非空的循环单链表head的尾结点(由p所指向)满足?

   A. p->next == NULL B

   B. p == NULL

   C. p->next == head

   D. p == head

   *前面我们说了 循环链表实际上唯一区别就是尾部的下一个结点会指向头部 所以这里选择C*

3. 若某表最常用的操作是在最后一个结点之后插入一个结点或删除最后一个结点 则采用上面存储方式最节省运算时间?

   A. 单链表

   B. 给出表头指针的单循环链表

   C. 双链表

   D. 带头结点的双循环链表

   *题干说明了常用的是在尾结点插入或删除尾结点 那么此时不仅需要快速找到最后一个结点 也需要快速找到最后一个结点的前驱结点 所以肯定是使用双向链表 为了快速找到尾结点 使用循环双向链表从头结点直接向前就能找到 所以选择D*

4. 如果对线性表的操作只有两种 即删除第一个元素 在最后一个元素的后面插入新元素 则最好使用?

   A. 只有表头指针没有表尾指针的循环单链表

   B. 只有表尾指针没有表头指针的循环单链表

   C. 非循环双链表

   D. 循环双链表

   *首先这里需要操作两个内容 一个是删除第一个元素 另一个是在最后插入新元素 所以A的话只有表头指针虽然循环但是还是得往后遍历才行 而B正好符合 因为循环链表的尾指针可以快速到达头结点 C不可能 D的话 循环双链表也可以 但是没有单链表节省空间 故B是最优解*

### 特殊线性表

前面我们讲解的基础的线性表 通过使用线性表 我们就可以很方便地对数据进行管理了 这一部分 我们将继续认识一些特殊的线性表 它有着特别的规则 在特定场景有着很大的作用 也是考察的重点

#### 栈

栈(也叫堆栈 Stack)是一种特殊的线性表 它只能在在表尾进行插入和删除操作 就像下面这样:

<img src="https://s2.loli.net/2022/07/24/D3heysaM9EpAgS4.png"/>

也就是说 我们只能在一端就行插入和删除 当我们依次插入1, 2, 3, 4这四个元素后 连续进行四次删除操作 删除的顺序刚好相反: 4, 3, 2, 1 我们一般将其竖着看:

<img src="https://s2.loli.net/2022/07/24/2NxUpCIRLoZt9Ky.png"/>

底部称为栈底 顶部称为栈顶 所有的操作只能在栈顶进行 也就是说 被压在下方的元素 只能等待其上方的元素出栈之后才能取出 就像我们往箱子里里面放的书一样 因为只有一个口取出里面的物品 所以被压在下面的书只能等上面的书被拿出来之后才能取出 这就是栈的思想 它是一种先进后出的数据结构(FILO, First In, Last Out)

实现栈也是非常简单的 可以基于我们前面的顺序表或是链表 这里我们先使用顺序表来实现一下 这里我们需要实现两个新的操作:

- pop: 出栈操作 从栈顶取出一个元素
- push: 入栈操作 向栈中压入一个新的元素

首先还是按照我们的顺序表就行编写:

```c
                            typedef int E;

                            struct Stack {
                                
                                E *array;
                                int capacity;
                                int top; // 这里使用top来表示当前的栈顶位置 存的是栈顶元素的下标
                                
                            };

                            typedef struct Stack *array_stack; // 起个别名
```

接着我们需要编写一个初始化方法:

```c
                            _Bool init_stack(array_stack stack) {
                                
                                stack->array = malloc(sizeof(E) * 10);
                                if(stack->array == NULL) return 0;
                                stack->capacity = 10; // 容量还是10
                                stack->top = -1; // 由于栈内没有元素 那么栈顶默认就为-1
                                return 1;
                                
                            }
```

```c
                            int main() {
                                
                                struct Stack stack;
                                init_stack(&stack);
                                
                            }
```

接着就是栈的两个操作了 一个是入栈操作 一个是出栈操作:

```c
                            _Bool push_stack(array_stack stack, E element) {
                                // 入栈操作只需要给元素就可以 不需要index 因为只能从尾部入栈
                            }
```

由于入栈只能在尾部插入 所以就很好写了:

```c
                            _Bool push_stack(array_stack stack, E element) {
                                
                                stack->array[stack->top + 1] = element; // 直接设定栈顶元素
                                stack->top++; // 栈顶top变量记得自增
                                return 1;
                                
                            }
```

我们来测试一下吧:

```c
                            void print_stack(array_stack stack) {
                                
                                for (int i = 0; i < stack->top + 1; ++i)
                                    printf("%d, ", stack->array[i]);
                                
                                printf("\n");
                                
                            }

                            int main() {
                                
                                struct Stack stack;
                                init_stack(&stack);
                                for (int i = 0; i < 3; ++i)
                                    push_stack(&stack, i*100);
                                
                                print_stack(&stack);
                                
                            }
```

测试结果也是正确的:

<img src="https://s2.loli.net/2022/07/24/cDwAgi8FnyQBpRT.png"/>

可以看到 从栈底到栈顶一次是0, 100, 200 不过我们现在的`push`操作还不够完美 因为栈有可能塞满 所以要进行扩容处理:

```c
                            _Bool push_stack(array_stack stack, E element) {
                                
                                if(stack->top + 1 == stack->capacity) { // 栈顶+1如果等于容量的话 那么说明已经塞满了
                                    
                                    int new_capacity = stack->capacity + (stack->capacity >> 1); // 大体操作和顺序表一致
                                    E *new_array = realloc(stack->array, new_capacity * sizeof(E));
                                    if(new_array == NULL) return 0;
                                    stack->array = new_array;
                                    stack->capacity = new_capacity;
                                    
                                }
                                
                                stack->array[stack->top + 1] = element;
                                stack->top++;
                                return 1;
                                
                            }
```

这样我们的入栈操作就编写完成了 接着是出栈操作 出栈操作我们只需要将栈顶元素取出即可:

```c
                            _Bool is_empty(array_stack stack) { // 在出栈之前 我们还需要使用isEmpty判断一下栈是否为空 空栈元素都没有出个毛
                                return stack->top == -1;   
                            }

                            E pop_stack(array_stack stack) {
                                return stack->array[stack->top--]; // 直接返回栈顶元素 注意多加一个自减操作
                            }
```

我们来测试一下吧:

```c
                            int main() {
                                
                                struct Stack stack;
                                init_stack(&stack);
                                for (int i = 0; i < 3; ++i) {
                                    push_stack(&stack, i*100);
                                }
                                print_stack(&stack);
                                while (!is_empty(&stack)) {
                                    printf("%d ", pop_stack(&stack)); // 将栈中所有元素依次出栈
                                }
                                
                            }
```

可以看到 出栈顺序和入栈顺序是完全相反的:

<img src="https://s2.loli.net/2022/07/24/U1SrtmFs3ibGO78.png"/>

当然使用数组实现栈除了这种可以自己扩容的之外 也由固定大小的栈 当栈已满时 就无法再进行入栈操作了

不过有些时候 栈的利用率可能会很低 这个时候我们可以将一个固定长度的数组共享给两个栈来使用:

<img src="https://s2.loli.net/2022/07/24/HRveZ8Ed2TrtaC7.png"/>

数组的两头分别作为两个栈的栈底 当两个栈的栈顶指针相遇时(栈顶指针下标之差绝对值为1时) 表示栈已满 通过这种方式 我们就可以将数组占用的空间更充分地使用 这样的栈我们称为**共享栈**

前面我们演示了使用顺序表实现栈 我们接着来看如何使用链表来实现栈 实际上使用链表会更加的方便 我们可以直接将头结点指向栈顶结点 而栈顶结点连接后续的栈内结点:

<img src="https://s2.loli.net/2022/07/24/outf2S7D3WzQK8c.png"/>

当有新的元素入栈 只需要在链表头部插入新的结点即可 我们来尝试编写一下:

```c
                            typedef int E;

                            struct list_node {
                                
                                E element;
                                struct list_node *next;
                                
                            };
                            typedef struct list_node *Node;

                            void init_stack(Node head) {
                                head->next = NULL;
                            }

                            int main() {
                                
                                struct list_node head;
                                init_stack(&head);
                                
                            }
```

接着我们来编写一下入栈操作:

<img src="https://s2.loli.net/2022/07/24/GdBj3g5YRFzSsVw.png"/>

代码如下:

```c
                            _Bool push_stack(Node head, E element) {
                                
                                Node node = malloc(sizeof(struct list_node)); // 创建新的结点
                                if(node == NULL) return 0; // 失败就返回0
                                node->next = head->next; // 将当前结点的下一个设定为头结点的下一个
                                node->element = element; // 设置元素
                                head->next = node; // 将头结点的下一个设定为当前结点
                                return 1;
                                
                            }
```

我们来编写一个测试:

```c
                            void print_stack(Node head) {
                                
                                head = head->next;
                                while (head){
                                    printf("%d ", head->element);
                                    head = head->next;
                                }
                                printf("\n");

                            }

                            int main() {
                                
                                struct list_node head;
                                init_stack(&head);
                                for (int i = 0; i < 3; ++i)
                                    push_stack(&head, i*100);

                                print_stack(&head);
                                
                            }
```

可以看到结果没有问题:

<img src="https://s2.loli.net/2022/07/24/fy6ZCNqd3eJYIrG.png"/>

其实出栈也是同理 所以我们只需要将第一个元素移除即可:

```c
                            _Bool is_empty(Node head) {
                                return head->next == NULL; // 判断栈是否为空只需要看头结点下一个是否为NULL即可
                            }

                            E pop_stack(Node head) {
                                
                                Node top = head->next;
                                head->next = head->next->next;
                                E e = top->element;
                                free(top); // 别忘了释放结点的内存
                                return e; // 返回出栈元素
                                
                            }
```

这里我们来测试一下:

```c
                            int main() {
                                
                                struct list_node head;
                                init_stack(&head);
                                for (int i = 0; i < 3; ++i) {
                                    push_stack(&head, i*100);
                                    
                                print_stack(&head);
                                while (!is_empty(&head)) {
                                    printf("%d ", pop_stack(&head)); // 将栈中所有元素依次出栈
                                }
                                
                            }
```

<img src="https://s2.loli.net/2022/07/24/xjOvlieXr2V9BZg.png"/>

实际上无论使用链表还是顺序表 都可以很轻松地实现栈 因为栈的插入和删除操作很特殊

**栈练习题: **

1. 若进栈序列为1, 2, 3, 4 则不可能得到的出栈序列是?

   A. 3, 2,1, 4

   B. 3, 2, 4, 1

   C. 4, 2, 3, 1

   D. 2, 3, 4, 1

   *注意进栈并不一定会一次性全部进栈 可能会出现边进边出的情况 所以出栈的顺序可能有很多种情况 首先来看A 第一个出栈的是3 那么按照顺序 说明前面一定入栈了`2, 1` 在出栈时4还没有入栈 然后是`2, 1`最后是4 没有问题 接着是B 跟前面的A一样 不过这次是先出站`3, 2` 而1留在栈中 接着4入栈 然后再让`4, 1`出栈 也是正确的 然后是C 首先是4出栈 那么说明前三个一定都入栈了 而此时却紧接着的一定是3 而这里是2 错误 所以选择C*

2. 假设有5个整数以1, 2, 3, 4, 5的顺序被压入堆栈 且出栈顺序为3, 5, 4, 2, 1 那么栈大小至少为?

   A. 2

   B. 3

   C. 4

   D. 5

   *首先我们分析一下 第一个出栈的元素为3 那么也就是说前面的`1, 2`都在栈内 所以大小至少为3 然后是5 那么说明此时栈内为1, 2, 4 算是出栈的5 那么至少需要的大小就是4了 所以选择C*

#### 队列

前面我们学习了栈 栈中元素只能栈顶出入 它是一种特殊的线性表 同样的 队列(Queue)也是一种特殊的线性表

就像我们在城市, 食堂需要排队一样 我们总是排成一列 先到的人就排在前面 后来的人就排在后面 越前面的人越先完成任务 这就是队列 队列有队头和队尾:

<img src="https://s2.loli.net/2022/07/25/xBuZckTNtR54AEq.png"/>

秉承先来后到的原则 队列中的元素只能从队尾进入 只能从队首出去 也就是说 入队顺序为1, 2, 3, 4 那么出队顺序也一定是1、2、3、4 所以队列是一种先进先出(FIFO, First In, First Out)的数据结构

想要实现队列也是很简单的 也可以通过两种线性表来实现 我们先来看看使用顺序表如何实现队列 假设一开始的时候队列中有0个元素 队首和队尾一般都初始都是-1这个位置:

<img src="https://s2.loli.net/2022/07/25/OKVFSEfQIkDjzNu.png"/>

此时有新的元素入队了 队尾向后移动一格(+1) 然后在所指向位置插入新的元素:

<img src="https://s2.loli.net/2022/07/25/Pd6ZRUxKIhzVF9E.png"/>

之后都是同样的方式进行插入 队尾会一直向后移动:

<img src="https://s2.loli.net/2022/07/25/8w3Mlroz25EeIcL.png"/>

现在我们想要执行出队操作了 那么需要将队首向后移动一格 然后删除队首指向的元素:

<img src="https://s2.loli.net/2022/07/25/LaZsrtwi8AkW9gh.png"/>

看起来设计的还挺不错的 不过这样有一个问题 这个队列是一次性的 如果队列经过反复出队入队操作 那么最后指针会直接指向数组的最后 如果我们延长数组的话 也不是一个办法 不可能无限制的延伸下去吧? 所以一般我们采用循环队列的形式 来实现重复使用一个数组(不过就没办法扩容了 大小是固定的)

<img src="https://s2.loli.net/2022/07/25/MNaqpZRgkHcTlCU.png"/>

我们可以在有移动队首队尾指针时 考虑循环的问题 也就是说如果到达了数组尽头 那么就直接从数组的前面重新开始计算这样就相当于逻辑上都循环了 队首和队尾指针在一开始的时候都指向同一个位置 每入队一个新的元素 依然是先让队尾后移一位 在所指向位置插入元素 出队同理

不过这样还是有问题 既然是循环的 那么怎么判断队列是否已满呢?

<img src="https://s2.loli.net/2022/07/25/eptxXASywr3b4c9.png"/>

由于队首指针和队尾指针重合时表示队列为空 所以我们只能舍弃一个存储单元 当队尾距离队首一个单元的时候 表示队列已满

好了 现在理论讲解完毕 我们可以开始编写代码了:

```c
                            typedef int E;

                            struct Queue {
                                
                                E *array;
                                int capacity; // 数组容量
                                int rear, front; // 队尾, 队首指针
                                
                            };

                            typedef struct Queue *array_queue;
```

接着我们来对其进行初始化:

```c
                            _Bool init_queue(array_queue queue) {

                                queue->array = malloc(sizeof(E) * 10);

                                if (queue->array == NULL) return 0;

                                queue->front = queue->rear = 0; // 默认情况下队首和队尾都指向0的位置
                                return 1;

                            }

                            int main() {

                                struct Queue queue;
                                init_queue(&queue);

                            }
```

接着我们来编写一下入队操作:

```c
                            _Bool offer_queue(array_queue queue, E element) {
                                
                                if((queue->rear + 1) % queue->capacity == queue->front) // 先判断队列是否已满 如果队尾下一个就是队首 那么说明已满
                                    return 0;
                                queue->rear = (queue->rear + 1) % queue->capacity;  // 队尾先向前移动一位 注意取余计算才能实现循环
                                queue->array[queue->rear] = element; // 在新的位置插入元素
                                return 1;
                                
                            }
```

我们来测试一下:

```c
                            void print_queue(array_queue queue) {

                                int i = queue->front; // 遍历队列需要从队首开始
                                do {
                                    i = (i+1) % queue->capacity; // 先向后循环移动
                                    printf("%d ", queue->array[i]); // 然后打印当前位置上的元素
                                } while (i != queue->rear); // 当到达队尾时 结束

                            }

                            int main() {

                                struct Queue queue;
                                inti_queue(&queue);
                                for (int i = 0; i < 5; ++i)
                                    offer_queue(&queue, i*100);

                                print_queue(&queue);

                            }
```

最后结果如下:

<img src="https://s2.loli.net/2022/07/25/zLRWSAH8OaTgFBv.png"/>

我们接着来看出队操作:

```c
                            _Bool is_empty(array_queue queue) { // 在出队之前需要先看看容量是否足够
                                return queue->rear == queue->front;
                            }

                            E poll_queue(array_queue queue) {
                                
                                queue->front = (queue->front + 1) % queue->capacity; // 先将队首指针后移
                                return queue->array[queue->front]; // 出队 完事
                                
                            }
```

我们来测试一下吧:

```c
                            int main() {
                                
                                struct Queue queue;
                                init_queue(&queue);
                                for (int i = 0; i < 5; ++i) {
                                    offer_queue(&queue, i * 100);
                                }
                                print_queue(&queue);
                                while (!is_empty(&queue)) {
                                    printf("%d ", poll_queue(&queue));
                                }
                                
                            }
```

我们来看看结果:

<img src="https://s2.loli.net/2022/07/25/45dI2h7iWPuQJRp.png"/>

可以看到 队列是先进先出的 我们是以什么顺序放入队列中 那么出来的就是什么顺序

同样的 队列也可以使用链表来实现 并且使用链表的话就不需要关心容量之类的问题了 会更加灵活一些:

<img src="https://s2.loli.net/2022/07/25/lwGgHXqAV5z2KNk.png"/>

注意 我们需要同时保存队首和队尾两个指针 因为是单链表 所以队首需要存放指向头结点的指针 因为需要的是前驱结点 而队尾则直接是指向尾结点的指针即可 后面只需要直接在后面拼接就行

当有新的元素入队时 只需要拼在队尾就行了 同时队尾指针也要后移一位:

<img src="https://s2.loli.net/2022/07/25/ufmFEwrS9xVKoIZ.png"/>

出队时 只需要移除队首指向的下一个元素即可:

<img src="https://s2.loli.net/2022/07/25/geJRFwHKhGT69XD.png"/>

那么我们就按照这个思路 来编写一下代码吧:

```c
                            typedef int E;

                            struct LNode {
                                
                                E element;
                                struct LNode *next;
                                
                            };

                            typedef struct LNode *Node;

                            struct Queue {
                                Node front, rear;
                            };

                            typedef struct Queue *linked_queue; // 因为要存储首位两个指针 所以这里封装一个新的结构体吧
```

接着是初始化 初始化的时候 需要把头结点先创建出来:

```c
                            _Bool init_queue(linked_queue queue) {

                                Node node = malloc(sizeof(struct LNode));

                                if (node == NULL) return 0;

                                node->next = NULL;
                                queue->front = queue->rear = node; // 一开始两个指针都是指向头结点的 表示队列为空
                                return 1;

                            }

                            int main() {

                                struct Queue queue;
                                init_queue(&queue);

                            }
```

首先是入队操作 入队其实直接在后面插入新的结点就行了:

```c
                            _Bool offer_queue(linked_queue queue, E element) {
                                
                                Node node = malloc(sizeof(struct LNode));
                                if(node == NULL) return 0;
                                node->next = NULL;
                                node->element = element;
                                queue->rear->next = node; // 先让尾结点的下一个指向新的结点
                                queue->rear = node; // 然后让队尾指针指向新的尾结点
                                return 1;
                                
                            }
```

我们来测试一下看看:

```c
                            void print_queue(linked_queue queue) {
                                
                                Node node = queue->front->next;
                                while (1) { // 注意不能直接判空 因为前面我们没考虑 也就没将新结点next设定为NULL
                                    printf("%d ", node->element);
                                    if(node == queue->rear) break; // 当已经打印最后一个元素后 再结束
                                    else node = node->next;
                                }
                                
                            }

                            int main() {
                                
                                struct Queue queue;
                                init_queue(&queue);
                                for (int i = 0; i < 5; ++i) {
                                    offer_queue(&queue, i*100);
                                }
                                print_queue(&queue);
                                
                            }
```

测试结果如下:

<img src="https://s2.loli.net/2022/07/25/SqeNUgimC4I5aZD.png"/>

接着是出队操作 出队操作要相对麻烦一点:

```c
                            E poll_queue(linked_queue queue) {
                                
                                E e = queue->front->next->element;
                                Node node = queue->front->next;
                                queue->front->next = queue->front->next->next; // 直接让头结点指向下下个结点
                                if(queue->rear == node) queue->rear = queue->front; // 如果队尾就是待出队的结点 那么队尾回到队首位置上
                                free(node); // 释放内存
                                return e;
                                
                            }
```

这样 我们就编写好了:

```c
                            int main() {
                                
                                struct Queue queue;
                                init_queue(&queue);
                                for (int i = 0; i < 5; ++i) {
                                    offer_queue(&queue, i*100);
                                }
                                print_queue(&queue);
                                while (!is_empty(&queue)){
                                    printf("%d ", poll_queue(&queue));
                                }
                                
                            }
```

测试结果如下:

<img src="https://s2.loli.net/2022/07/25/KT8mn2RkxPvgZuF.png"/>

效果和前面的数组实现是一样的 只不过使用链表会更加灵活一些

**队列练习题:**

1. 使用链表方式存储的队列 在进行出队操作时需要?

   A. 仅修改头结点指向

   B. 仅修改尾指针

   C. 头结点指向, 尾指针都要修改

   D. 头结点指向, 尾指针可能都要修改

   *首先出队肯定是要动头结点指向的 但是不一定需要动尾指针 因为只有当尾指针指向的是待出队的元素时才需要 因为执行后队列就为空了 所以需要将队尾指针移回头结点处 选择D*

2. 引起循环队列队头位置发生变化的操作是?

   A. 出队

   B. 入队

   C. 获取队头元素

   D. 获取队尾元素

   *这个题还是很简单的 因为只有出队操作才会使得队头位置后移 所以选择A*

### 算法实战

欢迎来到线性结构篇算法实战 这一部分我们将从算法相关题目上下手 解决实际问题 其中链表作为重点考察项目

#### (简单) 删除链表中重复元素

本题来自LeetCode: [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)

给定一个已排序的链表的头 head(注意是无头结点的链表 上来第一个结点就是存放第一个元素) 删除所有重复的元素 使每个元素只出现一次  返回已排序的链表

示例1: 

> <img src="https://assets.leetcode.com/uploads/2021/01/04/list1.jpg"/>
>
> 输入: head = [1,1,2]
> 输出: [1,2]

示例2: 

> <img src="https://assets.leetcode.com/uploads/2021/01/04/list2.jpg"/>
>
> 输入: head = [1,1,2,3,3]
> 输出: [1,2,3]

这道题实际上比较简单 只是考察各位小伙伴对于链表数据结构的掌握程度 我们只需要牢牢记住如何对链表中的元素进行删除操作就能轻松解决这道题了

#### (简单) 反转链表

本题来自LeetCode: [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

给你单链表的头节点head 请你反转链表 并返回反转后的链表

示例1:

> <img src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg"/>
>
> 输入: head = [1,2,3,4,5]
> 输出: [5,4,3,2,1]

示例2:

> <img src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg"/>
>
> 输入: head = [1,2]
> 输出: [2,1]

这道题依然是考察各位小伙伴对于链表相关操作的掌握程度 我们如何才能将一个链表的顺序进行反转 关键就在于如何修改每个节点的指针指向

```c
                            struct list_node* reverse_list(struct list_node *head) {
                                
                                struct list_node *new_head = NULL, *tmp; // 创建一个指针存放新的头结点(注意默认要为NULL) 和一个中间暂存指针
                                while (head != NULL) { // 这里利用head不断向后遍历，来依次修改每个结点的指向
                                    tmp = head; // 先暂存当前结点
                                    head = head->next; // head可以先后移了
                                    tmp->next = new_head; // 将暂存节点的下一个节点 指向前一个结点
                                    new_head = tmp; // 最后新的头结点就是tmp所指向结点 这样循环操作直到结束
                                }
                                return new_head; // 最后返回新的结点即可
                                
                            }
```

#### (中等) 旋转链表

本题来自LeetCode: [61. 旋转链表](https://leetcode.cn/problems/rotate-list/)

给你一个链表的头节点 head 旋转链表 将链表每个节点向右移动 k 个位置

示例1:

> <img src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg"/>
>
> 输入: head = [1,2]
> 输出: [2,1]

示例2:

> <img src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg"/>
>
> 输入: head = [0,1,2], k = 4
> 输出: [2,0,1]

这道题需要我们进行一些思考了 首先我们要知道 在经过旋转之后最终的头结点是哪一个 在知道后 这道题就很简单了 我们只需要断掉对应头结点的指针即可 最后返回头结点 就是旋转之后的链表了

```c
                            struct list_node* rotate_right(struct list_node *head, int k) {
                                
                                if(head == NULL || k == 0) return head; // 如果给进来的链表是空的 或者说k为0 那么就没必要再继续了
                                struct list_node *node = head;
                                int len = 1;
                                while (node->next) { // 先来算一波链表的长度
                                    node = node->next;
                                    len++;
                                }
                                if(k == len) return head; // 如果len和k长度一样 那也没必要继续了

                                node->next = head; // 将链表连起来变成循环的 一会再切割
                                int index = len - k % len; // 计算头结点最终位置

                                node = head;
                                while (--index) node = node->next;
                                head = node->next; // 找到新的头结点
                                node->next = NULL; // 切断尾部与头部
                                return head; // 返回新的头结点
                                
                            }
```

#### (简单) 有效的括号

本题来自LeetCode: [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s  判断字符串是否有效

有效字符串需满足:

1. 左括号必须用相同类型的右括号闭合
2. 左括号必须以正确的顺序闭合

示例1:

> 输入: s = "()"
> 输出: true

示例2:

> 输入: s = "()[]{}"
> 输出: true

示例3:

> 输入: s = "(]"
> 输出: false

示例4:

> 输入: s = "([)]"
> 输出: false

示例5:

> 输入: s = "{[]}"
> 输出: true

题干很明确 就是需要我们去对这些括号完成匹配 如果给定字符串中的括号无法完成一一匹配的话 那么就表示匹配失败。实际上这种问题我们就可以利用前面学习的栈这种数据结构来解决 我们可以将所有括号的左半部分放入栈中 当遇到右半部分时 进行匹配 如果匹配失败 那么就失败 如果匹配成功 那么就消耗一个左半部分 直到括号消耗完毕

```c
                            #include <stdlib.h>
                            #include <stdbool.h>
                            #include <string.h>

                            typedef char E;
                            struct LNode {
                                
                                E element;
                                struct LNode *next;
                                
                            };
                            typedef struct LNode *Node;

                            void init_stack(Node head) {
                                head->next = NULL;
                            }

                            _Bool push_stack(Node head, E element) {
                                
                                Node node = malloc(sizeof(struct LNode));
                                if(node == NULL) return 0;
                                node->next = head->next;
                                node->element = element;
                                head->next = node;
                                return 1;
                                
                            }

                            _Bool is_empty(Node head) {
                                return head->next == NULL;
                            }

                            E pop_stack(Node head) {
                                
                                Node top = head->next;
                                head->next = head->next->next;
                                E e = top->element;
                                free(top);
                                return e;
                                
                            }

                            bool is_valid(char *s) {
                                
                                unsigned long len = strlen(s);
                                if(len % 2 == 1) return false; // 如果长度不是偶数 那么一定不能成功匹配
                                struct LNode head;
                                init_stack(&head);
                                for (int i = 0; i < len; ++i) {
                                    char c = s[i];
                                    if(c == '(' || c == '[' || c == '{') {
                                        push_stack(&head, c);
                                    }else {
                                        if(is_empty(&head)) return false;
                                        if(c == ')') {
                                            if(pop_stack(&head) != '(') return false;
                                        } else if(c == ']') {
                                            if(pop_stack(&head) != '[') return false;
                                        } else {
                                            if(pop_stack(&head) != '{') return false;
                                        }
                                    }
                                }
                                return i_empty(&head);
                                
                            }
```

一般遇到括号匹配问题, 算式计算问题 都可以使用栈这种数据结构来轻松解决 当然使用C语言太过原始 像Java, C++这些语言一般系统库都会直接提供栈的实现类 所以我们在打比赛时 可以尽量选择这些方便的语言 能节省不少时间

#### (简单) 第 k 个缺失的正整数

本题来自LeetCode: [1539. 第 k 个缺失的正整数](https://leetcode.cn/problems/kth-missing-positive-number/)

给你一个严格升序排列的正整数数组 arr 和一个整数 k 请你找到这个数组里第 k 个缺失的正整数

示例1:

> 输入: arr = [2,3,4,7,11], k = 5
> 输出: 9
> 解释: 缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 第5个缺失的正整数为9

示例2:

> 输入: arr = [1,2,3,4], k = 2
> 输出: 6
> 解释: 缺失的正整数包括 [5,6,7,...] 第2个缺失的正整数为6

实际上这种问题 我们第一个能够想到的就是直接通过遍历挨个寻找 从头开始一个一个找 总能找到第K个吧? 我们可以很轻松地得到如下的代码:

```c
                            int findkth_positive(int *arr, int arr_size, int k) {
                                
                                int j = 1, i = 0; // 直接从第一个元素开始挨个找
                                while (i < arr_size) {
                                    if(arr[i] != j) {
                                        if(--k == 0) return j; //发现不相等时 相当于找到了一个数 k自减 如果自减后为0 那么说明已经找到第K个了 直接返回对应的j
                                    } else{
                                        i++; // 相等的话就继续看下一个
                                    }
                                    j++; // 每一轮j自增 表示下一轮应该按顺序匹配的数
                                }
                                return j + k - 1; // 如果遍历完了都还没找到 那就按顺序直接算出下一个
                                
                            }
```

不过这样的效率并不高 如果这个数组特别长的话 那么我们总不可能还是挨个看吧? 这样的遍历查找算法的时间复杂度为𝑂(𝑛)*O*(*n*) 那么有没有更好的算法能够解决这种问题呢?

既然这个数组是有序的 那么我们不妨直接采用二分搜索的思想 通过使用二分搜索 我们就可以更快速地找到对应的位置 但是有一个问题 我们怎么知道二分搜索找到的数 是不是第N个数呢? 实际上也很简单 通过规律我们不难发现 如果某个位置上的数不匹配 那么被跳过的数`k`一定满足:
$$
k=arr[i]−i−1
$$
所以 我们只需要找到一个大于等于`k`的位置即可 并且要尽可能的接近 在找到之后 再根据公式去寻找即可:

```c
                            int findKth_positive(int *arr, int arr_size, int k) {
                                
                                if (arr[0] > k) return k;

                                int l = 0, r = arr_size;
                                while (l < r) {
                                    int mid = (l + r) / 2;
                                    if (arr[mid] - mid - 1 >= k) {
                                        r = mid;
                                    } else {
                                        l = mid + 1;
                                    }
                                }

                                return k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1];
                                
                            }
```
