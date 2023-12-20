#include "pch.h"
#include "CTestClass1.h"

//using namespace TestDll;

void CTestClass1::print()
{
	std::cout << "m_nNum is " << m_nNum << std::endl;
}

void CTestClass1::print(int nCycle)
{
	for (int i = 0; i < nCycle; i++)
	{
		std::cout << "m_nNum is " << m_nNum << std::endl;
	}
}

TESTDLL_API void print(int nCycle)
{
	for (int i = 0; i < nCycle; i++)
	{
		std::cout << "just for test" << std::endl;
	}
}