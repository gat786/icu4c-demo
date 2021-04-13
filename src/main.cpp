#include <inttypes.h>

#include <iostream>
#include "unicode/utypes.h"
#include "unicode/uchar.h"
#include "unicode/locid.h"
#include "unicode/ustring.h"
#include "unicode/ucnv.h"
#include "unicode/unistr.h"
#include "unicode/resbund.h"

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

static UChar *quotedString(const UChar *string) {
    int len = u_strlen(string);
    int alen = len;
    const UChar *sp;
    UChar *newstr, *np;

    for (sp = string; *sp; ++sp) {
        switch (*sp) {
            case '\n':
            case 0x0022:
                ++alen;
                break;
        }
    }

    newstr = (UChar *) malloc((1 + alen) * sizeof(*newstr));
    for (sp = string, np = newstr; *sp; ++sp) {
        switch (*sp) {
            case '\n':
                *np++ = 0x005C;
                *np++ = 0x006E;
                break;

            case 0x0022:
                *np++ = 0x005C;
                
            default:
                *np++ = *sp;
                break;
        }
    }
    *np = 0;

    return newstr;
};

int main(){
    UErrorCode status = U_ZERO_ERROR;
	UResourceBundle *english = ures_open("./src/res","hi",&status);
    if(U_SUCCESS(status)){
        std::cout << "Found the resource" << std::endl;


        int len = 11;
        const UChar *key = ures_getString(english, &len, &status);
        // std::string str(key);
        std::cout << quotedString(key) << std::endl;

        // std::cout << english << std::endl;

        // char *result;
        
        // ures_getUTF8StringByKey(english, "hello", result, &len, true, &status);
        // if(U_SUCCESS(status)){
        //     std::cout << "Hello world" << std::endl;
        // }
        // else{
        //     std::cout << "Couldn't find the string" << std::endl;
        // }
    }
    else{
        std::cout << "Error Finding Bundle" << std::endl;
    }
	return 0;
}
