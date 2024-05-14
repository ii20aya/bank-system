#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bank database.h"  // Assuming this header defines customer_t

extern int counter;
extern customer_t arr[5];

void create_new_customer(void) {
    customer_t new_customer;
    printf("Enter name of customer %i:", counter + 1);
    fflush(stdin);
    fgets(new_customer.name, sizeof(new_customer.name), stdin); // Use fgets to prevent buffer overflow
    new_customer.name[strcspn(new_customer.name, "\n")] = '\0'; // Remove trailing newline

label:
    printf("Enter cash of customer %i:", counter + 1);
    scanf("%lf", &(new_customer.cash));
    if (new_customer.cash < 0) {
        printf("Money should be positive\n");
        goto label;
    }

    printf("Enter type of the customer %i (debit or credit):", counter + 1);
    fflush(stdin);
    fgets(new_customer.type, sizeof(new_customer.type), stdin);
    new_customer.type[strcspn(new_customer.type, "\n")] = '\0'; // Remove trailing newline

    printf("Enter ID of customer %i:", counter + 1);
    scanf("%i", &(new_customer.id));

    // Assuming type_custom is an enum for account type (individual, institute)
    printf("Enter account type of customer %i (individual or institute):", counter + 1);
    scanf("%i", &(new_customer.type_custom));

    printf("\n\n");
    arr[counter] = new_customer; // Add new structure to arr
    counter++;
}

void edit_customer(int id) {
    int i;
    for (i = 0; i <= counter; i++) {
        if (id == arr[i].id) {
            printf("Enter the new cash: ");
            scanf("%lf", &(arr[i].cash));


            break;
        }
    }

    if (i > counter) { // Handle case where ID is not found
        printf("Customer with ID %d not found.\n", id);
    }
}

void print_customer_data(int id) {
    int i;
    for (i = 0; i <= counter; i++) {
        if (id == arr[i].id) {
            printf("Name of customer number %i is: %s\n", i + 1, arr[i].name);
            printf("Cash of customer number %i is: %0.2lf\n", i + 1, arr[i].cash);
            printf("Type of customer number %i is: %s\n", i + 1, arr[i].type);
            printf("ID of customer number %i is: %i\n", i + 1, arr[i].id);
            printf("Account type of customer %i is: %s\n", i + 1 ,arr[i].type_custom );  // Assuming INDIVIDUAL and INSTITUTE are defined enums



                   time_t last_modified = arr[i].last_modified;
      struct tm *local_time = localtime(&last_modified);
      printf("Last modified on: %d-%02d-%02d %02d:%02d:%02d\n",
             local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
             local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

            printf("\n\n");
            break;
        }
    }

}

     void transfer_money(int source_id ,int destination_id,double money)
     {
         int i ;
         int index_from=-1 ;
         int index_to=-1 ;
     L1:    for(i=0;i<=counter;i++)
         {
          if(arr[i].id==source_id)
          {
              index_from=i ;
          }
          else if (arr[i].id==destination_id)
          {
              index_to=i ;
          }
          if((index_from!=-1)&&(index_to!=-1))
          {
             break;
          }

        }
         if((index_from==-1)||(index_to==-1))
         {
             printf("please enter valid id\n");


         }
         if(money>arr[index_from].cash)
        {
            printf("the money transfered is greater than your cash \n");
            printf("please enter the money transfered again and take care :");
            scanf("%lf",&money);
            goto L1;
        }

         arr[index_from].cash=arr[index_from].cash-money;
         arr[index_to].cash=arr[index_to].cash+money;
         }

void delete_customer_data(int id )
{
    int i ;
    int index ;
    for(i=0;i<=counter-1;i++)
        {
        if(arr[i].id==id)
        {
            index=i ;
    for(i=index;i<=counter-1;i++)
        {
        arr[i]=arr[i+1];

        }
        }
        }
        arr[counter].cash=-1; // -1 indicate this is empty place for new customer
        arr[counter].id=-1 ;  // -1 indicate this is empty place for new customer
        strcpy(arr[counter].name,"-1"); // -1 indicate this is empty place for new customer
        strcpy(arr[counter].type,"-1"); // -1 indicate this is empty place for new customer
        counter--;
}


