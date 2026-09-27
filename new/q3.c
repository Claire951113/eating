#include<stdio.h>
int main(){
    int H,U,D;
    int day=1;
    int height=0;
    printf("Enter well depth, climb per day, slide per night:");
    scanf("%d %d %d",&H,&U,&D);
    
    if(H<0||U<0||D<0){
        printf("All values must be positive");
        return 0;
    }

    if(U<=D){
        printf("The snail will never escape the well");
        return 0;
    }

    while(H>U){
        height+=U;
        printf("Day %d: climbs to %d m",day,height);
        if(height>H){
            printf("\n");
            printf("The snail escapes on day:%d\n",day);
            break;
        }
        day++;
        height-=D;
        printf(",  slides back to %d m\n",height);
    }//end while

}//end main