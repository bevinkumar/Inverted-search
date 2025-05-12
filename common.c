#include "main.h"
int read_and_validate(int argc,char *argv[],struct filename **head)
{
    int i;
    if(argc<2)
    {
        printf("ERROR :you need to include files\n");
        return FAILURE;
    }
struct filename *current=NULL;
for(i=1;i<argc;i++)
{
        if((strstr(argv[i],".txt"))==NULL)
        {
            printf("'%s'filename is not valid\n",argv[i]);
            continue;
        }

    
    FILE *fptr = fopen(argv[i],"r");
    {
        if(fptr==NULL)
        {
            printf("'%s'File is does not exist\n",argv[i]);
            continue;
        }
    }
    fseek(fptr,0,SEEK_END);
    int position=ftell(fptr);
    if(position==0)
    {
      printf("ERROR: File '%s' contains nothing.\n", argv[i]);
      continue;
    }
    struct filename *new=malloc(sizeof(struct filename));
    if(new==NULL)
    {
        printf("Memory allocation failed!\n");
    }
  //  struct filename *head=NULL,*current=NULL;
    strcpy(new->valid_file,argv[i]);
    new->link=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        current->link=new;
    }
    current=new;
    fclose(fptr);
}
struct filename *temp=*head;
while(temp!=NULL)
{
    printf("'%s'file is included\n",temp->valid_file);
    temp=temp->link;
}
return SUCCESS;
}
int find_index(char ch)
{
    if(isalpha(ch))
    {
        return tolower(ch)-'a';
    }
    else if(isdigit(ch))
    {
        return 26;
    }
    else
    {
        return 27;
    }
}
