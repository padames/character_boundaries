#include <iostream>
#include <locale>
#include <sstream>

int main() {
    std::istringstream iss;
    iss.imbue(std::locale("en_US.UTF8"));

    // std::u8string test_fruit = "🍇";

    // std::cout << test_fruit ;


    return 0;
}
