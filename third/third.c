#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
	int value;
	struct node* next;
}node_t;

node_t* pop(node_t* head){
	node_t* cur = head;
	if(cur==NULL){
		return cur;
	}
	else{
		cur = cur->next;
		free(head);
		return cur;
	}
}

node_t* push(node_t* head, int valu){
	node_t* cur = head;
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	if(cur == NULL){	
		temp->value = valu;
		temp->next = NULL;
		return temp;
	}
	else{
		temp->value = valu;
		temp->next = cur;
		return temp;
	}	
	
}

node_t* enqueue(node_t* head, int valu){
	node_t* cur = head;
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	if(cur == NULL){	
		temp->value = valu;
		temp->next = NULL;
		return temp;
	}
	else{
		node_t*next = cur->next;
		while(next != NULL) {
			next = next->next;
			cur = cur->next;
		}
	}
	temp->value = valu;
	temp->next = NULL;
	cur->next = temp;	
	return head;
}

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
		if(name[1] == 'O') {
			head = pop(head);
			//printf("INSERT %d\n ", val);
		}
		else if(name[1] == 'U') {
			head = push(head, val);
			//printf("INSERT %d\n ", val);
		}
		else{
			head = enqueue(head, val);
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


