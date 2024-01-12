#include <iostream>

class A
{
public:
    void print1() // 这个是继承
    {
        std::cout << "class A's function : print1" << std::endl;
    }

    void print2() // 这个是遮掩
    {
        std::cout << "class A's function : print2" << std::endl;
    }

    virtual void print3() // 这个是多态
    {
        std::cout << "class A's function : print3" << std::endl;
    }

private:
    int m_x = 0;
    int m_y = 1;
    char m_c = '0';
};

class B : public A
{
public:
    void print2() // 这个是遮掩
    {
        std::cout << "class B's function : print2" << std::endl;
    }

    virtual void print3() override // 这个是多态
    {
        std::cout << "class B's function : print3" << std::endl;
    }

};

int main()
{
    A _a;
    std::cout << "size of class A :" << sizeof(A) << std::endl;
    B _b;
    std::cout << "size of class B :" << sizeof(B) << std::endl;
    std::cout << "############################" << std::endl;

    A* _pA = new A;
    _pA->print1();
    _pA->print2();
    _pA->print3();
    std::cout << "############################" << std::endl;

    B* _pB = new B;
    _pB->print1();
    _pB->print2();
    _pB->print3();
    std::cout << "############################" << std::endl;

    A* _pBA = dynamic_cast<A*>(_pB);
    _pBA->print1();
    _pBA->print2();
    _pBA->print3();
    std::cout << "############################" << std::endl;

    A* _pP = new B;
    _pP->print1();
    _pP->print2();
    _pP->print3();
    std::cout << "############################" << std::endl;

    system("pause");

    return 0;
}