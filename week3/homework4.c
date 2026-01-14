#include<stdio.h>
int is_prime(int n);

int main(void){
    int a,b;
    int n;
    int count=0;
    printf("Please enter integer a:");
    scanf("%d",&a);
    printf("Please enter integer b:");
    scanf("%d",&b);
    if(a<=20){
        printf("a error\n");
        return 0;
    }//end if
    if(b>=10){
        printf("b error");
        return 0;
        }
    n=a;
    while(count<b){
        if(is_prime(n)){
            printf("%d                  %d\n",n,n-a);
            count++;
        }
        n++;
    }//end while
    return 0;
}//end main

int is_prime(int n){
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
