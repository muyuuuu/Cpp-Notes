#include <iostream>

int main(){
    // 数据没有被修改，指针指的值被修改
    // 常量用大写
    const char* p = "hello";
    p = "world";
    for (int i = 0; i < 5; i++){
        std::cout << *(p+i);
    }

    int a{1}, b{2};
    const int* c = &a;
    c = &b;
    std::cout << *c << std::endl;

    const int x{12};
    std::cout << sizeof(x) << std::endl;
    return 0;
}