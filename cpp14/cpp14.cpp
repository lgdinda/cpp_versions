#include <iostream>
#include <algorithm>  // for_each
#include <map>
#include <thread>

#include "cpp11.h"

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



int main()
{
    std::cout << "\n\t*** C++14 ***\n\n";
    SmallImprovements();


    return 0;
}
