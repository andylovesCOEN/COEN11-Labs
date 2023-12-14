#include "global10.h"

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

void readFile(char *file, int key)
{
        int i;
        for(i =0; i< 3;i++)
        {
                arr[i].head = NULL;
                arr[i].tail = NULL;
        }
        char f[20];
        char l[20];
	char line[200];
	char *p;
        int a;
        FILE *fp;
        fp = fopen(file, "r");
        if(fp == NULL)
        {
                return;
        }
        while(fgets(line, 50, fp)!= NULL)
        {
		p = line;
		while(*p != '\n')
		{
			*p ^= key;
			p++;
		}
		sscanf(line, "%s %s %d", f, l, &a);
		insert(f,l,a);
        }
        fclose(fp);
        return;
}

void saveFile(char *file, int key)
{
        int i;
        FILE *fp;
	NODE *p;
	char line[200];
	char *q;
        fp = fopen(file, "w");
        if(fp == NULL)
        {
                return;
        }
        for(i = 0; i < 3; i++)
        {
                p = arr[i].head;
                while(p != NULL)
                {
                        sprintf(line, "%s %s %d\n", p->first, p->last, p->age);
			q = line;
			while(*q != '\0')
			{
				*q ^= key;
				q++;
			}
			fprintf(fp, "%s", line);
			fprintf(fp, "\n");
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

