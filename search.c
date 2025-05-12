
#include "main.h"

void search(struct hashtable *database, const char *word) 
{
    if (word == NULL || database == NULL) 
    {
        printf("ERROR: Invalid input for search function.\n");
        return;
    }

    
    int index = find_index(word[0]);
    if (index < 0 || index >= 28)
     {
        printf("ERROR: Word '%s' is not valid for the database.\n", word);
        return;
    }

    struct mainnode *main_ptr = database[index].head;


    while (main_ptr != NULL) {
        if (strcmp(main_ptr->word, word) == 0) 
        {
            
            printf("Word '%s' found in the database with count %d.\n", main_ptr->word, main_ptr->count);

            struct subnode *sub_ptr = main_ptr->sublink;
            while (sub_ptr != NULL) 
            {
                printf(" - Found in file '%s' with count %d\n", sub_ptr->filename, sub_ptr->wordcount);
                sub_ptr = sub_ptr->sublink;
            }
            return; 
        }
        main_ptr = main_ptr->mainlink;
    }

    printf("Word '%s' not found in the database.\n", word);
}
