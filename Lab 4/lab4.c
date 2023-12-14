#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union extrainfo{
        int years_of_retirement;
        float salary;
        char schoolname[20];
};

struct globalVariables{
        char firstnames[20];
        char lastnames[20];
        int ages;
        union extrainfo EXTRA_INFO;
};

int counter = 0;

int del_index_array[10];
int del_index_array_counter;

struct globalVariables variables[10];
struct globalVariables *p, *q;

void insert(void)
{
        p = variables;
        q = variables;

        char inputFn[20];
        char inputLn[20];
        int inputAge;
        int inputYears_of_retirement;
        float inputSalary;
        char inputSchoolname;
        int samename = 0;
        int i;
        int j;

            printf("Insert first name:");
                 scanf("%s", inputFn);
            printf("Insert last name:");
                 scanf("%s", inputLn);
            printf("Insert age:");
                 scanf("%d", &inputAge);

                for(i=0; i < counter; i++, p++)
                {
                        if((strcmp(p->firstnames, inputFn) == 0) && (strcmp(p->lastnames, inputLn) == 0))
                        {
                                samename=1;
                                break;
                        }
                }
                if(samename == 1)
                {
                        printf("\nName already in use.");
                }

            else{
                                if(inputAge <= 18){
                                        printf("School?");
                                        scanf("%s", p->EXTRA_INFO.schoolname);

                                }
                                else if(inputAge >= 65){
                                        printf("Years of retirement?");
                                        scanf("%d", &p->EXTRA_INFO.years_of_retirement);

                                }
                                else if(inputAge > 18 && inputAge < 65)
                                {
                                        printf("Annual salary?");
                                        scanf("%f", &p->EXTRA_INFO.salary);

                                }
                strcpy(p->firstnames, inputFn);
                strcpy(p->lastnames, inputLn);
                    p->ages = inputAge;
                                counter++;
                                        p++;
                }

             for(j = 0; j<counter-1; j++)
                {
                        struct globalVariables *prev = variables;
                        struct globalVariables *next = variables;
                        int k;
                        next++;
                        for(k = 0; k < counter-j-1; ++k)
                        {
                                        if(strcmp(prev->lastnames, next->lastnames)>0)
                                {
                                        struct globalVariables temp = *prev;
                                                strcpy(prev->firstnames, next->firstnames);
                                                strcpy(prev->lastnames, next->lastnames);
                                                prev->ages = next->ages;
                                                strcpy(next->firstnames, temp.firstnames);
                                                strcpy(next->lastnames, temp.lastnames);
                                                next->ages = temp.ages;
                                }
                                next++;
                                prev++;
                        }

                 }
}

void delete_record(int del_index)
{
                for(int i = del_index; i<counter; i++)
                {
                        variables[i] = variables[i+1];
                }
                counter--;
}

int find_record_index(char *last_name, char *first_name)
{
struct globalVariables *p = variables;

        for(int i=0; i<counter; i++, p++)
        {
                if(strcmp(p->lastnames, last_name) ==0 && strcmp(p->firstnames, first_name) ==0)
                {
                        return i;
                }
        }
}

        int find_record_index_age(int age)
{
        struct globalVariables *p = variables;

        int i =0;
        for(i=0; i<counter; i++, p++)
        {
                if(p->ages == age)
                {
                        return i;
                }
        }
}

        void delete_with_name()
{
        char last[20];
        char first[20];
        int del_index;
        int i;
        struct globalVariables current, next;
        printf("\nPlease enter a name to delete >> ");
        scanf("%s", first);
        printf("\nPlease enter a last name to delete >> ");
        scanf("%s", last);
        del_index = find_record_index(last,first);

        delete_record(del_index);
}

void delete_with_age()
{
        int age;
        int del_index;
        int i;

        printf("Please enter an age you want to delete >> ");
        scanf("%d", &age);

                for(i=0; i<counter; i++)
        {
                del_index = find_record_index_age(age);
                delete_record(del_index);
        }
}

void show(void)
{
    int i;
        p = variables;

        for(i=0; i< counter; i++, p++)
        {
            printf("\nFirstname:\t%s, \nlastname:\t%s, \nage:\t%d \n:salary:\t:%f, \nschoolname:\t%s, \nyearsofretirement:\t%d", p->firstnames, p->lastnames, p->ages,  p->EXTRA_INFO.salary, p->EXTRA_INFO.schoolname, p->EXTRA_INFO.years_of_retirement);

        }
        return;
}

void searchAge(void)
{
        int userage;
        int i;
        p = variables;
        printf("\nPlease enter age");
        scanf("%d", &userage);

        for(i=0; i< counter; i++, p++)
        {

            if(p->ages == userage)
                {
                printf("\nFirstname: %s, \nlastname: %s, \nage: %d", p->firstnames, p->lastnames, p->ages);
                }
        }
}

int main(void)
{
        int run = 1;
        int userinput;

        while(run == 1)
        {
                printf("\nEnter 1 to add names, 2 to list all entries, 3 to list entries with age, 4 to delete entries, 5 to delete an entry with an age, 0 to quit");
                        scanf("%d", &userinput);

            switch(userinput)
            {
            case 1:
            insert();
            break;
                        case 2:
                            show();
                            break;
                        case 3:
                            searchAge();
                            break;
                        case 4:
                            delete_with_name();
                                break;
                        case 5:
                            delete_with_age();
                                break;
                        case 0:
                            run = 0;
                                break;
                }
        }
}
