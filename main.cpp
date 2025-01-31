#include <unicode/chariter.h>
#include <unicode/errorcode.h>
#include <unicode/brkiter.h>
#include <iostream>
#include <cassert>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::string> fruit;
    fruit.push_back("🍇");
    fruit.push_back("🍈");
    fruit.push_back("🍉");
    fruit.push_back("🍊");
    fruit.push_back("🍋");

    std::string test_string = fruit[0];

    std::string long_fruity_string = "Hello " + test_string + ", " + fruit[1] + "!";
    
    //Note: Since C++17 and ICU 76, you can use UTF-16 string literals with compile-time
    //      length determination. 
    const icu::UnicodeString str = icu::UnicodeString::fromUTF8(long_fruity_string);
    std::string st;
    str.toUTF8String(st);
    std::cout << "Sentence to parse: \"" << st << "\"" << std::endl;

    UErrorCode err = U_ZERO_ERROR;
    
    std::unique_ptr<icu::BreakIterator> iter(
        icu::BreakIterator::createCharacterInstance(icu::Locale::getDefault(), err));
    assert(U_SUCCESS(err));
    iter->setText(str);
    auto start = iter->first();
    auto end = start;
    std::string charToPrintUTF8{};
    auto ctp = icu::UnicodeString{};
    while (iter->next() != icu::BreakIterator::DONE) {
        start = end; // set start of the current grapheme before a pass throught the loop
        end = iter->current(); // update the end position of the current grapheme boundary found via iter->next 
        auto len = end - start; // in code units containing a grapheme
        charToPrintUTF8.clear(); 
        ctp = str.tempSubString(start, len); 
        ctp.toUTF8String(charToPrintUTF8);
        auto grapheme = len<2? std::string{charToPrintUTF8.front()}: charToPrintUTF8;
        std::cout << "Code units: " << len << "; grapheme: '" << grapheme << "' of " << charToPrintUTF8.length() << " bytes" << std::endl;
    }
    return 0; 
}