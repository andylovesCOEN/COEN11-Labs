#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NODE struct node

struct node
{
    char first_name[20];
    char last_name[20];
    int age;
    NODE *next;
};

typedef struct list
{
    NODE *head;
    NODE *tail;
}LIST;

LIST array[3];
int checkDuplicates(char firstName[], char lastName[]);
int clear(NODE *p);

void insert(char tempfirstName[], char templastName[], int age)
{
    int j = 0;
    if(age > 18 && age < 65)
    {
        j = 1;
    }
    if(age >= 65)
    {
        j = 2;
    }
    if(checkDuplicates(tempfirstName, templastName) == 1)
    {
        printf("\nEntry already exists.");
        return;
    }
    NODE *p = (NODE*)malloc(sizeof(NODE));
    strcpy(p->first_name, tempfirstName);
    strcpy(p->last_name, templastName);
    p->age = age;
    p->next = NULL;
    if(array[j].head == NULL && array[j].tail == NULL)
    {
        array[j].head = p;
        array[j].tail = p;
    }
    else
    {
        array[j].tail->next = p;
        array[j].tail = p;
    }   
}

int checkDuplicates(char firstName[], char lastName[])
{
    NODE *p;
    int i;
    for(i = 0; i < 3; i++)
    {   
        p = array[i].head;
        while (p != NULL)
        {
            if(strcasecmp(firstName, p->first_name) == 0 && strcasecmp(lastName, p->last_name) == 0)
            {
                return 1;
            }
            p = p->next;
        }
    } 
    return 0;
}

void display(void)
{
    NODE *p;
    for(int i = 0; i<3; i++)
    {
        p = array[i].head;
        while(p != NULL)
        {
            printf("First Name: %s\t", p->first_name);
            printf("Last Name: %s\t", p->last_name);
            printf("Age: %d\n", p->age);
            p = p->next;
        }
    }
}

int displayAge()
{
    int tempAge;
    NODE *p;
    printf("Display entries of specific age");
    printf("\nAge:");
    scanf("%d", &tempAge);
    for(int i = 0; i < 3; i++)
    {
        p = array[i].head;
        while(p != NULL)
        {
            if(p->age == tempAge
                ){
                printf("First Name: %s\t, Last Name: %s\t, Age: %d\n",p->first_name, p->last_name, p->age);
            }
            p = p->next;
        }
    }
   return 0;
}

void save(char fileName[])
{
    FILE *outfp;
    int i;
    if((outfp = fopen(fileName, "wb")) == NULL)
    {
        printf("ERROR FILE CANNOT BE ACCESSED!\n");
        return;
    }
    int k;
    for(k = 0; k < 3; k++)
    {
        NODE *p, *q;
        p = array[k].head;
        q = array[k].head;

        while(p != NULL)
        { 
            fwrite(p, sizeof(NODE), 1, outfp);
            q = p;
            p = p->next;
        }      
        clear(q);
    }
    fclose(outfp);

}
int clear(NODE *p)
{
        if(p == NULL) return 0;
        else{
            clear(p->next);
            free(p);
        }
        return 0;
}

void read(char fileName[])
{
    FILE *ifp;
    NODE temp;
    if((ifp = fopen(fileName, "rb")) == NULL)
    {
        printf("CANNOT ACCESS FILE!\n");
        return;
    }
    char readFirst[20], readLast[20];
    int readAge;    
    while(fread(&temp, sizeof(NODE), 1, ifp) == 1)
    {
        insert(temp.first_name, temp.last_name, temp.age);
    }
    fclose(ifp);
}

void delete(char firstName[], char lastName[])
{
    NODE *p, *q;
    int found = 0;
    int i;
    for(i = 0; i< 3; i++)
    {
        p = array[i].head;
        while(p != NULL)
        {   
            if(strcmp(p->first_name, firstName) == 0 && strcmp(p->last_name, lastName) == 0)
            { 
                found = 1;
                break;
            }
            q = p;
            p = p->next;
        }
        if(found == 1)
        {
            break;
        }
    }
    if(p == NULL) return;
    else if(array[i].head == array[i].tail)
    {
        array[i].head->next = NULL;
        array[i].head = array[i].tail = NULL;
        free(p);
        return;
    }
    else if(array[i].head == p)
    {
        array[i].head = array[i].head->next;
        free(p);
        return;
    }
    else if(p != array[i].tail)
    {
        q->next = p->next;
        free(p);
        return;
    }
    else{
        q->next = NULL;
        array[i].tail = q;
        free(p);
    }
    return; 
}

void replace(char firstName[], char lastName[],  int newage)
{
    int i;
    NODE *p;
    for(i = 0; i<3; i++)
    {
        p = array[i].head;
        while(p != NULL){
            if(strcmp(p->first_name, firstName) == 0 && strcmp(p->last_name, lastName) == 0)
            {
                delete(firstName, lastName);
                insert(firstName, lastName, newage);
            }
            p = p->next;
         }
    }
}

int main(int argc, char *condition[])
{
    char firstName[20];
    char lastName[20];
    int age;
    
    printf("%s", array[0].head->first_name);
    if(argc == 1) return 1;
    int z;
    for(z = 0; z < 3; z++)
    {
        array[z].head = NULL;
        array[z].tail = NULL;
    }
    read(condition[1]);    
    int run = 1;
    int userinput;
    while(run == 1)
    {
        printf("\nAdd a new entry - 1 Display the entire list - 2 Display people with a given age - 3 Remove a person from the list - 4 Quit out - 0\n"
        );
        scanf("%d", &userinput);
        switch(userinput)
        {
            case 1:
                printf("\nPlease enter the first name: ");
                scanf("%s", firstName);                
                printf("\nPlease enter the last name: ");
                scanf("%s", lastName);               
                printf("\nPlease enter the age: ");
                scanf("%d", &age);        
                insert(firstName, lastName, age);             
                break;
            case 2:
                display();
                break;
            case 3:
                displayAge();
                break;
            case 4:
            printf("Delete entry");

            printf("\nFirst name:");
            scanf("%s", firstName);

            printf("\nLast name:");
            scanf("%s", lastName);

            delete(firstName, lastName);
            break;
            case 5:
                printf("\nPlease enter the first name: ");
                scanf("%s", firstName);
                
                printf("\nPlease enter the last name: ");
                scanf("%s", lastName);

                printf("\nPlease enter the new age: ");
                scanf("%d", &age);
                replace(firstName, lastName, age);
                break;
            case 0:
                save(condition[1]);
                run = 0;
                break;
            default:
                printf("\nERROR INVALID INPUT\n");
        }
    }
}
