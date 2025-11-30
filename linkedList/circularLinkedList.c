#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *last = NULL;

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
    if (last == NULL){
        last = create(val);
        last->next = last;
        return;
    }
    struct Node *curr = create(val);
    curr->next = last->next;
    last->next = curr;
}
void addEnd(int val){
    if (last == NULL){
        last = create(val);
        last->next = last;
        return;
    }
    struct Node *curr = create(val);
    curr->next = last->next;
    last->next = curr;
    last = curr;
}
void insertSorted(int val){
    if (last == NULL ){
        last = create(val);
        last->next = last;
        return;
    }
    if (last->next->data > val){
        struct Node *curr = create(val);
        curr->next = last->next;
        last->next = curr;
        return;
    }
    struct Node *temp = last->next;
    struct Node *prev = last;
    do{
        prev = temp;
        temp = temp->next;
    } while (temp != last->next && temp->data < val);
    struct Node *curr = create(val);
    prev->next = curr;
    curr->next = temp;
    if(prev == last)
        last = curr;
}

void delBeg(){
    if (last == NULL){
        printf("List is empty!!");
        return;
    }
    if (last->next == last){
        free(last);
        last = NULL;
    }
    struct Node *temp = last->next;
    last->next = temp->next;
    free(temp);
}

void delEnd(){
    if (last == NULL){
        printf("List is empty!!");
        return;
    }
    if (last->next == last){
        free(last);
        last = NULL;
    }
    struct Node *temp = last->next;
    while (temp->next != last){
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    last = temp;
}

void delAny(int val){
    if (last == NULL){
        printf("List is empty!!");
        return;
    }
    struct Node *temp = last->next;
    struct Node *prev = last;
    do{
        if (temp->data == val){
            if(prev == temp){
                free(temp);
                last = NULL;
            }
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
    printf("Element not found!!");
}

void displayFoward(){
    if (last == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next;
    do{
        printf("%3d", temp->data);
        temp = temp->next;
    } while (temp != last->next);
}

void displayBackward(struct Node *head){
    if (head == last){
        printf("%3d", head->data);
        return;
    }
    displayBackward(head->next);
    printf("%3d", head->data);
}

void reverse(){
    if (last == NULL || last->next == last)
        return;
    struct Node *prev = last;
    struct Node *curr = last->next;
    struct Node *next = NULL;
    last = curr;
    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != last);
}

void middle(){
    if (last == NULL || last->next == last)
        return;
    struct Node *fast = last->next;
    struct Node *slow = last->next;
    do{
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != last->next && fast->next != last->next);
    printf("Middle element %d", slow->data);
}

int search(int val){
    if (last == NULL)
        return 0;
    int node = 1;
    struct Node *temp = last->next;
    do{
        if (temp->data == val)
            return node;
        temp = temp->next;
        node++;
    } while (temp != last->next);
    return -1;
}

int smallest(){
    if (last == NULL)
        return -1;
    int smallest = INT_MAX;
    struct Node *temp = last->next;
    do{
        smallest = fmin(smallest,temp->data);
        temp = temp->next;
    } while (temp != last->next);
    return smallest;
}

int largest(){
    if (last == NULL)
        return -1;
    int largest = INT_MIN;
    struct Node *temp = last->next;
    do{
        largest = fmax(largest, temp->data);
        temp = temp->next;
    } while (temp != last->next);
    return largest;
}
int main(){
    int choice, val, pos;

    while (1){
        printf("\n\n===== Circular Linked List Menu =====\n");
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

        switch (choice)
        {
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
            displayBackward(last->next);
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
            if (pos == 0)
                printf("List is empty\n");
            else if (pos == -1)
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