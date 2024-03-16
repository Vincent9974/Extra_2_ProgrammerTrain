#include <iostream>
using namespace std;

void ex_1()
{
    int i = 5.0; // 修改为整数
    float f = 5;
    printf("%f\n", 5);   // 修改为%f
    printf("%1f\n", 5.01);  // 修改为%f
    printf("%f\n", f);     // 修改为%f

    printf("%d\n", 5.01);  // 修改为%d
    printf("%d\n", i);     // 修改为%d
}

void ex_2()
{
    unsigned short int i = 0;
    unsigned char ii = 255;
    int j = 8, p, q;
    p = j << 1;
    q = j >> 1;
    i = i - 1;
    ii = ii + 1;

    printf("i = %d\n", i);
    printf("ii = %d\n", ii);
    printf("p = %d\n", p);
    printf("q = %d\n", q);
}

#define BIT3 (0x1 << 3)
static int a;
void ex_3()
{
    a |= BIT3;  //设置
    a &= ~BIT3; //取反
}

#define BIT7 (0x1 << 7)
int calculate(unsigned char c)
{
    int count = 0;
    unsigned char comp = BIT7;

    for(int i = 0; i < sizeof(unsigned char) * 8; ++i)
    {
        if((comp & c) != 0)
        {
            count ++;
        }
        comp = comp >> 1;
    }
    return count;
}

void ex_4()
{
    unsigned char c = 1;
    int count = 0;
    printf("Enter a value for c: ");
    scanf("%hhu", &c); // 使用 %hhu 读取无符号字符
    count = calculate(c);
    printf("The number of set bits in c is: %d\n", count);
}

int checkCPU()
{
	union w
    {
        int a;
        char b;
    } c;
    c.a = 1;
    return (c.b == 1);
}

void ex_15()
{
    cout << checkCPU() << endl;
}

unsigned int zero = 0;
unsigned int compzero =0xFFFF;

int main()
{

    //ex_1();

    //ex_2();

    //ex_4();

    ex_15();

    return 0;
}