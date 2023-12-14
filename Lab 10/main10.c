#include "global10.h"

int main(int argc, char *argv[])
{
        int i = 1;
        int j, k;
	int key = atoi(argv[3]);
        char f[20];
        char l[20];
        int a, na;
        if(argc != 4)
        {
                printf("MISSING FILE NAME!\n");
                return 1;
        }

        pthread_t thr;
        pthread_mutex_init (&mutex, NULL);
        pthread_create(&thr, NULL, autosave,(void *) argv[2]);

        pthread_mutex_lock (&mutex);
        readFile(argv[1], key);
        pthread_mutex_unlock (&mutex);


        while(i)
        {
                int comm = 0;
                printf("Enter a command #0-7: \n");
                scanf("%d", &comm);
                switch(comm)
                {
                        case 0:
                                pthread_mutex_lock (&mutex);
                                pthread_cancel(thr);
                                pthread_mutex_unlock (&mutex);
                                saveFile(argv[1], key);
                                for(j = 0; j < 3; j++)
                                {
                                        clear(arr[j].head);
                                }
                                i = 0;
                                break;
                        case 1:
                                printf("Please enter first name, last name, and age: \n");
                                scanf("%s%s%d", f, l, &a);
                                if(checkDuplicates(f,l) == -1)
                                {
                                        printf("Repeated name\n");
                                        break;
                                }
                                pthread_mutex_lock (&mutex);
                                insert(f,l,a);
                                pthread_mutex_unlock (&mutex);
                                break;
			case 2:
                                show();
                                break;
                        case 3:
                                showAge();
                                break;
                        case 4:
                                printf("Enter first name and last name of person to be removed: \n");
                                scanf("%s%s", f, l);
                                pthread_mutex_lock (&mutex);
                                removeName(f,l);
                                pthread_mutex_unlock (&mutex);
                                break;
                        case 5:
                                pthread_mutex_lock (&mutex);
                                readBinary(argv[2]);
                                pthread_mutex_unlock (&mutex);
                                break;
                        case 6:
                                showTail();
                                break;
                        case 7:
                                for(k = 2; k >= 0; k--)
                                {
                                        showRec(arr[k].head);
                                }
                                break;
                        default:
                                printf("Invalid command\n");
                }
        }
}

