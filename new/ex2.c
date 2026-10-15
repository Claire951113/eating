#include<stdio.h>
int sum(int number);

int main(){
    int number;
    scanf("%d",&number);
    printf("%d",sum(number));
}//end main
int sum(int number){
    int tem1,tem2;
    if(number<10){
        return number;
    }else{
        tem1=number%10;
        tem2=number/10;
        return (tem1+sum(tem2));
    }
}