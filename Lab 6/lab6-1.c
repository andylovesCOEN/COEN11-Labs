#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char firstName[10];
  char lastName[10];
  int age;
  struct node*next;
};

struct listpointer
{
  struct node * head;
  struct node * tail;
};

struct listpointer array[3];
int breaktemp=0;

void insert1(char *fname, char *lname, int age)
{
  struct listpointer * arrayptr;
  arrayptr=&array[0];
  struct node*temp;
  if(arrayptr->head==NULL)
  {
    printf("No elements\n");
    arrayptr->head=temp;
    arrayptr->tail=temp;
  }

  else
  {
    arrayptr->tail->next=temp;
    arrayptr->tail=arrayptr->tail->next;
  }
}

void insert2(struct node * temp)
{
  struct listpointer * arrayptr;
  arrayptr=&array[1];
  if(arrayptr->head==NULL)
  {
    printf("No elements\n");
    arrayptr->head=temp;
    arrayptr->tail=temp;
  }

  else
  {
    arrayptr->tail->next=temp;
    arrayptr->tail=arrayptr->tail->next;
  }
}

void insert3(struct node * temp)
{
  struct listpointer * arrayptr;
  arrayptr=&array[2];
  if(arrayptr->head==NULL)
  {
    printf("No elements\n");
    arrayptr->head=temp;
    arrayptr->tail=temp;
  }

  else
  {
    arrayptr->tail->next=temp;
    arrayptr->tail=arrayptr->tail->next;
 }
}

int check_duplicates(char fname[], char lname[], int age)
{
  struct node* temp;
  struct node* temp2;
  temp=malloc(sizeof(struct node));
  strcpy(temp->firstName, fname);
  strcpy(temp->lastName, lname);
  temp->age=age;
  for(int p=0; p<3; p++)
  {
    temp2=array[p].head;
    while(temp2!=NULL)
    {
      if(strcmp(temp2->firstName, fname)==0 && strcmp(temp2->lastName, lname)==0)
      {
        return 0;
      }
        return 1;
      temp2=temp2->next;
    }
  }

  if(age>65)
  {
    insert1(temp->firstName,temp->lastName,temp->age);
  }

  else if(age>18)
  {
    insert2(temp);
  }

  else
  {
    insert3(temp);
  }
}

void find_age(int age){
  struct node * findtemp;
  for(int p=0; p<3; p++){
    findtemp=array[p].head;
    while(findtemp!=NULL){
      if(findtemp->age==age){
        printf("found name: %s %s \n", findtemp->firstName, findtemp->lastName);
      }
      findtemp=findtemp->next;
    }
  }
}

void list()
{
  struct node * headtemp;
  struct node * tailtemp;
  for(int q=0; q<3; q++)
  {
    headtemp=array[q].head;
    while(headtemp!=NULL)
    {
      printf("element is %s %s %d \n", headtemp->firstName, headtemp->lastName, headtemp->age);
      headtemp=headtemp->next;
   }

    if(q<2)
    {
      printf("\n||next list||\n");
    }
  }
}

void delete()
{
  char fname[10];
  char lname[10];
  struct listpointer * arraytemp;
  struct node * temp;
  struct node *temp2;
  printf("enter first name");
  scanf("%s", fname);
  printf("enter last name");
  scanf("%s", lname);

  for(int p=0; p<3; p++)
  {
    temp=array[p].head;
    temp2=array[p].head;
    while(temp!=NULL)
    {
      if(strcmp(temp->firstName, fname)==0 && strcmp(temp->lastName, lname)==0)
      {
        arraytemp=&array[p];
        goto FOUND;
      }
      temp=temp->next;
    }
  }

  FOUND : printf("pointer one is at %s %s\n", temp->firstName, temp->lastName);
  printf("pointer two starts at %s %s\n", temp2->firstName, temp2->lastName);
  printf("pointer one is at %s and pointer two is at %s \n", temp->firstName, temp2->firstName);

  if(arraytemp->head==arraytemp->tail)
  {
    printf("only one element");
    arraytemp->head=NULL;
    arraytemp->tail=NULL;
    return;
  }
    if(temp==arraytemp->head)
    {
        arraytemp->head=arraytemp->head->next;
        return;
    }

  else
  {
    printf("this works ");
    while(temp2->next != temp)
    {
      temp2=temp2->next;
    }
    printf("pointer TWO is now at %s %s\n", temp2->firstName, temp2->lastName);
    printf("pointer ONE is now at %s %s\n", temp->firstName, temp->lastName);
    printf("arraytemp head is at %s %s arraytemp tail is at %s %s\n",
           arraytemp->head->firstName, arraytemp->head->lastName, arraytemp->tail->firstName, arraytemp->tail->lastName);

    if(temp==arraytemp->tail)
    {
      temp2->next=NULL;
      arraytemp->tail=temp2;
      printf("arraytemp tail is now at %s %s\n", arraytemp->tail->firstName, arraytemp->tail->lastName);
        }

    else
    {
      temp=temp->next;
      temp2->next=temp;
    }
  }
}

void saveall()
{
  FILE* fp;
  char str[]="||new array||\n";
  char strline[]="\n";
  char strspace[]=" ";
  char end[]="?";
  char result[10];
  fp=fopen("dat.txt", "w");
  struct node * savertemp;
    struct node * secondtemp;
  for(int f=0; f<3; f++){
    savertemp=array[f].head;
    while(savertemp!=NULL){
      fprintf(fp, "%s\t%s\t%d\n", savertemp->firstName, savertemp->lastName, savertemp->age);
        savertemp=savertemp->next;
    }
  }
  fwrite(end, strlen(end), 1, fp);
  fclose(fp);
}

void read_all()
{
    FILE* ptr;
    char ch;
    char buffer[100];
    char buffer2[100];
    char buffer3[100];
    char fnamer[10]={0};
    char lnamer[10]={0};
    int ager;
    int i=0;
    int rem;
    int spacecount=0;
    char * strptr;
    ptr = fopen("dat.txt", "r");
    if (NULL == ptr) {
        printf("ERROR\n");
    }
    while(fscanf(ptr, "%s\t%s\t%d\n", fnamer, lnamer, &ager )==3){
        check_duplicates(fnamer, lnamer, ager);
    }
}

int main(int argc, char*argv[])
{
  int breakcondition=0;
  int agetemp;
  char fnametemp[10];
  char lnametemp[10];
  array[0].head=NULL;
  int x;
    if(argc==1)
     {
        printf("the file name is missing currently");
        return 1;
    }
    for(int s=0; s>-1; s++)
    {
      printf("\n1). Add new student 2). display all students in list 3). check all students of a certain age 4). delete a student 5). load 0). exit\n");
        scanf("\n%d", &x);

    switch(x)
    {
      case 1:
        printf("enter first name");
        scanf("%s", fnametemp);
        printf("enter last name");
        scanf("%s", lnametemp);
        printf("enter age");
        scanf("%d", &agetemp);
        if(check_duplicates(fnametemp, lnametemp, agetemp)!=0)
        insert1(fnametemp, lnametemp, agetemp);
        break;

      case 2:
        list();
        break;

      case 3:
        printf("enter age");
        scanf("%d", &agetemp);
        find_age(agetemp);
        break;

      case 4:
        delete();
        break;

      case 5:
        read_all(argv[1]);
        break;

      case 0:
        saveall(argv[1]);
        breakcondition=-1;
        break;

    }
    if(breakcondition==-1)
    {
        break;
    }
  }
}