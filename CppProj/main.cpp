#include <iostream>


int myStrLen(const char* string_) {
    char endOfStr = '\0';
    int sumb = 0;

    if (string_ == nullptr)
        return 0;

    while (*string_ != endOfStr) {
        sumb++;
        string_++;
    }
    return sumb + 1;
}


int main() {

    int res;


    if ((res = myStrLen("hello")) != 6)


        printf("Test 1 - FAIL\n");

    else

        printf("Test 1 -  OK\n");


    if ((res = myStrLen(nullptr)) != 0)

        printf("Test 2 - FAIL\n");

    else

        printf("Test 2 - OK\n");

    getchar();
}
