#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    struct node *pre;
    int data;
    struct node *next;
};

void insert(struct node **head, int ele) {
    struct node *new1, *curr, *prev = NULL;
    new1 = (struct node *)malloc(sizeof(struct node));

    if (!new1) {
        printf("Memory allocation failed\n");
        return;
    }

    new1->data = ele;
    new1->next = NULL;
    new1->pre = NULL;

    // Insertion logic
    if (*head == NULL) { // Empty list
        *head = new1;
    } else {
        curr = *head;
        while (curr && curr->data < ele) { // Find correct position
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL) { // Insert at the beginning
            new1->next = *head;
            (*head)->pre = new1;
            *head = new1;
        } else if (curr == NULL) { // Insert at the end
            prev->next = new1;
            new1->pre = prev;
        } else { // Insert in between
            prev->next = new1;
            new1->pre = prev;
            new1->next = curr;
	    curr->pre = new1;
	}
    }
    printf("Inserted: %d\n", ele);
}

int del(struct node **head) {
    int ele,val;
    struct node *curr = *head;

    if (*head == NULL) {
	printf("List is empty\n");
	return -1;
    }

    printf("Enter value you want to delete: ");
    scanf("%d", &ele);

    while (curr && curr->data != ele) { // Search for the node to delete
	curr = curr->next;
    }

    if (!curr) {
	printf("Element not found\n");
	return -1;
    }

    if (*head == curr) { // Deleting the first node
	*head = curr->next;
	if (*head) {
	    (*head)->pre = NULL;
	}
    } else if (curr->next == NULL) { // Deleting the last node
	curr->pre->next = NULL;
    } else { // Deleting a node in between
	curr->pre->next = curr->next;
	curr->next->pre = curr->pre;
    }

    val = curr->data;
    free(curr);
    return val;
}

void modify(struct node *head, int ele) {
	int newValue;
    if (!head) {
	printf("List is empty\n");
	return;
    }
    while (head) {
	if (head->data == ele) {
	    printf("Enter new value: ");
	    scanf("%d", &newValue);
	    head->data = newValue;
	    printf("Modified\n");
	    return;
	}
	head = head->next;
    }
    printf("Element not found\n");
}

void display(struct node *head) {
    if (!head) {
	printf("List is empty\n");
	return;
    }

    printf("Doubly linked list: \n");
    while (head) {
	printf(" %p - %d - %p -> ", head->pre, head->data, head->next);
	head = head->next;
    }
   // printf("NULL\n");
}

void main() {
    int choice, ele;
    struct node *head = NULL;
    clrscr();
    while (1) {
	printf("\n1. Insert \n2. Delete \n3. Modify \n4. Display \n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value: ");
		scanf("%d", &ele);
		insert(&head, ele);
		break;
	    case 2:
		printf("Deleted: %d\n", del(&head));
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
    getch();
}
