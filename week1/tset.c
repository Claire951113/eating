#include<stdio.h>
int reverse(int);

int main(){
    int N=509;
    printf("Reverse number R:");
    reverse(N);
}//end main

int reverse(int N){
    if(N<10){
        printf("%d",N);
        return N;
    }
    else{
        printf("%d",(N%10));
        return reverse((N-N%10)/10);
    }//end else

}