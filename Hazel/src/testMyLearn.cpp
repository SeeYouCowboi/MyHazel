#include <stdio.h>
#define LOG_ERROR(fm, ...) printf(fm,__VA_ARGS__)
using namespace std;

int main() {
    int x=1;
    int y=2;
    LOG_ERROR("233333","66666");
}