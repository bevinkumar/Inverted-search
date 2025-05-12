/*
name:Bevin kumar
Title : Inverted Search

Brief:	The purpose of storing an index is to optimize speed and performance in finding relevant documents for a search query. Without an index, the search engine would scan every document in the corpus, which would require considerable time and computing power.
Pre-requisite:	
Hashing
Single linked list
Level	Complex*/

#include "main.h"
int main(int argc, char *argv[])
{
struct filename *head = NULL;
struct hashtable *database = malloc(sizeof(struct hashtable) * 28);
if (database == NULL)
{
        printf("ERROR: Memory allocation for database failed.\n");
}
if(read_and_validate(argc,argv,&head)==FAILURE)
{
   printf("Validation failed!");
   return 0;
}
    int operation,flag=0;
    do {
        // Display menu
        printf("\nSelect an operation:\n");
        printf("1: Create database\n");
        printf("2: Display database\n");
        printf("3: Update database\n");
        printf("4: Search word in the database\n");
        printf("5: Exit\n");
        printf("Enter the operation number (1-5): ");
        scanf("%d", &operation);

        switch (operation) {
            case 1: // Create database
                printf("Creating database...\n");
               if( create_data_base(head, database)==SUCCESS)
               {
                printf("Database created and saved successfully.\n");
                flag=1;
               }
                break;

            case 2: // Display database
                
                printf("Displaying database...\n");
                if(display(database)==SUCCESS)
                {
                    printf("Successfully displayed.\n");
                }
                break;

            case 3:
               if(flag==1)
               {
                char filename [20];
				printf ("INPUT: Enter the File Name to be Updated in the Database: " );
				scanf ("%s", filename);	//To read the File Name to be updated in the Database.
                printf("Updating database...\n");
                if(update_database(&head, filename, database)==SUCCESS)
                {
                printf("Database updated successfully.\n");
                }
               }
               else
               {
                printf("You need to create database.\n");
               }
                break;

            case 4:
                {
                    char word[100];
                    printf("Enter the word to search: ");
                    scanf("%s", word);
                    search(database, word);
                }
                break;

            case 5: 
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("ERROR: Invalid operation. Please select a valid option (1-5).\n");
                break;
        }
    } while(operation!=5);
    free(database);
    return 0;
}
