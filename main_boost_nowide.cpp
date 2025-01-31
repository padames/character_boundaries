#include <boost/nowide/args.hpp>
#include <boost/nowide/fstream.hpp>
#include <boost/nowide/iostream.hpp>
#include <vector>

int main(int argc,char **argv)
{
    std::vector<std::string> fruit;
    fruit.push_back("🍇");
    fruit.push_back("🍈");
    fruit.push_back("🍉");
    fruit.push_back("🍊");
    fruit.push_back("🍋");

    std::string test_string = fruit[0];

    std::string long_fruity_string = "Hello" + test_string + ", " + fruit[1];

    boost::nowide::cout << long_fruity_string << std::endl;

    for ( const char& letter: long_fruity_string){
        boost::nowide::cout << letter << std::endl;
    }
    return 0;
}