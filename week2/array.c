#include<stdio.h>
#define arrsize 5
int main(){
    int sum=0;
    int integer;
    int array[arrsize];
    for(integer=0;integer<arrsize;integer++){
        printf("Enter integer %d",integer+1);
        scanf("%d",&array[integer]);
    }//end for
    size_t i;
    for(i=0;i<arrsize;i++){
        sum=sum+array[i];
        printf("Array[%zu]=%d\n",i,array[i]);
    }
    printf("Sum of digital =%d",sum);
}//end main