#include <iostream>

struct TNode {
	int data;
	TNode* left;
	TNode* right;
};

struct BinaryTree {
	TNode* root;
};

void push(BinaryTree &tree, int data) {
	TNode* node = new TNode;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	if (tree.root == nullptr) {
		tree.root = node;
		return;
	}

	TNode* root = tree.root;
	while (root != nullptr) {
		if (data <= root->data) {
			if (root->left != nullptr) {
				root = root->left;
			}
			else {
				root->left = node;
				break;
			}
		}
		else {
			if (root->right != nullptr) {
				root = root->right;
			}
			else {
				root->right = node;
				break;
			}
		}
	}
}

void printbinarytree(BinaryTree &tree) { //Function of printing 4 levels of Binary Tree 
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Binary Tree  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	if (tree.root != nullptr) {
		int* tempnodetracker = new int[6]{ 0, 0, 0, 0, 0, 0 };
		std::cout << "\t\t\t\t\t" << tree.root->data << "\t\t\t\t\t" << std::endl;


		if (tree.root->left != nullptr) { std::cout << "\t\t" << tree.root->left->data << "\t\t\t\t\t\t"; }
		else {
			TNode* node = new TNode; // making aditionals nodes with system data = -999999999( can be another number ) on ends of tree 
			node->data = -999999999; //for not showing that nodes and not have problemes with nullptr adressing that not exists
			node->left = nullptr;
			node->right = nullptr;
			tree.root->left = node;
			tempnodetracker[0] = 1;
			std::cout << "\t\t\t\t  \t\t\t\t"; }
		if (tree.root->right != nullptr) { std::cout << tree.root->right->data << "\t\t\t\t"; }
		else { 
			TNode* node1 = new TNode;
			node1->data = -999999999;
			node1->left = nullptr;
			node1->right = nullptr;
			tree.root->right = node1;
			tempnodetracker[1] = 1;
			std::cout << "  \t\t\t\t"; }
		std::cout << std::endl;
		

		if (tree.root->left->left != nullptr && tree.root->left->left->data != -999999999) { std::cout << "\t" << tree.root->left->left->data << "\t";}
		else {
			TNode* node2 = new TNode;
			node2->data = -999999999;
			node2->left = nullptr;
			node2->right = nullptr;
			tree.root->left->left = node2;
			tempnodetracker[2] = 1;
			std::cout << "\t  \t"; }
		if (tree.root->left->right != nullptr && tree.root->left->right->data != -999999999) { std::cout << "\t" << tree.root->left->right->data << "\t"; }
		else { 
			TNode* node3 = new TNode;
			node3->data = -999999999;
			node3->left = nullptr;
			node3->right = nullptr;
			tree.root->left->right = node3;
			tempnodetracker[3] = 1;
			std::cout << "\t  \t"; }
		if (tree.root->right->left != nullptr && tree.root->right->left->data != -999999999) { std::cout << "\t\t\t" << tree.root->right->left->data << "\t"; }
		else { 
			TNode* node4 = new TNode;
			node4->data = -999999999;
			node4->left = nullptr;
			node4->right = nullptr;
			tree.root->right->left = node4;
			tempnodetracker[4] = 1;
			std::cout << "\t\t\t  \t"; }
		if (tree.root->right->right != nullptr && tree.root->right->right->data != -999999999) { std::cout << "\t" << tree.root->right->right->data << "\t"; }
		else { 
			TNode* node5 = new TNode;
			node5->data = -999999999;
			node5->left = nullptr;
			node5->right = nullptr;
			tree.root->right->right = node5;
			tempnodetracker[5] = 1;
			std::cout << "\t  \t"; }
		std::cout << std::endl;

		if (tree.root->left->left->left != nullptr) { std::cout << "    " << tree.root->left->left->left->data << "\t"; }
		else { std::cout << "      \t"; }
		if (tree.root->left->left->right != nullptr) { std::cout << "    " << tree.root->left->left->right->data << "\t"; }
		else { std::cout << "      \t"; }
		if (tree.root->left->right->left != nullptr) { std::cout << "    " << tree.root->left->right->left->data << "\t"; }
		else { std::cout << "      \t"; }
		if (tree.root->left->right->right != nullptr) { std::cout << "    " << tree.root->left->right->right->data << "\t"; }
		else { std::cout << "      \t"; }
		if (tree.root->right->left->left != nullptr) { std::cout << "  \t  \t   " << tree.root->right->left->left->data << "\t"; }
		else { std::cout << "  \t  \t  \t  "; }
		if (tree.root->right->left->right != nullptr) { std::cout << "     " << tree.root->right->left->right->data << "\t"; }
		else { std::cout << "     \t"; }
		if (tree.root->right->right->left != nullptr) { std::cout << "    " << tree.root->right->right->left->data << "\t"; }
		else { std::cout << "    \t"; }
		if (tree.root->right->right->right != nullptr) { std::cout << "    " << tree.root->right->right->right->data << "\t"; }
		else { std::cout << "      \t"; }
		std::cout << std::endl;

		if (tempnodetracker[5] != 0) {
			delete tree.root->right->right; // Why cant use delete node5???
			tree.root->right->right = nullptr;
		}
		if (tempnodetracker[4] != 0) {
			delete tree.root->right->left;
			tree.root->right->left = nullptr;
		}
		if (tempnodetracker[3] != 0) {
			delete tree.root->left->right;
			tree.root->left->right = nullptr;
		}
		if (tempnodetracker[2] != 0) {
			delete tree.root->left->left;
			tree.root->left->left = nullptr;
		}
		if (tempnodetracker[1] != 0) {
			delete tree.root->right;
			tree.root->right = nullptr;
		}
		if (tempnodetracker[0] != 0) {
			delete tree.root->left;
			tree.root->left = nullptr;
		}
		delete [] tempnodetracker;
	} 
	else {
		std::cout << "\t\t\t ! Empty Binary Tree ! \t\t\t" << std::endl;
	}
}

TNode* findnode(TNode* root, int data) {
	if (root == nullptr)
	{
		return nullptr;
	}
	else {
		if (data == root->data) {
			return root;
		}
		else if (data < root->data) {
			return findnode(root->left, data);
		}
		else {
			return findnode(root->right, data);
		}
	}
}

int main(){
	BinaryTree tree;
	tree.root = nullptr;
	//pushing first data set
	for (int e : {50, 30, 70, 20, 40, 60, 80}) { //Sample good looking set {50,30,70,20,40,60,80,10,25,35,45,55,65,75,85}
		push(tree, e);
	}
	printbinarytree(tree);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	std::cout << "\t\t\t    Pushing aditional data set...\n";

	//pushing editional data set
	for (int e : {10, 25, 35, 45, 55, 65, 75, 85}) { //Sample good looking set {50,30,70,20,40,60,80,10,25,35,45,55,65,75,85}
		push(tree, e);
	}
	printbinarytree(tree);

	//example1
	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	std::cout << "\t\t     Trying to find node with number \"75\" in data \n";
	TNode* example1 = findnode(tree.root, 75);
	if (example1 != nullptr) {
		std::cout << "\t\t     Node finded and returned, node->data is {" << example1->data << "}\n\n";
	}
	else {
		std::cout << "\t\t     Node with such data not finded! \n\n";
	}

	//example2
	std::cout << "\t\t     Trying to find node with number \"11\" in data \n";
	TNode* example2 = findnode(tree.root, 11);
	if (example2 != nullptr) {
		std::cout << "\t\t     Node finded and returned, node->data is {" << example2->data << "}\n\n";
	}
	else {
		std::cout << "\t\t     Node with such data not finded! \n\n\n";
	}

	return 0;
}
