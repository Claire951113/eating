#include<stdio.h>
int main(){
float workedhour;
float wage;
float salary;
while(1){
puts("Please enter your worked hours:");
scanf("%f",&workedhour);
if(workedhour==0){
    break;
}//end if
puts("Please enter your hourly wage:");
scanf("%f",&wage);
if(workedhour<0||wage<0){
    printf("Invaild.\n");
    continue;
}//end if
salary=workedhour*wage;
printf("Your salary is: %.1f\n",salary);

}//end while
}//end main