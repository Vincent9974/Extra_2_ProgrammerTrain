#include <iostream>
using namespace std;


class Base {
protected:
    void printProtected() {
        cout << "print Protected" << endl;
    }
public:
    void printPublic() {
        cout << "print Public" << endl;
    }
};

class Derived1 : protected Base {
};

class Derived2 : private Base {
};

class A : public Derived1 {
public:
    void print() {
        printProtected();
        printPublic();
    }
};

class B : public Derived2 {
public:
    void print() {
        // 编译错误，不能访问
        // printProtected();
        // 编译错误，不能访问
        // printPublic();
    }
};



void ex_1()
{
    A objA;
    cout << "Printing from A:" << endl;
    objA.print();

    B objB;
    cout << "Printing from B:" << endl;
}


// 轮胎类
class Tire {
public:
    void roll() {
        cout << "Tire is rolling" << endl;
    }
};

// 引擎类
class Engine {
public:
    void start() {
        cout << "Engine is starting" << endl;
    }
};

// 汽车类，包含轮胎和引擎对象作为成员
class Car {
private:
    Tire tire;
    Engine engine;
public:
    void drive() {
        tire.roll();
        engine.start();
        cout << "Car is driving" << endl;
    }
};

void ex_5()
{
    Car car;
    car.drive();
}

class AA {
public:
    virtual void print(void) {
        cout << "AA::print()" << endl;
    }
};

class BB: public AA {
public:
    virtual void print(void) {
        cout << "BB::print()" << endl;
    }
};

class CC: public AA {
public:
    void print(void) {
        cout << "CC::print()" << endl;
    }
};

void print(AA a) {
    a.print();
}

void ex_9()
{
    AA a;
    BB b;
    CC c;

    AA *pa, *pb, *pc;
    pa = &a;
    pb = &b;
    pc = &c;

    a.print();
    b.print();
    c.print();

    pa->print();
    pb->print();
    pc->print();

    print(a);
    print(b);
    print(c);
}

class Shape
{
public:
    virtual double area() const = 0; 
    virtual void draw() const = 0;
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
    void draw() const override
    {
        cout << "Drawing Rectangle with area:" << area() << endl;
    }
};


class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}
    void draw() const override
    {
        cout << "Drawing Square with area:" << area() << endl;
    }
};

#define  M_PI 3.14
class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(3.14) {}
    double area() const override
    {
        return M_PI * radius * radius;
    }
    void draw() const  override
    {
        cout << "Drawing Circle with area:" << area() << endl;
    }
};

void ex_19()
{
    // 创建图形对象并调用绘制函数
    Rectangle rect(5.0, 3.0);
    Square square(4.0);
    Circle circle(2.5);

    rect.draw();
    square.draw();
    circle.draw();
}

int main()
{

    // ex_1();

    //ex_5();

    //ex_9();

    ex_19();

    return 0;
}
