#include <iostream>
#include <array>
#include <thread>

using namespace std;

int g_nGlobalInt = 1;
const int c_nConstInt = 1;

int* testReturn()
{
    int _nX = 100;
    cout << "&_nX: " << &_nX << endl;
    cout << "_nX: " << _nX << endl;
    int* _pInt = &_nX;
    return _pInt;
}

/*volatile*/ int g_nCnt = 0;
void testIntCnt()
{
    for (int _nIdx = 0; _nIdx < 10000; ++_nIdx)
    {
        g_nCnt++;
    }
}

/*volatile*/ int g_bFlag = false;
void testVolatile()
{
    while (!g_bFlag)
    {
        // 空循环
    }

    cout << "testVolatile flag is set." << endl;
}

int main()
{
    // 内存分配1
#if 0
    int _nLocalInt1 = 1;
    int _nLocalInt2 = 1;
    int* _nTempInt1 = new int;
    int* _nTempInt2 = new int;
    cout << "global: " << &g_nGlobalInt << endl;
    cout << "const: " << &c_nConstInt << endl;
    cout << "local1: " << &_nLocalInt1 << endl;
    cout << "local2: " << &_nLocalInt2 << endl;
    cout << "temp1: " << _nTempInt1 << endl;
    cout << "temp2: " << _nTempInt2 << endl;
    delete _nTempInt1;
    delete _nTempInt2;
#endif
    // 内存分配2-Q
#if 0
    int* _pInt = testReturn();
    cout << "_pInt: " << _pInt << endl;
    cout << "*_pInt: " << *_pInt << endl;

    int _nY = 200;
    cout << "&_nY: " << &_nY << endl;
    cout << "_nY: " << _nY << endl;

    cout << "_pInt: " << _pInt << endl;
    cout << "*_pInt: " << *_pInt << endl;
#endif
    // 代码消除优化
#if 0
    int _nTest = 1;

    while (false)
    {
        //...
    }

    if (true)
    {
        return 0;
        cout << "passed" << endl;
    }
#endif
    // 数据流分析优化
#if 0
    auto _funCalc = [&](int a, int b) ->int
    {
        int x = a + b;
        int y = a - b;
        int result = x * y;  // 可以将乘法操作优化为 result = (a + b) * (a - b);
        return result;
    };
    cout << "_funCalc" << _funCalc(10, 20) << endl;
#endif
    // 循环展开
#if 0
    array<int, 4> _arrTest{};
    for (int i = 0; i < 4; i++)
    {
        _arrTest[i] = i * 2;
    }
    // 展开后的
    // _arrTest[0] = 0 * 2;
    // _arrTest[1] = 1 * 2;
    // _arrTest[2] = 2 * 2;
    // _arrTest[3] = 3 * 2;
#endif
    // 递归优化
#if 0
    auto _funFibonacci1 = [&](auto& funSelf, int n)->int
    {
        if (n <= 1)
        {
            return n;
        }

        return funSelf(funSelf, n - 1) + funSelf(funSelf, n - 2);
    };
    auto _funFibonacci2 = [&](int n)->int
    {
        int a = 0;
        int b = 1;

        for (int i = 2; i <= n; i++)
        {
            int temp = a + b;
            a = b;
            b = temp;
        }

        return b;
    };
    cout << "_funFibonacci1: " << _funFibonacci1(_funFibonacci1, 10) << endl;
    cout << "_funFibonacci2: " << _funFibonacci2(10) << endl;
#endif
    // 多线程volatile1-Q
#if 0
    thread _testThread(testVolatile);

    this_thread::sleep_for(chrono::seconds(5));
    g_bFlag = true;

    _testThread.join();

#endif
    // 多线程volatile2
#if 0
    thread _arrThds[15];
    for (int _nIdx = 0; _nIdx < 15; ++_nIdx)
    {
        _arrThds[_nIdx] = thread(testIntCnt);
    }
    for (auto& _tt : _arrThds)
    {
        _tt.join();
    }
    cout << "g_nCnt: " << g_nCnt << endl;
#endif
    // 常量优化volatile
#if 1
    volatile const int _nX = 500;
    auto _pX = const_cast<int*>(&_nX);

    cout << "初始值 :" << _nX << endl;
    *_pX = 100;
    cout << "修改后的值 :" << _nX << endl;
#endif

    system("pause");
}
