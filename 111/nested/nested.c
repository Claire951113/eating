 #include <stdio.h>
 int main(void){
    int row=0;
    int col=0;
    int rowsize,colsize=0;
    int counter=0;

    printf("Please enter your rowsize:");
    scanf("%d",&rowsize);
    printf("Please enter your colsize:");
    scanf("%d",&colsize);

    for(row=1;row<=rowsize;row++){
        for(col=1;col<=colsize;col++){
            counter++;
            printf("%d ",counter);
        }//end inner loop
        printf("\n");
    }//end for

}//end main

