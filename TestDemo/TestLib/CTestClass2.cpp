#include "pch.h"
#include "CTestClass2.h"

void funcTestLib()
{
	std::cout << "this is a lib function" << std::endl;
}

void CTestClass2::print()
{
	std::cout << "m_nNum is " << m_nNum << std::endl;
}

void CTestClass2::print(int nCycle)
{
	for (int i = 0; i < nCycle; i++)
	{
		std::cout << "m_nNum is " << m_nNum << std::endl;
	}
}