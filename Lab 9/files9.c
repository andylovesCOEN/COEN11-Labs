#include "globe9.h"

void *autosave(void *arg)
{
        while(1)
        {
                pthread_mutex_lock (&mutex);
                int i;
                char *file = (char *) arg;
                FILE *fp;
                fp = fopen(file, "wb");
                if(fp == NULL)
                {
                        printf("Cannot open file for autosave\n");
                        exit(1);
                }
                for(i = 0; i < 3; i++)
                {
                        NODE *p;
                        p = arr[i].head;
                        while(p != NULL)
                        {
                                fwrite(p, sizeof(NODE), 1, fp);
                                p = p->next;
                        }
                }
                fclose(fp);
                pthread_mutex_unlock (&mutex);
                sleep (15);
        }
}

void readFile(char *file)
{
        int i;
        for(i =0; i< 3;i++)
        {
                arr[i].head = NULL;
                arr[i].tail = NULL;
        }
        char f[20];
        char l[20];
        int a;
        FILE *fp;
        fp = fopen(file, "r");
        if(fp == NULL)
        {
                return;
        }
        while(fscanf(fp, "%s%s%d", f, l, &a) == 3)
        {
                insert(f,l,a);
        }
        fclose(fp);
        return;
}

void saveFile(char *file)
{
        int i;
        FILE *fp;
        fp = fopen(file, "w");
        if(fp == NULL)
        {
                return;
        }
        for(i = 0; i < 3; i++)
        {
                NODE *p;
                p = arr[i].head;
                while(p != NULL)
                {
                        fprintf(fp, "%s %s %d\n", p->first, p->last, p->age);
                        p = p->next;
                }
        }
        fclose(fp);
        return;
}

void readBinary(char *file)
{
        FILE *fp;
        fp = fopen(file, "rb");
        if(fp == NULL)
        {
                return;
        }
        NODE *p;
        p = (NODE*)malloc(sizeof(NODE));
        while(fread(p, sizeof(NODE), 1, fp )>0)
        {
                printf("%s\t %s\t %d\n", p->first, p->last, p->age);
        }
        fclose(fp);
        return;

}
