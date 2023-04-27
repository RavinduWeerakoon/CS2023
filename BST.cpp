#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//create function to create a node for a give data
node * create(int key){
  node * n = new node;
  n -> key = key;
  n->left = NULL;
  n->right = NULL;
  return n;
}

// Inorder traversal
void traverseInOrder(struct node *root) {

  if(root == NULL) return;

  traverseInOrder(root->left);
  cout << root -> key<< " ";
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  if(node == NULL){
    return create(key);
  }

  if (key <= node ->key){
    node->left = insertNode(node->left, key);
  }else{
    node->right = insertNode(node->right, key);
  }


  return node;

}

node* findMin(node* root){
        if(root->left==NULL){
            return root;
        }
        return findMin(root->left);
    }
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
        //search until the item is being found
        if(root == NULL) return root;
        else if(root->key>key) root-> left=deleteNode(root->left, key);

        else if(root->key<key) root->right = deleteNode(root->right, key);

        else{ //I founcd you,  it's showtime

            if(root-> left == NULL && root->right == NULL){
                delete root;
                root == NULL;
            }else if(root-> left==NULL){
                node* temp = root;
                root = root -> right;
                delete temp;
            }else if(root -> right==NULL){
                node* temp = root;
                root = root->left;
                delete temp;
            }else{
                node *temp = findMin(root->right);

                root ->key = temp -> key;
                deleteNode(root->right, temp->key);
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
 
  return 0;

}



