#include<stdio.h>
void multiplication(int i,int j);

int main(void){
    int option;
    int integer;
    int i=0;
    int j=0;
    do{
        puts("====Menu====");
        puts("1) Option 1-times table");
        puts("2) Option 2-reverse the number");
        puts("(-1)End program");
        
        puts("Please select an option:");
        scanf("%d",&option);

        if(option==1){
            multiplication(i,j);
        }//end if

        else if(option==2){
            do{
                puts("Enter a positive integer between 1 and 100000:");
                scanf("%d",&integer);

            if((integer<0) || (integer>100000)){
                puts("Invaild input!");
            }//end if

            }while(integer<=1&&integer>=100000);
        puts("---REVERSAL RESULT---");
        }//end else if

        else if(option==-1){
            puts("Program terminated.");
        }//end else if

        else {
            puts("Invaild Option.Try again.");
        }//end else

    }while(option!=-1);
    }//end main

void multiplication(int i,int j){
    for(i=1;i<=9;i++){
                for(j=1;j<=9;j++){
                printf("%2d* %2d = %2d ",i,j,i*j);
            }
        printf("\n");
        }
   }