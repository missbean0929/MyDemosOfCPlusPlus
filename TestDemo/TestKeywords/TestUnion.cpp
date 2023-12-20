#include <iostream>
#include <Windows.h>
#include <bitset>

class CTestClass1
{
    /*public:
        ~CTestClass1();*/

    public:
        void print()
        {
            std::cout << "CTestClass1's print func : " << m_int + 1 << std::endl;
        }

    private:
        int m_int;
};

class CTestClass2
{
public:
    void print()
    {
        std::cout << "CTestClass2's print func : " << m_int + 100 << std::endl;
        //std::cout << "CTestClass2's print func : " << m_double + 100 << std::endl;
    }

private:
    int m_int;
    //double m_double;
};

union TestUnion1
{
    int integrateMember;
    /*char textMember;
    float floatMember;
    double doubleMember;
    int arrayMember[7];*/

    CTestClass1 classMember1; 
    CTestClass2 classMember2;
};

union TestUnion2
{
    unsigned char m_bits[4];
    int m_num;
};

union TestUnion3
{
    int m_num;
    char m_char;
};

struct SBitVal
{
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

union TestUnion4
{
    unsigned char m_bytedata;
    SBitVal m_bitdata;
};

struct STestStruct1
{
    int m_int;

    void print()
    {
        std::cout << "STestStruct1's print func : " << m_int << std::endl;
    }
};

int main()
{
    // size of union
#if 0
    TestUnion1 _union;
    std::cout << "TestUnion1 size : " << sizeof(_union) << std::endl;
    STestStruct1 _struct;
    std::cout << "STestStruct1 size : " << sizeof(_struct) << std::endl;
    CTestClass1 _class;
    _class.print();
    std::cout << "CTestClass1 size : " << sizeof(_class) << std::endl;
#endif
    // init of union
#if 0
    TestUnion1 _union = { 100 };
    //TestUnion1 _union = { 100 , 200};
#endif
    // value of union
#if 0
    TestUnion1 _union;
    /*_union.integrateMember = 100;
    std::cout << "TestUnion1 integrateMember : " << _union.integrateMember << std::endl;
    std::cout << "TestUnion1 textMember : " << _union.textMember << std::endl;
    std::cout << "TestUnion1 floatMember : " << _union.floatMember << std::endl;
    std::cout << "TestUnion1 doubleMember : " << _union.doubleMember << std::endl;*/
    _union.doubleMember = 200;
    std::cout << "TestUnion1 integrateMember : " << _union.integrateMember << std::endl;
    std::cout << "TestUnion1 textMember : " << _union.textMember << std::endl;
    std::cout << "TestUnion1 floatMember : " << _union.floatMember << std::endl;
    std::cout << "TestUnion1 doubleMember : " << _union.doubleMember << std::endl;
#endif
    // cast of union
#if 0
    TestUnion1 _union;
    _union.integrateMember = 100;
    TestUnion1* _pUnion = &_union;
    CTestClass2* _pInt = (CTestClass2*)_pUnion;
    _pInt->print();
#endif
    // usage of union - data type cast
#if 0
    TestUnion1 _union;
    _union.integrateMember = 100;
    _union.classMember1.print();
    _union.classMember2.print();
#endif
    // usage of union - memory
#if 0
    TestUnion2 _union;
    _union.m_num  = 114514;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::bitset<8>(_union.m_bits[i]) << " ";
    }
#endif
    // usage of union - storey type
#if 0
    TestUnion3 _union;
    _union.m_num = 0x11223344;
    if (_union.m_char == 0x11)
    {
        std::cout << "大端";
    }
    else if (_union.m_char == 0x44)
    {
        std::cout << "小端";
    }
#endif
    // usage of union - bit
#if 1
    TestUnion4 _union;
    _union.m_bytedata = 0x5A;
    printf("%d\n", _union.m_bytedata);
    printf("%d\n", _union.m_bitdata.bit5);    // 读取第6位   
    _union.m_bitdata.bit7 = 1;              // 修改第8位
    printf("%d\n", _union.m_bytedata);
#endif
    // examples of BIMBase's union

    system("pause");
}
