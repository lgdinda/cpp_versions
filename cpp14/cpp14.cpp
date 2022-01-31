#include <iostream>
#include <map>
#include <string>


#include "cpp14.h"

using namespace std;
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

int main()
{
    std::cout << "\n\t*** C++14 ***\n\n";
    SmallImprovements();
    auto CoolMap = ProveAutomaticReturnTypeDeduction();

    return 0;
}
