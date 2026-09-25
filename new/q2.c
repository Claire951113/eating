#include<stdio.h>
int main(){
    int number,digital;
    int total=0;
    int sum=0;
    printf("Enter a positive integer:");
    scanf("%d",&number);
    if(number>0){
       while(number>0){
        digital=number%10;
        sum=sum+digital;
        number=number/10;
        total++;
       }//end while
    }else{
        printf("The number must be positive.");
    }
    printf("Number of digits:%d\n",total);
    printf("Sum of digits:%d\n",sum);
    sum%2==0?printf("The digit sum is even"):printf("The digit sum is odd");
}//end main