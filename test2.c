#include <stdio.h>
#include <string.h> // strlen 需要此头文件

int main() {
    char str[] = "Hello";
    // C 语言的数组在内存中分配空间时，必须在编译期确定大小。
    // 如果不带初始化，则数组的大小必须在编译期确定，因此 char str[]; 这种写法是错误的，编译器无法确定数组的大小。
    
    // 可以省略中括号里数字情况
    // 1. 如果数组在定义时被初始化，char str[] = "Hello";，编译器会根据右边的字符串长度，自动推断出数组大小是 6。
    // 2. 在函数定义中写 void func(char str[])，这其实等价于 void func(char *str)，它是指针，不是真实数组。
    // 3. 外部声明：extern char str[]; 告诉编译器“这是个数组，大小在别的文件里定义了”。

    // strlen: 从首地址开始数，直到遇到 '\0' 为止，不包含 '\0'
    printf("strlen = %zu\n", strlen(str)); 
    
    // sizeof: 数组占用的总字节数，包含 '\0'
    printf("sizeof = %zu\n", sizeof(str)); 
    

    str[3] = '\0'; // 将字符串截断为 "Hel"
    printf("strlen（截断后）= %zu\n", strlen(str)); // 现在 strlen 只计算到 '\0' 之前的字符数
    printf("sizeof（截断后）= %zu\n", sizeof(str)); // sizeof 仍然返回数组的总大小，包括 '\0'   


    // 对于指针，sizeof 得到的是指针本身的大小（8字节），而不是字符串长度
    char *p = str;
    printf("sizeof(p) = %zu\n", sizeof(p)); 

    return 0;
}