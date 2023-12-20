#include <iostream>
#include <Windows.h>

// 动态库隐式链接1
#if 0
#include "../TestDll/TestDllDef.h"
#include "../TestDll/CTestClass1.h"

#pragma comment(lib, "../x64/Debug/TestDll.lib")

int main()
{
    CTestClass1 _class1;
    _class1.print();

    system("pause");
}

#endif

// 动态库隐式链接2
#if 0
#include "../TestDll/TestDllDef.h"

#pragma comment(lib, "../x64/Debug/TestDll.lib")

TESTDLL_API void print(int nCycle);
/*TESTDLL_API*/ class CTestClass1;
class CClassTest
{
public:
    CTestClass1* ppp;
};



int main()
{
    print(6);

   // CTestClass1 _class;

    CClassTest _tttt;
    //_tttt.ppp = new CTestClass1;

    system("pause");
}

#endif

// 动态库显式链接
#if 1
int main()
{
    HINSTANCE _hDll = ::LoadLibrary(L"TestDll.dll");
    if (_hDll)
    {
        typedef void(_cdecl* funcPrint)(int nCycle);
        funcPrint _pFunc = (funcPrint)GetProcAddress(_hDll, "print");
        if (_pFunc)
        {
            _pFunc(6);
        }
    }

    system("pause");
}
#endif

// 静态库链接
#if 0
#include "../TestLib/CTestClass2.h"

#pragma comment(lib, "../x64/Debug/TestLib.lib")

int main()
{
    CTestClass2 _class2;
    _class2.print();

    funcTestLib();

    system("pause");
}
#endif
