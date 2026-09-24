#include<stdio.h>
int main(){
    int score;
    float average;
    int total=0;
    int sum=0;
    printf("Enter score, -1 to end:");
    scanf("%d",&score);
    if(score==-1){
        printf("No scores were entered\n");
    }
    do{
        printf("Enter score, -1 to end:");
        scanf("%d",&score);
        if(score>100||score<0){
            puts("Invalid score! Must be between 0 and 100\n");
        }else if(score>=90){
            printf("Grade:A\n");
            total=total+1;
            sum=sum+score;
        }else if(score>=80){
            printf("Grade:B\n");
            total=total+1;
            sum=sum+score;
        }else if(score>=70){
            printf("Grade:C\n");
            total=total+1;
            sum=sum+score;
        }else if(score>=60){
            printf("Grade:D\n");
            total=total+1;
            sum=sum+score;
        }else{
            printf("Grade:F\n");
            total=total+1;
            sum=sum+score;
        }//end 
    }while(score!=-1); 
    average=sum/total;
    printf("Scores entered:%d\n",total);
    printf("Class average:%.2f",average);
}//end main
