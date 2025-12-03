//Depth First Search
#include<iostream>

using namespace std;

class Node{
	public:
	int value;
	Node *leftNode = NULL;
	Node *rightNode = NULL;

	Node(int value, Node *leftNode, Node *rightNode){
		this->value = value;
		this->leftNode = leftNode;
		this->rightNode= rightNode;
	}
};


Node *dfs(Node *root, int targetVal){
	if(root != NULL && root->value == targetVal){
		return root;
	}

	Node *leftNode;
	Node *rightNode;
	if(root->leftNode) leftNode = dfs(root->leftNode, targetVal);
	if(root->rightNode) rightNode = dfs(root->rightNode, targetVal);

	if(leftNode) return leftNode;
	if(rightNode) return rightNode;

	return NULL;
}

Node *recursiveFill(Node *node, int value){
	if(value < 15){
		node->leftNode = recursiveFill(new Node(value, NULL, NULL), value+1);
		node->rightNode = recursiveFill(new Node(value+2, NULL, NULL), value+3);
	}
	return node;
}


int main(){
	
	Node *binaryTree = recursiveFill(new Node(0, NULL, NULL), 1);
	cout << binaryTree->value << endl;
	Node *foundNode = dfs(binaryTree, 6);
	if(foundNode) cout << "found: " << foundNode->value << endl;
	delete binaryTree;
	return 0;

}