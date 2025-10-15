#include <stdio.h>
#include <stdbool.h>


#define lowA 2
#define lowB 3
#define lowC 2
#define adminPassword 1122

void buyItem(int item);
void displayItems(void);
void adminMode(void);
int payItem(int item);

float priceA = 1.5;
float priceB = 5.0;
float priceC = 4.5;

int QtyA = 10;
int QtyB = 15;
int QtyC = 10;


int main() {
    bool flag = false;
    while (1)
    {
        int choice;
        printf("\n==============================\n");
        printf("Welcome to the Vending Machine\n");
        printf(" 1-> Buy A Product \n 2-> Admin Mode \n 3-> Exit\n");
        printf("Enter your Desired Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
                displayItems();
                printf("Enter the Number of the Product you want to buy: ");
                int item; 
                scanf("%d", &item);
                buyItem(item);
        
            
        case 2:
            printf("\n==============================\n");
            printf("=== Admin Mode ===\n");
            printf("Enter Admin Password: ");
            int pass;
            scanf("%d", &pass);
            if (pass == adminPassword)
            {
                /*adminMode();*/
            } else
            {
                printf("\nIncorrect Password");
                continue;
            }
        
        case 3:
            printf("\nExiting program....");
            printf("\n==============================\n");
            break;

        default:
            printf("Invalid Choice");
            printf("\n==============================\n");
        }
    }  
    
return 0;
}

void buyItem(int item){
     printf("\n------------------------------\n");
     printf("Buying Item...");
    switch (item)
    {
        case 1:
            printf("Confirm to Buy CocaCola for %d", priceA);
            break;
        case 2:
            printf("Confirm to Buy Water Can for %d", priceB);
            break;
        case 3: 
            printf("Confirm to Buy Pringles for %d", priceC);
            break;
        default:
            printf("Invalid Choice");  
    }
    char choice;
    scanf("%d",&choice);
    if (choice == 'y')
    {
        int payConfirm = payItem(item);
        if (payConfirm == 1){
            printf("\n==============================\n");
            printf("Payment Successful");
            switch (item)
            {
                case 1:
                    QtyA -= 1;
                    break;
                case 2:
                    QtyB -= 1;
                    break;
                case 3: 
                    QtyC -= 1;
                    break;
                default:
                    printf("Error");  
            }
            printf("Thank you for your purchase");

            
        }
    }
    

}

void displayItems(void)
{
    printf("\n+----+----------+----------+----------+\n");
    printf("| No | Products |  Price   | Quantity |\n");
    printf("|  1 | CocaCola | %8.1f | %8.1d |\n", priceA, QtyA);
    printf("|  2 | WaterCan | %8.1f | %8.1d |\n", priceB, QtyB);
    printf("|  3 | Pringles | %8.1f | %8.1d |\n", priceC, QtyC);
    printf("+----+----------+----------+----------+\n");
}

int payItem(int item){
    float itemAmount;
    float coin;
    float payAmount;
    float change;
    switch (item)
            {
                case 1:
                    itemAmount = priceA;
                    break;
                case 2:
                    itemAmount = priceB;
                    break;
                case 3: 
                    itemAmount = priceC;
                    break;
                default:
                    printf("Invalid Item");  
            }
    printf("\n==============================\n");
    printf("Welcome to the Payment Portal");
    while (coin < itemAmount)
    {
        printf("Enter Coins(1.0, 0.50, 0.25 or -1 to Cancel Payment) : \n");
        scanf("%f", &coin);
        if(coin != 1 || coin != 0.25 || coin != 0.5){
        printf("Enter Correct Amount(1/0.5/0.25)");
        } 
        else if (coin == -1)
        {
            return 0;
        }
        
        else
        {
            payAmount += coin;
            change = itemAmount - payAmount;
            if (change > 0)
            {
                printf("%f to be paid...");
            } 
            else if (change == 0)
            {
                printf("Payment Completed...");
                return 1;
            }
            else{
                printf("Payment Completed... \nChange to be given: %f", change);
                return 1;
            }  
        }
        
    }
    return 0;
    
}