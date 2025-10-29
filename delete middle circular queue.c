#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; 

void delete_at_middle() {
    
    int pos, i;
    struct Node *q, *r;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (pos == 1) {
        if (head == NULL) {
            printf("List is empty, cannot delete.\n");
            return;
        }
        q = head;
        head = head->next;
        free(q);
        printf("Deleted node at position 1.\n");
        return;
    }

    q = head;
    r = NULL; 

    for (i = 0; i < pos - 1; i++) {
        
        if (q == NULL) {
            printf("Invalid position. Position out of bounds.\n");
            return;
        }
        r = q;
        q = q->next;
    }

    if (q == NULL) {
        printf("Invalid position. Position out of bounds.\n");
        return;
    }
    
    r->next = q->next;
    free(q);
    
    printf("Deleted node at position %d.\n", pos);
}
