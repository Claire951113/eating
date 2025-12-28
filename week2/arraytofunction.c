#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5

void intializearray(int size,int array[size]);
void printarray(int size,int array[size]);
void randomarray(int size,int array[size]);
int main(void){
    int array[SIZE]={1,1,1,1,1};
    intializearray(SIZE,array);
    printarray(SIZE,array);
    puts("======");
    randomarray(SIZE,array);

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
        printf("%d",array[c]);
    }
    
}