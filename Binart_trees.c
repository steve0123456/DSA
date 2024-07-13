#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * create(int data){
    struct Node* node= (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
void inorder(struct Node *root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    }
}
struct Node * findmin( struct Node *root){
     if(root==NULL){
         printf("empty");
     }
     while(root->left!=NULL){
         root=root->left;
     }
     printf("%d",root);
     return root;
 }
 void postorder(struct Node *root){
     if(root==NULL){
         printf("empty");
     }
     while(root!=NULL){
         postorder(root->left);
         postorder(root->right);
         printf("%d",root->data);
     }
 }
struct Node * insert(struct Node *root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}
int main() {
    
 
    
    struct Node* root = NULL;
    int choice, data;

    while (choice!=12) {
        printf("Binary Search Tree Menu:\n");
        printf("1. Insert an element\n");
        printf("2. findmin\n");
        printf("3. inorder\n");
        printf("4. Postorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Find the mirror image of the tree\n");
        printf("7. Count internal and external nodes\n");
        printf("8. Search for an element\n");
        printf("9. Find the height of the tree\n");
        printf("10. Find the smallest element\n");
        printf("11. Find the largest element\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:  printf("Enter the element to insert: ");
                scanf("%d", &data);
                root=insert(root,data);
                break;
            case 2: 
                root=findmin(root);
                break;
                case 3:
                 inorder(root);
                 break;
                 case 4:
                 postorder(root);
                 break;
                 case 5:
                 //preorder(root);
                 break;
                 
            
        }
    }

    return 0;
}