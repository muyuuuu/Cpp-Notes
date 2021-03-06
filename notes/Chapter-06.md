# 继承

子类是一种父类，如自行车是父类，竞速车和山地车是子类，继承了父类的特征。
- 父类到子类：子类继承父类，能添加属性和方法，不能删除。子类包含父类中的大部分成员。
- 子类到父类，父类泛化子类，提取共有的特征

特殊标志符：`final` 阻止类被继承。`class B final{};`

# 继承中的构造函数

派生类可以继承构造函数，不能继承友元函数和析构函数。只能继承所有基类的构造函数：`using A::A`。

调用继承的构造函数：`B():A(){空}`，初始化列表位置调用父类的构造函数。

调用基类的构造函数：派生类需要初始化，派生类构造函数调用基类构造函数，既要初始化本类(初始化列表)，也要初始化基类(调用)。

# 继承中的默认构造函数

基类的构造函数没有被显式调用，基类的默认构造函数会被调用。等价：
```C++
Circle(double r){radius = r;}
Circle(double r): Shape{} {radius = r;}
```
所以最好给基类提供构造函数。

类应该在头文件中声明，在源文件中定义，文件名与类名相同；类的成员变量不能声明为 `public`。

# 构造链和析构链

默认的调用基类的构造函数和析构函数。调用次序：

- 构造函数：越基类，调用次序越靠前
- 析构函数：子类先，越父类越后

# 继承中的名字隐藏

类中有同名函数，派生类内部作用域，基类外部作用域，同名函数会屏蔽外部作用域。避免写出潜在危险的代码。

# 重定义函数

因为基类函数名在子类中隐藏，所以子类可以定义完全一样的函数。比如用于输出派生类更加详细的信息。与重载完全不同。

# 多态

不同类型的实体对同一消息有不同的响应。继承的子类可以实现，不同的子类重定义同名函数。

联编：确定具有多态的语句调用哪个函数的过程。
- 静态联编：函数重载，派生类访问同名函数(重定义函数)，基类对象的指针访问同名函数(指针什么类型就调什么类型)
- 动态联编：运行时才能确定调用哪个函数，基类对象的指针或引用访问同名虚函数(函数虚，不看指针看对象)

实现运行时多态：

如果直接重载函数，每个类型都需要写函数，这样会很麻烦。使用虚函数，`virtual`。

覆写`override`：派生类中重定义一个虚函数(基类中的虚函数)，传参是基类类型的指针。隐式类型转换，将子类的地址转换为基类类型的指针。基类类型指针访问同名虚函数：

- 不由指针类型决定
- 由指针所指的实际对象的类型决定
- 运行时，检查指针所指对象的类型
- 如果一不小心写错了，不执行自己的，执行基类的

虚函数用途：父类指针访问子类对象的成员。

虚函数的传递性：如果基类定义了同名虚函数，那么派生类的同名函数自动变为虚函数。使用代价：

- 虚函数表
- 运行时需要动态联编
- 比非虚函数开销大

`override`是标志符，除了特殊位置，其他位置可以定义这个变量。指定虚函数覆写另一个虚函数。注意事项：

- `void foo() const override` 不能覆写 `void foo()`，类型不匹配
- 不能覆写非虚函数
- 覆写函数不能在类的外部定义，只能在类内使用
- 避免写出 `bug` 的代码

`final`，显示声明禁止覆写：

- `void foo() final // 被覆写，且是最终覆写`
- `class B final : A // B 不能被继承，且 B 不能覆写 foo() 函数`

# 访问控制

`protected` 保护属性的数据或函数，可以被类的派生类访问，但不能在类的外面访问，派生类中不能访问基类`private`保护的数据。

`class B : public A`中的`public`表示派生方式为公有继承。所有的基类成员的访问属性在派生类中不会改变，派生类只能访问基类的 `public` 和 `protected` 成员，不能访问 `private` 成员。类外面派生类对象只能访问 `public` 的成员。

`class B : private A`私有继承，基类所有成员到派生类中都会变成私有的。派生类只能访问基类的 `public` 和 `protected` 成员，类外面，派生类的对象不能访问任何基类的私有数据。
子类私有继承，孙类继承子类，无法访问子类的任何成员。

`class B : protected A`保护继承，基类的`public`成员到派生类中变成`protected`，其余成员的属性不变。派生类只能访问基类的 `public` 和 `protected` 成员。类外面，派生类无法访问基类的任何成员。
子类保护继承父类，孙类保护继承和共有继承，能访问父类的 `protected` 保护成员。

# 抽象类和纯虚函数

基类更加一般化，派生类会更加明确和具体。类太抽象无法实例化，叫做抽象类。

成员函数出现的继承层次：
- Shape类不写 getArea 函数
- 所有子类必须实现 getArea 函数

抽象函数要求子类必须实现。`virtual double getArea() = 0;`，= 0体现纯虚。子类可以继承纯虚函数，必须实现纯虚函数才能实例化。包含抽象函数的类叫做抽象类，抽象类不能实例化。

# 动态类型转换

在之前的 `print` 函数中，想打印额外的信息。比如，如果是圆的话，打印半径：

```C++
void print(Shape& p){
    p.show();
}
```

`dynamic_cast`运算符，沿着类的继承层次，向上、向下、侧向转换类的指针和引用。转换成功，返回；失败，指针返回`nullptr`，引用抛异常。

# 向上转换和向下转换

- `upcasting`：向上，派生类类型指针赋给基类类型指针，可以隐式转换，安全的；
- `downcasting`：向下，基类指针赋给派生类类型指针，必须显式执行。

## 基类对象和派生对象的互操作

对象赋值需要注意的事项：

1. 可以把派生类对象斩断，只使用继承来的信息
2. 不能把基类加长，无中生有编出派生类对象

# typeid

运行时刻查看类型信息，判断是否能转换成功。获取对象所属类的信息。返回一个`type_info`对象的引用，`typeid.name()`拿到类型的名字，返回实现定义的内容，类型是`char*`。