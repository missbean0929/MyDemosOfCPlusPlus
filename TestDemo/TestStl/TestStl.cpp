#include <iostream>
#include <vector>
int main()
{
#if 1 // vector
    std::vector<int> _vctNum;
    std::cout << "size of vector is: " << sizeof(_vctNum) << std::endl;
    std::cout << "capacity of vector is: " << _vctNum.capacity() << std::endl;
    std::cout << "address of vector is: " << _vctNum.begin()._Ptr << std::endl;

    _vctNum.push_back(1);
    _vctNum.push_back(2);
    _vctNum.push_back(3);
    _vctNum.push_back(4);
    _vctNum.push_back(5);
    _vctNum.push_back(6);
    _vctNum.push_back(7);
    _vctNum.push_back(8);
    _vctNum.push_back(9);
    _vctNum.push_back(10);
    std::cout << "size of vector is: " << sizeof(_vctNum) << std::endl;
    std::cout << "capacity of vector is: " << _vctNum.capacity() << std::endl;
    std::cout << "address of vector is: " << _vctNum.begin()._Ptr << std::endl;

    _vctNum.reserve(50);
    std::cout << "size of vector is: " << sizeof(_vctNum) << std::endl;
    std::cout << "capacity of vector is: " << _vctNum.capacity() << std::endl;
    std::cout << "address of vector is: " << _vctNum.begin()._Ptr << std::endl;

#endif



    std::cout << "Hello World!\n";
}
