#include<stdio.h>
int main(){
    int step=0;
    int odd,even,integer,max;
    printf("Enter a positive integer:");
    scanf("%d",&integer);
    if(integer<0){
        printf("Input must be positive.");
    }

    while(integer>1){
        if(integer%2==0){
            integer=integer/2;
            printf("%d\t",integer);
            step++;
        }
        if(integer==1){
            break;
        }
        if(integer%2!=0){
            integer=3*integer+1;
            printf("%d\t",integer);
            step++;
            max=integer;
        }
    }//end while
    printf("\n");
    printf("Steps:%d\n",step);
    printf("Maximum value:%d",max);
}//end main
