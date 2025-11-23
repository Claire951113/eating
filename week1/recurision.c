#include<stdio.h>
int digital(int n);
int main (void){
    int n=5;
    digital(n);
    return 0;
}
int digital(int n){
    if(n==1){
        printf("%d",n);
        return 1;
    }//end if
    else{
        printf("%d",n);
       return (digital(n-1));
    }//end else
    
}//end digital