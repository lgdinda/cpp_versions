#include <iostream>
#include <map>
#include <string>
#include <cassert>


#include "cpp14.h"

using namespace std;

// for Tempalete Variables

//value of PI for generic type
template<typename T>
constexpr T PI = T(3.141592653589793238462643383);

template<typename T>
constexpr T maxValue = T(1000);

template<>
constexpr double maxValue<double> = 2000;

template<>
constexpr char maxValue<char> = 'Z';

void TemplateVariables()
{
    cout << "\n -> Template Variables\n";
    cout << "\nPI<int>     : " << PI<int> << endl;
    cout << "PI<double>  : " << PI<double> << endl;
    cout << "PI<float>   : " << PI<float> << endl;
    cout << "\nMaxValue<int>     : " << maxValue<int> << endl;
    cout << "MaxValue<double>  : " << maxValue<double> << endl;
    cout << "MaxValue<char>    : " << maxValue<char> << endl;
}

void SmallImprovements()
{
    cout << "\n -> Small Improvements\n";
    cout << "       - digital separators '\n";

    long x = 1'000'000;
    long y = 10'00'00'0;
    if(x==y) cout << "1'000'000 == 10'00'00'0" <<endl;

    cout << "       - binary literals 0b \n";

    auto d = 0x47; // binary 01000111
    auto b = 0b01000111;
    if(b==d) cout << "0x47 == 0b01000111" <<endl;

    cout << "       - binary literals with digital separators \n";

    auto a = 0B0100'0111;
    if(a==b) cout << "0b01000111 == 0B0100'0111" <<endl;
}

auto ProveAutomaticReturnTypeDeduction()
{
    cout << "\n -> Automatic Return Type Deduction\n";
    /*double a = 123;
    double b = 456;
    auto result = a*b;*/

    std::map< std::string, std::string > result;
    result.insert(make_pair("key","value"));
    return result;
}

int Fibonacci(int n)
{
    switch(n)
    {
        case 0: return 0;
        case 1: return 1;
        default:
            return Fibonacci(n-2)+Fibonacci(n-1);
    }
}
constexpr int FibonacciCompileTime(int n)
{
    switch(n)
    {
        case 0: return 0;
        case 1: return 1;
        default:
            return FibonacciCompileTime(n-2)+FibonacciCompileTime(n-1);
    }
}

void RelaxedConstexprFunctions()
{
    cout << "\n -> constexpr functions (executed at compile time) relaxed\n";
    cout << "       - C++14 relaxed highly constrined C++11 constexpr requirements: \n";
    cout << "           - local variables possible \n";
    cout << "           - control flow statements possible (if/else, switch, while, for, ...) \n";

    int n=10;
    cout << "\nFibonacci(" <<10<<")="<<FibonacciCompileTime(n)<<endl;

    static_assert(FibonacciCompileTime(10)==55,"Unexpected Fibonacci number."); // n cannot be used at compile time
    assert(Fibonacci(n)==55); // n can be used at run time
    //static_assert(FibonacciCompileTime(10)==5,"Unexpected Fibonacci number."); // error at compile time
    //assert(Fibonacci(n)==5); // error at run time

}


int main()
{
    std::cout << "\n\t*** C++14 ***\n\n";
    SmallImprovements();
    auto CoolMap = ProveAutomaticReturnTypeDeduction();
    RelaxedConstexprFunctions();
    TemplateVariables();

    return 0;
}
