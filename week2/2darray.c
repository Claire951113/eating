#include<stdio.h>
int main(void){
int v[3][3];
int i,j;
int k=1;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        v[i][j]=k;
        printf("%d ",v[i][j]);
        k++;
    }
    printf("\n");

}//end for
}//end main