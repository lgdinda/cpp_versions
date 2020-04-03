#include <iostream>
#include <algorithm>  // for_each
#include "cpp11.h"

void LambdaExpressions()
{
    std::cout << "\n -> Lambda Expressions\n";
    // define functions locally, at the place of the call
    // [capture](parameters)->return-type {body}

    char sentence[] = "How many Upper Case characters do I contain?";
    int Uppercase = 0;
    std::for_each(sentence, sentence+(sizeof(sentence)),[&Uppercase](char c)
                                                        {
                                                         if(std::isupper(c))
                                                         {
                                                             Uppercase++;
                                                         }
                                                        });

    std::cout<< Uppercase<<" uppercase letters in: "<< sentence << std::endl;
}

void AutomaticTypeDeduction()
{
    std::cout << "\n -> Automatic Type Deduction\n";
    // declare object without specifying type

    auto zero = 0;      // int
    auto c = 'c';       // char
    auto point = 2.5;   // double
    auto debt = 1440000000000LL;    // long long

    static const int tmp[] = {0, 1, 2};
    std::vector<int> zeros (tmp,tmp + sizeof(tmp) / sizeof(tmp[0]) );
    FunctionWithAuto(zeros);
}

void FunctionWithAuto(const std::vector<int> &arVector)
{
    std::cout << "    - Function With Auto\n";

    std::vector<int>::const_iterator it=arVector.begin();
    auto it_end = arVector.end();
    for(it;it!=it_end;it++)
    {
        std::cout << "\t" << *it;
    }

    std::cout << "   this many times I needed to declare iterator type\n";

    //capturing the type of an object or an expression
    std::cout << "    - decltype\n";
    typedef decltype(arVector.begin()) CIT;
    CIT it_prev = --it;
    std::cout << "   What was the last one? " << *it_prev << std::endl;
}

int main()
{
    std::cout << "\n\t*** C++11 ***\n\n";
    LambdaExpressions();
    AutomaticTypeDeduction();

    return 0;
}
