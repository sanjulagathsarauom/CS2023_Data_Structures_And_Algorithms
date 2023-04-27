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



    if(key < root->key){
        root->left = deleteNode(root->left,key);
        return root;
    }
    else if(key > root->key){
        root->right = deleteNode(root->right,key);
        return root;
    }

    // Base Case
    if(key == root->key && root->left == NULL && root->right == NULL){
        return NULL;

    }
    else if(key == root->key && root->left != NULL && root->right == NULL ){
        cout<<"came";
        root->key = root->left->key;
        root->left = root->left->left;
        root->right = root->left->right;
        cout<<"gone";
        return root;
    }
    else if(key == root->key && root->left == NULL && root->right != NULL){
        root->key = root->right->key;
        root->right = deleteNode(root->right,root->right->key);
        //cout<<" Node deleted from left"<<endl;
        return root;

    }
    else if(key == root->key && root->left != NULL && root->right != NULL){
        root->key = root->right->key;
        root->right = deleteNode(root->right,root->right->key);
        //cout<<" Node deleted from right"<<endl;
        return root;
    }
    else{
        cout<<" Enter deletable Node key : Exit with Error of User Input"<<endl;
    }


exit(0);

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

