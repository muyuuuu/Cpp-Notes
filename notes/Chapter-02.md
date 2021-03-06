# 代码文件

- `header file`：头文件，后缀名为`.h`
- `source file`：源文件，后缀名为`.cpp`

linux系统中：可能会见到`.hpp`和`.cxx`。

# 编译文件

1. 创建修改源代码
2. 预编译：代码文本的替换工作，如将 `#include <iostream>` 文件的内容引入到当前文件
3. 编译：源代码生成目标文件，机器代码的形式。`.obj`
4. 链接：将目标文件外加库链接为一个可执行文件
5. 可执行文件：保存到磁盘

# 常见错误

1. 语法错误，违反编程规则，由编译器检查
2. 运行时错误，编译器无法检查，如 整数除以 0 ，内存不足
3. 逻辑错误，与预期正确结果不符

# 输入输出

按目的分类：

1. 标准IO：键盘上输入信息和屏幕上显示信息
2. 文件IO
3. 字符串IO：从字符串读入和写出
4. 网络IO

如：C：`scanf, gets(), printf(), puts()`

对于 `C++` 而言：引入流(stream)的概念，对屏幕、键盘或文件进行IO操作。最常见的是`cin`和`cout`，这两个都是流对象，前者流输入，后者流输出，`c`表示`character`。

使用`cin`和`cout`这两个流对象，需要使用操作符来使用，`>>`流提取运算符，从流中取出信息；`<<`流插入运算符，将信息输入到流中。

- `cin.get()` 流中读取一个字符；
- `cin.getline()` 流中读取一行，直到行尾或指定分隔符
- `cin.ignore()` 忽略指定数量的字符
- `cout.put()` 字符无格式写到流中
- `cout.flush()` 将流的缓存内容全部输出。流有缓冲区，输出的信息不会直接到屏幕，而不是直接到屏幕上。
