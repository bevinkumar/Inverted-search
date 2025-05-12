#include "main.h"

// Function to check if a file is valid
int IsFileValid(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (!strstr(filename, ".txt"))
    {
        printf("ERROR!! File name should have extension .txt\n");
        return FAILURE;
    }
    else
    {
        fseek(fptr, 0L, SEEK_END);
        int pos = ftell(fptr);
        if (pos == 0)
        {
            printf("ERROR!! The file %s is empty.\nINFO: This file cannot be added into the database.\n", filename);
            fclose(fptr);
            return FAILURE;
        }
        else
        {
            fclose(fptr); // Close the opened file
            return SUCCESS;
        }
    }
}

// Function to update the database
int update_database(struct filename **head, const char *filename, struct hashtable *database)
{
    int ret;

    if (IsFileValid((char *)filename) == SUCCESS) // If the file name is valid, proceed to check if it is repeated
    {
        if (IsFileDuplicate((char *)filename, head) == FAILURE) // If the file name is not present, proceed to add it
        {
            ret = store_filenames_to_list((char *)filename, head);
            if (ret == SUCCESS) // If the filename is added successfully, proceed
            {
                printf("INFO: The file %s is added to the list successfully.\n", filename);

                // Create a database for the new file (for example, initializing the data)
              //  ret = create_database_for_file(filename);
                ret = create_data_base(*head, database);
                if (ret == SUCCESS)
                {
                    printf("INFO: Database creation for the file %s was successful.\n", filename);
                    return SUCCESS;
                }
                else
                {
                    printf("ERROR: Database creation for the file %s failed.\n", filename);
                    return FAILURE;
                }
            }
        }
    }

    // If any condition fails, the file cannot be updated in the database
    return FAILURE;
}


// Function to check if a file is a duplicate in the list
int IsFileDuplicate(char* filename, struct filename **head)
{
    struct filename* temp = *head;

    while (temp != NULL) // Traverse through the file list and compare each filename
    {
        if (strcmp(filename, temp->valid_file) == 0) // If filename is already present
        {
            printf("ERROR: The file %s is already present in the database.\nINFO: This file cannot be added.\n", filename);
            return SUCCESS;
        }

        temp = temp->link;
    }

    return FAILURE;
}

// Function to store filenames into the list
int store_filenames_to_list(char* filename, struct filename **head)
{
    struct filename* new = (struct filename*) malloc(sizeof(struct filename));
    if (new == NULL) // Memory allocation error
    {
        return FAILURE;
    }

    strcpy(new->valid_file, filename); // Copy the filename to the new node
    new->link = *head; // Point the new node's link to the current head of the list
    new->head = NULL;  // Initialize the head field (you might use this field for other purposes)
    *head = new; // Set the head of the list to the new node

    return SUCCESS;
}

// Function to delete the entire list
int delete_list(struct filename *head)
{
    if (head == NULL)
    {
        return FAILURE; // If the list is empty, nothing to delete
    }

    struct filename *temp;
    while (head != NULL)
    {
        temp = head;
        head = temp->link; // Move the head pointer to the next node
        free(temp); // Free the current node
    }

    return SUCCESS;
}
