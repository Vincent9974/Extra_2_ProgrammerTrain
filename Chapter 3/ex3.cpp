#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void ex_1()
{
    int a = 10;
    int b = 20;
    int &rn = a;
    int equal;
    
    rn = b;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    
    rn = 100;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    
    equal = (&a == &rn) ? 1 : 0;
    std::cout << "equal = " << equal << std::endl;
}

void ex_2()
{
    int a = 1;
    int b = 10;
    int* p = &a;
    int* &pa = p;
    
    (*pa)++;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "*p = " << *p << std::endl;
    
    pa = &b;
    (*pa)++;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "*p = " << *p << std::endl;
    
}

void ex_3()
{
    int a = 1, b = 2;
    // int &c; 未初始化，错误
    int &d = a;
    //&d = b; //只能在申明时候赋值，不能再将d作为其他变量的别名
    int *p;

    // *p = 5; //p没有被初始化，是个野指针，很危险，程序会崩溃
}

void swap(char *&x, char *&y) {
    char *temp;
    temp = x;
    x = y;
    y = temp;
}

// void ex_4()
// {
//     char *ap = "he1lo";
//     char *bp = "how are you?";
//     cout << "ap: " << ap << endl;
//     cout << "bp: " << bp << endl;
//     swap(ap, bp);
//     cout << "swap ap, bp" << endl;
//     cout << "ap: " << ap << endl;
//     cout << "bp: " << bp << endl;
// }

const float pi = 3.14f;
float f;

float f1(float r) {
    f = r * r * pi;
    return f;
}

float& f2(float r) {
    f = r * r * pi;
    return f;
}

void ex_5()
{
    float f1(float=5);
    float& f2(float=5);
    float a = f1();
    // float& b = f1(); //这里对一个临时变量temp进行引用会发生错误。
    float c = f2();
    float& d = f2();
    d += 1.0f;
    std::cout << "a = " << a << std::endl;
    //std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "f = " << f << std::endl;
}

class Test {
public:
    void f(const int& arg);
private:
    int value;
};


void Test::f(const int& arg) {
    // 不能修改 const 引用参数 arg 的值
    // arg = 10;
    cout << "arg = " << arg << endl;
    value = 20;
}

void ex_6()
{
    int a = 7;
    const int b = 10;
    const int &c = b; //b为常量，而c不是常量引用
    const int &d = a;
    a++;
    // const 引用可以绑定到非 const 对象
    // 但不能通过 const 引用修改非 const 对象的值
    // d++;
    Test test;
    test.f(a);
    cout << "a = " << a << endl;
}

void ex_10()
{
    char a[] = "hello, world";
    char *ptr = a;

    printf("%c\n", *(ptr + 4));
    printf("%c\n", ptr[4]);
    printf("%c\n", a[4]);
    printf("%c\n", *(a + 4));

    *(ptr + 4) += 1;
    printf("%s \n", a);
}

void ex_11()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *)(&a + 1);

    printf("%d\n", *(a + 1));
    printf("%d\n", *(ptr - 1));
}

// void ex_12()
// {
//     char str1[] = "abc";
//     char str2[] = "abc";
//     const char str3[] = "abc";
//     const char str4[] = "abc";
//     const char* str5 = "abc";
//     const char* str6 = "abc";
//     char* str7 = "abc";
//     char* str8 = "abc";

//     cout << (str1 == str2) << endl;
//     cout << (str3 == str4) << endl;
//     cout << (str5 == str6) << endl;
//     cout << (str6 == str7) << endl;
//     cout << (str7 == str8) << endl;
// }

// void ex_13()
// {
//     char a;
//     char *str1 = &a;
//     char* str2 = "AAA";
    
//     //strcpy(str1, "hello"); // 使用 strcpy 函数来将字符串复制到 str1 指向的内存中, 但是这片内存大小不够
//     cout << str1 << endl;

//     // 下面这一行会导致编译错误，因为字符串字面值 "AAA" 存储在只读数据段，不允许修改
//     str2[0] = 'B'; 
//     cout << str1 << endl;
// }

void ex_14()
{
    // int ival = 1024;
    // int ival2 = 2048;
    // int *pi1 = &ival;
    // int *pi2 = &ival2;
    // int **pi3 = nullptr;

    // ival = *pi3; // 试图解引用空指针，可能导致未定义的行为
    // *pi2 = *pi3; // 试图解引用空指针，可能导致未定义的行为
    // ival = *pi2; // 将指针 pi2 指向的值赋给 ival
    // pi2 = *pi1; // 将指针 pi1 指向的值（整型）赋给指针 pi2，类型不匹配
    // pi1 = *pi3; // 将指针 pi3 指向的值（空指针）赋给指针 pi1
    // ival = *pi1; // 将指针 pi1 指向的值（空指针）赋给 ival
    // pi1 = &ival; // 将指针 pi1 指向 ival
    // pi3 = &pi2; // 将指针 pi3 指向指针 pi2

    // // 这里输出了一个数字 3，但是似乎并没有相关的语句
    // printf("%d\n", 3);
}


class MyClass {
public:
    int data;
    MyClass(int data) {
        this->data = data;
    }
    void print() {
        cout << data << endl;
        cout << "hello" << endl;
    }
};

void ex_19()
{
    MyClass *pMyClass;
    pMyClass = new MyClass(1);
    pMyClass->print();

    // 创建了一个 MyClass 类型的指针数组
    MyClass *pMyClassArray = new MyClass[3]{2, 3, 4};

    // 通过指针数组访问不同的 MyClass 对象并调用 print 方法
    pMyClassArray[0].print();
    pMyClassArray[1].print();
    pMyClassArray[2].print();

    // 尝试访问超出数组范围的元素，这是未定义行为
    // pMyClassArray[10000000].print();

    // 释放动态分配的内存
    delete pMyClass;
    delete[] pMyClassArray;
}

void ex_20()
{
    int x1[4] = {1, 2, 3, 4};
    int x2[2] = {5, 6};
    int x3[3] = {7, 8, 9};
    int* a[2];
    int* b = x1;
    int i = 0;

    a[0] = x2;
    a[1] = x3;

    cout << "输出a[0]: ";
    for(i = 0; i < sizeof(x2) / sizeof(int); i++) {
        cout << a[0][i] << " ";
    }
    cout << endl;

    cout << "输出a[1]: ";
    for(i = 0; i < sizeof(x3) / sizeof(int); i++) {
        cout << a[1][i] << " ";
    }
    cout << endl;

    cout << "输出b: ";
    for(i = 0; i < sizeof(x1) / sizeof(int); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}


// void ex_21()
// {
//     char *str[] = { "Welcome", "to", "Fortemedia", "Nanjing" };
//     char **p = str + 1;

//     str[0] = (*p++) + 2;
//     str[1] = *(p + 1);
//     str[2] = p[1] + 3;
//     str[3] = p[0] + (str[2] - str[1]);

//     printf("%sIn", str[0]);
//     printf("%s\n", str[1]);
//     printf("%sin", str[2]);
//     printf("%sin", str[3]);
// }


int max(int x, int y) {
    return (x > y ? x : y);
}

float *find(float *p, int x) {
    return p + x;
}

void ex_22()
{
    float score[] = { 10, 20, 30, 40 };
    int (*p)(int, int);
    float *q = find(score + 1, 1);
    int a;
    p = max;
    a = (*p)(1, 2);
    cout << "a = " << a << endl;
    cout << "*q=" << *q << endl;
}


int max1(int x, int y) {
    return x > y ? x : y;
}
void ex_25()
{
    int (*p)(int, int);
    int a, b, c;
    int result;

    p = max1;

    cout << "Please input three integers: ";
    cin >> a >> b >> c;

    result = (*p)((*p)(a, b), c);

    cout << "result = " << result << endl;
}

int add1(int a1, int b1) {
    return a1 + b1;
}

int add2(int a2, int b2) {
    return a2 + b2;
}
void ex_26()
{
    int numa1 = 1, numb1 = 2;
    int numa2 = 2, numb2 = 3;
    int (*op[2])(int a, int b);

    op[0] = add1;
    op[1] = add2;

    printf("%d %d\n", op[0](numa1, numb1), op[1](numa2, numb2));

    getchar();
}

class obj {
public:
    obj() {
        cout << "Initialization" << endl;
    }
    ~obj() {
        cout << "Destroy " << endl;
    }
};

void UseMallocFree() {
    cout << "in UseMallocFree()..." << endl;
    obj *a = (obj*)malloc(sizeof(obj));
    free(a);
}

void UseNewDelete() {
    cout << "in UseNewDelete()..." << endl;
    obj *a = new obj;
    delete a;
}

void ex_30()
{
    UseMallocFree();
    UseNewDelete();
}

class Base {
private:
    char *name;

public:
    Base(char *className) {
        name = new char[strlen(className) + 1];
        strcpy(name, className);
    }

    ~Base() {
        delete[] name;
    }

    char *copyName() {
        char *newname = new char[strlen(name) + 1];
        strcpy(newname, name);
        return newname;
    }

    char *getName() {
        return name;
    }
};

class Subclass : public Base {
public:
    Subclass(char *className) : Base(className) {
    }
};

void ex_33()
{
    Base *pBase = new Subclass("test");
    printf("name: %s\n", pBase->getName());
    printf("new name: %s\n", pBase->copyName());
    delete pBase;
}

int main()
{

    //ex_1();

    //ex_2();

    //ex_3();

    //ex_4();

    //ex_5();

    // ex_6();
    
    //ex_10();

    //ex_11();

    //ex_12();

    //ex_13();

    //ex_14();

    //ex_19();

    //ex_20();

    //ex_21();

    //ex_22();

    //ex_25();

    //ex_26();

    //ex_30();

    ex_33();

    return 0;
}