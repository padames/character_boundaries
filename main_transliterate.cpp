#include <unicode/uconfig.h>
#include <unicode/platform.h>
#include <unicode/unistr.h>
#include <unicode/translit.h>
#include <unicode/bytestream.h>
#include <unicode/errorcode.h>
#include <iostream>
#include <unicode/ustream.h>
int main(int argc,char **argv)
{
    auto err = UErrorCode();

    icu::Transliterator* myTrans = 
                  icu::Transliterator::createInstance("zh-Latin",UTRANS_FORWARD, err);
    icu::UnicodeString str = icu::UnicodeString::fromUTF8("直接输出html代码而不是作为函数返回值代后处理");
    myTrans->transliterate(str);
    std::string st;
    str.toUTF8String(st);
    std::cout << st << std::endl;
    std::cout << str << std::endl;

    return 0;

}
// #include <unicode/unistr.h>
// #include <unicode/ustream.h>

// #include <iostream>

// int main()
// {
//     icu::UnicodeString s("привет");

//     std::cout << s << std::endl;

//     return 0;
// }
