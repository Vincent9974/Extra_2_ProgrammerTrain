#include <iostream>

using namespace std;

void ex_1()
{
    int x = 3, y, z;

    // 复合赋值运算 x = 12
    x *= (y = z = 4);
    printf("x = %d\n", x);

    z = 2;

    // 赋值运算 x = 2
    x = (y = z);
    printf("x = %d \n", x);

    // 相等比较运算 x = 1
    x = (y == z);
    printf("x = %d \n", x);

    // 位运算 AND x = 2
    x = (y & z);
    printf("x = %d\n", x);

    // 逻辑运算 AND x = 1
    x = (y && z);
    printf("x = %d\n", x);

    y = 4;

    // 位运算 OR x = 6
    x = (y | z);
    printf("x = %d\n", x);

    // 逻辑运算 OR (注意：应该使用 || 而不是 il) x = 1
    x = (y || z); 
    printf("x = %d\n", x);

    // 条件运算符 x = 5
    x = (y == z) ? 4 : 5;
    printf("x = %d\n", x);

    // 嵌套条件运算符 x = 3
    x = (y == z) ? 1 : (y < z) ? 2 : 3;
    printf("x = %d\n", x);

}

int value = 0;
void printValue()
{
    printf("value = %d\n", value);
}
void ex_2()
{
    int value = 0;
    value = 1;
    printf ( "value = %d\n", value);
    ::value = 2;
    printValue() ;
}

void ex_3()
{
    int i = 8;
    printf("%d\n", ++i);
    printf("%d\n", --i);
    printf("%d\n", i++);
    printf("%d\n", i--);
    printf("%d\n", -i++);
    printf("%d\n", -i--);
    printf("---\n");
}

char getChar(int x, int y) {
    char c;
    unsigned int a = (unsigned int)x; // 转换为无符号整数
    (a + y > 10) ? (c = 1) : (c = 2);
    return c;
}

void ex_6()
{
    char c1 = getChar(7, 4);
    char c2 = getChar(7, 3);
    char c3 = getChar(7, -7);
    char c4 = getChar(7, -8);

    printf("c1 = %d\n", c1);
    printf("c2 = %d\n", c2);
    printf("c3 = %d\n", c3);
    printf("c4 = %d\n", c4);
}


void fn1(void);
void fn2(void);

void ex_12()
{
    atexit(fn1);
    atexit(fn2);
    printf("main exit...\n");
}

void fn1() {
    printf("calling fn1()...\n");
}

void fn2() {
    printf("calling fn2()...\n");
}



int main()
{
    //ex_1();

    //ex_2();

    //ex_3();

    //ex_6();

    //ex_12();
    

    return 0;

}