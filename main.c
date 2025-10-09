#include <stdio.h>
#include <stdbool.h>

#define lowA 2
#define lowB 3
#define lowC 2
#define adminPassword 1122

void buyItem(char item);
void displayItems(void);
void adminMode(void);

float priceA = 1.5;
float priceB = 5.0;
float priceC = 4.5;

int QtyA = 10;
int QtyB = 15;
int QtyC = 10;


int main() {
    while (1)
    {
        int choice;
        printf("\n==============================\n");
        printf("Welcome to the Vending Machine\n");
        printf("1-> Buy A Product \n 2-> Admin Mode \n 3-> Exit\n");
        printf("Enter your Desired Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bool flag = false;
            while (!flag)
            {
                displayItems();
            }
            

            
        case 2:
            printf("\n==============================\n");
            printf("=== Admin Mode ===\n");
            printf("Enter Admin Password: ");
            int pass;
            scanf("%d", pass);
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

void buyItem(char item){


}

void displayItems(void)
{
    printf("\n+----+----------+----------+----------+\n");
    printf("| No | Products |  Price   | Quantity |\n");
    printf("|  1 | CocaCola | %8.1d | %8.1d |\n", priceA, QtyA);
    printf("|  2 | WaterCan | %8.1d | %8.1d |\n", priceB, QtyB);
    printf("|  3 | Pringles | %8.1d | %8.1d |\n", priceC, QtyC);
    printf("\n+----+----------+----------+----------+\n");
}