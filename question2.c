#include <stdio.h>
#include <string.h>

//Since we were only asked to keep records rather than have a transaction I only made the function of the program to keep records.

struct account_history
{
    char date[11];
    char type[15];
    float amount;
};

struct Banking
{
    char account_type[20];
    float balance;
    char creation_date[20];
    float interest_rate;
    struct account_history history[50];
    int transaction_count;
};

void lasttransaction(int transaction_count, struct account_history history[]);


int main()
{

    int choice;
    struct Banking account;

    int minbalance;

    printf("What Type of Account do you want to manage? \n");
    printf("1. Savings Account \n");
    printf("2. Current Account \n");
    printf("3. Deposit Account \n");
    scanf(" %d", &choice);

    if (choice == 1)
    {
        strcpy(account.account_type, "Savings");
        account.interest_rate = 0.04;
        minbalance = 1000;
    }

    else if (choice == 2)
    {
        strcpy(account.account_type, "Current");
        account.interest_rate = 0;
        minbalance = 5000;
    }

    else if (choice == 3)
    {
        strcpy(account.account_type, "Deposit");
        account.interest_rate = 0.07;
        minbalance = 10000;
    }

    else
    {
        printf("Invalid Input");
        return 0;
    }

    printf("when was the account created? DD/MM/YYYY format \n");
    scanf(" %[^\n]", account.creation_date);

    printf("State the balance in the account \n");
    scanf("%f", &account.balance);

    if (account.balance < minbalance)
    {
        printf("You do not reach the minimum account Balance Sorry \n");
        return 0;
    }
    account.transaction_count = 0;

    for (int i = 0; i < 50; i++)
    {
        account.history[i].amount = 0;
        printf("state the date of transaction (DD/MM/YYYY) \n");
        scanf(" %[^\n]", account.history[i].date);

        printf("state the type of transaction (Deposit/Withdrawal) \n");
        scanf(" %[^\n]", account.history[i].type);

        printf("state the amount of transaction \n");
        scanf(" %f", &account.history[i].amount);
        account.transaction_count++;

        printf("Do you want to add another transaction? (1 for Yes / 0 for No) \n");
        int choice;
        scanf(" %d", &choice);
        if (choice == 0)
        {
            break;
        }
    }

    printf("Account Type: %s\n", account.account_type);
    printf("Account Balance: %.2f\n", account.balance);
    printf("Transaction History:\n");
    for (int i = 0; i < account.transaction_count; i++)
    {
        printf("|Date: %s, \t| Type: %s, \t| Amount: %.2f| \n", account.history[i].date, account.history[i].type, account.history[i].amount);
    }
    lasttransaction(account.transaction_count, account.history);
}

void lasttransaction(int transaction_count, struct account_history history[])
{
    if (transaction_count > 0)
    {
        int i = transaction_count - 1;

        printf("Last Transaction - Date: %s, Type: %s, Amount: %.2f\n",
               history[i].date,
               history[i].type,
               history[i].amount);
    }
    else
    {
        printf("No transactions available.\n");
    }
}