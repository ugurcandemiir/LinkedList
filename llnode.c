#include "llnode.h"
#include <stdlib.h>
#include <stdio.h>

struct llnode {
	int payload;
	struct llnode * next;
};

/* Add code for methods here */
node newNode(int value){
	node new_node = (node) malloc (sizeof (node));
	new_node->payload = value;
	new_node->next = NULL;
	return new_node;
}
node addToHead(node head,int value){
	// Returns the new head node
	node temp = newNode(value);

	temp->next = head;
	return temp;
}


int listSize(node head){

  if (head==NULL) return 0;
	return 1+listSize(head->next);

}
void printList(node head){
	printf("Head@%p ",head);
	while(head!=NULL) {
		printf(" -> %d",head->payload);
		head = head->next;
	}
	printf("\n");
}
void freeList(node head){
	if (head==NULL) return;
		freeList(head->next);
		free(head);

}
node addToTail(node head,int value){
		// Returns a new head node if list was empty
		node temp = newNode(value);
		if(head == NULL){return temp;}
		node n_temp = head;
		while(n_temp->next != NULL){
			 n_temp = n_temp->next ;
		}
		n_temp->next = temp;
		return head;
}

node addIncreasing(node head,int value){
	// adds a node with value before node with higher value in list that starts at head
	// May put value at head of list, so return head
	node add_temp = newNode(value);
	if (head == NULL) {
		head = add_temp;
		return head;
	}
	if (head->payload > value) {
		add_temp->next = head;
		return add_temp;
	}
	node add_temp2;
	add_temp2 = head;
	while(add_temp2->payload < value) {
		add_temp2 = add_temp2->next;
	}
	add_temp->next = add_temp2->next;
	add_temp2->next = add_temp;
	return head;

}
