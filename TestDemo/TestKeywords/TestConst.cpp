#include <iostream>
#include <Windows.h>
#include "CTestConstClass.h"

void defineNumber()
{
    const int _cnY = 200;
    #define CONST_INT_Y 200
}

int main()
{
    // const和#define的作用域
#if 0
    {
        const int _cnX = 100;
        std::cout << "_cnX: " << _cnX << std::endl;
    }
    //std::cout << "_cnX: " << _cnX << std::endl;

    {
#define CONST_INT_X 100
        std::cout << "CONST_INT_X: " << CONST_INT_X << std::endl;
    }
    std::cout << "CONST_INT_X: " << CONST_INT_X << std::endl;
    std::cout << "CONST_INT_Y: " << CONST_INT_Y << std::endl;
#endif
    // const和#define的类型检查
#if 1
    const int c_nX = 100;
    std::cout << "c_nX: " << c_nX << std::endl;
    //c_nX = 200;

    #define NUMBER_TEST 100
    int _nY = NUMBER_TEST;
    std::cout << "_nY: " << _nY << std::endl;
    _nY = 200;
    std::cout << "_nY: " << _nY << std::endl;

    const int c_nZ = NUMBER_TEST;
    std::cout << "c_nZ: " << c_nZ << std::endl;
    //c_nZ = 200;
#endif
    // const和#define的替代
#if 0
    const int c_nX = 100;
    std::cout << "c_nX: " << c_nX << std::endl;
    //const int c_nX = 200;
    //std::cout << "c_nX: " << c_nX << std::endl;
    #define NUMBER_TEST 100
    std::cout << "NUMBER_TEST: " << NUMBER_TEST << std::endl;
    #define NUMBER_TEST 200
    std::cout << "NUMBER_TEST: " << NUMBER_TEST << std::endl;
    #undef NUMBER_TEST
    //std::cout << "NUMBER_TEST: " << NUMBER_TEST << std::endl;
#endif
    // 修饰变量
#if 0
    const int _cnX = 100;
    std::cout << "_cnX: " << _cnX << std::endl;
    //_cnX = 200;
    //int* _pX = &_cnX;
    const int* _pX = &_cnX;
    std::cout << "*_pX: " << *_pX << std::endl;
    //*_pX = 200;
    int* _pX1 = const_cast<int*>(_pX);
    *_pX1 = 200;
    std::cout << "_cnX: " << _cnX << std::endl;
    std::cout << "*_pX: " << *_pX << std::endl;
    std::cout << "*_pX1: " << *_pX1 << std::endl;
#endif
    // 修饰指针
#if 0
    int _nX = 100;
    std::cout << "_nX: " << _nX << std::endl;
    int _nY = 200;
    std::cout << "_nY: " << _nY << std::endl;

    const int* _pX = &_nX;
    std::cout << "*_pX: " << *_pX << std::endl;
    //*_pX = 300;
    _pX = &_nY;
    std::cout << "*_pX: " << *_pX << std::endl;

    int* const _pY = &_nY;
    std::cout << "*_pY: " << *_pY << std::endl;
    *_pY = 300;
    std::cout << "*_pY: " << *_pY << std::endl;
    //_pY = &_nX;
#endif
    // 修饰引用
#if 0
    int _nX = 100;
    std::cout << "_nX: " << _nX << std::endl;
    int _nY = 200;
    std::cout << "_nY: " << _nY << std::endl;

    const int& _rX = _nX;
    std::cout << "_rX: " << _rX << std::endl;
    //_rX = 300;
    //std::cout << "_rX: " << _rX << std::endl;
    //std::cout << "_nX: " << _nX << std::endl;
    //_rX = _nY;
    //std::cout << "_rX: " << _rX << std::endl;
#endif
    // 类中的使用
#if 1
    CTestConstClass _classTest;

    int _nTestParam = 900;

    _classTest.testConstFunc1(_nTestParam);
    std::cout << "1 _nTestParam: " << _nTestParam << std::endl;
    _classTest.testConstFunc2(_nTestParam);
    std::cout << "2 _nTestParam: " << _nTestParam << std::endl;

    _classTest.testConstParam1(_nTestParam);
    std::cout << "3 _nTestParam: " << _nTestParam << std::endl;
    _classTest.testConstParam2(&_nTestParam);
    std::cout << "4 _nTestParam: " << _nTestParam << std::endl;
    _classTest.testConstParam3(&_nTestParam);
    std::cout << "5 _nTestParam: " << _nTestParam << std::endl;
    //_classTest.testConstParam4(&_nTestParam);
    const int* _pTestParam = &_nTestParam;
    _classTest.testConstParam4(_pTestParam);
    std::cout << "6 _nTestParam: " << *_pTestParam << std::endl;

    const int _nReturn1 = _classTest.testConstReturn1();
    const int& _nReturn2 = _classTest.testConstReturn2();
    //_nReturn = 888;


    const CTestConstClass _classTest2;
    //_classTest2.testConstReturn1();
    _classTest2.testPrint();
#endif
    
    system("pause");
}
