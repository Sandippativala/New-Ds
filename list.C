#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head, int ele) {
    struct node *new1, *curr, *prev;
    new1 = (struct node*)malloc(sizeof(struct node));

    if(!new1){
	printf("Memory allocation failed\n");
	return;
    }
    curr = *head;
    prev = NULL;

    new1->data = ele;

    if (*head == NULL || curr->data >= ele) {
	new1->next = *head;
	*head = new1;
    } else {
	while (curr != NULL && curr->data < ele) {
	    prev = curr;
	    curr = curr->next;
	}
	new1 ->next = curr;
	prev ->next = new1;
    }

    printf("Inserted %d \n", ele);
}

int del(struct node **head, int ele) {
	struct node *curr = *head, *prev = NULL;
	int val;

    if (*head == NULL) {
	printf("List is empty\n");
	return -1;
    }

    if (curr != NULL && curr -> data == ele) {
	*head = curr->next;
	val = curr ->data;
	free(curr);
	printf("Deleted element %d\n",val);
	return val;
    }

    while (curr != NULL && curr ->data != ele) {
	prev = curr;
	curr = curr->next;
    }

    if (curr == NULL) {
	printf("Element %d not found in the list\n", ele);
	return -1;
    }

    prev->next = curr->next;
    val = curr->data;
    free(curr);

    printf("Deleted element %d\n", val);
    return val;
}

void modify(struct node *head, int ele) {
	int newVal;

    if(head == NULL){
	printf("List is empty\n");
	return;
    }
    while(head != NULL){
	if(head->data == ele){
	    printf("Enter new value: ");
	    scanf("%d", &newVal);
	    head->data = newVal;
	    printf("Value modified.\n");
	    return;
	}
	head = head->next;
    }
    printf("Element %d not found in the list.\n", ele);
}

void display(struct node *head) {
    if (head == NULL) {
	printf("List is empty\n");
    } else {
	while (head != NULL) {
	    printf("%d -> ", head->data);
	    head = head->next;
	}
    }
    printf("NULL\n");
}

void main() {
    int choice, ele;
    struct node *head = NULL;
    clrscr();
    while (1) {
	printf("---- Linked List ----\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Modify\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("--------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice) {
	    case 1:
		printf("Enter value to insert: ");
		scanf("%d", &ele);
		insert(&head, ele);
		break;
	    case 2:
		printf("Enter value to delete: ");
		scanf("%d", &ele);
		del(&head, ele);
		break;
	    case 3:
		printf("Enter value to modify: ");
		scanf("%d", &ele);
		modify(head, ele);
		break;
	    case 4:
		display(head);
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice\n");
		break;
	}
    }
}
