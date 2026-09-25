#include<stdio.h>
int main(){
    int balance,choice,amount;
    int total=0;
    printf("Balance:");
    scanf("%d",&balance);

    while(1){
        printf("Enter code (1=deposit, 2=withdraw, 0=quit):");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter amount:");
            scanf("%d",&amount);
            balance+=amount;
            printf("Deposit successful. Balance:%d\n",balance);
            total++;
        }else if(choice==2){
            printf("Enter amount:");
            scanf("%d",&amount);
            if(amount>balance){
                printf("Insufficient funds! Balance:%d\n",balance);
            }else{
                balance-=amount;
                printf("Withdrawal successful. Balance:%d\n",balance);
                total++;
            }
        }else if(choice==0){
            printf("Final balance:%d\n",balance);
            break;
        }else{
            printf("Invalid code!\n");
        }
    }//end while

    printf("Successful transactions:%d\n",total);
}//end main