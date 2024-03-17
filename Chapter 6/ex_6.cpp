#include <iostream>
#include <cstring>
using namespace std;

struct Point
{
    int x;
    int y;
    void print()
    {
        printf("Point"); //非法
    }
};

class Cpoint
{
    int x;
    int y;
    void print()
    {
        cout << "Cpoint:(" << x <<", " << y << ")" << endl;
    }
public:
    Cpoint(int x, int y) : x(x),y(y) {}
    void print1()
    {
        cout << "Cpoint:(" << x <<", " << y << ")" << endl;
    }
};

struct SPoint {
    int x;
    int y;

    // 默认为public
    void print() {
        std::cout << "SPoint: (" << x << ", " << y << ")" << std::endl;
    }

    // 构造函数，默认为public
    SPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

private:
    // private类型的成员函数
    void print1() {
        std::cout << "SPoint: (" << x << ", " << y << ")" << std::endl;
    }
};

class CBase {
public:
    void print() {
        std::cout << "CBase: print() ..." << std::endl;
    }
};

class CDerived1 : CBase {
    // 默认private继承
};

class CDerived2 : public CBase {
    // 指定public继承
};

struct sDerived1 : CBase {
    // 默认public继承
};

struct sDerived2 : private CBase {
    // 指定private继承
};

void ex_4()
{
    Point p;
    p.print();

    Cpoint cpt(1, 2);
    SPoint spt(3, 4);

    // 编译错误，x和y是私有成员，无法在类外直接访问
    // cout << cpt.x << " " << cpt.y << endl;

    // 编译错误，print函数是私有成员，无法在类外直接访问
    // cpt.print();

    // 编译错误，print1函数是私有成员，无法在类外直接访问
    // cpt.print1();

    spt.print(); // 合法
    // 编译错误，print1函数是私有成员，无法在类外直接访问
    // spt.print1();

    // 编译错误，spt对象没有v成员
    // cout << sot.x << " " << spt.v << endl;

    CDerived1 cd1;
    // 编译错误，无法访问基类的成员函数
    // cd1.print();

    CDerived2 cd2;
    // 合法，public继承，可以访问基类的公有成员函数
    cd2.print();

    sDerived1 sd1;
    // 编译错误，无法访问基类的成员函数
    // sd1.print();

    sDerived2 sd2;
    // 编译错误，private继承，无法访问基类的公有成员函数
    // sd2.print();
}

// struct Test {
//     Test(int) {}
//     Test() {}
//     void fun() { std::cout << "fun() called" << std::endl; }
// };

// void ex_5()
// {
//     Test a(1);
//     a.fun();  // 输出: fun() called

//     // Test b();
//     Test b;
//     b.fun();  
// }


class obj {
public:
    obj(int k) : j(k), i(j) {}
    void print() {
        cout << i << endl << j << endl;
    }
private:
    int i;
    int j;
};

void ex_7()
{
    obj obj(2);
    obj.print();
}

class Myclass {
public:
    Myclass(int a, int b, int c);
    void GetNumber();
    void GetSum();
private:
    int A;
    int B;
    int C;
    int Num;
    static int sum;
};

int Myclass::sum = 0;

Myclass::Myclass(int a, int b, int c) {
    A = a;
    B = b;
    C = c;
    Num = A + B + C;
    sum = A + B + C;
}

void Myclass::GetNumber() {
    cout << "Number = " << Num << endl;
}

void Myclass::GetSum() {
    cout << "Sum = " << sum << endl;
}
void ex_8()
{
    Myclass M(3, 7, 10), N(14, 9, 11);
    M.GetNumber();
    N.GetNumber();
    M.GetSum();
    N.GetSum();
}

class A {
private:
    int a; // 私有成员

public:
    A() {} // 默认构造函数
    A(int x) : a(x) {} // 带参数的构造函数对a初始化

    void printA() {
        cout << "a = " << a << endl;
    }
};

class B : public A {
private:
    int b;

public:
    B(int x, int y) : A(x), b(y) {} // 需要初始化b以及父类的a

    void printB() {
        cout << "b = " << b << endl;
    }
};

void ex_10()
{
    B b(2, 3);
    b.printA(); // 调用子类的printA()
    b.printB(); // 调用自己的printB()
}

class test1 {
public:
    static int i;
    int j;
    test1(int a) : j(a) {} // 使用初始化列表初始化j，不对静态成员i进行初始化

    void func1() {
        cout << i << ", " << j << endl;
    }

    static void func2() {
        cout << i << ", " << endl; // 注意此处i是静态成员，可以直接访问，而j是非静态成员，需要通过对象来访问
    }
};

int test1::i = 1; // 对静态成员i进行初始化

void ex_11()
{
    test1 t(2);
    t.func1(); // 调用非静态成员函数func1
    t.func2(); // 调用静态成员函数func2
}

class Empty{};

class Test {
public:
    Test();
    Test(char *Name, int len = 0);
    Test(char *Name);
    // Test(string str);
    // Test(string str, int len = 0);
};

void ex_16()
{
    string str = "hello";
    // Test(str, 10);
    cout << "16" << endl;
}

struct CLs
{
    int m_i;
    CLs(int i) : m_i(i) {} // 正确定义构造函数
    CLs() : m_i(0) {} // 默认构造函数
    // CLs()
    // {
    //     CLs(0);
    // }
};

void ex_17()
{
    CLs obj;
    cout << obj.m_i << endl;
}

class Test1 {
public:
    Test1(int n) { num = n; } // 普通构造函数
private:
    int num;
};

class Test2 {
public:
    explicit Test2(int n) { num = n; } // explicit(显式)构造函数
private:
    int num;
};

void ex_18()
{

    Test1 t1 = 12; // 隐式调用其构造函数，成功
    // Test2 t2 = 12; // 编译错误，不能隐式调用其构造函数
    Test2 t3(12); // 显示调用成功
}

class Number {
public:
    string type;
    Number(): type("void") {}
    explicit Number(short): type("short") {}
    Number(int): type("int") {}
};

void Show(const Number& n) {
    cout << n.type;
}

void ex_19()
{
    short s = 42;
    Show(s);
}

class Base {
public:
    Base() {
        cout << "Output from the constructor of class Base!" << endl;
    }
    virtual ~Base() {
        cout << "Output from the destructor of class Base!" << endl;
    }
    virtual void Dosomething() {
        cout << "Do something in class Base!" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Output from the constructor of class Derived!" << endl;
    }
    ~Derived() {
        cout << "Output from the destructor of class Derived!" << endl;
    }
    void Dosomething() override {
        cout << "Do something in class Derived!" << endl;
    }
};


void ex_20()
{
    Derived *pTest1 = new Derived();
    pTest1->Dosomething();
    delete pTest1;
    cout << endl;
    
    Base *pTest2 = new Derived();
    pTest2->Dosomething();
    delete pTest2;
}

class AA {
private:
    int a;
public:
    AA(int aa) { a = aa; }
    ~AA() { cout << "Destructor A! " << a << endl; }
};

class BB: public AA {
private:
    int b;
public:
    BB(int aa = 0, int bb = 0): AA(aa) { b = bb; }
    ~BB() { cout << "Destructor B! " << b << endl; }
};

void ex_21()
{
    BB obj1(5), obj2(6, 7);
}


class TestA {
public:
    int a;
    TestA(int x) {
        a = x;
    }
    TestA(const TestA &test) {
        cout << "copy constructor" << endl;
        a = test.a;
    }
};

void fun1(TestA test) {
    cout << "fun1()..." << endl;
}

TestA fun2() {
    TestA t(2);
    cout << "fun2()..." << endl;
    return t;
}

class BaseA {
public:
    BaseA(): i(0) { cout << "BaseA()" << endl; }
    BaseA(int n) : i(n) { cout << "BaseA(int)" << endl; }
    BaseA(const BaseA &b) : i(b.i) { cout << "BaseA(BaseA&)" << endl; }

private:
    int i;
};

class DerivedA : public BaseA {
public:
    DerivedA() : BaseA(0), j(0) { cout << "DerivedA()" << endl; }
    DerivedA(int m, int n) : BaseA(m), j(n) { cout << "DerivedA(int)" << endl; }
    DerivedA(DerivedA &obj) : BaseA(obj), j(obj.j) { cout << "DerivedA(DerivedA&)" << endl; }

private:
    int j;
};


void ex_22()
{
    TestA t1(1);
    TestA t2 = t1;
    cout << "before fun1()..." << endl;
    fun1(t1);
    TestA t3 = fun2();
    cout << "after fun2()..." << endl;
}



void ex_24()
{
    BaseA b(1);
    DerivedA obj(2, 3);
    DerivedA d(obj);
}


class String
{
public:
    String(const char* str = NULL);
    String(const String &other);
    ~String(void);
    String& operator= (const String &other);
private:
    char* m_String;
};

String::String(const char *str)
{
    cout << "Constructing " << endl;
    if(str == NULL)
    {
        m_String = new char[1];
        *m_String = '\0';
    }
    else
    {
        m_String = new char[strlen(str) + 1];
        strcpy(m_String, str);
    }
}

String::String(const String &other)
{
    cout << "Construcing Copy" << endl;
    m_String = new char[strlen(other.m_String) + 1];
    strcpy(m_String, other.m_String);
}

String::~String(void)
{
    cout << "Destructing" << endl;
    if(m_String != NULL)
    {
        m_String = new char[1];
        *m_String = '\0';
    }
}

String &String::operator=(const String &other)
{
    // TODO: 在此处插入 return 语句

    cout << "operator=" << endl;
    if(this == &other)
    {
        return *this;
    }

    delete[] m_String;
    m_String = new char[strlen(other.m_String) + 1];
    strcpy(m_String, other.m_String);
    return *this;
}


void ex_26()
{
    String a("hello");
    String b("world");
    String c(a);
    c = b;
}

class A3 {
private:
    int num;
public:
    A3() {
        cout << "Default constructor" << endl;
    }
    ~A3() {
        cout << "Destructor" << endl;
        cout << num << endl;
    }
    A3(const A3 &a) {
        cout << "Copy constructor" << endl;
    }
    void operator=(const A3 &a) {
        cout << "Overloaded operator=" << endl;
    }
    void setNum(int n) {
        num = n;
    }
};


void ex_27()
{
    A3 a1; //31
    A3 a2(a1);
    A3 a3 = a1;
    A3 &a4 = a1;
    a1.setNum(1);
    a2.setNum(2);
    a2.setNum(3);
    a2.setNum(4);
}



class BBB {
public:
    BBB() {
        std::cout << "default constructor" << std::endl;
    }
    ~BBB() {
        std::cout << "destructed" << std::endl;
    }
    BBB(int i) : data(i) {
        std::cout << "constructed by parameter " << data << std::endl;
    }
private:
    int data;
};

BBB Play(BBB b) {
    return b;
}

void ex_28_1()
{
    BBB t1 = Play(5);
    BBB t2 = Play(t1);
}

void ex_28_2()
{
    BBB t1 = Play(5);
    BBB t2 = Play(10);
}

class myString
{
public:
    myString(char *s)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~myString()
    {
        delete[] str;
    }

    myString& operator = (myString &string)
    {
        if(this == &string)
        {
            return *this;
        }
        if(str != NULL)
        {
            delete[] str;
        }
        str = new char[strlen(string.str) + 1];
        strcpy(str, string.str);
        return *this;
    }

    myString & operator + (myString &string)
    {
        char *temp = str;
        str = new char[strlen(temp) + strlen(string.str) + 1];
        strcpy(str, temp); //复制第一个字符串
        delete[] temp;
        strcat(str, string.str);
        return *this;
    }

    void print()
    {
        cout << str << endl;
    }

private:
    char* str;
};

class String1
{
private:
    char* data;
    size_t length;
public:
    // 默认构造函数
    String1() : data(nullptr), length(0) {}

    // 代参构造函数
    String1(const char* str) : data(nullptr), length(0)
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // 拷贝构造函数
    String1(const String1& other) : data(nullptr), length(other.length)
    {
        if(other.data)
        {
            data = new char[length + 1];
            strcpy(data, other.data);
        }
    }

    // 析构函数
    ~String1() {
        delete[] data;
    }

    // 获取字符串长度
    size_t size() const {
        return length;
    }

    String1& operator=(const String1& other)
    {
        if(this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
        return *this;
    }

    bool operator==(const String1& other)
    {
        return strcmp(data, other.data);
    }

    String1 operator +(const String1& other) const 
    {
        String1 result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    friend std::istream& operator>>(std::istream& is,  String1& str)
    {
        char buffer[1024];
        is.getline(buffer, 1024);
        str = buffer;
        return is;
    }

    friend std::ostream& operator<<(ostream& os, const String1 str)
    {
        os << str.data;
        return os;
    }
};

void ex_36()
{
    // 测试用例
    String1 s1("Hello");
    String1 s2("World");
    String1 s3 = s1 + " " + s2;
    
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    
    std::cout << "Enter a string: ";
    std::cin >> s1;
    std::cout << "You entered: " << s1 << std::endl;
}

int main()
{

    // ex_4();

    // ex_7();

    // ex_8();

    // ex_10();

    // ex_11();

    //ex_16();

    // ex_17();

    //ex_18();

    // ex_19();

    // ex_20();

    // ex_21();

    // ex_22();

    //ex_24();

    // ex_26();

    // ex_27();

    // ex_28_1();

    // ex_28_2();

    ex_36();

    return 0;
}


