#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE 0
struct filename 
{
    char valid_file[60];       
    struct filename *link;
    struct filename *head;     
};
struct hashtable 
{
    int key;                   
    struct mainnode *head;     
};
struct mainnode 
{
    int count;                 
    char word[30];             
    struct subnode *sublink;   
    struct mainnode *mainlink;
};
struct subnode {
    int wordcount;           
    char filename[20];         
    struct subnode *sublink;   
};
//read and validate files
int read_and_validate(int argc,char *argv[],struct filename **head);
//Create data base
int find_index(char ch);
//find index of particualr word
int create_data_base(struct filename *head,struct hashtable *database);
//Display data base
int display(struct hashtable *database); 
//Search data base
//void update_database(struct filename **head);
int IsFileValid(char *filename);
int IsFileDuplicate(char *filename, struct filename **head);
int store_filenames_to_list(char *filename, struct filename **head);
int delete_list(struct filename *head);
//int update_database(struct filename **head);
//int update_database(struct filename **head, const char *filename);
int update_database(struct filename **head, const char *filename, struct hashtable *database);
//update
void search(struct hashtable *database, const char *word);
//Save data base
void save_data(struct hashtable *database); 
#endif