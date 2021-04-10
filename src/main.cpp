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

int main(){
    UErrorCode status = U_ZERO_ERROR;
	UResourceBundle *hindi = ures_open(NULL,"es",&status);
    if(U_SUCCESS(status)){
        std::cout << "Found the resource" << std::endl;

        char hello;
        int hello_length = 12;
        ures_getUTF8String(hindi,&hello, &hello_length,false, &status);
        std::cout << hello << std::endl;
        // int len = 100;
        // const UChar *result = ures_getStringByKey(english,"hello",&len,&status);
        // if(U_SUCCESS(status)){
        //     std::cout << result << std::endl;
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
