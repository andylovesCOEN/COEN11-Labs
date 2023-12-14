#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  char firstName[20];
  char lastName[20];
  int age;
  struct Node *next;
};

struct Node *head = NULL;

int check_duplicate(char first_name[], char last_name[]){
  struct Node *p = head;
  while(p != NULL) {
    if(strcmp(p -> firstName, first_name) == 0 && strcmp(p -> lastName, last_name) == 0) 
    {
      printf("\nName was already in list\n");
         return 0;
    }
    else {
    p = p -> next;
    }
  }
  return 1;
}

void list_remove(char first_name[], char last_name[])
  {
  struct Node *p = head;
  struct Node *q = head;
  if (p == NULL){
    return;
  }
  while(p != NULL)
{
    if (strcmp(p -> firstName, first_name) == 0 && strcmp(p -> lastName, last_name) == 0)
      {
      if (p == head) 
      {
        head = p -> next;
      }
      else
      {
        q -> next = p -> next;
           free(p);
           p = q;
      }
      return;
    }
    else if (p == head)
    {
    p = p -> next;
    }
    else 
    {
    q = p;
    p = p -> next;
    }
  }
}

void insert(char first_name[], char last_name[], int age)
  {
  if(check_duplicate(first_name, last_name) == 0)
  {
    return;
  }
  struct Node *p = (struct Node*)malloc(sizeof(struct Node));
  strcpy(p -> firstName, first_name);
  strcpy(p -> lastName, last_name);
  p -> age = age;
  p -> next = head;
  head = p;
}

void show(struct Node *head)
{
  struct Node *p = head;
  while (p != NULL)
  {
    printf("%s, ", p -> firstName);
    printf("%s, ", p -> lastName);
    printf("%i\n", p -> age);
    p = p -> next;
  }
}

void show_age(int age)
  {
  struct Node *p = head;
  if (p == NULL){
    return;
  }
  while (p != NULL) 
  {
    if (p -> age == age)
    {
      printf("%s, ", p -> firstName);
      printf("%s, ", p -> lastName);
      printf("%i\n", p -> age);
      p = p -> next;
      }
    else{
      p = p -> next;
    }
  }
}

int main() 
{
  int option;
  char firstName[20];
  char lastName[20];
  int age;
  while(option != -1)
  {
    printf("\nAdd a new entry - 1 Display the entire list - 2 Display people with a given age - 3 Remove a person from the list - 4 Quit out - 0\n");
    scanf("%i", &option);
    switch (option)
    {
      case 0:
        option = -1;
        break;
      case 1:
        printf("\nPlease enter the first name: ");
           scanf("%s", firstName);
        printf("\nPlease enter the last name: ");
           scanf("%s", lastName);
        printf("\nPlease enter the age: ");
           scanf("%i", &age);
        insert(firstName, lastName, age);
        break;
      case 2:
        show(head);
           break;
      case 3:
        printf("\nWhat age do you want to look for? ");
           scanf("%i",  &age);
        show_age(age);
           break;
      case 4:
        printf("\nWhat is the first name of the person to remove? ");
           scanf("%s", firstName);
        printf("\nWhat is the last name of the person to remove?  ");
           scanf("%s", lastName);
        list_remove(firstName, lastName);      
           break;
    }
  }
  return 0;
}