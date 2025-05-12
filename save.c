#include "main.h"
#include "main.h"

void save_data(struct hashtable *database)
 {
    
    FILE *backup_file = fopen("database_backup.txt", "w");
    if (backup_file == NULL)
     {
        printf("ERROR: Could not create or open backup file 'database_backup.txt'\n");
        return;
    }
  
    for (int i = 0; i < 28; i++) {
        struct mainnode *main_ptr = database[i].head;

        
        while (main_ptr != NULL) {
            struct subnode *sub_ptr = main_ptr->sublink;

            while (sub_ptr != NULL) {
                
                fprintf(backup_file, "%d;%s;%d;%s;%d\n", 
                        i,                         
                        main_ptr->word,           
                        main_ptr->count,           
                        sub_ptr->filename,         
                        sub_ptr->wordcount);       

                sub_ptr = sub_ptr->sublink; 
            }

            main_ptr = main_ptr->mainlink;  
        }
    }

    fclose(backup_file);
    printf("Database backup created successfully in 'database_backup.txt'\n");
}
