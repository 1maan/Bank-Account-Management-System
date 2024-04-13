#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define NAME_LENGTH 50

struct Account {
    int accNumber;
    char name[NAME_LENGTH];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    	scanf("%d", &newAccount.accNumber);
    printf("Enter account holder's name: ");
    	scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    	scanf("%f", &newAccount.balance);

    accounts[numAccounts++] = newAccount;
    printf("Account created successfully.\n");
}

void deposit() {
    int accNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNumber);

    int imaan;
    for (imaan = 0; imaan < numAccounts; imaan++) {
        if (accounts[imaan].accNumber == accNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[imaan].balance += amount;
            printf("Deposit successful. Current balance: %.2f\n", accounts[imaan].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNumber);

    int imaan;
    for (imaan = 0; imaan < numAccounts; imaan++) {
        if (accounts[imaan].accNumber == accNumber) {
        	printf("Current balance: %.2f\n", accounts[imaan].balance);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[imaan].balance) {
                printf("Insufficient balance.\n");
                return;
            }
            accounts[imaan].balance -= amount;
            printf("Withdrawal successful. Current balance: %.2f\n", accounts[imaan].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccountInfo() {
    int accNumber;
    printf("Enter account number: ");
    scanf("%d", &accNumber);

    int imaan;
    for (imaan = 0; imaan < numAccounts; imaan++) {
        if (accounts[imaan].accNumber == accNumber) {
            printf("Account Number: %d\n", accounts[imaan].accNumber);
            printf("Account Holder's Name: %s\n", accounts[imaan].name);
            printf("Balance: %.2f\n", accounts[imaan].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	if(choice < 1 || choice > 5){
		printf("NO option is selected.\n");
		break;
	}else{
		switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccountInfo();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
	}
        
    } while (choice != 5);

    return 0;
}
