/*2、打印出各种变量类型所占字节数。*/
#include <stdio.h>

int main(void) {
    short short_size;
    int int_size;
    long long_size;
    float float_size;
    double double_size;

    printf("\n");
    printf("Short size is:%4d\n", sizeof(short_size));
    printf("Int size is:%6d\n", sizeof(int_size));
    printf("Long size is:%5d\n", sizeof(long_size));
    printf("float size is:%4d\n", sizeof(float_size));
    printf("double size is:%3d\n", sizeof(double_size));
    return 0;
}