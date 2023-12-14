#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct globalVariables{
	char firstnames[20];
	char lastnames[20];
	int ages;
};


int counter = 0;


struct globalVariables variables[10];
struct globalVariables *p, *q;


void insert(void)
{	
	    
            struct globalVariables *p;
            p = variables;
	    
	    
            char inputFn[20];
            char inputLn[20];
            int inputAge;
	
	   
            int samename = 0;

       
            int i;
            int j;         

            
            printf("Insert first name:");
	        scanf("%s", inputFn);

            printf("Insert last name:");
            scanf("%s", inputLn);

            printf("Insert age:");
            scanf("%d", &inputAge);
            
	    
            
 	    /*for(j = 0; j<counter; j++, p++){
			printf("\n%s", p->lastnames);
			printf("%d %d", p, counter);
                        
                          if((strcmp(inputLn, p->lastnames)>0 )){
                             char tempfn[20];
                             char templn[20];
                             int tempage;
                             
                            
             
                             
                             variables[i-1] = variables[i];
                             variables[i] = q;
                       } 
             } */

	    
            for(i=0; i < counter; i++, p++){
                if((strcmp(p->firstnames, inputFn) == 0) && (strcmp(p->lastnames, inputLn) == 0)){
			            samename=1;
                        break; 
                }
            } 

            if(samename == 1){
                printf("\nThere is already an entry with that name!");
            }
	    else if(counter >=10){
	    	 
	    }
           
             else{		
					strcpy(p->firstnames, inputFn); //next three lines just copying input values into global arrays 
                    strcpy(p->lastnames, inputLn);
                    p->ages = inputAge;
		        	counter++;
					p++;
		    }
	     
	     for(j = 0; j< counter-1; j++){
			struct globalVariables *prev = variables;
			struct globalVariables *next = variables;
			int k;
			next++;
			for(k = 0; k < counter-j-1; ++k){
				
				if(strcmp(prev->lastnames, next->lastnames)>0){
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
int find_record_index(char *last_name, char *first_name){
	
	struct globalVariables *p = variables;
	int i = 0;
	for(int i=0; i<counter; i++, p++){
		if(strcmp(p->lastnames, last_name) ==0 && strcmp(p->firstnames, first_name) ==0){
			return i;
		}
	}
}

void delete_record(){
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
	if(del_index == -1){
		printf("Unable to find first name: %s, lastname:%s to delete\n", first, last);
		return;
	}

	for(i = del_index; i<counter; i++){
		variables[i] = variables[i+1];
	}
	counter--;
	
	
}
void show(void){	
    int i;
	p = variables;
	 
	for(i=0; i< counter; i++, p++){
	    printf("\nFirstname:\t%s, \nlastname:\t%s, \nage:\t%d", p->firstnames, p->lastnames, p->ages);
	}
	
}


void searchAge(void){
	int userage;
	int i;
	p = variables;
	printf("\nPlease enter age");
	scanf("%d", &userage);
	
	for(i=0; i< counter; i++, p++){
	    if(p->ages == userage){
	    	printf("\nFirstname: %s, \nlastname: %s, \nage: %d", p->firstnames, p->lastnames, p->ages);

	    }
	}
}

int main(void){
        
        int run= 1;
	
	int userinput;

        while(run == 1)
        {
                printf("\nEnter in 1 to add names, 2 to show list of all entries, 3 to show all entries with a certain age, 4 to delete an entry, 0 to quit");
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
			    delete_record();
				break;
                
		    case 0:
			    run = 0;
				break;
				}
        }

}


