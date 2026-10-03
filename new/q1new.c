#include<stdio.h>
int main(){
    int score;
    double average;
    int total=0;
    int sum=0;
    printf("Enter score, -1 to end:");
    scanf("%d",&score);
    while(score!=-1){  
        if(score>100){
            puts("Invalid score! Must be between 0 and 100\n");
        }else if(score<0){
            printf("Invalid score! Must be between 0 and 100\n");
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
        }
        printf("Enter score -1 to end:");
        scanf("%d",&score);
    }
    if(total==0){
        printf("No scores were entered");
        return 0;
    }
    average=(double)sum/total;
    printf("Scores entered:%d\n",total);
    printf("Class average:%.2f",average);
}//end main
