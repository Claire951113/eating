#include<stdio.h>
int f(int i);
int main(){
    for(int i=0;i<=10;i++){
        printf("%d ",f(i));
    }
}//end main
int f(int i){
    if(i==0){
        return 0;
    }if(i==1){
        return 1;
    }else{
        return (f(i-1)+f(i-2));
    }
}