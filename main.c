#include <stdio.h>
#include <stdlib.h>
#include "bank database.h"
int counter ;
customer_t arr[5] ;

int main()
{  char choice ;
   int id_check ;
   int id_from ;
   int id_to ;
   double money_transfer ;
   while(1)
   {


    printf("Select one of the following options :\n\n1-create anew customer \n2-edit customer \n3-delete customer \n4-print customer data \n5-cash transfer from customer to another \n6-exit \n\nEnter your choice:");
    fflush(stdin);
    scanf("%c",&choice);
    printf("\n\n");
    switch(choice)
    {
    case '1' :
        if(counter>=5)
        {
            printf("Max number of customers is 5 \n");
            break ;
        }
        create_new_customer();
        break ;

    case '2' :
        printf("Enter ID of customer to change its data :");
        scanf("%i",&id_check);
        edit_customer(id_check) ;
        break ;

    case '3' :
        printf("Enter ID of customer to delete its data :");
        scanf("%i",&id_check);
        delete_customer_data(id_check);
        break;
    case '4' :
        printf("Enter ID of customer  to print its data :");
        scanf("%i",&id_check);
        print_customer_data(id_check) ;
        break;
    case '5' :
        printf("Enter ID of the customer who the money will transfer FROM his cash  :");
        scanf("%i",&id_from);
        printf("Enter ID of the customer who the money will transfer TO his cash  :");
        scanf("%i",&id_to);
     printf("please enter the money which will be transfered  :");
        scanf("%lf",&money_transfer);
        transfer_money(id_from,id_to,money_transfer);
        break;

    case '6' :
        exit(0);
    default:
        printf("wrong choice\n\n");
    }

   }

    return 0 ;
    }
