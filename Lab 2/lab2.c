#include <stdio.h>
#include <string.h>

char firstName[10][20];
char lastName[10][20];
int age[10];
int count;


void insert(void)
{

            char inputfirstName[20];
            char inputlastName[20];
            int inputAge;
            int sameName = 0;
            int i;
            int j;

            printf("What's your first name?");
            scanf("%s", inputfirstName);

            printf("What's your last name?");
            scanf("%s", inputlastName);

            printf("How old are you?");
            scanf("%d", &inputAge);



            for(i=0; i<count; i++)
            {
                if((strcmp(firstName[i], inputfirstName) == 0) && (strcmp(lastName[i], inputlastName) == 0))
                {
                        sameName=1;
                        break;
                }
            }

            if(sameName == 1)
            {
                printf("There is already an entry with that name!");
            }
            else if(count >= 10)
                {
                      printf("Unable to add more data!");

                }
                 else
                 {

                        strcpy(firstName[count], inputfirstName);
                        strcpy(lastName[count], inputlastName);
                        age[count] = inputAge;
                        count++;
                 }


}

void list(void)
{
        int i;
        for(i=0; i<count; i++)
        {
            printf("first name:\t%s, last name:\t%s, age:\t%d", firstName[i], lastName[i], age[i]);
        }

}
void list(void)
{
        int i;
        for(i=0; i<count; i++)
        {
            printf("first name:\t%s, last name:\t%s, age:\t%d", firstName[i], lastName[i], age[i]);
        }

}


void returnAge(void)
{
        int userAge;
        int i;
        scanf("\n%d", &userAge);

        for(i=0; i<count; i++)
        {
            if(age[i] == userAge)
            {
                printf("first name: %s, last name: %s, age: %d", firstName[i], lastName[i], age[i]);

            }
        }
}

int main(void)
{
        int caseTest= 1;
        int input;

        while(caseTest == 1)
        {
                printf("1 to insert names, 2 to list of all entries, 3 to show entries of certain age, 0 to quit");
                scanf("%d", &input);

                switch(input)
                {
                        case 1:
                             insert();
                             break;
                        case 2:
                            list();
                            break;
                        case 3:
                           returnAge();
                            break;
                        case 0:
                            caseTest = 0;
                            break;
                }
        }

}
