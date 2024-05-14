#ifndef bank_H
#define bank_H
#include <time.h>

typedef struct customer
{
    char name[50];
    double cash ;
    char type[7] ;
    int id ;
    char type_custom [20];
     time_t last_modified;
}customer_t ;


void create_new_customer(void) ;
void  edit_customer(int id ) ;
void print_customer_data(int id) ;
void transfer_money(int source_id ,int destination_id,double money);
void delete_customer_data(int id );
#endif

