#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *create(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!\n");
        return ptr;
    }
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void addBeg(int val){
    if (head == NULL){
        head = create(val);
        return;
    }
    struct Node *curr = create(val);
    curr->next = head;
    head = curr;
}

void addEnd(int val){
    if (head == NULL){
        head = create(val);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = create(val);
}

void insertAfter(int key,int val){
    if (head == NULL){
        printf("List empty!!");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL && temp->data != key){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Key not found!!");
        return;
    }
    struct Node *curr = create(val);
    curr->next = temp->next;
    temp->next = curr;
}

void insertSorted(int val){
    if (head == NULL || head->data > val){
        struct Node *curr = create(val);
        curr->next = head;
        head = curr;
        return;
    }
    struct Node *temp = head;
    struct Node *prev = head;
    while (temp != NULL && temp->data < val){
        prev = temp;
        temp = temp->next;
    }
    prev->next = create(val);
    prev->next->next = temp;
}

void delBeg(){
    if (head == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delEnd(){
    if (head == NULL)
        return;
    if (head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delAny(int val){
    if (head == NULL)
        return;
    struct Node *temp = head;
    struct Node *prev = head;
    if (head->data == val){
        head = head->next;
        free(temp);
        return;
    }
    while (temp != NULL){
        if (temp->data == val){
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void displayFoward(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL){
        printf("%3d", temp->data);
        temp = temp->next;
    }
}

void displayBackward(struct Node *head){
    if (head == NULL)
        return;
    displayBackward(head->next);
    printf("%3d", head->data);
}

void reverse(){
    if (head == NULL || head->next == NULL)
        return;
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void middle(){
    if (head == NULL || head->next == NULL)
        return;
    struct Node *fast = head;
    struct Node *slow = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("Middle element %d", slow->data);
}

int search(int val){
    if (head == NULL)
        return -1;
    int node = 1;
    struct Node *temp = head;
    while (temp != NULL){
        if (temp->data == val)
            return node;
        temp = temp->next;
        node++;
    }
    return -1;
}

int smallest(){
    if (head == NULL)
        return -1;
    int smallest = INT_MAX;
    struct Node *temp = head;
    while (temp != NULL){
        smallest = fmin(temp->data, smallest); // read the issue from largest fn
        temp = temp->next;
    }
    return smallest;
}

int largest(){
    if (head == NULL)
        return -1;
    int largest = INT_MIN;
    struct Node *temp = head;
    while (temp != NULL){
        largest = fmax(temp->data, largest); // return double value may cause error if ant just typeCast or use ternary opertaor same for smallest
        temp = temp->next;
    }
    return largest;
}

int main(){
    int choice, val, pos;

    while (1){
        printf("\n\n===== Linked List Menu =====\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Insert in Sorted Order\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete Specific Value\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Reverse List\n");
        printf("10. Find Middle Element\n");
        printf("11. Search Element\n");
        printf("12. Find Smallest Element\n");
        printf("13. Find Largest Element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            addBeg(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            addEnd(val);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            insertSorted(val);
            break;

        case 4:
            delBeg();
            break;

        case 5:
            delEnd();
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delAny(val);
            break;

        case 7:
            displayFoward();
            break;

        case 8:
            displayBackward(head);
            break;

        case 9:
            reverse();
            break;

        case 10:
            middle();
            break;

        case 11:
            printf("Enter value to search: ");
            scanf("%d", &val);
            pos = search(val);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element found at position %d\n", pos);
            break;

        case 12:
            val = smallest();
            if (val == -1)
                printf("List is empty\n");
            else
                printf("Smallest element: %d\n", val);
            break;

        case 13:
            val = largest();
            if (val == -1)
                printf("List is empty\n");
            else
                printf("Largest element: %d\n", val);
            break;

        case 0:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}