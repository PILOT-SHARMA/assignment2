#include <stdio.h>

#define MAX_ACCOUNTS 3

typedef struct {
    int account_number;
    float balance;
} Account;

void deposit(Account *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited $%.2f to Account %d.\n", amount, account->account_number);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(Account *account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew $%.2f from Account %d.\n", amount, account->account_number);
    } else {
        printf("Invalid withdrawal amount or insufficient funds.\n");
    }
}

void check_balance(Account *account) {
    printf("Account %d balance: $%.2f\n", account->account_number, account->balance);
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    
    // Initialize accounts
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i].account_number = i + 1;
        accounts[i].balance = 0.0;
    }

    int choice, account_number;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Select account (1-3): ");
        scanf("%d", &account_number);
        
        if (account_number < 1 || account_number > MAX_ACCOUNTS) {
            printf("Invalid account number. Please select between 1 and 3.\n");
            continue;
        }

        switch (choice) {
            case 1:
                deposit(&accounts[account_number - 1]);
                break;
            case 2:
                withdraw(&accounts[account_number - 1]);
                break;
            case 3:
                check_balance(&accounts[account_number - 1]);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
