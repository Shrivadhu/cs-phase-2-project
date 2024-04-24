#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storee.h"

int main() {
    int opt;
    int numCustomers = 0;
    struct order *customers = NULL;

    printf("\t\tWELCOME\n");
    printf("==============PESU STORE==============\n\n");
    
    while (1) {
        printf("1 Generate Invoice\n");
        printf("2 Show All Invoices\n");
        printf("3 Search Invoice\n");
        printf("4 Exit\n\n");
        printf("Please Select Your Option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                numCustomers++;
                customers = (struct order *)realloc(customers, numCustomers * sizeof(struct order));
                generateInvoice(&customers[numCustomers - 1]);
                break;
            case 2:
                showAllInvoices(customers, numCustomers);
                break;
            case 3:
                searchInvoice(customers, numCustomers);
                break;
            case 4:
                freeMemory(customers, numCustomers);
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
