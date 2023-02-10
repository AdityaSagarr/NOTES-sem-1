#include <iostream>
#include <queue>
using namespace std;


struct Node{
int data;
Node *left;
Node *right;
Node(int val): data(val), left(nullptr), right(nullptr){} 
~Node() {}
};

void inorder (Node *root){ 
if (!root)
return; 
inorder (root->left);
std::cout << root->data << "\t"; inorder (root->right);
inorder(root->right);
}

void remove_node (Node *root, Node *n) {
if(root == nullptr)
return;
if (root == n){
delete n; 
root = nullptr;
return;
} 
if(root->left == n){
delete n; 
root->left = nullptr;
return;
} 
if(root->right == n){
delete n; 
root->right = nullptr;
return;
}
remove_node(root->left, n); 
remove_node(root->right, n);
}

Node* delete_node (Node *root, int key)
{
 if(root == nullptr) 
 		 return nullptr;

 if(!root->left && !root->right) {
    if(root->data == key){
	delete root; 
	root = nullptr;
}
return root;
}
std::queue<Node *>Q;
Q.push(root);

Node *key_node=nullptr;
Node *curr_node=nullptr;

while (!Q.empty()){
curr_node = Q.front (); 
Q.pop();

if (curr_node->data == key){ 
key_node = curr_node;
}
if(curr_node->left) 
Q.push(curr_node->left);

if (curr_node->right) 
Q.push(curr_node->right);
}

if(key_node) {
key_node->data = curr_node->data; 
//remove the last node remove_node(root, curr_node);
remove_node(root,curr_node);
}

return root;

}

int main() {

Node *n1 = new Node (1);
Node *n2 = new Node (2);
Node *n3 = new Node (3);
Node *n4 = new Node (4);
Node *n5= new Node (5);
Node *n6= new Node (6);

n1->left = n2;
n1->right = n3;
n2->left = n4;
n3->left = n5;
n4->right = n6;

Node *root = n1;

inorder (root); 
std::cout << endl;

root = delete_node(root, 3);

inorder (root);
std::cout << endl;

return 0;
}
