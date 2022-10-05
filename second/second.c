#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
	int value;
	struct node* next;
}node_t;


node_t* add(node_t* head, int valu){
	node_t* cur = head;
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	//checks if LL is empty
	if(cur==NULL){
		temp->value = valu;
		temp->next = NULL;
		return temp;
	}
	//checks if LL already has value
	else if(cur->value == valu){
		free(temp);
		return head;
	}
	//checks if cur's value is above what you're trying to add. If it is, put it in.
	else if(cur->value > valu){
		temp->value = valu;
		temp->next = cur;
		return temp;
	}
	else{
		node_t* next = cur->next;
		while(next!=NULL){
			if(next->value == valu){
				free(temp);
				return head;
			}
			else if(next->value > valu){
				temp->value = valu;
				temp->next = next;
				cur->next = temp;	
				return head;
			}
			else {
			next = next->next;
			cur = cur->next;		
			}
		}
		temp->value = valu;
		temp->next = NULL;
		cur->next = temp;
		return head;
	}
	return NULL;
}	

node_t* delete(node_t* head, int valu){
	node_t* cur = head;
	if(cur==NULL){
		return cur;
	}
	else if(cur->value == valu){
		cur = cur->next;
		free(head);
		return cur;
	}
	else {
		node_t* prev = head;
		cur = cur->next;
		while(cur != NULL){
	 		if(cur->value == valu){
				prev->next = cur->next;
			free(cur);
			return head;
			}
			else{
			prev = prev->next;
			cur = cur->next;
			}
		}
		return head;	
	}
}
/*--------------------DIVIDER------------------------------- */

int main(int argc, char* argv[argc+1]){
	if (argc != 2){
		printf("FAILED\n");
		return EXIT_SUCCESS;
	}
	FILE* f = fopen (argv[1], "r");
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	}
	node_t* head = NULL;
	int val;  
	char name[10];
	while(fscanf(f, "%s %d\n", name, &val) != EOF) {
		if(name[0] == 'I') {
			head = add(head, val);
			//printf("INSERT %d\n ", val);
		}
		else{
			head = delete(head, val);
			//printf("DELETE %d\n ", val);
		}
		if(head == NULL){
			printf("EMPTY \n");
		}
		else{
			node_t* temp = head;
			while(temp != NULL) {
				printf("%d ", temp->value);
				temp = temp->next;
			}
			printf("\n");
		}
	}
	if(head != NULL){
		node_t* prev = head;
		node_t* cur = head->next;
		while(cur != NULL){
			free(prev);
			prev = cur;
			cur = cur->next;
		}
		free(prev);	
	}
	fclose(f);	
	return EXIT_SUCCESS;
}



