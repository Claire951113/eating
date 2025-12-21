#include<stdio.h>
int main(){
    int midtermexam;
    int project;
    int finalexam;
    float finalgrade;
while(1){
    printf("Please enter your midterm exam:");
    scanf("%d",&midtermexam);
    if(midtermexam==-1)
        break;
    printf("Please enter your project:");
    scanf("%d",&project);
    printf("Please enter your final exam:");
    scanf("%d",&finalexam);

    finalgrade=0.3*midtermexam+0.3*project+0.4*finalexam;
    printf("%.1f  ",finalgrade);
     if(finalgrade>=90){
        printf("A\n");
    }//end if
    else if(finalgrade>=80||finalgrade<=89){
        printf("B\n");
    }//end else if
    else{
        printf("F\n");
    }//end else
}
}//end main