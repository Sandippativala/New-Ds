#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct pqueue {
    int front;
    int size;
    int rear;
    int *arr;
};

void insert(struct pqueue *ptr, int val) {
    if (ptr->rear == ptr->size - 1) {
        printf("Queue is full\n");
    } else {
        if (ptr->front == -1 && ptr->rear == -1) { 
            ptr->front = 0;
            ptr->rear = 0;
            ptr->arr[ptr->rear] = val;
        } else {
            int pos = ptr->rear;
            while (pos >= ptr->front && ptr->arr[pos] < val) {
                ptr->arr[pos + 1] = ptr->arr[pos];
                pos--;
            }
            ptr->arr[pos + 1] = val;
            ptr->rear++;
        }
        printf("Value inserted: %d\n", val);
    }
}

void delete(struct pqueue *ptr) {
    if (ptr->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Value deleted: %d\n", ptr->arr[ptr->front]);
        if (ptr->front == ptr->rear) { 
            ptr->front = ptr->rear = -1;
        } else {
            ptr->front++;
        }
    }
}

void display(struct pqueue *ptr) {
    if (ptr->front == -1) {
        printf("Queue is empty\n");
    } else {
	int i;
	printf("Queue elements are: ");
	for (i = ptr->front; i <= ptr->rear; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice, val;
    struct pqueue *pq = (struct pqueue*)malloc(sizeof(struct pqueue));
    pq->size = 5;
    pq->front = -1;
    pq->rear = -1;
    pq->arr = (int*)malloc(pq->size * sizeof(int));

    while (1) {
        printf("\n----------- Priority Queue -----------");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(pq, val);
		break;

	    case 2:
		delete(pq);
		break;

	    case 3:
		display(pq);
		break;

	    case 4:
		exit(0);

	    default:
		printf("Invalid choice.\n");
		break;
	}
    }
}
