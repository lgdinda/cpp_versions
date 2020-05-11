#include <iostream>
#include <algorithm>  // for_each
#include <map>
#include <thread>

#include "cpp11.h"

void LambdaExpressions()
{
    std::cout << "\n -> Lambda Expressions\n";
    std::cout << "       - define functions locally, at the place of the call\n";
    std::cout << "         [capture](parameters)->return-type {body}\n\n";

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
    std::cout << "       - auto - declare object without specifying type\n\n";

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

void UniformInitializationSyntax()
{
    std::cout << "\n -> Uniform Initialization Syntax\n";
    // old:
        // 1. parenthesized
        std::string s("hello");
        int a = int();
        // 2. = notation
        std::string z = "hello";
        int b = 1;
        // 3. POD aggregates
        int arr[4] = {1, 2, 3, 4};
        struct tm today{0};
        // 4. member initializers in constructors
        struct time{
            int hour;
            time(int a):hour(a){}
        };

    // new:
    std::cout << "    - uniform brace notation\n";
        int *c = new int[4]{5, 6, 7, 8}; // !!!
        class ClassSimpleMembers{
            int a;
            int b;
        public:
            ClassSimpleMembers(int aa, int bb){}
        };
        ClassSimpleMembers csm{0,0};    //old: ClassSimpleMembers csm(0,0);

    std::cout << "    - intuitive containers init\n";
        std::vector<std::string> vect = {"first", "second", "third"}; // no push_back or temp array!
        std::map<std::string,std::string> actors = {
            {"David Harbour", "Jim Hopper"},
            {"Kevin Spacey", "Francis Underwood"}
    };

    std::cout << "    - member array initializer\n";
        class ClassComplexMembers{
            int c[4];
        public:
            ClassComplexMembers(int aa, int bb, int cc, int dd): c{aa,bb,cc,dd}{}
        };

    std::cout << "    - in-class members initialization\n";
        class InClass{
            int x = 5;   // !!!
        public:
            InClass();
        };

}

void DefaultAndDeleteFunctions()
{
    std::cout << "\n -> Default and Delete Functions\n";

    std::cout << "       - default instructs the compiler to generate the default implementation for the function\n";
    struct A{
        A() = default;
        virtual ~A() = default;
    };

    std::cout << "       - deleted functions are useful for preventing object copying, among the rest\n";
    struct NoCopy{
        NoCopy(){};
        NoCopy & operator =(const NoCopy&) = delete;  // assignment operator
        NoCopy(const NoCopy&) = delete;               // copy constructor
    };

    NoCopy a;
    //NoCopy b(a);  // compilation error, copy constructor is delete
}
void f(int){std::cout << "\t- replcaces NULL macro, and the literal 0\n";}
void f(char *){std::cout << "\t- strongly typed\n";}
void pf(){std::cout << "\tpointer to function\n";}
void NullPtrConstant()
{
    std::cout << "\n -> nullptr - null pointer constant\n";

    f(0);
    f(nullptr);

    std::string str = "\tdata pointer";
    const char *pc=str.c_str(); //data pointers
    if (pc!=nullptr)

        std::cout<<pc<<std::endl;

    class A{
    public:
        static void pmf(){std::cout << "\tpointer to member function\n";}
    };

    A::pmf();
    int (A::*pmf)()=nullptr;

    pf();
    void (*pf)()=nullptr; //pointer to function
}

void DelegatingConstructor()
{
    std::cout << "\n -> Delegating Constructor\n";

    class M{
        int x, y;
        char *p;

    public:
        M(int z):x(z),y(0),p(new char[5]){}
        M():M(0){std::cout <<"\t - constructor may call another constructor of the same class\n";}
    };

    M m;
}

void ThreadingLibrary()
{
    std::cout << "\n -> Threading Library\n";

    class do_work {
    public:
        void operator()(){};  //function call operator
    };

    do_work dw;
    std::thread t(dw);
    t.join();
    //t.detach();

    std::cout << "       - async() function - template for launching concurrent tasks\n";
    // todo ...
    std::cout << "       - thread_local - storage type for declaring thread-unique data\n";
    // todo ...

}

void NewSmartPointers()
{
    std::cout << "\n -> New Smart Pointers\n";
    std::cout << "       - shared_ptr\n";
     // todo ...
    std::cout << "       - unique_ptr\n";
    // todo ...
}

int main()
{
    std::cout << "\n\t*** C++11 ***\n\n";
    LambdaExpressions();
    AutomaticTypeDeduction();
    UniformInitializationSyntax();
    DefaultAndDeleteFunctions();
    NullPtrConstant();
    DelegatingConstructor();
    ThreadingLibrary();
    NewSmartPointers();


    return 0;
}
