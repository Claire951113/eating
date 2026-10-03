#include<stdio.h>
int main(){
    int rowsize,colsize;
    int row,col;
    int number=1;
    printf("Please enter your rowsize:");
    scanf("%d",&rowsize);
    printf("Please enter your colsize:");
    scanf("%d",&colsize);
    for(row=1;row<=rowsize;row++){
        for(col=1;col<=colsize;col++){
            printf("%d  ",number);
            number++;
        }//inner row
        printf("\n");
    }
}