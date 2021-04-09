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
    printf("%s%s \n", announce, out);

    // // output the code units (not code points)
    // length=s.length();
    // for(i=0; i<length; ++i) {
    //     printf(" %04x", s.charAt(i));
    // }
    // printf(" }\n");
};

int main(){
	static const UChar input[]={
        0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0
    };

    

	icu::UnicodeString s(input), t;
    const icu::Locale &system = icu::Locale::getDefault();
	const icu::Locale &chinese = icu::Locale::getChinese();
	icu::Locale hi("hi","IN");

	printUnicodeString("input string: ",s);
    /* lowercase/English */
    printUnicodeString("full-lowercased/en: ", (t=s).toLower(chinese));
    /* lowercase/Turkish */
    printUnicodeString("full-lowercased/tr: ", (t=s).toLower(hi));
    /* uppercase/English */
    printUnicodeString("full-uppercased/en: ", (t=s).toUpper(chinese));
    /* uppercase/Turkish */
    printUnicodeString("full-uppercased/tr: ", (t=s).toUpper(hi));
    /* titlecase/English */
    printUnicodeString("full-titlecased/en: ", (t=s).toTitle(NULL, chinese));
    /* titlecase/Turkish */
    printUnicodeString("full-titlecased/tr: ", (t=s).toTitle(NULL, hi));
    /* case-folde/default */
    printUnicodeString("full-case-folded/default: ", (t=s).foldCase(U_FOLD_CASE_DEFAULT));
    /* case-folde/Turkic */
    printUnicodeString("full-case-folded/Turkic: ", (t=s).foldCase(U_FOLD_CASE_EXCLUDE_SPECIAL_I));
	return 0;
}
