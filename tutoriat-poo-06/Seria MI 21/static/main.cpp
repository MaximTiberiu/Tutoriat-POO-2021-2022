#include <iostream>

// int staticVar = 14; - EROARE: multiple definitions of 'staticVar'
extern int staticVar1;
int staticVar2 = 90;

void fun() {
    static int i = 0;
    i++;
    std::cout << i << "\n";
}

class myClass {
public:
    static int value;

    static void printValue() {
        std::cout << value << "\n";
    }
};

int myClass::value;

class mySingletonClass {
private:
    static mySingletonClass *_instance;
    int _n;
    mySingletonClass() = default;
public:
      static mySingletonClass* getInstance() {
          if (_instance == nullptr) {
              _instance = new mySingletonClass();
          }
          return _instance;
      }

      void setN(int n) {this->_n = n;}
      int getN() const {return _n;}
      void printN() const {std::cout << _n << "\n";}
};

mySingletonClass * mySingletonClass::_instance;

int main() {
//    std::cout << staticVar << "\n";
//    std::cout << staticVar1 << "\n";
//    std::cout << staticVar2 << "\n";

//    fun();
//    fun();
//    fun();
//    fun();
//    fun();

//    myClass::value = 2;
//
//    myClass::value = 5;
//
//    myClass::printValue();
//    myClass::printValue();


    mySingletonClass *instance = mySingletonClass::getInstance();
    instance->setN(4);
    instance->printN();

    mySingletonClass *instance1 = mySingletonClass::getInstance();
    instance1->setN(9);
    instance->printN();

    return 0;
}
