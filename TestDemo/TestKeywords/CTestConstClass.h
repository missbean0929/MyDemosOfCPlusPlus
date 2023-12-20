#pragma once

class CTestConstClass
{
public:
	CTestConstClass();

public:
	void testPrint();

	void testPrint() const;

	void testConstFunc1(int nParam) const;

	void testConstFunc2(int& nParam) const;
	// useless
	void testConstParam1(const int nParam);
	// useless
	void testConstParam2(const int* nParam);
	
	void testConstParam3(int* const nParam);
	// bravo
	void testConstParam4(const int*& nParam);
	// useless
	const int testConstReturn1();
	// bravo
	const int& testConstReturn2();

private:
	const int m_cnX;
	mutable int m_nY;
	mutable int m_nZ;
	const int* m_cpX;
	int* const m_cpY;
};
