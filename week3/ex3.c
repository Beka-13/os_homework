#include <stdio.h>
#include <stdlib.h> 
  
struct Node{
	int data;
	struct Node* next;
};

void print_list(struct Node *h){
	h = h->next;
	int i = 1;
	while (h != NULL){
		printf("%d::%d", i, h->data);
		i++;
		h = h->next;
		if(h!=NULL)printf("  -->  ");
	}
	printf("\n");
}

void add_node(struct Node *h, int v){
	while(h->next != NULL){
		h = h->next;
	}

	struct Node *tmp = NULL;
	tmp = (struct Node*)malloc(sizeof(struct Node));

	tmp->data = v;
	tmp->next = NULL;
	h->next = tmp;
}

void insert_node(struct Node *h, int id, int v){
	int i = 1;

	while(i != id){
		h = h->next;

		if(h==NULL){
			printf("Incorrect index\n");
		  return;
		}
		i++;
	}

	struct Node *tmp = NULL;
	tmp = (struct Node*)malloc(sizeof(struct Node));

	tmp->data = v;
	tmp->next = (h->next);

	h->next = tmp;
}

void delete_node(struct Node *h, int id){
	int i = 1;

	while(i != id){
		h = h->next;

		if(h==NULL){
			printf("Incorrect index\n");
		  return;
		}
		i++;
	}

	struct Node *tmp = h->next;

	h->next = tmp->next;
	tmp->next = NULL;
	free(tmp);
}

int main(){

	struct Node *head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 0;
	head->next = NULL;

	add_node(head, 3);	//1
	add_node(head, 10);	//2
	add_node(head, 3);	//3
	add_node(head, 1);	//4

	print_list(head);

	insert_node(head, 3, 555);

	print_list(head);

	delete_node(head, 4);

	print_list(head);


  return 0;
}