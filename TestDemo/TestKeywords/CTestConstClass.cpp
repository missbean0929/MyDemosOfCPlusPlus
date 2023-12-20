#include <iostream>
#include "CTestConstClass.h"

CTestConstClass::CTestConstClass() :m_cnX(100), m_cpX(&m_cnX), m_cpY(&m_nY)
{
	m_nY = m_nZ = 100;

	//m_cnX = 200;

	//*m_cpX = 200;
	m_cpX = &m_nY;

	//m_cpY = &m_nZ;
	*m_cpY = 200;
}

void CTestConstClass::testPrint()
{
	std::cout << "heiheihei" << std::endl;
}

void CTestConstClass::testPrint() const
{
	std::cout << "heiheihei" << std::endl;
}

void CTestConstClass::testConstFunc1(int nParam) const
{
	//m_nY = 300;
	//m_nZ = 300;
	nParam += 100;
}

void CTestConstClass::testConstFunc2(int& nParam) const
{
	//m_nY = 300;
	//m_nZ = 300;
	nParam += 100;
}

void CTestConstClass::testConstParam1(const int nParam)
{
	//nParam += 100;
	m_nY = 300;
	m_nZ = 800;
}

void CTestConstClass::testConstParam2(const int* nParam)
{
	//*nParam = 300;
	nParam = &m_nY;
}

void CTestConstClass::testConstParam3(int* const nParam)
{
	*nParam = 300;
	//nParam = &m_nY;
}

void CTestConstClass::testConstParam4(const int*& nParam)
{
	//*nParam = 300;
	nParam = &m_nZ;
}

const int CTestConstClass::testConstReturn1()
{
	return m_nY;
}

const int& CTestConstClass::testConstReturn2()
{
	return m_nY;
}
