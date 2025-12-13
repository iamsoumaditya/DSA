#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root = NULL;

struct Node* create(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Insufficient memory\n");
        return ptr;
    }
    ptr->lchild = NULL;
    ptr->data = val;
    ptr->rchild = NULL;
    return ptr;
}

void insert(int val){ // TC = O(logn) best case O(n) skewed tree SC = O(1)
    if(root == NULL){
        root = create(val);
        return;
    }
    struct Node *curr = root;
    struct Node *parent = NULL;
    while(curr != NULL){
        parent = curr;
        if(val < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    if(val < parent->data)
        parent->lchild = create(val);
    else
        parent->rchild = create(val);
}

void inOrder(struct Node *r){ //TC = O(n) SC = O(logn) skewed tree-> O(n)
    if(r == NULL)
        return;
    inOrder(r->lchild);
    printf("%3d",r->data);
    inOrder(r->rchild);
}

void preOrder(struct Node *r){
    if(r == NULL)
        return;
    printf("%3d",r->data);
    preOrder(r->lchild);
    preOrder(r->rchild);
}

void postOrder(struct Node *r){
    if(r == NULL)
        return;
    postOrder(r->lchild);
    postOrder(r->rchild);
    printf("%3d",r->data);
}

struct Node* mvn(struct Node* r){
    if (r == NULL)
        return r;
    while(r->lchild != NULL){
        r = r->lchild;
    }
    return r;
}

struct Node* delete(struct Node* r, int key){ //TC = SC= O(logn) skewed tree-> O(n)
    if(r == NULL)
        return r;
    else if (key < r->data)
        r->lchild = delete(r->lchild, key);
    else if (key > r->data)
        r->rchild = delete(r->rchild, key);
    else{
        if (r->lchild == NULL && r->rchild == NULL){
            free(r);
            return NULL;
        }
        else if(r->lchild == NULL){
            struct Node *temp = r->rchild;
            free(r);
            return temp;
        }
        else if(r->rchild == NULL){
            struct Node *temp = r->lchild;
            free(r);
            return temp;
        }else{
            struct Node *temp = mvn(r->rchild);
            r->data = temp->data;
            r->rchild = delete(r->rchild, temp->data);
        }
    }
    return r;
}

int search(struct Node *root, int key){
    if(root == NULL)
        return 0;
    if(key == root->data)
        return 1;
    else if(key < root->data)
        return search(root->lchild, key);
    else
        return search(root->rchild, key);
}

int largest(struct Node*root){
    if(root == NULL)
        return INT_MIN;
    if(root->rchild == NULL)
        return root->data;
    else
        return largest(root->rchild);
}

int smallest(struct Node*root){
    if(root == NULL)
        return INT_MAX;
    if(root->lchild == NULL)
        return root->data;
    else
        return smallest(root->lchild);
}

int height(struct Node*root){
    if(root == NULL)
        return -1; // return 0;
    int hl = height(root->lchild);
    int hr = height(root->rchild);

    return 1 + (hl > hr ? hl : hr);
}

int totalNode(struct Node* root){
    if(root == NULL)
        return 0;
    return totalNode(root->lchild) + totalNode(root->rchild) + 1;
}

int internalNode(struct Node* root){
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 0;
    else
       return internalNode(root->lchild) + internalNode(root->rchild) + 1;
}

int externalNode(struct Node* root){
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
       return externalNode(root->lchild) + externalNode(root->rchild);
}

int main(){
    int choice, val;

    while (1){
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete\n");
        printf("6. search\n");
        printf("7. largest\n");
        printf("8. smallest\n");
        printf("9. height\n");
        printf("10. Internal Node\n");
        printf("11. External Node\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delete(root,val);
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("%d found in BST.\n", val);
            else
                printf("%d not found.\n", val);

            break;
        case 7:
            val = largest(root);
            if (val == INT_MIN)
                printf("Tree is empty.\n");
            else
                printf("Largest element = %d\n", val);

            break;
        case 8:
            val = smallest(root);
            if (val == INT_MAX)
                printf("Tree is empty.\n");
            else
                printf("Smallest element = %d\n", val);
            break;
        case 9:
            val = height(root);
            printf("Height of the Tree is %d.\n",val);
            break;
        case 10:
            val = internalNode(root);
            printf("Total internal node of the Tree is %d.\n",val);
            break;
        case 11:
            val = externalNode(root);
            printf("Total external node of the Tree is %d.\n",val);
            break;
        case 12:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}