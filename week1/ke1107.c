
#include<stdio.h>
#include <stdio.h>

int main() {

    int choice;
    int rowsize, colsize;
    int row, col, layer, i, j;
    int number = 1;

    do {
        printf("=== Nested loop menu ===\n");
        printf("1 Number square\n");
        printf("2 Star triangle\n");
        printf("3 Exit\n");
        printf("Select: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Please enter your rowsize: ");
            scanf("%d", &rowsize);

            printf("Please enter your colsize: ");
            scanf("%d", &colsize);

            for(row = 1; row <= rowsize; row++) {
                for(col = 1; col <= colsize; col++) {
                    printf("%d  ", number);
                    number++;
                }

                printf("\n");
            }

            break;

        case 2:
            printf("Please enter your layer: ");
            scanf("%d", &layer);

            for(i = 1; i <= layer; i++) {
                for(j = 1; j <= i; j++) {
                    printf("* ");
                }

                printf("\n");
            }

            break;

        case 3:
            printf("Exit\n");
            break;
        }

    } while(choice != 3);

    return 0;
}