#include<iostream>
using namespace std;

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

void Preorder(struct Node *root) {
	if (root == NULL) return;

	printf("%c ", root->data);
	Preorder(root->left);     
	Preorder(root->right);    
}

void Inorder(Node *root) {
	if (root == NULL) return;

	Inorder(root->left);       
	printf("%c ", root->data); 
	Inorder(root->right);      
}

void Postorder(Node *root) {
	if (root == NULL) return;

	Postorder(root->left);    
	Postorder(root->right);   
	printf("%c ", root->data);
}

Node* Insert(Node *root, char data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main() {
	/*
	Creating an example tree
	M
	/ \
	B   Q
	/ \   \
	A   C   Z
	*/
	Node* root = NULL;
	root = Insert(root, 'A'); 
	root = Insert(root, 'B');
	root = Insert(root, 'D');
	root = Insert(root, 'C');
	root = Insert(root, 'E');
	root = Insert(root, 'F');
	root = Insert(root, 'I');
	root = Insert(root, 'H');

	//Print Nodes in Preorder. 
	cout << "Preorder: ";
	Preorder(root);
	cout << "\n";
	//Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";
	//Print Nodes in Postorder
	cout << "Postorder: ";
	Postorder(root);
	cout << "\n";
}
