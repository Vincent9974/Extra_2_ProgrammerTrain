#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void ex_2()
{
    int x = 10;
    int y = 20;

    std::cout << "Max value: " << MAX(x, y) << std::endl;
    std::cout << "Min value: " << MIN(x, y) << std::endl;
}

#define SQR(x) (x*x)
#define SQR1(x) ((x)*(x))
void ex_3()
{
    int a, b =3;
    a = SQR(b+2);
    printf("a= %d\n", a);
    a = SQR1(b+2);
    printf("a= %d\n", a);
}

#define STR(s) #s // '#' 转为字符串
#define CONS(a, b) int(a##e##b) //'##'预处理的连接操作符
void ex_4()
{
    printf(STR(vck));
    printf("\n");
    printf("%d\n", CONS(2, 3));
}

#define WORD_LO(xxx) ((unsigned char)((unsigned short)(xxx) & 255))
#define WORD_HI(xxx) ((unsigned char)(((unsigned short)(xxx)) >> 8))


void ex_5()
{
    unsigned int myWord = 0xABCD;  // 一个示例字

    unsigned char lowByte = WORD_LO(myWord);
    unsigned char highByte = WORD_HI(myWord);

    // 打印结果
    printf("Low Byte: 0x%X\n", lowByte);
    printf("High Byte: 0x%X\n", highByte);
}

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))
void ex_6()
{
    int myArray[] = {1, 2, 3, 4, 5};
    int length = ARRAY_LENGTH(myArray);
    printf("length of arr: %d\n", length);
}

void ex_7()
{
    const int x = 1;
    int b = 10;
    int c = 20;

    const int* a1 = &b;
    int* const a2 = &b;
    const int* const a3 = &b;


    // 修改 b 的值
    b *= 2;

    // 修改指针指向的值
    // a1 是指向常量的指针，不能通过它修改变量的值
    // *a1 = 1; // 错误

    // a2 是常量指针，不能修改指针指向的地址
    // a2 = &c; // 错误

    // a3 同时具有 const 限定，不能修改指针指向的地址，也不能修改指针指向的值
    // a3 = &c; // 错误
    // *a3 = 1; // 错误
}

class Widget
{
public:
    Widget()
    {
        count++;
    }

    ~Widget()
    {
        count--;
    }

    static int num()
    {
        return count;
    }

private:
    static int count;
};

int Widget::count = 0;

void ex_12()
{
    Widget x, y;
    std::cout << "The Num. is " << Widget::num() << std::endl;

    if (Widget::num() > 1)
    {
        Widget x, y, z;
        std::cout << "The Num. is " << Widget::num() << std::endl;
    }

    Widget z;
    std::cout << "The Num. is " << Widget::num() << std::endl;
}

void ex_13()
{
    int integerVar;
    char charVar;
    double doubleVar;

    std::cout << "Size of int: " << sizeof(integerVar) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(charVar) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(doubleVar) << " bytes" << std::endl;

}

// class A {
// public:
//     int i;
// };

// class B {
// public:
//     char ch;
// };

class C {
public:
    int i;
    short j;
};

class D {
public:
    int i;
    short j;
    char ch;
};

class E {
public:
    int i;
    int ii;
    short j;
    char ch;
    char chr;
};

class F {
public:
    int i;
    int ii;
    int iii;
    short j;
    char ch;
    char chr;
};

void ex_14()
{
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << std::endl;
    // std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    // std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
    std::cout << "sizeof(D) = " << sizeof(D) << std::endl;
    std::cout << "sizeof(E) = " << sizeof(E) << std::endl;
    std::cout << "sizeof(F) = " << sizeof(F) << std::endl;
}

class Base {
public:
    Base(int x) : a(x) {
    }

    void print() {
        cout << "base" << endl;
    }

private:
    int a;
};

class Derived : public Base {
public:
    Derived(int x) : Base(x - 1), b(x) {
    }

    void print() {
        cout << "derived" << endl;
    }

private:
    int b;
};

class A {
public:
    A(int x) : a(x) {
    }

    virtual void print() {
        cout << "A" << endl;
    }

private:
    int a;
};

class B : public A {
public:
    B(int x) : A(x - 1), b(x) {
    }

    virtual void print() {
        cout << "B" << endl;
    }

private:
    int b;
};

void ex_15()
{
    Base obj1(1);
    cout << "size of Base obj is " << sizeof(obj1) << endl;

    Derived obj2(2);
    cout << "size of Derived obj is " << sizeof(obj2) << endl;

    A a(1);
    cout << "size of A obj is " << sizeof(a) << endl;

    B b(2);
    cout << "size of B obj is " << sizeof(b) << endl;
}

union U {
    double a;
    int b;
};

union U2 {
    char a[13];
    int b;
};

union U3 {
    char a[13];
    char b;
};

#pragma pack(2)
union U4
{
    char buf[9];
    int a;
};

void ex_20()
{
    std::cout << "Size of U: " << sizeof(U) << " bytes" << std::endl;
    std::cout << "Size of U2: " << sizeof(U2) << " bytes" << std::endl;
    std::cout << "Size of U3: " << sizeof(U3) << " bytes" << std::endl;
    std::cout << "Size of U4: " << sizeof(U4) << " bytes" << std::endl;
}

int main() {

    //ex_2();

    //ex_3();

    //ex_4();

    //ex_5();

    //ex_6();

    //ex_12();

    //ex_13();

    //ex_14();

    //ex_15();

    ex_20();

    return 0;
}
