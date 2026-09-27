#include <stdio.h>

// 1. 宏定义区域（预处理阶段进行纯文本替换）
// ❌ 反面教材：不带括号的宏定义（极易引发优先级灾难）
#define BAD_MATH 2 + 3
#define BAD_SQUARE(x) x * x

// ✅ 正面教材：带括号的安全宏定义（标准规范）
#define GOOD_MATH (2 + 3)
#define GOOD_SQUARE(x) ((x) * (x))
#define TEST_SQUARE(x) (x * x)

// 使用宏定义表示圆周率
#define PI 3.14159

// 2. 常量定义区域（编译阶段处理，有类型检查）
const int CONST_PI = 3;       // 整数常量
const double CONST_PI_D = 3.14; // 浮点常量

int main() {
    // 测试 1：无参宏的优先级陷阱
    int result1 = 2 * BAD_MATH;   // 展开后变成：2 * 2 + 3
    int result2 = 2 * GOOD_MATH;  // 展开后变成：2 * (2 + 3)

    printf("--- 测试1：无参宏的优先级陷阱 ---\n");
    printf("2 * BAD_MATH  = %d (预期是10，实际是7，因为先乘后加)\n", result1);
    printf("2 * GOOD_MATH = %d (预期是10，实际是10，括号保护了优先级)\n", result2);
    printf("\n");

    // 测试 2：带参宏的陷阱
    int result3 = BAD_SQUARE(2 + 3);  // 展开后变成：2 + 3 * 2 + 3
    int result4 = GOOD_SQUARE(2 + 3); // 展开后变成：((2 + 3) * (2 + 3))
    int result5 = TEST_SQUARE(2 + 3); // 展开后变成：(2 + 3 * 2 + 3)

    printf("--- 测试2：带参宏的陷阱 ---\n");
    printf("BAD_SQUARE(2+3)  = %d (预期是25，实际是11，因为变成了2 + 3*2 + 3)\n", result3);
    printf("GOOD_SQUARE(2+3) = %d (预期是25，实际是25，安全)\n", result4);
    printf("TEST_SQUARE(2+3) = %d (预期是25，实际是11，因为没有括号保护)\n", result5);

    printf("\n");

    // 测试 3：宏 vs const 常量的计算
    // 宏定义是文本替换，它不认识数据类型
    double circle_area1 = PI * 2 * 2; 
    
    // const 常量是带有类型的变量
    double circle_area2 = CONST_PI_D * 2 * 2; 
    
    // ❌ 错误示范：宏定义不能像变量一样被修改
    // PI = 3.14; // 编译报错：lvalue required as left operand of assignment
    
    // ❌ 错误示范：const 常量不能被修改
    // CONST_PI = 4; // 编译报错：assignment of read-only variable 'CONST_PI'

    printf("--- 测试3：宏定义与const常量的本质区别 ---\n");
    printf("使用宏计算圆面积: %.2f\n", circle_area1);
    printf("使用const常量计算圆面积: %.2f\n", circle_area2);
    printf("\n");

    // 测试 4：sizeof 对宏和常量的不同反应
    printf("--- 测试4：sizeof 的区别 ---\n");
    // 宏定义在预处理阶段就被替换成了数字，所以sizeof的是数字常量的类型
    printf("sizeof(BAD_MATH) = %zu (等价于 sizeof(2 + 3)，结果是int大小，通常是4)\n", sizeof(BAD_MATH));
    printf("sizeof(CONST_PI) = %zu (const int 的大小)\n", sizeof(CONST_PI));

    return 0;
}