#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  
    if(root->left != NULL){
        traverseInOrder(root->left);
    }
    cout<<" "<<root->key;
    if(root->right != NULL){
        traverseInOrder(root->right);
    }
    
}

// Insert a node
struct node *insertNode(struct node *node, int key) {


    
    if(node == NULL){
        struct node *nodeFirst = new struct node;
        nodeFirst->key = key;
        return nodeFirst;
    }

    if(node->key > key){
        node->left = insertNode(node->left,key);
    }
    else{
        node->right = insertNode(node->right,key);
    }

    return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

    // Base Case
    if(key == root->key && root->left == NULL && root->right == NULL){
        return NULL;
    }

    if(key < root->key){
        if(root->left->key == key){
        root->left = root->left->left;
        return root;
        }
        else{
            deleteNode(root->left,key);
        }
    }


    return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}

