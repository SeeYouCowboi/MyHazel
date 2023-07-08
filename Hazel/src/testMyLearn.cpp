#include <stdio.h>
#include <functional>
#include <string>
#include <iostream>
#include "hzpch.h"
using namespace std;



class Test 
    {
    public:
        static constexpr const char* str = "some useful string constant";
    };

template<typename T>
void testfunc(T& t)
    {
        printf("%s", T::str);
    }

int main() {
    
}