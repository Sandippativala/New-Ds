#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *pre;
    int data;
    struct node *next;
};

void insert(struct node **head, int ele) {
	struct node *curr = *head, *prev = NULL;
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    if (!new1) {
        printf("Memory allocation failed\n");
        return;
    }
    new1->data = ele;
    new1->next = new1->pre = NULL;

    if (*head == NULL) { // Empty list
	new1->next = new1->pre = new1;
	*head = new1;
    } else {
	do {
	    if (curr->data >= ele) break; // Find correct position
	    prev = curr;
	    curr = curr->next;
	} while (curr != *head);

	if (prev == NULL) { // Insert at the beginning
	    struct node *last = (*head)->pre;
	    new1->next = *head;
	    new1->pre = last;
	    last->next = new1;
	    (*head)->pre = new1;
	    *head = new1;
	} else { // Insert after 'prev'
	    new1->next = prev->next;
	    new1->pre = prev;
	    prev->next->pre = new1;
	    prev->next = new1;
	}
    }
    printf("Inserted: %d\n", ele);
}

int del(struct node **head) {
	 struct node *curr = *head;
    int ele, val;
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    printf("Enter value you want to delete: ");
    scanf("%d", &ele);

    do {
        if (curr->data == ele) break;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != ele) {
        printf("Element not found\n");
        return -1;
    }

    val = curr->data;
    if (curr->next == curr) { // Only one node
        free(curr);
        *head = NULL;
    } else {
        struct node *prev = curr->pre, *next = curr->next;
        prev->next = next;
        next->pre = prev;

        if (*head == curr) *head = next; // Update head if needed
        free(curr);
    }
    return val;
}

void modify(struct node *head, int ele) {
	    struct node *curr = head;
    int newValue;
    if (!head) {
        printf("List is empty\n");
        return;
    }
    do {
        if (curr->data == ele) {
            printf("Enter new value: ");
            scanf("%d", &newValue);
            curr->data = newValue;
            printf("Modified\n");
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Element not found\n");
}

void display(struct node *head) {
	    struct node *curr = head;
    if (!head) {
        printf("List is empty\n");
        return;
    }
    printf("Double Circular Linked List:\n");
    do {
	printf(" %p - %d - %p -> ", curr->pre, curr->data, curr->next);
	curr = curr->next;
    } while (curr != head);
    printf(" (Back to head: %d)\n", head->data);
}

void main() {
    int choice, ele;
    struct node *head = NULL;

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
