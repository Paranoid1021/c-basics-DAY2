#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("请输入你的姓名（可以包含空格）：");
    
    // fgets 读取一整行，包括空格，最多读 sizeof(name)-1 个字符
    fgets(name, sizeof(name), stdin); 
    
    // fgets 会读入换行符，需要去掉
    name[strcspn(name, "\n")] = '\0';
    // strcspn的作用是：从字符串开头开始扫描，统计有多少个字符“不属于”第二个参数里的字符集合。一旦遇到属于第二个参数里的字符，就立刻停止，并返回已经扫描过的字符个数（也就是下标位置）。
    
    printf("你好，%s！\n", name);
    return 0;
}