
#include "main.h"

int display(struct hashtable *database) {
    printf("index\tword\t\tfilecount\tfilename\twordcount\n");

    for (int i = 0; i < 28; i++) {
        struct mainnode *main_ptr = database[i].head;

        if (main_ptr == NULL) {
            continue; // Skip if no main nodes exist for this index
        }

        while (main_ptr != NULL) 
        {
        
            printf("%-8d%-16s%-16d", i, main_ptr->word, main_ptr->count);

            struct subnode *sub_ptr = main_ptr->sublink;

            int first_subnode = 1; 
            while (sub_ptr != NULL) 
            {
                if (!first_subnode) 
                {
                    
                    printf("%-8s%-16s%-16s", "", "", "");
                }
                printf("%-16s%-16d\n", sub_ptr->filename, sub_ptr->wordcount);
                sub_ptr = sub_ptr->sublink;
                first_subnode = 0;
            }

            main_ptr = main_ptr->mainlink; 
        }
    }
    return SUCCESS;
}
