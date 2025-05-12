#include "main.h"
#include "main.h"

int create_data_base(struct filename *head, struct hashtable *database) {
    struct filename *temp = head;
    FILE *fptr;

    // Initialize the hashtable
    for (int i = 0; i < 28; i++) {
        database[i].key = -1;
        database[i].head = NULL;
    }

    while (temp != NULL) {
        fptr = fopen(temp->valid_file, "r");
        if (fptr == NULL) {
            printf("ERROR: Could not open file '%s'\n", temp->valid_file);
            temp = temp->link;
            continue;
        }

        char word[24];
        int index;

        while (fscanf(fptr, "%s", word) == 1) {
            index = find_index(word[0]);

            if (database[index].head == NULL) {
                struct mainnode *new_main = malloc(sizeof(struct mainnode));
                if (new_main == NULL) {
                    printf("ERROR: Memory allocation for mainnode failed.\n");
                    fclose(fptr);
                    return FAILURE; // Return failure code
                }
                strcpy(new_main->word, word);
                new_main->count = 1;
                new_main->sublink = NULL;
                new_main->mainlink = NULL;
                database[index].head = new_main;

                struct subnode *new_sub = malloc(sizeof(struct subnode));
                if (new_sub == NULL) {
                    printf("ERROR: Memory allocation for subnode failed.\n");
                    fclose(fptr);
                    return FAILURE; // Return failure code
                }
                strcpy(new_sub->filename, temp->valid_file);
                new_sub->wordcount = 1;
                new_sub->sublink = NULL;
                new_main->sublink = new_sub;
            } else {
                struct mainnode *main_ptr = database[index].head;
                struct mainnode *prev_main = NULL;

                while (main_ptr != NULL && strcmp(main_ptr->word, word) != 0) {
                    prev_main = main_ptr;
                    main_ptr = main_ptr->mainlink;
                }

                if (main_ptr == NULL) {
                    struct mainnode *new_main = malloc(sizeof(struct mainnode));
                    if (new_main == NULL) {
                        printf("ERROR: Memory allocation for mainnode failed.\n");
                        fclose(fptr);
                        return FAILURE; // Return failure code
                    }
                    strcpy(new_main->word, word);
                    new_main->count = 1;
                    new_main->sublink = NULL;
                    new_main->mainlink = NULL;
                    prev_main->mainlink = new_main;

                    struct subnode *new_sub = malloc(sizeof(struct subnode));
                    if (new_sub == NULL) {
                        printf("ERROR: Memory allocation for subnode failed.\n");
                        fclose(fptr);
                        return FAILURE; // Return failure code
                    }
                    strcpy(new_sub->filename, temp->valid_file);
                    new_sub->wordcount = 1;
                    new_sub->sublink = NULL;
                    new_main->sublink = new_sub;
                } else {
                    struct subnode *sub_ptr = main_ptr->sublink;
                    while (sub_ptr != NULL && strcmp(sub_ptr->filename, temp->valid_file) != 0) {
                        sub_ptr = sub_ptr->sublink;
                    }

                    if (sub_ptr == NULL) {
                        struct subnode *new_sub = malloc(sizeof(struct subnode));
                        if (new_sub == NULL) {
                            printf("ERROR: Memory allocation for subnode failed.\n");
                            fclose(fptr);
                            return FAILURE; // Return failure code
                        }
                        strcpy(new_sub->filename, temp->valid_file);
                        new_sub->wordcount = 1;
                        new_sub->sublink = main_ptr->sublink;
                        main_ptr->sublink = new_sub;
                    } else {
                        sub_ptr->wordcount++;
                    }
                    main_ptr->count++;
                }
            }
        }

        fclose(fptr);
        temp = temp->link;
    }

    save_data(database);
    return SUCCESS; // Return success code
}
