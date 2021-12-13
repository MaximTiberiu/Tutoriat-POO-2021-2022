#include <iostream>

class A {
public:

};

class B : public A {
public:

};

class C : public A {
public:

};

int main() {
//    int a = (int) 2.5;
//    int b = static_cast<int>(2.5);

    B *b = new B();
    A *a = dynamic_cast<A*>(b);

    return 0;
}
