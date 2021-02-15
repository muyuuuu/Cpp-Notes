# 标准模板库基础

Standard template library，C++标准库这噢乖要组成部分，94年进入标准。组成部分：
- 容器：保存一组数据，各种各样的类型，数据个体是元素。
- 迭代器：指针，访问容器中的元素(非下标)。将`*, ++, ->`进行了重载的类模板，不同容器的迭代器不一样。一种泛型指针，和容器共同使用。有些迭代器和容器无关。
- 算法：操作容器里面数据的一种方法，和具体容器无关。查找，排序，替换等。
- 函数对象
- 空间分配器

## 容器分类

1. 顺序容器：线性数据结构，`vector, list, deque`，多个元素的有序集合，元素有前有后
2. 关联容器：非线性数据结构，`map, set`，多个元素的无序集合，元素无前无后，用于存储键值对
3. 容器适配器：依赖顺序容器的受限版本，处理特殊情况。`stack, queue, priority_queue`。

- `vector`，直接访问任意元素，快速插入、删除尾部元素
- `deque`，直接访问任意元素，快速插入、删除头部和尾部元素，但开销大
- `list`，快速插入删除任意位置的元素，没办法访问任意位置元素，不能使用数组下标
- `set`，快速查询元素，无重复关键字
- `multiset`，允许重复关键字
- `map`，键值对，不允许重复关键字，使用关键字快速查询元素
- `multimap`，允许重复关键字
- `stack`，后进先出
- `queue`，先进先出
- `priority_queue`，先进先出

所有容器的共同函数：
1. 构造函数
2. 拷贝函数
3. `empty()`判空
4. `size()`元素数目
5. `operator()=`将容器复制
6. `>, <, ==, !=`的判断

一级容器的共同函数（顺序容器+关联容器）：
1. `a.swap(b)`交换
2. `a.max_size()`最大容纳的元素数量
3. `clear()`删除
4. `begin()`返回容器首元素的迭代器
5. `end()`返回容器尾元素之后位置的迭代器
6. `rbegin()`容器最后位置的迭代器，逆序遍历
7. `rend()`容器首元素之前位置的迭代器
8. `erase(begin, end)`删除`[begin, end-1]`位置的元素，两者都是迭代器

# 迭代器

访问和处理一级容器中的元素。
- 顺序容器，输出顺序和输入顺序一致
- 关联容器，很可能不一致

## 类型

各类容器有自己的迭代器类型，不同容器的迭代器不一样。迭代器可分为5类：
- 输入迭代器，可读取所指内容
- 输出迭代器，可修改所指内容
- 前向迭代器，只能单步的向前移动
- 双向迭代器，可单步前后移动
- 随机访问迭代器，可加可减可任意跳转，类似数组访问方式

- `vector, deque`元素严格有序，支持随机访问迭代器
- `list, set, map`只支持双向迭代器
- 非一级容器不支持迭代器

特殊注意：输入迭代器，`*p`仅作右值；输出迭代器，`*p`仅作左值。随机访问迭代器还可以比较大小。

# 顺序容器

- 随机迭代器：`vector`，`deque`（双端队列）
- 双向迭代器：`list`

- `vector`：一端操作的数组，满了之后申请新的数组，拷贝原有数组
- `deque`：双端操作，先入先出，内部有多个数组容纳新的元素
- `list`：若干节点，节点有两个指针，有前驱和后继，插入和删除快

共同函数：
- `assign(n, elem)`元素做`n`份拷贝，覆盖原有内容
- `assign(beg, end)`迭代器`[beg, end)`之间的元素赋值给当前容器
- `push_back`尾部添加
- `pop_back`删除尾部
- `front`返回首部
- `back`返回尾部
- `insert(pos, elem)`元素插入到指定位置

# 关联容器

使用`key`快速存取元素，元素按默认规则进行排序。共同函数：

- `find(key)`搜索容器中具有`key`的元素，返回指向的迭代器，没找到返回指向容器最后一个元素后面的迭代器
- `lower_bound(key)`搜索具有`key`的第一个元素，返回指向元素的迭代器
- `upper_bound(key)`搜索具有`key`的最后一个元素，返回指向元素之后位置的迭代器
- `count(key)`具有`key`元素的数量
