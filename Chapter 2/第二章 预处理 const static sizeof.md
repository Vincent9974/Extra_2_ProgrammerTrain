# 1. 预处理的使用

看下面的代码并写出结果。

考点: #ifdef、#else、#endif在程序中的使用

出现频率:★★★

```cpp
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int main() {
    int i = 0;
    char c;

    while (1) {
        i++;
        c = getchar();

        if (c != '\n') {
            getchar();
        }

        if (c == 'q' || c == 'Q') {
#ifdef DEBUG
            printf("we got: %c, about to exit.\n", c);
#endif
            break;
        } else {
            printf("i = %d", i);
#ifdef DEBUG
            printf(", we got: %c", c);
#endif
            printf(" In\n");
        }
    }

    return 0;
}
```

​	在代码第4行，首先定义了名为DEBUG的预处理器常量，而后分别在第18行和第24行用#ifdef判断DEBUG是否被定义了;如果被定义了，就进行 printf输出信息。



# 2. 用#define实现宏并求最大值和最小值

考点: #define宏定义的使用

出现频率:★★★★

以下为实现代码:

```cpp
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void ex_2()
{
    int x = 10;
    int y = 20;

    std::cout << "Max value: " << MAX(x, y) << std::endl;
    std::cout << "Min value: " << MIN(x, y) << std::endl;
}
```



在这里，MAX(x,y)表示x和y的最大值，MIN(x,y)表示x和y的最小值。此题有以下几个目的。
(1) #define在宏上应用的基本知识。
(2）三元运算符(?:)的知识。这个运算符能产生比 if-else 更优化的代码，并且书写上更加简洁明了。
(3）在宏中需要把参数小心地用括号括起来。因为宏只是简单的文本替换，如果不注意，很容易引起歧义。



# 3. 宏定义的使用

写出下面代码的输出结果。

考点:使用#define宏定义时需要注意的地方

出现频率:★★★★

```cpp
#define SQR(x) (x*x)
void ex_3()
{
    int a, b =3;
    a = SQR(b+2);
    printf("a= %d\n", a);
}
```



这里定义的SQR(x)显然是想要获得x的二次方，在第5行中调用的参数为b+2，原本想将a赋为(b+2)*(b+2)，也就是5的二次方，即25。但是由于宏定义展开是在预处理时期，也就是在编译之前，此时b并没有被赋值，这时的b只是一个符号。因此在第行被展开成:

`a = (b+2*b+2)` 就变成了 `a = (3 + 2*3 + 2)`，计算结果为 `11`。

若想修改正确则可将

#define SQR(x) (x*x)

修改为:

#define SQR(x) ((x)*(x)



# 4. 看代码写输出——宏参数的连接

考点:如何连接宏参数

出现频率:★★★

```cpp
#define STR(s) #s // '#' 转为字符串
#define CONS(a, b) int(a##e##b) //'##'预处理的连接操作符
void ex_4()
{
    printf(STR(vck));
    printf("\n");
    printf("%d\n", CONS(2, 3));
}
```

​	在这个程序中，我们使用#把宏参数变为一个字符串，用#把两个宏参数贴合在一起。第3行中 STR(s)定义的是一个参数s表示的字符串。在第8行的调用中，STR(vck)实际表示就是字符串"vck"。第4行中 CONS(a,b)定义的是一个将参数a与b按aeb连接起来的一个整型值。在第10行的调用中，CONS(2,3)实际表示就是整型值2e3，也就是十进制数2000。

输出:

vck
2000



# 5. 用宏定义得到一个字的高位和低位字节

考点:宏定义与位运算的使用

出现频率:★★★★

```cpp
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
```



# 6.用宏定义得到一个数组所含的元素个数

考点:宏定义与sizeof的使用

出现频率:★★★★

```cpp
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))
void ex_6()
{
    int myArray[] = {1, 2, 3, 4, 5};
    int length = ARRAY_LENGTH(myArray);
    printf("length of arr: %d\n", length);
}
```

​	它含有100个int型的元素。如果int为4个字节，那么这个数组总共有400个字节。sizeof(array)为总大小，即 400个字节;sizeof(array[0])为一个int大小，即4个字节。两个大小相除就是100，也就是数组的元素个数。这里，为了保证宏定义不会发生“二义性”，在a以及a[0]上都加了括号。



# 7. 找错-const 的使用
考点: const使用时的注意点

出现频率:★★★★

```cpp
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
```

1. `const int* a1 = &b;` 指的是 `a1` 是一个指向 `const int` 的指针，所以不能通过 `a1` 来修改其指向的值。但是在后面的 `*a1 = 1;` 语句中，试图修改 `a1` 指向的值，这是错误的。正确的做法是将 `a1` 改成 `int* const a1 = &b;`，表示 `a1` 是一个指向 `int` 的常量指针，指针本身是不可变的，但可以通过 `a1` 来修改其指向的值。
2. 代码第15行和第16行，a1定义为const int类型，注意这里的const在 int的左侧,它是用修饰指针所指向的变量，即指针指向为常量。第15行中把a1 指向变量c是允许的，因为这修改的是指针a1本身。但是第16行改变al指向的内容是不允许的。编译器给出的错误同样是“1-value specifies const object”。
3. 代码第18行和第19行，a2定义为intconst类型，注意这里的const在 int的右侧，它是用修饰指针本身，即指针本身为常量。因此第18行中修改指针a2本身是不允许的。而第19行修改a2指向的内容是允许的。
4. 代码第21行和第22行，a3定义为const int* const类型，这里有两个const，分别出现在 int*的左右两侧，因此它表示不仅指针本身不能修改，并且其指向的内容也不能修改。所以代码第21行和第22行都会出现编译错误。

注意:变量x、a2和a3在声明的同时一定要初始化，因为它们在后面都不能被赋值。而变量a1可以在声明的时候不初始化。



# 8.说明const 与#ldefine的特点及区别

考点:对const与#define 的特点及区别的理解

出现频率:★★★

#define只是用来做文本替换的。例如。

```cpp
#define PI 3.1415926
float angel;
angel = 3o* PI / 180;
```


那么，当程序进行编译的时候，编译器会首先将“#define Pi3.1415926”以后所有代码中的“PI”全部换成“3.1415926"，然后进行编译。因此，#define常量则是一个Compile-Time概念，它的生命周期止于编译期，它存在于程序的代码段，在实际程序中它只是个常数、一个命令中的参数，并没有实际的存在。
const常量存在于程序的数据段，并在堆栈分配了空间。const常量是一个Run-Time的概念，它在程序中确确实实地存在着并可以被调用、传递。const常量有数据类型，而宏常量没有数据类型。编译器可以对const常量进行类型安全检查。



# 9. 面试题10static有什么作用（至少说出2个)

考点:对C++中const的理解

出现频率:★★★★★

1. const用于定义常量: const定义的常量编译器可以对其进行数据静态类型安全检查。
2. const 修饰函数形式参数:当输入参数为用户自定义类型和抽象数据类型时，应该将“值传递”改为“const &传递”，可以提高效率。比较下面两段代码:

```cpp
void fun(A a) ;
void fun(A const &a);
```

​	第一个函数效率低。函数体内产生A类型的临时对象用于复制参数a，临时对象的构造、复制、析构过程都将消耗时间。而第二个函数提高了效率。用“引用传递”不需要立生临时对象，节省了临时对象的构造、复制、析构过程消耗的时间。但光用引用有可能改变a,所以加const。

3.  const修饰函数的返回值:如给“指针传递”的函数返回值加const，则返回值不能被直接修改，且该返回值只能被赋值给加const修饰的同类型指针。例如:

```cpp
const char *GetChar (void){};
char *ch = GetChar(); // error
const char *ch = GetChar(); // correct
```

4. const修饰类的成员函数（函数定义体):任何不会修改数据成员的函数都应用const修饰，这样，当不小心修改了数据成员或调用了非 const成员函数时，编译器都会报错。const修饰类的成员函数形式为:

```cpp
class MyClass {
public:
    int GetCount() const {
        // 在常量成员函数中不能修改成员变量
        // 例如，下面的语句会导致编译错误
        // count = 10;
        return count;
    }

private:
    int count;
};
```



# 10. static有什么作用（至少说出2个)

考点:对C++中static的作用的理解

出现频率:★★★★★

在C语言中，关键字static有3个明显的作用:

1. **静态局部变量：** 在函数体内声明的静态变量在函数被调用的过程中维持其值不变。这意味着即使函数调用结束，静态局部变量的值也会被保留，下次调用该函数时会继续使用上一次的值。

```cpp
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // 静态局部变量
    count++;
    printf("Call count: %d\n", count);
}

int main() {
    exampleFunction();  // 输出: Call count: 1
    exampleFunction();  // 输出: Call count: 2
    return 0;
}
```



2. **静态全局变量：** 在模块内（但在函数体外)声明的静态变量可以被模块内所有函数访问，但不能被模块外的其他函数访问。它是一个本地的全局变量，对外部文件不可见。

   ```cpp
   // File1.c
   static int globalVar = 10;  // 静态全局变量，只在当前文件可见
   
   // File2.c
   extern int globalVar;  // 错误：在其他文件中无法访问静态全局变量
   ```

   

3. **静态函数：** 在模块内声明的静态函数只能被同一模块内的其他函数调用。它被限制在声明它的模块的本地范围内使用，对于其他模块是不可见的。

```cpp
// File1.c
static void localFunction() {
    printf("This is a static function\n");
}

// File2.c
extern void localFunction();  // 错误：在其他文件中无法访问静态函数

```

这些用法使得`static`在不同的上下文中具有不同的语义，但总体来说，它用于控制变量和函数的作用域和生命周期。



# 11. static全局变量与普通的全局变量有什么区别

static全局变量与普通的全局变量有什么区别? static局部变量和普通的局部变量有什么区别? static函数与普通函数有什么区别?

考点:对C++中static 的作用的理解

出现频率:★★★★

​	全局变量的说明之前再加上 static就构成了静态的全局变量。全局变量本身就是静态存储方式，静态全局变量当然也是静态存储方式。这两者在存储方式上并无不同。这两者的区别在于，非静态全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，非静态的全局变量在各个源文件中都是有效的;而静态全局变量则限制了其作用域，即只在定义该变量的源文件内有效，在同一源程序的其他源文件中不能使用它。由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用，因此可以避免在其他源文件中引起错误。

​	从以上分析可以看出，把局部变量改变为静态变量后是改变了它的存储方式，即改变了它的生存期;把全局变量改变为静态变量后是改变了它的作用域，限制了它的使用范围

​	static函数与普通函数的作用域不同。static函数的作用域仅在本文件，只在当前源文件中使用的函数应该说明为内部函数(static)，内部函数应该在当前源文件中说明和定义。对于可在当前源文件以外使用的函数，应该在一个头文件中说明，要使用这些函数的源文件要包含这个头文件。

​	因此，static全局变量与普通的全局变量的区别是，static全局变量只初始化一次，防止在其他文件单元中被引用;static局部变量和普通局部变量的区别是，static局部变量只被初始化一次，下一次依据上一次结果值;static函数与普通函数的区别是，static函数在内存中只有一份，普通函数在每个被调用中维持一份复制品。

【答案】
	static全局变量与普通全局变量的区别是，static全局变量只初始化一次，防止在其他文件单元中被引用。
	static局部变量和普通局部变量的区别是，static局部变量只被初始化一次，下一次依据上一次结果值。
	static函数与普通函数的区别是，static函数在内存中只有一份，普通函数在每个被调用中维持一份复制品。



# 12.看代码写结果——C++类的静态成员

考点:对C++中类的静态成员的理解

出现频率:★★★★★

```cpp
#include <iostream>

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

```

​	类widget有一个静态成员count和一个静态方法num()。我们知道，类中的静态成员或方法不属于类的实例，而属于类本身并在所有类的实例间共享。在调用它们时应该用类名加上操作符“:”来引用。
在代码第7行类widget的构造方法里把静态成员count 的值加1，在代码第11行类widget的析构方法里把静态成员count 的值减1。也就是说，静态成员count 的值表示类widget 实例的个数。
​	通过以上的分析，可以看到运行到代码第26行时，只有两个类widget的实例，运行到代码第30行时，又产生了3个实例，然后这3个实例在第31行结束后被销毁。最后运行到代码第32行又产生了1个实例。

【答案】
The Num.is 2

The Num.is 5

The Num.is 3



# 13. 使用sizeof 计算普通变量所占空间大小

考点:使用sizeof计算普通变量所占空间大小

出现频率:★★★★

假设在64位WinNT操作系统环境下，代码如下。

```cpp
char str[] = "He1lo";
char *p = str;
int n = 10;
sizeof(str) = 6;  // 包括字符串末尾的空字符 '\0'
sizeof(p) = 4;   // 32位系统下指针占4字节
sizeof(n) = 4;   // 32位系统下int占4字节
void Func(char str[100]) {
    sizeof(str) = 100;  // 数组参数在函数内部会被当作指针处理，所以返回的是指针的大小
}
void *ptr = malloc(100);
sizeof(ptr) = 4;  // 32位系统下void*占4字节
```

​	代码第4行，str变量表示数组，对数组变量做sizeof运算得到的是数组占用内存的总大小。在这里，str的总大小为strlen("Hello")+1，注意数组中要有一个元素保存字符串结束符，所以sizeof(str)为6。
​	代码第5行和第6行中的p和n分别是指针和 int型变量。在32位 WinNT平台下，指针和 int 都是4个字节，所以结果都是4。
​	代码第9行中的str是函数的参数，它在做sizeof运算时被认为是指针。这是因为当我们调用函数Func (str）时，由于数组是“传址”的，程序会在栈上分配一个4字节的指针来指向数组，因此结果也是4。
​	代码第11行中的p首先指向一个100字节的堆内存。这里还是对指针做sizeof运算，结果仍然是4。

​	总之，数组和指针的sizeof运算有细微的区别。如果数组变量被传入函数中做sizeof运算，则和指针的运算没有区别，否则得到整个数组占用内存的总大小。对于指针，无论是何种类型的指针，其大小都是固定的，在32位 WinNT平台下都是4。

# 14. 使用sizeof计算类对象所占空间大小

考点:使用sizeof计算类对象所占空间大小

出现频率:★★★★

请指出下面程序的输出是什么（在32位WinNT操作系统环境下)。

```cpp
#include <iostream>

class A {
public:
    int i;
};

class B {
public:
    char ch;
};

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

int main() {
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << std::endl;
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
    std::cout << "sizeof(D) = " << sizeof(D) << std::endl;
    std::cout << "sizeof(E) = " << sizeof(E) << std::endl;
    std::cout << "sizeof(F) = " << sizeof(F) << std::endl;

    return 0;
}
```



结果:

```cpp
sizeof(int) = 4
sizeof(short) = 2
sizeof(char) = 1

sizeof(A) = 4
sizeof(B) = 1
sizeof(C) = 8
sizeof(D) = 8
sizeof(E) = 12
sizeof(F) = 16
```

这都是由于字节对齐引起的。对齐的作用和原因:

​	各个硬件平台对存储空间的处理上有很大的不同。一些平台对某些特定类型的数据只能从某些特定地址开始存取。其他平台可能没有这种情况，但是最常见的是，如果不按照适合其平台的要求对数据存放进行对齐，会给存取效率带来损失。例如，有些平台每次读都是从偶地址开始，如果一个int型（假设为32位系统）存放在偶地址开始的地方，那么一个读周期就可以读出;而如果存放在奇地址开始的地方，可能会需要⒉个读周期，并对两次读出的结果的高低字节进行拼凑才能得到该int 型数据。显然，在读取效率上下降很多。这也是空间和时间的博弈。

​	对齐的实现:通常，我们写程序的时候，不需要考虑对齐问题。编译器会替我们选择适合目标平台的对齐策略。当然，我们也可以通知给编译器传递预编译指令而改变对指定数据的对齐方法。

​	字节对齐的细节和编译器实现相关，一般而言，需要满足3个准则:

1. 结构体变量的首地址能够被其最宽基本类型成员的大小所整除;
2. 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍，
   如有需要，编译器会在成员之间加上填充字节( internal adding) ;
3. 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要，编译器会在最末一个成员之后加上填充字节( trailing padding） 。



现在以下面的结构体为例。

```cpp
struct s{
	char c1;
	int i;
	char c2;
}
```

​	c1的偏移量为0，i的偏移量为4，c1与i之间便需要3个填充字节。c2的偏移量为8，加起来就是1+3+4+1，等于9个字节。由于这里最宽的基本类型为int，大小为4个字节,再补3个字节凑成4的倍数。这样一共是12个字节。现在给出例题代码中各个类大小的计算过程:

```
sizeof(A)=4;
sizeof(B)=1
sizeof(C)=4+1+3(补齐）=8
sizeof(D)=4+2+1+1(补齐）=8
sizeof(E) =4+4+2+1+1=12
sizeof(F)=4+4+4+2+1+1=16
```



# 15.使用sizeof 计算含有虚函数的类对象的空间大小

考点:使用sizeof计算含有虚函数的类对象的空间大小

出现频率:★★★★

请指出下面程序的输出是什么(在32位WinNT操作系统环境下)。

```cpp
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
```

​	上面这个程序定义了4个类，分别是Base、Derived、A和B。其中 Derived类是Base的子类，B是A的子类。下面是各个类的大小分析。

1. 对于Base类来说，它占用内存大小为sizeof(int)，等于4，print()函数不占内存。
2. 对于Derived类来说，比 Base类多一个整型成员，因而多4个字节，一共是12个字节。
3. 对于A类来说，由于它含有虚函数，因此占用的内存除了一个整型变量之外，还包括一个隐含的虚表指针成员，一共是8个字节。
4. 对于B类来说，比A类多一个整型成员，因而多4个字节，一共是12个字节。

​	通过这个例子可以看出，普通函数不占用内存，只要有虚函数，就会占用一个指针大小的内存，原因是系统多用了一个指针维护这个类的虚函数表，并且注意这个虚函数无论含有多少项（类中含有多少个虚函数）都不会再影响类的大小。

# 16.使用sizeof 计算虚拟继承的类对象的空间大小

考点:使用sizeof计算虚拟继承的类对象的空间大小

出现频率:★★★★

```cpp
#include <iostream>
using namespace std;

class A {};
class B {};
class C : public A, public B {};
class D : virtual public A {};
class E : virtual public A, virtual public B {};
class F {
public:
    int a;
    static int b;
};
int F::b = 10;

int main() {
    cout << "sizeof(A) = " << sizeof(A) << endl; //35
    cout << "sizeof(B) = " << sizeof(B) << endl; //36
    cout << "sizeof(C) = " << sizeof(C) << endl; //37
    cout << "sizeof(D) = " << sizeof(D) << endl; //38
    cout << "sizeof(E) = " << sizeof(E) << endl; //39 
    cout << "sizeof(F) = " << sizeof(F) << endl; //40

    return 0;
}

```

程序说明如下。

1. 代码第35行，由于A是空类，编译器会安插一个char 给空类，用来标记它的每
   一个对象。因此其大小为1个字节。
2. 口代码第36行，类B大小和A相同，都是1个字节。
3. 代码第37行，类C是多重继承自A和B，其大小仍然为1个字节。
4. 代码第38行，类D是虚继承自A，编译器为该类安插一个指向父类的指针，指针大
   小为4。由于此类有了指针，编译器不会安插一个char了。因此其大小是4个字节。
5. 代码第39行，类E虚继承自A并且也虚继承自B，因此它有指向父类A的指针
   与父类B的指针，加起来大小为8个字节。
6. 代码第40行，类F含有一个静态成员变量，这个静态成员的空间不在类的实例中，而
   是像全局变量一样在静态存储区中，被每一个类的实例共享，因此其大小是4个字节。



# 17. sizeof 与 strlen有哪些区别

考点:理解sizeof与 strlen的区别

出现频率:★★★

1. sizeof是操作符，strlen是函数。
2. sizeof操作符的结果类型是size_t，它在头文件中 typedef为unsignedint类型，该类型保证能容纳实现所建立的最大对象的字节大小。
3. sizeof可以用类型做参数，strlen只能用char*做参数，且必须是以"\0"结尾的。
4. 数组做sizeof的参数不退化，传递给strlen就退化为指针了。
5. 大部分编译程序在编译的时候sizeof就被计算过了，这就是 sizeof(x)可以用来定义数组维数的原因。strlen的结果要在运行的时候才能计算出来，它用来计算字符串的长度，不是类型占内存的大小。
6. sizeof后如果是类型，必须加括弧;如果是变量名，可以不加括弧。这是因为sizeof是个操作符，而不是个函数。
7. 在计算字符串数组的长度上有区别。例如，

```cpp
char str[20]="0123456789";
int a=strlen(str);
int b=sizeof(str) ;
```

a计算的是以0x00结束的字符串的长度（不包括0x00结束符)，这里结果是10。
b计算的则是分配的数组 str[20]所占的内存空间的大小，不受里面存储内容的改变而改变，这里结果是20。
如果要计算指针指向的字符串的长度，则一定要使用strlen。例如。

```cpp
char* ss = "0123456789" ;
int a = sizeof (ss) ;
int b = strlen(ss ) ;
```

a计算的是ss 指针占用的内存空间大小，这里结果是4。
b计算的是ss指向的字符串的长度，这里结果是10。



# 18. sizeof有哪些用途

考点:理解sizeof的用途

出现频率:★★★★



1. 与存储分配和I/O系统那样的例程进行通信。例如，

```cpp
void* malloc (size_t size);
size_t fread(void* ptr,size_t size,size_t nmemb，FILE* stream );
```

2. 查看某个类型的对象在内存中所占的单元字节。例如，
   ```cpp
   void* memset(void* s,int c, sizeof(s) );
   ```

3. 在动态分配一对象时，可以让系统知道要分配多少内存。便于一些类型的扩充，在 Windows 中很多结构类型就有一个专用的字段是用来放该类型的字节大小的。

4. 由于操作数的字节数在实现时可能出现变化，建议在涉及操作数字节大小时用sizeof来代替常量计算。

5. 如果操作数是函数中的数组形参或函数类型的形参，则 sizeof给出其指针的大小。



# 19. 找错——使用strlen()函数代替sizeof 计算字符串长度

考点: sizeof不能用于计算字符串长度

出现频率:★★★
这个程序存在下面两方面的问题。
	(1）函数UpperCase(char str[)的意图是将str指向的字符串中小写字母转换为大写字母。于是在代码第9行利用sizeof(str)/sizeof(str[0])获得数组中的元素个数以便做循环操作。然而，sizeof(str)得到的并不是数组占用内存的总大小，而是一个字符指针的大小，为4字节。因此这里只能循环4次，在代码第18行main()函数的调用中只能改变对数组的前四个字符进行转换。转换的结果为“ABCDe”。
	(2）在代码第17行，这里的意图是使用要打印字符串的长度。然而，sizeof(str)sizeof(str[O])计算的是数组元素的个数，比字符串的长度大1，原因是数组的长度还包括字符串的结束符\O'。
应该用strlen()函数来代替sizeof计算字符串长度。正确的代码如下。

```cpp
#include <iostream>

void upperCase(char str[]) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}

int main() {
    char str[] = "aBcDe";
    cout << "The length of str is " << strlen(str) << endl;
    upperCase(str);
    cout << str << endl;
    return 0;
}
```

# 20. 使用sizeof计算联合体的大小

写出以下代码的输出结果。

考点:使用sizeof计算联合体的大小

出现频率:★★★★

```cpp
#include <iostream>

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

int main() {
    std::cout << "Size of U: " << sizeof(U) << " bytes" << std::endl;
    std::cout << "Size of U2: " << sizeof(U2) << " bytes" << std::endl;
    std::cout << "Size of U3: " << sizeof(U3) << " bytes" << std::endl;

    return 0;
}
```

这个程序定义了3个联合体u、u2和u3。我们知道联合体的大小取决于它所有的成员中占用空间最大的一个成员的大小。并且对于复合数据类型，如 union、struct、class的对齐方式为成员中最大的成员对齐方式。

1. 对于u来说，大小就是最大的double类型成员a了，即 sizeof(u)=sizeof(double)=8。
2. 对于u2来说，最大的空间是 char[13]类型的数组。这里要注意，由于它的另一个成员int b的存在，u2的对齐方式变成4，也就是说，u2的大小必须在4的对齐上，所以占用的空间变为最接近13的对齐，即16。
3. 对于u3来说，最大的空间是char[13]类型的数组，即 sizeof(u3)=13。

​	这里又出现了CPU对齐的问题。所以编译器会尽量把数据放在它的对齐上以提高内存的命中率。对齐是可以更改的，使用#pragma pack(x)可以改变编译器的对齐方式。C++固有类型的对齐取编译器对齐方式与自身大小中较小的一个。例如，指定编译器按2对齐，int类型的大小是4，则 int 的对齐为2和4中较小的2。在默认的对齐方式下，因为几乎所有的数据类型都不大于默认的对齐方式8（除了long double)，所以所有的固有类型的对齐方式可以认为就是类型自身的大小。例如下面的程序:

```cpp
#include <iostream.h>
#pragma pack(2)
union u
{
char buf[9];int a;
};
int main()
{
cout << sizeof(u) << endl;
return 0;
}
```

​	C++固有类型的对齐取编译器对齐方式与自身大小中较小的一个。上面的程序中，由于使用手动更改对齐方式为2，所以int 的对齐也变成了2(int自身对齐为4)，u的对齐取成员中最大的对齐，也是2，所以此时sizeof(u)=10。

# 21. #pragma pack 的作用
选择代码输出的正确结果。

考点:理解#pragma pack指令的作用

出现频率:★★★★

```cpp
#include <iostream.h>

#pragma pack( 1)
struct test 
{
char c;
short s1;
short s2;
int i;
};

int main()
{
cout<< sizeof (test) <<endl;
return 0;
}
```

​	代码第3行用#pragma pack将对齐设为1。由于结构体test中的成员s1、s2和i的自身对齐分别为2、2和4，都小于1。因此它们都是用1作为对齐，sizeof(test)=1+2+2+4=9。
​	如果注释代码第3行，则编译器默认对齐为8。所以各个成员自身的对齐都小于8，因此它们使用自身的对齐，sizeof(test)=1+1（补齐）＋2＋2＋2(补齐)+4= 12。



# 22.为什么要引人内联函数

考点:理解内联函数的作用

出现频率:★★★★

​	引入内联函数的主要目的是，用它替代C语言中表达式形式的宏定义解决程序中函数调用的效率问题。在C语言里可以使用如下的宏定义。
```cpp
#define ExpressionName (Var1 ,var2) ( Var1+Var2)* (Var1 -Var2)
```

​	这种宏定义在形式及使用上像一个函数，但它使用预处理器实现，没有了参数压栈、代码生成等一系列的操作，因此效率很高。这种宏定义在形式上类似于一个函数，但在使用它时，仅仅只是做预处理器符号表中的简单替换，因此它不能进行参数有效性的检测，也就不能享受C++编译器严格类型检查的好处。另外，它的返回值也不能被强制转换为可转换的合适类型，这样，它的使用就存在着一系列的隐患和局限性。
​	另外，在C++中引入了类及类的访问控制，这样，如果一个操作或者说一个表达式涉及类的保护成员或私有成员，你就不可能使用这种宏定义来实现（因为无法将 this 指针放在合适的位置)。inline推出的目的，也正是为了取代这种表达式形式的宏定义。它消除了它的缺点，同时又很好地继承了它的优点。

# 23. 为什么inline能很好地取代表达式形式的预定义

考点:理解内联函数相比于宏定义的优越之处

出现频率:★★★

有如下几种原因:

1. inline定义的类的内联函数，函数的代码被放入符号表中，在使用时直接进行替换(像
   宏一样展开），没有了调用的开销，效率也很高。
2. 类的内联函数也是一个真正的函数。编译器在调用一个内联函数时，首先会检查
   它的参数的类型，保证调用正确;然后进行一系列的相关检查，就像对待任何一个真正的函数一样。这样就消除了它的隐患和局限性。
3. inline可以作为某个类的成员函数，当然就可以在其中使用所在类的保护成员及私有成员。



# 24.说明内联函数使用的场合

​	首先使用inline函数可以完全取代表达式形式的宏定义。
​	内联函数在C++类中应用最广的，应该是用来定义存取函数。我们定义的类中一般会把数据成员定义成私有的或者保护的，这样，外界就不能直接读写我们类成员的数据了。对于私有或者保护成员的读写就必须使用成员接口函数来进行。如果我们把这些读写成员函数定义成内联函数的话，将会获得比较好的效率。例如下面的代码:

```cpp
class A
{
Private :
	int nTest;
Public:
	int readTest()
    {
		return nTest;
    }
void setTest(int i);
};

inline void A: : setTest(int i)
{
	nTest= i;
};
```

​	类A的成员函数readTest()和 setTest()都是 inline 函数。readTest()函数的定义体被放在类声明之中，因而readTest()自动转换成inline 函数; setTest()函数的定义体在类声明之外，因此要加上 inline关键字。

# 25. 为什么不把所有的函数都定义成内联函数

考点:理解内联函数的缺点

出现频率:★★★★

​	内联是以代码膨胀（复制）为代价的，仅仅省去了函数调用的开销，从而提高函数的执行效率。如果执行函数体内代码的时间相比于函数调用的开销较大，那么效率的收获会很少。另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。以下情况不宜使用内联。

1. 如果函数体内的代码比较长，使用内联将导致内存消耗代价较高。
2. 如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。
3. 另外，类的构造函数和析构函数容易让人误解成使用内联更有效。要当心构造函数和析构函数可能会隐藏一些行为，如“偷偷地”执行了基类或成员对象的构造函数和析构函数。

​	所以不要随便地将构造函数和析构函数的定义体放在类声明中。一个好的编译器将会根据函数的定义体，自动地取消不值得的内联(这说明了inline不应该出现在函数的声明中)。



# 26. 内联函数与宏有什么区别

考点:理解内联函数与宏定义的区别

出现频率:★★★★

二者区别如下:

1. 内联函数在编译时展开，宏在预编译时展开。
2. 在编译的时候，内联函数可以直接被镶嵌到目标代码中，而宏只是一个简单的文
   本替换。
3. 内联函数可以完成诸如类型检测、语句是否正确等编译功能，宏就不具有这样的
   功能。
4. 宏不是函数，inline函数是函数。
5. 宏在定义时要小心处理宏参数（一般情况是把参数用括号括起来)，否则容易出
   现二义性。而内联函数定义时不会出现二义性。

