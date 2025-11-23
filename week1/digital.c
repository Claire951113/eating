#include<stdio.h>
int f(int);
int main(void){
    int i=12345;
    f(i);
    printf("Sum of digitals is:%d",f(i));
    return 0;
}//end main
int f(int i){
    if(i<10){
        return i;
    }//end if
    else{
    return ((i%10)+f((i-i%10)/10));
    }

}