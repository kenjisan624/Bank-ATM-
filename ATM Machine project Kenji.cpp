#include <stdio.h>
#include <string.h> 
#include <stdlib.h>   
#include <stdbool.h> 

void prinReceipt(char ans, double* balance) {
	if(ans == 'Y' || ans == 'y')
{
printf("**********************************************\n");
printf("**	Valencia College's bank   	    **\n");
printf("**	                                    **\n");
printf("**	Recepit for customer: 		    **\n");
printf("**	                                    **\n");
printf("** 	Remaining balance is %.02lf         **\n",*balance);
printf("**	Thank you for your service          **\n");
printf("**********************************************\n");
}
}

void mainScreen(double* balance, char ans) {
	int customerSelection = 0;
	int pressOption;
	double amount = 0; 
	while (true) {
			printf("1 -> Fast Cash      ");
			printf("Withdraw <-2\n");
			printf("3 -> Deposit        ");
			printf("Check Balance <- 4\n");
			printf("5 -> Get Card Back\n");
			printf(" \n");
			printf("Enter your choice: ");
			scanf("%d",&customerSelection);
			system("CLS");
		
		switch (customerSelection)	{
			
			case 1: 
			printf("Select Fast Cash option to withdraw: \n");
			printf("1--> $20.00          ");
			printf("$40.00 <- 2\n");
			printf("3--> $80.00          ");
			printf("$100.00 <- 4\n");
			
			printf("Type your option: \n");
			scanf("%d", &pressOption);
			
			if(pressOption == 1 ||pressOption == 2 || pressOption == 3 || pressOption == 4 ){
				double transactionAmount = 0;
								
				if(pressOption == 1) transactionAmount = 20.0;
				else if (pressOption == 2) transactionAmount = 40.0;
				else if (pressOption == 3) transactionAmount = 80.0;
				else if (pressOption == 4) transactionAmount = 100.0;
			
				if (*balance >= transactionAmount){
					*balance -= transactionAmount; 
					system("CLS");
				printf("Your current Balance is: %.2lf\n",*balance);
			}
			else{
				printf("Sorry, not enought balance\n");
			}
		}
			else {
			printf("Not valid entry\n");
			}
		
			break;
			
			case 2: 
						
			printf("Enter amount (enter 0 to cancel): ");
				scanf("%lf",&amount);
				if(amount > *balance ) {
				printf("Sorry not enough balance\n"); 
				}
				else {
				*balance -= amount;
				printf("Take your cash...\n");
				printf("Your current balance is: %.2lf\n", *balance);
				}
				break;
			
			case 3:
				printf("Enter amount (enter 0 to cancel)\n");
				scanf("%lf",&amount);
				*balance += amount;
				printf("Your current balance is: %.2lf\n",*balance);
			break;
			
			case 4:
				printf("Your balance is: $%.2lf\n", *balance);
				break;
				
			case 5:
				printf("THANK YOU FOR USING OUR VIRTUAL VALENCIA'S BANK SYSTEM\n");
				printf("GOODBYE...\n");
				prinReceipt(ans, balance);
				exit(100);
				
			default:
			printf("Invalid Entry\n");
			break;	
			
	}
	}
}


int main (void)
{
char enteredPin[10]; // Store entered PIN 
int i = 0;
int n = 1 + i;
// for printing in the screen options 
double* balance;
double balanceVal = 124.32;
balance = &balanceVal;
char receiptPrint;

printf("Welome to Valencia College's Bank!\n");

// PIN enter section: 
while ((strlen(enteredPin) != 4) &&  (i < 3 )){
		printf("Attempt# %d\n", n);
		printf("Enter your PIN number: \n");
		scanf("%s", enteredPin);
		i++;
		n++;
	if (strlen(enteredPin) != 4 && i < 3) {
		printf("Invalid PIN, Re-enter PIN: \n");
		}
	else{
		i = 3;
		}
	}
	
	if(strlen(enteredPin) == 4){
		system("CLS");
		printf("Obtaining your bank information...\n");
	}
	else {
		system("CLS");
	printf("Sorry you can't continue, contact your bank for assistnace! '\n");
	return 0;
	}
	
printf("Would you like to have a receipt? type Y or N\n");
scanf(" %c", &receiptPrint);
	mainScreen(balance, receiptPrint);
return 0;
}

