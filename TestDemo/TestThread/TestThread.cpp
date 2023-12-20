#include <iostream>
#include <windows.h>
#include <thread>
#include <mutex> 
#include <future>

void sayHello(int nRepeat)
{
    for (int _nIdx = 1; _nIdx <= nRepeat; ++_nIdx)
    {
        std::cout << "Hello Bro" << _nIdx  << "!" << std::endl;
    }
}

volatile int nCnt = 0;
std::mutex intMtx;
void increaseIntCnt()
{
    for (int _nIdx = 0; _nIdx < 10000; ++_nIdx)
    {
        //nCnt++;
        if (intMtx.try_lock())
        {
            nCnt++;
            intMtx.unlock();
        }
        else
        {
            _nIdx--;
        }
    }
}

std::string sTest = "";
std::mutex strMtx;
void increaseMapCnt()
{
    for (int _nIdx = 0; _nIdx < 10000; ++_nIdx)
    {
        //sTest.append("+");
        if (strMtx.try_lock())
        {
            sTest.append("+");
            strMtx.unlock();
        }
    }
}

volatile double dCnt = 0.0;
std::mutex dblMtx;
void increaseDblCnt()
{
    for (int _nIdx = 0; _nIdx < 10000; ++_nIdx)
    {
        /*if (dblMtx.try_lock())
        {
            dCnt += 1.0;
        }*/
        /*std::lock_guard<std::mutex> _guardian(dblMtx);
        dCnt += 1.0;*/
        std::unique_lock<std::mutex> _uniqueGrd(dblMtx, std::try_to_lock);
        dCnt += 1.0;

        // std::adopt_lock：表示这个互斥量已经被lock()，即不需要在构造函数中lock这个互斥量了。前提：必须提前lock
        // std::try_to_lock：尝试用mutex的lock()去锁定这个mutex，但如果没有锁定成功，会立即返回，不会阻塞在那里.前提：不能提前lock
        // std::defer_lock：初始化了一个没有加锁的mutex,不给它加锁的目的是以后可以调用unique_lock的一些方法.前提：不能提前lock
        // std::unique_lock<std::mutex> guard2(std::move(guard1)); guard1转移所有权至guard2
    }
}

std::atomic<int> atomicTest= 0;
//std::atomic<std::string> atomicTestStr;
void increaseAtomicTest()
{
    for (int _nIdx = 0; _nIdx < 100000000; ++_nIdx)
    {
        atomicTest++;

        //atomicTestStr.load().append("+");
        
        // store是原子写操作，load是原子读操作，exchange是于两个数值进行交换的原子操作
        // 一般atomic原子操作，支持++，–，+=，-=，&=，|=，^=
        // atomic只适用于 POD 类型（Plain Old Data），即标量类型和标量类型的数组，例如 int、short、long、bool、char、指针
        // 自定义类型使用atomic需满足简单且可复制(TriviallyCopyable)
    }
}

double doCalc(double dVal1, double dVal2)
{
    double _dSum = dVal1 + dVal2;

    Sleep(3000); // 假设该函数是个复杂的计算过程，需要消耗3秒

    return _dSum;
}

int main()
{
    // test thread
#if 0 
    std::cout << "Hello World!" << std::endl;

    std::thread _thd(sayHello, 10);
    //。。。
    //_thd.join();

    //_thd.detach();

    std::cout << "Hello World!" << std::endl;

    //Sleep(1.2);
#endif

    // test mutex 1
#if 0
    std::thread _arrThds[15];
    for (int _nIdx = 0; _nIdx < 15; ++_nIdx)
    {
        _arrThds[_nIdx] = std::thread(increaseIntCnt);
    }
    for (auto& _tt : _arrThds)
    {
        _tt.join();
    }
    std::cout << nCnt << std::endl;
#endif

    // test mutex 2
#if 0
    std::thread _arrThds[15];
    for (int _nIdx = 0; _nIdx < 15; ++_nIdx)
    {
        _arrThds[_nIdx] = std::thread(increaseMapCnt);
    }
    for (auto& _tt : _arrThds)
    {
        _tt.join();
    }
    std::cout << sTest << std::endl;
#endif

    // test lock_guard & unique_lock
#if 0
    std::thread _arrThds[15];
    for (int _nIdx = 0; _nIdx < 15; ++_nIdx)
    {
        _arrThds[_nIdx] = std::thread(increaseDblCnt);
    }
    for (auto& _tt : _arrThds)
    {
        _tt.join();
    }
    std::cout << dCnt << std::endl;
#endif

    // test atomic
#if 0
    std::thread _arrThds[1500000];
    for (int _nIdx = 0; _nIdx < 1500000; ++_nIdx)
    {
        _arrThds[_nIdx] = std::thread(increaseAtomicTest);
    }
    for (auto& _tt : _arrThds)
    {
        _tt.join();
    }
    std::cout << atomicTest << std::endl;
#endif

    // test async & future
#if 1
    std::future<double> _fuResult = std::async(doCalc, 1.0, 2.0); // 创建异步线程线程，并将线程的执行结果用_fuResult占位

    double _dTestVal = 0.0;
    for (int _nIdx = 0; _nIdx < 10000; ++_nIdx)
    {
        _dTestVal += 1.0;
    }
    std::cout << "_dTestVal：" << _dTestVal << std::endl;

    //std::cout << "计算结果：" << _fuResult.get() << std::endl; // 阻塞主线程，直至异步线程return

    std::cout << "结束计算" << std::endl;
#endif

    system("pause");
}
