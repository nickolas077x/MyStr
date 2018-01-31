#include <iostream>


int myStrLen(char *string_) {
    char endOfStr = '\0';
    int sumb = 0;
    while (*string_ != endOfStr) {
        sumb++;
        string_++;
    }
    return sumb;
}

void Test1() {
    char instring[100];
    char endOfStr = '\0';
    std::cout << "test1 sring consist of 99 symb \n";
    memset(instring, ' ', sizeof(instring));
    instring[99] = endOfStr;

    std::cout << myStrLen(instring) << std::endl;

}

void Test2() {
    std::cout << "test2 sring consist of 16 symb \n";

    char str[] = "hello hi bonguar";
    std::cout << myStrLen(str) << std::endl;

}

void Test3() {
    std::cout << "test3 empty sring \n";
    char str1[] = "";
    std::cout << myStrLen(str1) << std::endl;

}




int main() {
    Test1();
    Test2();
    Test3();
    getchar();


    return 0;
}

