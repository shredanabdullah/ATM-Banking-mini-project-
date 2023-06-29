#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>

int main()
{   //changing console color
    system("color 3F");
    /*variables declaration and definitions*/
    int pin =1234;//the default pin of the user
    int pinInput; //to store the value of the pin entered.
    int option;//options provided to the user
    int count=0;// to count or keep track of how many times the user entered an invalid pin
    int amount=1;//amount of money entered by the user
    int balance=5000;// the money the user has in the bank
    int continueTransaction=1;//to keep track whether user want to go to the next transaction or not

    time_t now;
    time(&now);
    printf("%184s\n", ctime(&now));
    printf("\t\t\t---------------- WELCOME TO BANKO ATM ----------------");

     while (pin != pinInput) {
        printf("\nPlease enter your pin number: ");
        scanf("%d", &pinInput);
        if (pinInput != pin) {
            Beep(630, 450);
            printf("Invalid pin!");
            count++;
            if(count==3){
                printf("\nYou exceed the number of pin trials!");
                exit(0);
             }
        }
    }
    printf("\nPin accepted. Access granted.\n");

while(continueTransaction!=0){
    printf("\n\t\t\t---------------- Available Transactions ----------------");
    printf("\n\t1-Check Balance");
    printf("\n\t2-Withdrawl");
    printf("\n\t3-Deposit");
    printf("\nPlease select one: ");

    scanf("%d",&option);
      if(option==1){
         printf("\nYour current balance is: %d",balance);

          printf("\nIf you want to go to main menu press 1, If you want to exit press 0: ");
          scanf("%d",&continueTransaction);
      }
      else if(option==2){
            printf("\nEnter the amount: ");
            scanf("%d",&amount);
            while(amount%100!=0){
                printf("\nThe amount should be multiple of 100");
                printf("\nEnter the amount again: ");
                scanf("%d",&amount);
                if(amount%100==0){
                      break;
                }
            }
             if(balance<amount){
             printf("\nInsufficient balance.");

             printf("\nIf you want to go to main menu press 1, If you want to exit press 0: ");
             scanf("%d",&continueTransaction);
              }
              else{
                balance=balance-amount;
                printf("\nYou have Withdrawn %d",amount);
                printf("\nYour new balance is: %d",balance);

                printf("\nIf you want to go to main menu press 1, If you want to exit press 0: ");
                scanf("%d",&continueTransaction);
            }}
      else if(option==3){
             printf("\nEnter the amount: ");
             scanf("%d",&amount);
             balance=balance+amount;
             printf("\nYou have deposited %d",amount);
             printf("\nYour new balance is: %d",balance);
             amount=1;

             printf("\nIf you want to go to main menu press 1, If you want to exit press 0: ");
             scanf("%d",&continueTransaction);
      }
      else{
        Beep(630, 450);
        printf("Your selection should be one of 1, 2 or 3 only");
        printf("\nIf you want to go to main menu press 1, If you want to exit press 0: ");
        scanf("%d",&continueTransaction);
      }
 }
    return 0;
}
