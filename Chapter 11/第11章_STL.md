​	STL (Standard Template Library)，即标准模板库，它涵盖了常用的数据结构和算法，并且具有跨平台的特点。将泛型编程思想和STL库用于系统设计中，明显降低了开发强度，提高了程序的可维护性及代码的可重用性。这也是越来越多的笔试和面试中考查STL相关知识的原因。
​	STL是C++标准函数库的一部分。STL的基本观念就是把数据和操作分离。图11.1所示的是STL组件之间的合作。

![11.1](./image\11.1.png)

​	由图11.1可知，STL中数据由容器类别来加以管理，操作则由可定制的算法来完成。迭代器在容器和算法之间充当黏合剂，它使得任何算法都可以和任何容器进行交互运作。STL含有容器、算法、迭代器组件。

* STL序列容器: vector、string、deque和 list

* STL关联容器:set、multiset、map和 multimap

* STL适配容器: stack、queue和 priority_queue



# 1. 什么是STL?

​	STL (Standard Template Library)，即标准模板库，是一个具有工业强度的、高效的C++程序库。它被容纳于C++标准程序库(C++ Standard Library)中，是 ANSI/ISOC++	标准中最新的也是极具革命性的一部分。该库包含了诸多在计算机科学领域里所常用的基本数据结构和基本算法，为广大C++程序员提供了一个可扩展的应用框架，高度体现了软件的可复用性。它类似于Microsoft Visual C++中的MFC (Microsoft Foundation ClassLibrary)。
​	从逻辑层次来看，在STL中体现了泛型化程序设计的思想(Generic Programming)，引入了许多新的名词,比如需求(requirements）概念(concept入模型(model)、容器(contaier)、算法(algorithmn)、迭代器（iterator）等。
​	从实现层次看，整个STL是以一种类型参数化(type parameterized）的方式实现的，这种方式基于一个在早先C++标准中没有出现的语言特性——模板(template)。如果查阅任何一个版本的STL源代码，你就会发现，模板作为构成整个STL的基石是一件千真万确的事情。除此之外，还有许多C++的新特性为STL的实现提供了方便。
​	STL是最新的C++标准函数库中的一个子集，它占据了整个库的大约80%的分量。而作为在实现STL过程中扮演关键角色的模板，则充斥了几乎整个C++标准函数库。C++标准函数库中的各个组件的关系图如图11.2所示。

![11.2](./image\11.2.png)

C++标准函数库包含了如下几个组件。

​	(1) C标准函数库，尽管有了一些变化，但是基本保持了与原有C语言程序库的良好兼容。C++标准库中存在两套C的函数库，一套是带有.h扩展名的（比如<stdio.h>)，而另一套则没有（比如<cstdio>)。它们确实没有太大的不同。

​	(2）语言支持(language support)部分，包含了一些标准类型的定义以及其他特性的定义。这些内容被用于标准库的其他地方或是具体的应用程序中。
​	(3）诊断(diagnostics）部分，提供了用于程序诊断和报错的功能，包含了异常处理( exception handling)、断言(assertions)、错误代码（ error number codes）三种方式。
​	(4）通用工具(general utilities）部分，这部分内容为C++标准库的其他部分提供支持。当然，你也可以在自己的程序中调用相应功能，比如动态内存管理工具、日期/时间处理工具。记住,这里的内容也已经被泛化了（采用了模板机制)。
​	(5）字符串 (string）部分，用来代表和处理文本。它提供了足够丰富的功能。
​	(6）国际化（internationalization）部分，作为OOP特性之一的封装机制在这里扮演着消除文化和地域差异的角色，采用locale和 facet可以为程序提供众多国际化支持，包括对各种字符集的支持、日期和时间的表示、数值和货币的处理等等。
​	(7）容器(containers）部分，是STL 的一个重要组成部分，涵盖了许多数据结构，如链表、vector(类似于大小可动态增加的数组)、queue(队列)、stack(堆栈)……string也可以看作一个容器，适用于容器的方法同样也适用于string。

​	(8）算法（algorithms）部分，用于操控各种容器，同时也可以操控内建数组。

​	(9）迭代器( iterators）部分，是STL的一个重要组成部分。它使得容器和算法能够完美地结合。事实上，每个容器都有自己的迭代器，只有容器自己才知道如何访问自己的元素。它有点像指针，算法通过迭代器来定位和操控容器中的元素。
​	(10）数值（numerics）部分，包含了一些数学运算功能，提供了复数运算的支持.

​	(11）输入/输出（input/output）部分，就是经过模板化了的原有标准库中的 iostream部分。它提供了对C++程序输入/输出的基本支持。在功能上保持了与原有iostream的兼容，增加了异常处理的机制，并支持国际化（ internationalization)。
​	总体上，在C++标准函数库中，STL主要包含了容器、算法、迭代器。string也可以算作STL的一部分。

​	STL，即标准模板库，是一个具有工业强度的、高效的C++程序库。它是最新的C++示准函数库中的一个子集，包括容器、算法、迭代器组件。

# 2. 具体说明STL 如何实现vector

vector的定义如下:

```cpp
template<class _Ty, class _A = allocator<_Ty> >class vector {
…
}
```

​	这里省略了中间的成员。其中\_Ty类型用于表示vector中存储的元素类型，\_A默认为allocator<_Ty>类型。
​	这里需要说明的是 allocator类，它是一种“内存配置器”，负责提供内存管理（可能包含内存分配、释放、自动回收等能力）相关的服务。于是对于程序员来说，就不用关心内存管理方面的问题了。

​	vector 支持随机访问，因此为了效率方面的考虑，它内部使用动态数组的方式实现。当进行insert或push_back把原数组的内容拷贝过去。所以，在一般动态地重新分配，一般是当前大小的两倍，然后把原数组的内容拷贝过去。所以，在一般情况下，其访问速度同一般数组，只有在重新分配发生时，其性能才会下降。例如下面的程序。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    // 初始时无元素，容量为0
    cout << v.capacity() << endl;

    v.push_back(1);
    // 容量不够，分配1个元素内存
    cout << v.capacity() << endl;

    v.push_back(2);
    // 容量不够，分配2个元素内存
    cout << v.capacity() << endl;

    v.push_back(3);
    // 容量不够，分配4个元素内存
    cout << v.capacity() << endl;

    v.push_back(4);
    v.push_back(5);
    // 容量不够，分配8个元素内存
    cout << v.capacity() << endl;

    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    // 容量不够，分配16个元素内存
    cout << v.capacity() << endl;

    return 0;
}
```

​	vector内部是使用动态数组的方式实现的。如果动态数组的内存不够用，就要动态地重新分配，一般是当前大小的两倍，然后把原数组的内容拷贝过去。所以，在一般情况下，其访问速度同一般数组，只有在重新分配发生时，其性能才会下降。它的内部使用allocator类进行内存管理，程序员不需要自己操作内存。

# 3. 看代码回答问题——vector容器中iterator的使用

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);

    for (vector<int>::size_type i = array.size() - 1; i >= 0; --i) {
        cout << array[i] << endl;
    }

    return 0;
}
```

​	当运行代码时，没有输出321，而是输出了一大堆很大的数字，为什么?于是修改代码:

```cpp
for (vector<int>::size_type j = array.size(); j > 0; j--) 
{
    cout << "element is " << array[j - 1] << endl;
}
```

​	这样输出了3 2 1, 到底是为什么呢?



​	由于vector支持随机访问，并且重载了[]运算符，因此可以像数组那样（比如a[i]）来访问 vector 中的第i+1个元素。

​	因此最后的结果为: size_type是个unsigned int类型成员。我们知道，无符号的整数是大于等于0的，因此上面第1段代码（代码第5行)中的i>=0永远为true，程序一直循环，输出很多随机数，最后程序崩溃。而第2段代码(代码第1行)使用了i>0作为循环的条件，即i为0时结束循环。

# 4.  看代码找错——vector容器的使用

```cpp
typedef vector IntArray;
IntArray array;
array.push_back(1);
array.push_back(2);
array.push_back(2);
array.push_back(3);

// 删除array数组中所有的2
for (IntArray::iterator itor = array.begin(); itor != array.end(); ++itor) {//8
    if (2 == *itor) {
        array.erase(itor);
}
```

这道题有两个错误。
	(1）代码第1行中没有使用类型参数，这将会导致编译错误。由于array需要添加 int类型的元素，因此代码第1行定义vector时应该加上 int类型。

​	(2）代码第8～12行的 for循环，这里只能删除 array数组中的第一个2，而不能删除所有的2。这是因为，每次调用“array.erase( itor );”后，被删除元素之后的内容会自动往前移，导致迭代漏项，应在删除一项后使 itor--，使之从已经前移的下一个元素起继续遍历。

```cpp
typedef vector<int> IntArray;
IntArray array;
array.push_back(1);
array.push_back(2);
array.push_back(2);
array.push_back(3);

// 删除array数组中所有的2
for (IntArray::iterator itor = array.begin(); itor != array.end(); ++itor) {
    if (2 == *itor) {
        itor = array.erase(itor);
        --itor; //给我回来
    } 
}

```



# 5. 把一个文件中的整数排序后输出到另一个文件中

​	这个题目涉及文件操作以及排序。我们可以使用vector容器来简化文件操作。在读文件的时候用push_back把所有的整数放入-一个vector<int>对象中，在写文件时用[]操作符直接把vector<int>对象输出到文件。代码如下。

```cpp
void Order(vector<int>& data)
{
    int count = data.size();
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count -i -1; j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j]  = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void ex_5()
{
    vector<int> data;
    ifstream in("./TXT/data.txt");
    if(!in)
    {
        cout << "infile error!" << endl;
        return;
    }
    int temp;
    while(!in.eof())
    {
        in >> temp;
        data.push_back(temp);
    }
    in.close();
    Order(data);
    ofstream out("./TXT/result.txt");
    if(!out)
    {
        cout << "outfile error!" << endl;
        return;
    }
    for(int i = 0; i < data.size(); ++ i)
    {
        out << data[i] << " ";
    }
    out.close();
}
```



# 6.  list和 vector有什么区别

​	vector和数组类似，它拥有一段连续的内存空间，并且起始地址不变，因此它能非常好地支持随机存取（使用[]操作符访问其中的元素)。但由于它的内存空间是连续的，所以在中间进行插入和删除操作会造成内存块的拷贝（复杂度是 O(n))。另外，当该数组后的内存空间不够时，需要重新申请一块足够大的内存并进行内存的拷贝。这些都大大影响了vector 的效率。
​	list是由数据结构中的双向链表实现的，因此它的内存空间可以是不连续的。因此只能通过指针来进行数据的访问。这个特点使得它的随机存取变得非常没有效率，需要遍历中间的元素，搜索复杂度O(n)，因此它没有提供[]操作符的重载。但由于链表的特点，它可以以很好的效率支持任意地方的删除和插入。

​	vector拥有一段连续的内存空间，因此支持随机存取。如果需要高效的随机存取，而不在乎插入和删除的效率，就使用vector。
​	list拥有一段不连续的内存空间，因此支持随机存取。如果需要大量的插入和删除
而不关心随机存取，则应使用list。



# 7. 分析代码问题并修正———list和vector容器的使用

```cpp
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> list1;

    // 将数字 0 到 7 添加到 list 中
    for (int i = 0; i < 8; i++) {
        list1.push_back(i);
    }

    // 删除 list 中所有偶数
    for (std::list<int>::iterator it = list1.begin(); it != list1.end();) {
        if (*it % 2 == 0) {
            it = list1.erase(it); // 删除偶数元素，并返回下一个元素的迭代器
        } 
        else
        {
            it++;
        }
    }

    return 0;
}
```

​	本题有下面两个方面的问题。
​	第一个问题是listl以及它的 iterator都缺少类型参数，代码第8行和第15行都有编译错误。由于在代码第12行添加的元素类型为int，因此需要将第8行和第15行中的list::改成 list<int>:。
​	第二个问题是当改正了上面编译的错误后，运行程序会导致程序崩溃。因为当第一次执行代码第19行（调用erase方法删除元素〉后，it原来指向的元素内存已经被释放掉了，因此进入下一次循环后，获得it的值就出现了访问违规。
​	这里要注意: vector使用的是数组方式，当删除一个元素后，此元素的后面元素会自动往前移动。而list由于使用链表结构，因此执行erase时会释放链表的节点内存。但是可以通过erase的返回值获得原来链表的下一个元素。



# 8.  stl::deque是一种什么数据类型

​	deque是由一段一段定量的连续空间组成的，因此是动态数组类型。



# 9.  在做应用时如何选择vector和l deque

​	deque称为双向队列容器，表面上与 vector非常相似，甚至能在许多实现中直接替换vector。比较deque和 vector两者的成员函数，可以发现下面两点。
​	( 1 ) deque 比 vector 多了push_front()和pop_front()两个函数，而这两个函数都是对于首部进行操作的。于是得到第一个使用deque 的情况，就是当程序需要从首尾两端进行插入或删除元素操作的时候。
​	(2) deque 中不存在capacity()和 reserve()成员函数。在 vector 中，这两个函数分别用于获取和设置容器容量，例如下面的代码段。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(1);
    std::cout << v.capacity() << std::endl;  // 输出：1

    v.reserve(10);
    std::cout << v.capacity() << std::endl;  // 输出：10

    return 0;
}
```

​	因此，对于vector来说，如果有大量的数据需要push back，则应当使用reserve()函数先设定其容量大小，否则会出现许多次容量扩充操作，导致效率很低。
​	而deque使用一段一段的定量内存，在进行内存扩充时也只是加一段定量内存，因此不存在容量的概念，也就没有capacity()和 reserve()成员函数。
​	最后，在插入(insert）操作上，deque和 vector有很大的不同。由于vector是一块连续的内存，所以插入的位置决定执行效率，位置越偏向数组首部，效率越低。而 deque中的内存是分段连续的，因此在不同段中的插入效率都相同。

# 10.  看代码找错—适配器stack和queue的使用

```cpp
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<int> s;
    queue<int> q;

    for (int i = 1; i < 10; i++) {
        s.push(i);
        q.push(i);
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}

```

​	代码第9～10行，使用vector分别定义了stack和 queue。代码第12～16行，把1～9放入s和q中。
​	代码第18~22行，循环打印s的栈顶元素，并且不断退栈，最终s变为空栈，打印的顺序为与入栈的顺序相反，即98765432 1。
​	代码第24~28行，与前面的操作方法一样，但是这里会出现编译错误。这是因为，queue是先进先出的，入队(调用push)是对队尾进行操作，由于q使用vector作为其序列容器，因此实际调用的是vector 的 push_back成员函数。而出队（调用pop）是对队首进行操作，此时q实际需要调用vector 的 pop_front成员函数，而vector没有这个pop_front成员。因此出现编译错误。stack 是后进先出的，入栈和退栈都是对尾部进行操作，而vector有相应的pushback和pop_back成员函数，因此代码第18～22行能够顺利执行。

# 11.  举例说明set的用法

```cpp
void ex_11()
{
    set<string> strset;
    set<string>::iterator si;

    strset.insert("cantaloupes");
    strset.insert("apple");
    strset.insert("orange");
    strset.insert("banana");
    strset.insert("grapes");
    strset.insert("grapes");

    strset.erase("banana");

    for (si = strset.begin(); si != strset.end(); si++) {
        cout << *si << " ";
    }
    
    cout << endl;
}
```

​	set不允许重复.



# 12. 举例说明map的用法

```cpp
void ex_12()
{
    map<int, string> mapstring;

    // 插入4个元素
    mapstring.insert(pair<int, string>(1, "one"));
    mapstring.insert(pair<int, string>(4, "four"));
    mapstring.insert(pair<int, string>(3, "three"));
    mapstring.insert(pair<int, string>(2, "two"));
    
    // 4已经存在，插入失败
    mapstring.insert(pair<int, string>(4, "four four"));
    
    // 1已经存在，修改键为1对应的值
    mapstring[1] = "one one";
    
    // 5不存在，添加键为5且值为"five"的元素
    mapstring[5] = "five";

    cout << mapstring[1] << endl; // 打印键为1对应元素的值

    mapstring.erase(2); // 删除键为2的元素
    
    // 查找键为2的元素
    map<int, string>::iterator f = mapstring.find(2);
    
    // 如果查找成功，则不相等
    if (f != mapstring.end()) {
        mapstring.erase(f);
        // 使用迭代器遍历map中所有元素
        map<int, string>::iterator it = mapstring.begin();
        while (it != mapstring.end()) {
            cout << (*it).first << " " << (*it).second << endl; // 打印元素的键和值
            it++;
        }
    }
}
```

​	上面的程序中，mapstring是存放pair<int, string>类型的元素。
​	插入操作，insert成员函数或使用[]操作符都可以进行插入。但它们有一点区别:当map中已经存在此键时，insert插入失败，例如代码第13行的插入没有作用;而[]操作符则修改此键所对应的元素，例如代码第15行则修改键为1对应的值。
​	查找操作，代码第20行查找键为2的元素，如果查找成功，则迭代器指向键为2的元素，否则指向末尾，即 mapstring.end()。
​	删除操作，这里演示了两种删除，和别的容器一样，可以删除迭代器指向的元素位置(或者两个迭代器的区间删除)。由于map中元素的键是唯一的，因此 map也提供了以键删除的操作（如代码第19行)。
​	遍历操作，与其他stl容器遍历操作类似，使用迭代器对 begin()和 end(O)之间进行迭代
it指向的是都pair<int, string>元素。pair有两个成员:first和 second，分别表示键(key)和值(value)。



# 13.  STL中map内部是怎么实现的

​	标准的STL关联容器（包括set和 map以及 set 的衍生体 multiset 和 map 的衍生体multimap）的内部结构是一个平衡二叉树(balanced binary tree)。平衡二叉树有下面几种。

​	STL的底层机制都是以RB-tree（红黑树）完成的。RB-tree也是一个独立容器但并不给外界使用。红黑树这个名字的得来就是由于树的每个结点都被着上了红色或者黑色，节点所着的颜色被用来检测树的平衡性。在对节点插入和删除的操作中，可能会被旋转来保持树的平衡性。平均和最坏情况下的插入、删除、查找时间都是O(Ign)。

# 14. map和 hashmap有什么区别?

​	有以下几点区别。
​	底层数据结构不同，map是红黑树，hashmap是哈希表。
​	map 的优点在于元素可以自动按照键值排序，而 hash map 的优点在于它的各项操
作的平均时间复杂度接近常数。
​	map属于标准的一部分，而hash map 则不是。

# 15. 什么是STL算法?

​	STL包含了大量的算法。它们巧妙地处理储存在容器中的数据。以reverse算法为例，我们只要简单使用reverse算法就能够逆置一个区间中的元素。

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 包含算法头文件
using namespace std;

int main() {
    int a[4] = {1, 2, 3, 4};
    vector<string> v;
    v.push_back("one");
    v.push_back("two");
    v.push_back("three");
    
    // 逆置数组 a 的所有元素
    reverse<int[4]>(a, a + 4);
    // 逆置 vector v 中的元素
    reverse<vector<string>::iterator>(v.begin(), v.end());

    // 输出 vector v 中的元素
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 输出数组 a 中的元素
    for (int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

​	可以看到，为了对数组a以及容器v中的所有元素进行逆置，我们都只调用了一个reverse方法。这里有几点要注意:
​	reverse是个全局函数，而不是成员函数。
​	reverse有两个参数，第一个参数是指向要操作的范围的头的指针，第二个参数是指
向尾的指针。
​	reverse操作一定范围的元素而不是仅仅操作容器，本题中对数组也进行了操作。

​	reverse和其他STL 算法一样，它们是通用的，也就是说，reverse不仅可以用来颠倒向量的元素，也可以用来颠倒链表中元素的顺序，甚至可以对数组操作。它们实际上都是函数模板。

# 16. 分析代码功能———STL算法的使用

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(int elem) {
    cout << elem << " ";
}

int main() {
    deque<int> coll;
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    deque<int>::iterator pos1;
    pos1 = find(coll.begin(), coll.end(), 2);
    deque<int>::iterator pos2;
    pos2 = find(coll.begin(), coll.end(), 7);

    for_each(pos1, pos2, print);
    cout << endl;

    deque<int>::reverse_iterator rpos1(pos1);
    deque<int>::reverse_iterator rpos2(pos2);

    for_each(rpos2, rpos1, print);
    cout << endl;

    return 0;
}
```

​	下面是程序的执行步骤。
​	(1）代码第14～17行，把1～9这9个数字放入coll容器中。
​	(2）代码第19、21行，调用find分别获得整数2和7在coll 中的存放位置，即 pos1指向2，pos2指向7。
​	(3)代码第22行，调用foreach对 pos1到pos2的区间元素依次执行print，打印各个元素值。由于左闭右开的原则，从2（pos1）开始到6 (pos2前一位）结束，打印结果为:23456。
​	(4）代码第25、26行，分别根据迭代器pos1和pos2得到反向迭代器rpos1和即rpos1指向1，rpos2指向6。
​	(5）代码第27行，此时使用rpos2和rpos1反向打印各个元素值。由于左闭右开的原则，从6 (rpos2）开始到2 (rpos1前一位）结束，打印结果为:65432。



# 17. vector中的erase方法与algorithm中的remove有什么区别

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> &a) {
    // 打印容器a中的所有元素
    for (typename vector<T>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);

    array.erase(array.begin()); // 调用erase删除1
    print(array);

    vector<int>::iterator pos;
    pos = remove(array.begin(), array.end(), 2); // 调用remove删除2
    print(array);

    if ((pos + 1) == array.end()) {
        cout << "(pos+1) == array.end()" << endl;
    }

    remove(array.begin(), array.end(), 3); // 调用remove删除所有3
    print(array);

    return 0;
}
```

​	vector 中erase是真正删除了元素，迭代器不能访问了。
​	而algorithm中的 remove只是简单地把要remove的元素移到了容器最后面，迭代器还是可以访问到的。这是因为algorithm通过迭代器操作，不知道容器的内部结构，所以无法做到真正删除。



# 18. 什么是auto_ptr ( STL智能指针)?如何使用

​	许多数据重要的结构以及应用，例如链表、STL容器、串、数据库系统以及交互式应用必须使用动态内存分配，因此仍然冒着万一发生异常导致内存溢出的风险。C++标准化委员会意识到了这个漏洞并在标准库中添加了一个特殊的类模板，它就是std:auto_ptr，其目的是促使动态内存和异常之前进行平滑的交互。auto_ptr保证当异常掷出时，分配的对象能被自动销毁，内存能被自动释放。下面是auto _ptr的用法。

```cpp
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Test {
public:
    Test() { name = NULL; }
    Test(const char* strname) {
        name = new char[strlen(strname) + 1];
        strcpy(name, strname);
    }
    Test& operator=(const char* namestr) {
        if (name != NULL) {
            delete name;
        }
        name = new char[strlen(namestr) + 1];
        strcpy(name, namestr);
        return *this;
    }
    void ShowName() { cout << name << endl; }
    ~Test() {
        if (name != NULL) {
            delete name;
            name = NULL;
            cout << "delete name" << endl;
        }
    }
public:
    char* name;
};

int main() {
    auto_ptr<Test> TestPtr(new Test("Terry")); // TestPtr智能指针
    TestPtr->ShowName(); // 使用智能指针调用ShowName()方法
    *TestPtr = "David"; // 使用智能指针改变字符串内容
    TestPtr->ShowName(); // 使用智能指针调用ShowName()方法

    int y = 1;
    int x = 0;
    y = y / x; // 产生异常，TestPtr指向对象的内存仍然能得到释放

    return 0;
}

```

​	在这里，我们定义了一个Test类用于测试。Test类有一个成员name，并实现它的构造函数、赋值函数以及析构函数，另外还有ShowName()打印 name字符串。下面是使用auto_ptr操作的步骤。
​	代码第37行，创建并初始化 auto_ptr。auto_ptr后面的尖括弧里指定auto_ptr 指针的类型，在这个例子中是Test。然后auto_ptr句柄的名字，在这个例子中是TestPtr。最后是用动态分配的对象指针初始化这个实例。注意，只能使用auto_ptr构造器的拷贝，也就是说，代码第38行使用赋值的方式是非法的，因此第38行会出现编译错误。
​	代码第39行，使用TestPtr调用Test中的ShowName()成员函数。和一般指针操作相同,这里使用的是->操作符。
​	代码第40行，使用TestPtr对原对象进行赋值。和一般指针相同，这里也是使用*操作符。代码第41行，再次调用ShowName()打印 name字符串。

​	代码第44行，这里会发生除0的异常，程序崩溃，但是智能指针指向的内存仍然能得到释放。
​	没有注释代码第44行，即程序不会崩溃，则main函数返回前，TestPt发生析构，这时会调用Test的析构函数。

输出:

```cpp
Terry
David
程序崩溃
Delete name
```

​	由此可以看出，使用auto_ptr可以代替指针进行类似指针的操作，并且不用关心内存释放。auto_ptr是如何解决前面提到的内存溢出问题的呢? auto_ptr的析构函数自动摧毁它绑定的动态分配对象。也就是说，当TestPt 的析构函数执行时，它删除构造TestPt 期间创建的Test对象指针。



# 19. 看代码找错─智能指针auto_ptr的使用
```cpp
std::auto_ptr ptr(new char[10]);
```

auto_ptr后面的尖括弧里必须指定auto_ptr指针的类型，这里为char。正确的语句为:

```cpp
std::auto_ptr<char> ptr(new char[10]);
```



# 20. 智能指针如何实现

​	智能指针是用来实现指针指向的对象的共享的。其实现的基本思想:每次创建类的新对象时，初始化指针并将引用计数置为1;
​	当对象作为另一对象的副本而创建时，拷贝构造函数拷贝指针并增加与之相应的引用计数;
​	对一个对象进行赋值时，赋值操作符减少左操作数所指对象的引用计数(如果引用计数减至0，则删除对象)，并增加右操作数所指对象的引用计数;
​	调用析构函数时，减少引用计数（如果引用计数减至0，则删除基础对象);重载“>”以及“*”操作符，使得智能指针有类似于普通指针的操作。



# 21. 使用std::auto_ptr有什么方面的限制

​	标准C++提供的 auto_ptr。而 auto_ptr的使用是有很多限制的，我们一条一条来细数。

​	(1) std::auto_ptr 要求一个对象只能有一个拥有者，严禁一物二主，这一点和前面实现的SmartPtr不同。比如以下用法是错误的。

```cpp
classA *pA = new classA;
auto_ptr<classA> ptr1(pA);
auto_ptr<classA> ptr2(pA);
```

​	(2） std::auto_ptr是不能以传值方式进行传递的。
​	因为所有权的转移，会导致传入的智能指针失去对指针的所有权。如果要传递，可以采用引用方式，利用const 引用方式还可以避免程序内其他方式的所有权的转移。

​	(3）其他注意事项:

​	不支持数组。

​	注意其 Release语意。Release是指释放出指针，即交出指针的所有权。

​	auto ptr在拷贝构造和=操作符时的特珠含义决定了它不能做为STL标准容器的成员。

# 22 . 如何理解函数对象?

​	简单地说，函数对象就是一个重载了“()”运算符的类的对象，它可以像一个函数一样使用。例如	

```cpp
#include <iostream>

// 定义一个函数对象类
class MyFunctor {
public:
    // 重载函数调用运算符
    int operator()(int x) const {
        return x * x;
    }
};

int main() {
    MyFunctor func; // 创建函数对象的实例

    // 使用函数对象调用
    std::cout << func(5) << std::endl; // 输出 25，等价于调用 func.operator()(5)

    return 0;
}
```

​	可以看出，由于类MyAdd和类MyMinus都重载了“()”运算符，因此它们的对象addObj和minusObj可以像函数那样使用。

​	STL中提供了一元和二元函数的两种函数对象。下面列出了各个函数对象。

​	negate，相反数。元函数对象:
​	plus，加（+)法。minus，减（-)法。multiplies，乘（*）法。divides，除(/)法。modulus，求余（(%)。equal_to，等于(==)。
​	not_equal_to，不等于（!=)。greater，大于(>)。
​	greater_equal，大于或等于(>=)。less，小于(<)。
​	less_equal，小于或等于(<=)。logical_and，逻辑与(&&)。

以上这些函数对象都是基于模板实现的，可以这样使用它们:

```cpp
minus<int> int_minus;
cout << int_minus(3,4) << endl;
```

# 23. 如何使用bindlst和 bind2nd

`bind1st` 和 `bind2nd` 是 C++ 标准库 `<functional>` 中的函数适配器，用于将二元函数适配成一元函数，以便在算法中使用。它们的使用方法如下：

1. `bind1st` 函数适配器：将一个二元函数的第一个参数绑定为指定的值，从而将其转换为一元函数。
2. `bind2nd` 函数适配器：将一个二元函数的第二个参数绑定为指定的值，从而将其转换为一元函数。

下面是它们的用法示例：

```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // 使用 bind1st 将 greater<int>() 转换为一元谓词
    auto greater_than_3 = std::bind1st(std::greater<int>(), 3);
    std::cout << "Numbers greater than 3: ";
    for (auto num : nums) {
        if (greater_than_3(num)) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    // 使用 bind2nd 将 less<int>() 转换为一元谓词
    auto less_than_4 = std::bind2nd(std::less<int>(), 4);
    std::cout << "Numbers less than 4: ";
    for (auto num : nums) {
        if (less_than_4(num)) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
```

​	bind1st和 bind2nd都是函数适配器，用于将二元函数对象转换为一兀函数对家。bindlst绑定的是第一个参数，而bind2nd绑定的是第二个参数。

