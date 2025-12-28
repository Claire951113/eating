#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5

void intializearray(int size,int array[size]);
void printarray(int size,int array[size]);
void randomarray(int size,int array[size]);
int sumofarrayelement(int size,int array[size]);


int main(void){

    int iSIZE;
    printf("Enter your size:");
    scanf("%d", &iSIZE);
    int array[iSIZE];

    
    intializearray(iSIZE,array);
    printarray(iSIZE,array);
    puts("======");
    randomarray(iSIZE,array);
    sumofarrayelement(iSIZE,array);
    printf("Sum of element:%d",sumofarrayelement(iSIZE,array));

}//end main
void intializearray(int size,int array[size]){
    int i;
    for(int i=0;i<size;i++){
        array[i]=array[i];
    }
}//end void
void printarray(int size,int array[size]){
    int j;
    for(j=0;j<size;j++){
        printf("%d",array[j]);
    }
    printf("\n");
}//end void
void randomarray(int size,int array[size]){
    int c;
    srand(time(NULL));
    for(c=0;c<size;c++){
        array[c]=rand()%10;
        printf("%d ",array[c]);
    }
    printf("\n");
    
}//end void

int sumofarrayelement(int size,int array[size]){
    int z;
    int sum=0;
    for(z=0;z<size;z++){
        sum=sum+array[z];
    }
    return sum;
}