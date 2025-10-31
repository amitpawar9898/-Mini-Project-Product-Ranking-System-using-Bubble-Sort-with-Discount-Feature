// Amit Pawar
// AIML - A1
//  Mini Project: Product Ranking System using Bubble Sort with Discount Feature
#include <stdio.h>
#include <string.h>
// Structure Definition
// Stores all details of a product
struct Product {
    char name[50];   
    float price;     
    float rating;   
    int sales;       
};

// Function to swap two products
void swap(struct Product *a, struct Product *b) {
    struct Product temp = *a;
    *a = *b;
    *b = temp;
}

// using Bubble Sort Function
void bubbleSort(struct Product arr[], int n, int choice) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int swapFlag = 0;  // check if swapping is needed
                // Rating (High to Low)
            if (choice == 1 && arr[j].rating < arr[j + 1].rating)
                swapFlag = 1;  // Sort by rating (descending)

                // Price (Low to High)
            else if (choice == 2 && arr[j].price > arr[j + 1].price)
                swapFlag = 1;  // Sort by price (ascending)

                //  Sales (High to Low)
            else if (choice == 3 && arr[j].sales < arr[j + 1].sales)
                swapFlag = 1;  // Sort by sales (descending)

            if (swapFlag)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
// Function to Display All Products
void displayProducts(struct Product arr[], int n) {
    printf("\n%-15s %-10s %-10s %-10s\n", "Product", "Price", "Rating", "Sales");
    printf("--------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-15s %-10.2f %-10.1f %-10d\n",
               arr[i].name, arr[i].price, arr[i].rating, arr[i].sales);
    }
}

// Function to Apply Discount
// Reduces the price of all products by a given percentage
void applyDiscount(struct Product arr[], int n) {
    float discount;
    printf("\nEnter discount percentage (e.g., 10 for 10%%): ");
    scanf("%f", &discount);

    for (int i = 0; i < n; i++) {
        arr[i].price = arr[i].price - (arr[i].price * discount / 100);
    }

    printf("\n✅ Discount of %.2f%% applied successfully!\n", discount);
    printf("\nUpdated product prices:\n");
    displayProducts(arr, n);
}

// Main Function
int main() {
    int n, choice;

    // number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    struct Product products[n];

    //  Input details of each product
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of product %d\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Rating (1-5): ");
        scanf("%f", &products[i].rating);
        printf("Sales (number of purchases): ");
        scanf("%d", &products[i].sales);
    }

    // Step 3: Menu-driven operations
    while (1) {
        printf("\n=============================");
        printf("\n     PRODUCT MENU");
        printf("\n=============================");
        printf("\n1. Sort Products");
        printf("\n2. Show Product List");
        printf("\n3. Apply Discount");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int sortChoice;
            printf("\nSort products by:\n");
            printf("1. Rating (High to Low)\n");
            printf("2. Price (Low to High)\n");
            printf("3. Sales (High to Low)\n");
            printf("Enter your choice: ");
            scanf("%d", &sortChoice);
            bubbleSort(products, n, sortChoice);
            printf("\n--- Sorted Product List ---\n");
            displayProducts(products, n);
        }
        else if (choice == 2) {
            displayProducts(products, n);
        }
        else if (choice == 3) {
            applyDiscount(products, n);
        }
        else if (choice == 4) {
            printf("\nThank you for using the Product Ranking System! \n");
            break;
        }
        else {
            printf("\n Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
