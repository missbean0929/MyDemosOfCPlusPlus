#include <iostream>
#include <Windows.h>
#include <variant>

class A
{
//protected:
//    virtual void xxx() = 0;
};
class B :public A
{
//protected:
//    virtual void xxx() { return; }
private:
    int m_nX = 0;
    int m_nY = 0;
    int m_nZ = 0;
};

struct SPrintVisitor
{
    void operator()(int i) const {
        std::cout << "int: " << i << std::endl;
    }
    void operator()(char c) const {
        std::cout << "char: " << c << std::endl;
    }
    void operator()(double d) const {
        std::cout << "double: " << d << std::endl;
    }
};

struct SPlusOneVisitor
{
    void operator()(int i) const {
        std::cout << "int: " << i << std::endl;
    }
    void operator()(char c) const {
        std::cout << "char: " << c << std::endl;
    }
    void operator()(double d) const {
        std::cout << "double: " << d << std::endl;
    }
};

int main()
{
    // size of variant
#if 1
    std::variant<int, char/*, double, B*/> _testVariant;
    std::cout << "size of variant : " << sizeof(_testVariant) << std::endl;
#endif
    // init of variant
#if 0
    //std::variant<int, char, double> _testVariant; // 初始化int
    //std::variant<int, char, double> _testVariant{'a'}; // 列表初始化
    //std::variant<int, char, double> _testVariant(100.0); // 值初始化
    //std::variant<int, char, double> _testVariant = 10; // 拷贝复制初始化
    //std::variant<int, char, double> _testVariantCopy(_testVariant);
    //std::variant<int, char, double> _testVariant{std::in_place_index<1>, 'x'}; // in_place指定索引初始化
    //std::cout << "value of variant : " << std::get<char>(_testVariant) << std::endl;
#endif
    // value of variant
#if 0
    std::variant<int, char, double> _testVariant;
    //_testVariant = "";
    /*_testVariant = 40;
    std::cout << "value of variant : " << std::get<int>(_testVariant) << std::endl;
    std::cout << "index of variant : " << _testVariant.index() << std::endl;
    std::cout << "does int member active: " << (std::holds_alternative<int>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does char member active: " << (std::holds_alternative<char>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does double member active: " << (std::holds_alternative<double>(_testVariant) ? "true" : "false") << std::endl;
    _testVariant = 'a';
    std::cout << "value of variant : " << std::get<char>(_testVariant) << std::endl;
    std::cout << "index of variant : " << _testVariant.index() << std::endl;
    std::cout << "does int member active: " << (std::holds_alternative<int>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does char member active: " << (std::holds_alternative<char>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does double member active: " << (std::holds_alternative<double>(_testVariant) ? "true" : "false") << std::endl;
    _testVariant = 500.0;
    std::cout << "value of variant : " << std::get<double>(_testVariant) << std::endl;
    std::cout << "index of variant : " << _testVariant.index() << std::endl;
    std::cout << "does int member active: " << (std::holds_alternative<int>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does char member active: " << (std::holds_alternative<char>(_testVariant) ? "true" : "false") << std::endl;
    std::cout << "does double member active: " << (std::holds_alternative<double>(_testVariant) ? "true" : "false") << std::endl;*/

    /*try
    {
        auto _val = std::get<char>(_testVariant);
        std::cout << "value of variant : " << _val << std::endl;
    }
    catch (std::bad_variant_access&)
    {
        std::cout << "our variant doesn't hold this type at this moment...\n";
    }*/
#endif
    // visit of variant
#if 0
    std::variant<int, char, double> _testVariant;
    _testVariant = 101;
    //_testVariant = 'a';
    //_testVariant = 200.0;
    //std::visit(SPrintVisitor{}, _testVariant);
#endif

    system("pause");
}
