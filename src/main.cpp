#include <iostream>
#include <unicode/resbund.h>
using namespace icu;
using icu::Locale;

int main(){
    UErrorCode status = U_ZERO_ERROR;
    auto loc = icu::Locale::getDefault();
    
	ResourceBundle res(UnicodeString("./res"),loc,status);
    if(U_FAILURE(status)){
        std::cerr << "Loading failed" << std::endl;
        return -1;
    }

    std::string utf8;
    std::cout << res.getStringEx("hello", status).toUTF8String(utf8) << std::endl;
    utf8 = "";
    std::cout << res.getStringEx("help", status).toUTF8String(utf8) << std::endl;
    utf8 = "";
    std::cout << res.getStringEx("support", status).toUTF8String(utf8) << std::endl;
    utf8 = "";
	std::cout << res.getStringEx("end", status).toUTF8String(utf8) << std::endl;

    return 0;
}
