#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void seperate_even_odd(int size,int array[size],int even[],int odd[]);

int main(void){
    int option;
    int size;
    int odd[20];
    int even[20];
    do{
        printf("====Menu====\n");
        printf("1) Option 1 - Split into even and odd number array\n");
        printf("2) Option 2 - Calculate Sum of Element in the Upper Triangle\n");
        printf("(-1) End program\n\n");  
        printf("Please select an option:");
        scanf("%d",&option);

        switch(option){
            case 1:{
            printf("Enter array size (1-20):");
            scanf("%d",&size);
            int array[size];
            puts("Original array:");
            seperate_even_odd(size,array,even,odd);
            break;
        }//end case
            case -1:
            printf("Program terminated.\n");
            break;

            default:
            printf("Invaild option.Try again.");
            break;

        }//end switch
    }while(option!=-1);//end while
}//end main
void seperate_even_odd(int size,int array[size],int even[],int odd[]){
    int c,k;
    int i=0;
    int j=0;
    srand(time(NULL));
    for(c=0;c<size;c++){
        array[c]=rand()%10;
        printf("%d ",array[c]);
    if(array[c]%2==0){
        even[i]=array[c];
        i=i+1;
    }//end if
    else{
        odd[j]=array[c];
        j=j+1;
    }//end else
}
  printf("\n\n");
  puts("Total even number:%d",i);
}//end void