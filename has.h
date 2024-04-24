#ifndef HAS_H
#define HAS_H

struct items {
    char item[20];
    float price;
    int qty;
};

struct order {
    char name[50];
    char date[50];
    int noofitems;
    struct items *itm;
};

void generateInvoice(struct order *customer);
void showAllInvoices(struct order *customers, int numCustomers);
void searchInvoice(struct order *customers, int numCustomers);
void freeMemory(struct order *customers, int numCustomers);

#endif /* HAS_H */
