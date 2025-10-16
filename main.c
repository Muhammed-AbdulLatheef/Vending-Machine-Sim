#include <stdio.h>
#include <stdlib.h>

//Constants
#define lowA 2
#define lowB 3
#define lowC 2
#define adminPassword 1122

// Prototypes 
void buyItem(int item);
void displayItems(void);
int adminMode(void);
int payItem(int item);
void replenishStock(void);
void changePrice(void);
void saleAmount(void);

// price and amount variables
float totalAmount = 2;
float priceA = 1.5;
float priceB = 5.0;
float priceC = 4.5;

// Quantity Variables
int QtyA = 10;
int QtyB = 15;
int QtyC = 10;

// Main Function
int main() {
    
    while (1)
    {
        int choice;
        printf("\n==============================\n");
        printf("Welcome to the Vending Machine\n");
        printf(" 1-> Buy A Product \n 2-> Admin Mode \n 3-> Exit\n");
        printf("Enter your Desired Choice: ");
        scanf("%d", &choice);
        // Menu Switch
        switch (choice)
        {
        // Purchase a product
        case 1: 
            
                displayItems(); //display function called
                printf("Enter the Number of the Product you want to buy: ");
                int item; 
                scanf("%d", &item);
                buyItem(item); // buy function called
                break;
        
        // Admin Mode   
        case 2:
            printf("\n==============================\n");
            printf("=== Admin Mode ===\n");
            printf("Enter Admin Password: ");
            int pass;
            scanf("%d", &pass);
            if (pass == adminPassword)
            {
                int loop = 1;
                while (loop != 0)
                {
                    loop = adminMode();
                }
                
            } 
            else
            {
                printf("\nIncorrect Password");
                continue;
            }
        // Exit
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

// Buy Function
void buyItem(int item){
     printf("\n------------------------------\n");
     printf("Buying Item...\n");
    switch (item)
    {
        case 1:
            printf("Confirm to Buy CocaCola for %f : ", priceA);
            break;
        case 2:
            printf("Confirm to Buy Water Can for %f : ", priceB);
            break;
        case 3: 
            printf("Confirm to Buy Pringles for %f : ", priceC);
            break;
        default:
            printf("Invalid Choice");  
            break;
    }
    char choice;
    scanf(" %c",&choice);
    if (choice == 'y')
    {
        int payConfirm = payItem(item); //Calling payment function
        if (payConfirm == 1){
            printf("\n==============================\n");
            printf("Payment Successful\n");
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
        else
        {
            printf("\nPayment Unsuccessefull");
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

    if (QtyA == lowA || QtyB == lowB || QtyC == lowC)
    {
        printf("\nItem in low quantity");
    }
    
}
// Payment function
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
    // Inserting coins
    while (coin < itemAmount)
    {
        printf("\nEnter Coins(1.0, 0.50, 0.25 or -1 to Cancel Payment) : \n");
        scanf("%f", &coin);
        if(coin != 1.000000 && coin != 0.250000 && coin != 0.500000){
        	printf("Enter Correct Amount(1/0.5/0.25)");
        	printf("%f", coin);
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
                printf("\n%f to be paid...",change);
            } 
            else if (change == 0)
            {
                printf("\nPayment Completed...");
                totalAmount += payAmount; //Adding to sale amount
                return 1;
            }
            else{
                printf("\nPayment Completed... \nChange to be given: %f", change);
                totalAmount += payAmount;
                return 1;
            }  
        }
        
    }
    return 0;
    
}

// Admin mode menu
int adminMode(void){
    int choice;
    printf("\n------------------------------\n");
    printf("***ADMIN MODE***\n");
    printf("Welcome to the Vending Machine\n");
    printf(" 1-> Replenish Products \n 2-> Change Product Prices \n 3-> Display the total sale amount\n 4-> Display the number of items of each product in the machine\n 0-> Exit Admin Mode");
    printf("\nEnter your Desired Choice: ");
    scanf("%d", &choice);
    // menu function calls
    switch (choice)
    {
        case 1:
            replenishStock();
            break;
        case 2:
            changePrice();
            break;
        case 3: 
            saleAmount();
            break;
        case 4:
            displayItems();
            break;
        case 0:
            return 0;
        default:
            printf("\nInvalid Choice");  
    }
return 1;
}

//replenish stock
void replenishStock(void){
    QtyA = rand() %10;
    QtyB = rand() %10;
    QtyC = rand() %10;
    printf("Items replenished Successfully");
}
// function to change the price of a product
void changePrice(void){
    int product;
    float newqty;
    printf("|  1 | CocaCola |\n");
    printf("|  2 | WaterCan |\n");
    printf("|  3 | Pringles |\n");
    printf("Choose the product you want to change the price of : ");
    scanf(" %d", &product);
    printf("\nChoose the price you want to update to:");
    scanf(" %f", &newqty);
    switch (product)
    {
        case 1:
            printf("%f",newqty);
            priceA = newqty;
            break;
        case 2:
            priceB = newqty;
            break;
        case 3: 
            priceC = newqty;
            break;
        default:
            printf("Invalid Item");  
    }
}
// Total Sale amount
void saleAmount(void){
    int c;
    printf("\nThe total Sale Amount is: %d", totalAmount);
    printf("\nDo you want to reset the Sale amount?:");
    scanf(" %c",&c);
    if(c == 'y'){
        totalAmount = 0;
    }
}
