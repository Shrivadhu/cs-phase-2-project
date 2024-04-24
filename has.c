#include<stdlib.h>
#include<stdio.h>
#include "has.h"

void generateInvoice(struct order *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter date: ");
    scanf("%s", customer->date);
    printf("Enter number of items: ");
    scanf("%d", &customer->noofitems);

    customer->itm = (struct items *)malloc(customer->noofitems * sizeof(struct items));

    printf("Enter details for each item:\n");
    for (int i = 0; i < customer->noofitems; i++) {
        printf("Item %d name: ", i + 1);
        scanf("%s", customer->itm[i].item);
        printf("Price: ");
        scanf("%f", &customer->itm[i].price);
        printf("Quantity: ");
        scanf("%d", &customer->itm[i].qty);
    }
}

void showAllInvoices(struct order *customers, int numCustomers) {
    if (numCustomers == 0) {
        printf("No invoices available\n");
        return;
    }

    printf("All Invoices:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("Customer Name: %s\n", customers[i].name);
        printf("Date: %s\n", customers[i].date);
        printf("Items Purchased:\n");
        for (int j = 0; j < customers[i].noofitems; j++) {
            printf("%s - Price: %.2f, Quantity: %d\n", customers[i].itm[j].item, customers[i].itm[j].price, customers[i].itm[j].qty);
        }
        printf("\n");
    }
}

void searchInvoice(struct order *customers, int numCustomers) {
    char searchName[50];
    printf("Enter customer name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].name, searchName) == 0) {
            found = 1;
            printf("Customer Name: %s\n", customers[i].name);
            printf("Date: %s\n", customers[i].date);
            printf("Items Purchased:\n");
            for (int j = 0; j < customers[i].noofitems; j++) {
                printf("%s - Price: %.2f, Quantity: %d\n", customers[i].itm[j].item, customers[i].itm[j].price, customers[i].itm[j].qty);
            }
            printf("\n");
        }
    }

    if (!found) {
        printf("No invoice found for customer '%s'\n", searchName);
    }
}

void freeMemory(struct order *customers, int numCustomers) {
    for (int i = 0; i < numCustomers; i++) {
        free(customers[i].itm);
    }
    free(customers);
}

