#include <iostream>
#include <string_view>

#include <boost/locale.hpp>

using namespace std::string_view_literals;

int main()
{
    boost::locale::generator gen;
    auto string = "noël 😸😾"sv;
    boost::locale::boundary::csegment_index map{
        boost::locale::boundary::character, std::begin(string),
        std::end(string), gen("")};
    for (const auto& i : map)
    {
        std::cout << i << '\n';
    }
}