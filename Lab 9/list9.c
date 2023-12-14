#include "globe9.h"

void insert(char *f, char *l, int a)
{
        int i;
        if(a <= 18)
        {
                i = 0;
        }
        if(a > 18 && a < 65)
        {
                i = 1;
        }
        if(a >= 65)
        {
                i = 2;
        }

        NODE *p;
        p=(NODE*)malloc(sizeof(NODE));

        if(p == NULL)
        {
                return;
        }
        strcpy(p->first, f);
        strcpy(p->last, l);
        p->age = a;
        p->next = NULL;

        if(arr[i].head == NULL)
        {
                arr[i].tail = p;
                arr[i].head = p;
                p->prev = NULL;
        }
        else
        {
                p->prev = arr[i].tail;
                arr[i].tail->next = p;
                arr[i].tail = p;

        }
}


void show()
{
        int i;
        for(i = 0; i < 3; i++)
        {
                NODE *p;
                p = arr[i].head;
                while(p!=NULL)
                {
                        printf("%s, %s, %d\n", p->first, p->last, p->age);
                        p = p->next;
                }
        }
}

void showAge()
{
        int i;
        int j = 0;
        printf("Enter a specific age: \n");
        scanf("%d", &j);
        for(i = 0; i < 3; i++)
        {
                NODE *p;
                p = arr[i].head;
                while(arr[i].head != NULL && p!=NULL)
                {
                        if(p->age == j)
                        { 
                                printf("%s, %s\n", p->first, p->last);
                        } 
                        p = p->next;
                }
        }
}

void removeName(char *f, char *l)
{
        int i;

        for(i = 0; i < 3; i++)
        {
                NODE *p, *q;
                p = arr[i].head;
                q = arr[i].head;

                while(p != NULL)
                {
                        if((strcmp(f, p->first) == 0) && (strcmp(l, p->last) == 0))
                        {
                                break;
                        }
                        q = p;
                        p = p->next;
                }
                if(p != NULL)
                {
                        if(arr[i].head->next == NULL)
                        {
                                arr[i].head = NULL;
                                free(p);
                                return;
                        }
                        if(arr[i].head == p)
                        {
                                arr[i].head = arr[i].head->next;
                                free(p);
                                return;
                        }
                        q->next = p->next;
                        free(p);
                        arr[i].tail = q;
                        return;
                }
        }
        return;
}

int checkDuplicates(char* f, char* l)
{
        NODE *p;
        int i;
        for(i = 0; i < 3; i++)
        {
                p = arr[i].head;
                while(p != NULL)
                {
                        if((strcmp(f, p->first) == 0) && (strcmp(l, p->last) == 0))
                        {
                                return -1;
                        }
                        p = p->next;
                }
        }
        return 1;
}

void clear(NODE *p)
{
        if(p == NULL)
                return;
        clear_program(p->next);
        free(p);
}

void showTail()
{
        int i;
        NODE *p;
        for(i = 2; i >= 0; i--)
        {
                p = arr[i].tail;
                while(p!=NULL)
                {
                        printf("%s %s %d\n", p->first, p->last, p->age);
                        p = p->prev;
                }
        }
}

void rec(NODE *p)
{
        if(p == NULL)
                return;
        rec(p->next);
        printf("%s %s %d\n", p->first, p->last, p->age);
        return;
}

