// https://stackoverflow.com/q/4579215/1585486
#include <unicode/uconfig.h>
#include <unicode/platform.h>
#include <unicode/unistr.h>
#include <unicode/translit.h>
#include <unicode/bytestream.h>
#include <unicode/errorcode.h>
#include <iostream>
#include <unicode/schriter.h>
#include <unicode/brkiter.h>

#include <iostream>
#include <cassert>
#include <memory>

int main()
{
    const icu::UnicodeString str = icu::UnicodeString::fromUTF8("नमस्ते");

    {
        // StringCharacterIterator doesn't seem to recognize graphemes
        icu::StringCharacterIterator iter(str);
        int count = 0;
        while(iter.hasNext())
        {
            ++count;
            iter.next();
        }
        std::cout << count << std::endl; // Gives "6"
    }

    {
        // BreakIterator works!!
        UErrorCode err = U_ZERO_ERROR;
        std::unique_ptr<icu::BreakIterator> iter(
            icu::BreakIterator::createCharacterInstance(icu::Locale::getDefault(), err));
        assert(U_SUCCESS(err));
        iter->setText(str);

        int count = 0;
        while(iter->next() != icu::BreakIterator::DONE) ++count;
        std::cout << count << std::endl; // Gives "4"
    }

    return 0;
}

