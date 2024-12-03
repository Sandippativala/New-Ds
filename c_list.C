#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int ele) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    struct node *curr = *head, *prev = NULL;
    new1->data = ele;

    if (!new1) {
	printf("Memory allocation failed\n");
	return;
    }

    if (*head == NULL) {
	*head = new1;
	new1->next = *head;
    }
    else {
	if (ele <= curr->data) {
	    while (curr->next != *head) {
		curr = curr->next;
	    }
	    new1->next = *head;
	    curr->next = new1;
	    *head = new1;
	}
	else {
		prev = *head;
		curr = curr ->next;

	    // Traverse to find the position to insert
	    while (curr != *head && curr->data < ele) {
		prev = curr;
		curr = curr->next;
	    }
	    prev->next = new1;
	    new1->next = curr;
	}
    }

    printf("Inserted %d \n", ele);
}

// Delete element from circular linked list
int del(struct node **head, int ele) {
	struct node *curr = *head, *prev = NULL;
	struct node *temp = *head;
	int val;
    if (*head == NULL) {
	printf("List is empty\n");
	return -1;
    }
    // Case 1: If there's only one node in the list
    if ((*head)->next == *head && (*head)->data == ele) {
	val = (*head)->data;
	free(*head);
	*head = NULL;
	printf("Deleted element %d\n", val);
	return val;
    }

    // Case 2: Deleting the head
    if ((*head)->data == ele) {
	// Traverse to the last node
	while (curr->next != *head) {
	    curr = curr->next;
	}
	val = temp->data;
	*head = (*head)->next;  // Update head
	curr->next = *head;     // Last node points to new head
	free(temp);
	printf("Deleted element %d\n", val);
	return val;
    }

    // Case 3: Deleting an element from the middle or end
    prev = *head;
    curr = (*head)->next;

    while (curr != *head && curr->data != ele) {
	prev = curr;
	curr = curr->next;
    }

    if (curr == *head) {
	printf("Element %d not found in the list\n", ele);
	return -1;
    }

    val = curr->data;
    prev->next = curr->next;
    free(curr);

    printf("Deleted element %d\n", val);
    return val;
}

// Modify an element in the circular linked list
void modify(struct node *head, int ele) {
	struct node *curr = head;
	int newVal;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
	if (curr->data == ele) {
            printf("Enter new value: ");
            scanf("%d", &newVal);
            curr->data = newVal;
            printf("Value modified.\n");
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Element %d not found in the list.\n", ele);
}

// Display the circular linked list
void display(struct node *head) {
	struct node *curr = head;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("HEAD (%d)\n", head->data);
}

void main() {
    int choice, ele;
    struct node *head = NULL;
    clrscr();

    while (1) {
        printf("---- Circular Linked List ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
