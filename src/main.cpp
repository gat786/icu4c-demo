#include <inttypes.h>

#include <iostream>
#include "unicode/utypes.h"
#include "unicode/uchar.h"
#include "unicode/locid.h"
#include "unicode/ustring.h"
#include "unicode/ucnv.h"
#include "unicode/unistr.h"


static void
printUnicodeString(const char *announce, const icu::UnicodeString &s) {
    static char out[200];
    int32_t i, length;

    // output the string, converted to the platform encoding

    // Note for Windows: The "platform encoding" defaults to the "ANSI codepage",
    // which is different from the "OEM codepage" in the console window.
    // However, if you pipe the output into a file and look at it with Notepad
    // or similar, then "ANSI" characters will show correctly.
    // Production code should be aware of what encoding is required,
    // and use a UConverter or at least a charset name explicitly.
    out[s.extract(0, 99, out)]=0;
    printf("%s%s {", announce, out);

    // output the code units (not code points)
    length=s.length();
    for(i=0; i<length; ++i) {
        printf(" %04x", s.charAt(i));
    }
    printf(" }\n");
};

int main(){
	static const UChar input[]={
        0x61, 0x42, 0x3a3,
        0x69, 0x49, 0x131, 0x130, 0x20,
        0xdf, 0x20, 0xfb03,
        0x3c2, 0x3c3, 0x3a3, 0
    };

	icu::UnicodeString s(input), t;
	const icu::Locale &en = icu::Locale::getEnglish();
	icu::Locale tr("tr");

	printUnicodeString("input string: ",s);
	return 0;
}
