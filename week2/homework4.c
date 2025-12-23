#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int stick=7;
    int player,computer;
    srand(time(NULL));
    printf("Your turn. Sticks remaining:%d\n",stick);
while(stick>0){

do{
    printf("How many sticks do you want to take(1-3):");
    scanf("%d",&player);
    if(player<1||player>3||stick<player){
        puts("Invaild.Please enter again.");
    }//end if
}while(player<1||player>3);

    stick-=player;
    printf("You took %d stick(s).Sticks remaining:%d\n",player,stick);
    if(stick==0){
        puts("Player took the last stick.You win");
        break;
    }//end if
    
    computer=rand()%3+1;
    if(computer>stick){
        computer=stick;
    }
    stick-=computer;
    printf("Computer took %d stick(s).Sticks remaining:%d\n",computer,stick);
    
    if(stick==0){
        puts("Computer took the last stick.You win");
        break;
    }//end if
    printf("Your turn. Sticks remaining:%d\n",stick);
}//end while
}//end main