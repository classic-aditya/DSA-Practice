// IMPLEMENTED ALL BASIC OPERATION'S ON BST in C-language
// defintion of node, creation of a node, traversal, searching, insertion and deletion
#include <stdio.h>
#include <stdlib.h>
// DEFINITION OF NODE OF THE TREE
struct node{
    int val;
    struct node* left;
    struct node* right;
};
// TO CREATE A NODE
struct node* createNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->val = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// TO TRAVSER THE TREE(BST) : INORDER
void traverse(struct node* root){
    if(root == NULL) return;
    traverse(root->left);
    printf("%d ",root->val);
    traverse(root->right);
}
// TO SEARCH SOMETHING IN BST
void search(struct node* root, int val){
    if(root == NULL) {printf("%d is not present\n",val); return;}
    else if(root->val == val) {printf("%d is present in tree\n",val); return;}
    if(root->val > val){
        search(root->left,val);
    }
    else search(root->right,val);
}
// TO INSERT A NODE i.e. val IN BST
void insert(struct node* root, int val){
    struct node* ptr = root;
    if(val > ptr->val){
        if(ptr->right == NULL){
            ptr->right = createNode(val);
            return;
        }
        else{
            insert(ptr->right, val);
        }
    }
    else{
        if(ptr->left == NULL){
            ptr->left = createNode(val);
            return;
        }
        else{
            insert(ptr->left, val);
        }
    }
}
// Helping function for deletion 
struct node* minValueNode(struct node* root){
    struct node* ptr = root;
    while(ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}
// TO DELETE A NODE IN BST
struct node* deleteNode(struct node* root, int val){
    if(root == NULL) return NULL;
    if(val < root->val){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->val){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
int main()
{
    // THE TREE I AM MAKING 
    /*
            17
          /    \
        9        20
      /  \      /  \
     8   12   18   25
    */

    struct node* root = createNode(17);

    root->left = createNode(9);
    root->right = createNode(20);

    root->left->left = createNode(8);
    root->left->right = createNode(12);

    root->right->left = createNode(18);
    root->right->right = createNode(25);

    //let's traverse the tree 
    printf("FUN-FACT: INORDER TRAVERSAL IN BST IS SORTED\nTRAVERSAL: ");
    traverse(root);
    printf("\n");

    // now search operation
    search(root,20);
    search(root,18);
    search(root,21);

    // let's insert something 
    insert(root,22); printf("\n22 is being inserted\n");
    printf("TRAVERSAL: "); traverse(root);
    insert(root,16); printf("\n16 is being inserted\n");
    printf("TRAVERSAL: "); traverse(root);
    
    // now let's perform deletion 
    root = deleteNode(root, 22);
    printf("\n22 is being deleted\n");
    printf("TRAVERSAL: ");
    traverse(root);

    root = deleteNode(root, 20);
    printf("\n20 is being deleted\n");
    printf("TRAVERSAL: ");
    traverse(root);

    root = deleteNode(root, 17);
    printf("\n17 is being deleted\n");
    printf("TRAVERSAL: ");
    traverse(root);
    printf("\n");

    return 0;
}