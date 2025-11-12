#include<stdio.h>
int main(void){
    int option;
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
            for(i=1;i<=9;i++){
                for(j=1;j<=9;j++){
                printf("%d* %d =%d ",i,j,i*j);
            }
            printf("\n");
            }
        }//end if
       else if(option==-1){
            puts("Program terminated.");
        }//end else if
        else {
            puts("Invaild Option.Try again.");
        }//end else
    }while(option!=-1);
    }//end main
   