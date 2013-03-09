/*1.输出9*9口诀。共9行9列，i控制行，j控制列。*/

#include <stdio.h>

int main(void) {
    int i = 0, j = 0, k =0;
    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            k = i * j;
            printf("%-3d", k);
        }
        printf("\n");
    }
    return 0;
}