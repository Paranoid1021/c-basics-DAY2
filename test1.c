#include<stdio.h>
char test[10]; // 全局数组，未初始化，默认值为0
int main() {
    char name[10] = "Alice";
    // 字符串常量自动在末尾添加 '\0'
    // 部分字符数组未被初始化的元素会被自动填充为 '\0'，因此name[5]到name[9]都是 '\0'
    
    // 遍历数组，打印每个字符及其ASCII码
    for (int i = 0; i < 10; i++) {
        printf("name[%d] = '%c' (ASCII: %d)\n", i, name[i] == '\0' ? '?' : name[i], name[i]);
        // if(name[i] == '\0') {
        //     printf("name[%d] = '?' (ASCII: %d)\n", i, name[i]);
        // } else {
        //     printf("name[%d] = '%c' (ASCII: %d)\n", i, name[i], name[i]);
        // }
        // ?:运算等同于if-else语句，简化代码
    }
    // 输出：name[0]='A'(65), name[1]='l'(108), ..., name[5]='\0'(0), 后续均为0

    // char test[10]; 如果是在函数内部定义test数组且不初始化，则test数组的内容是未定义的，可能包含垃圾值。
    for (int i = 0; i < 10; i++) {
         printf("test[%d] = '%c' (ASCII: %d)\n", i, test[i] == '\0' ? '?' : test[i], test[i]);
    }

    static char test2[10]; // 静态局部数组，未初始化，默认值为0
    for (int i = 0; i < 10; i++) {
        printf("test2[%d] = '%c' (ASCII: %d)\n", i, test2[i] == '\0' ? '?' : test2[i], test2[i]);
    }

    return 0;
}