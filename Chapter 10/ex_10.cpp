#include <iostream>
using namespace std;


template <class T>
T my_max(T a, T b)
{
    return a > b ? a : b;
}


void ex_1() 
{
    std::cout << my_max<int>(1, 2.0) << std::endl;//显示调用
    std::cout << my_max ('A', 'C') << endl;//隐式调用
}

template <typename T, typename U>
class Point
{
private:
    T x;
    U y;
public:
    Point(T x_val, U y_val) : x(x_val), y(y_val) {}

    T getX() const { return x; }
    U getY() const { return y; }
};

void ex_2()
{
    Point<int, int> p1(1, 2);
    Point<float, int> p2(1.5f, 2);
    Point<float, float> p3(1.5f, 2.5f);

    std::cout << "Point p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "Point p3: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl;

} 

int main()
{

    // ex_1();

    ex_2();

    return 0;
}