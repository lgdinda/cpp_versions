#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "\n\t*   Checking C++ versions   *\n\n";

    std::atexit([](){std::cout << "Good bye!";});
    return 0;
}
