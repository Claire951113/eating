#include<stdio.h>
int main(void){
    int height;
    int wide;
    int thick;
    int row,col;

puts("Please enter your height:");
scanf("%d",&height);
puts("Please enter your wide:");
scanf("%d",&wide);
puts("Please enter your thick:");
scanf("%d",&thick);

if((height-2*wide<=0)||(wide-2*thick<=0)|| thick<0||wide<0||height<0){
    printf("Enter again");
    return 0;
}

    for(row=1;row<=height;row++){
        for(col=1;col<=wide;col++){
            if(row<=thick||row>height-thick||col<=thick||col>wide-thick){
                printf("*");
            }//end if
            else{
                printf(" ");
            }//end else
        }//end inner for
        printf("\n");
    }//end outer for

}//end main
