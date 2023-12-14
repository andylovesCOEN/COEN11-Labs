#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NODE struct node
#define LIST struct list

#define PRINT_LOCATION fprintf(stderr, "Function: %s, Line: %d\n", __func__, __LINE__);

pthread_mutex_t mutex;

void* autosave(void*);

struct node
{
        char first[20];
        char last[20];
        int age;
        NODE *next;
        NODE *prev;
};

struct list
{
        NODE *head;
        NODE *tail;
};

LIST arr[3];
