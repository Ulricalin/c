#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define EMPTY_ELE '#'

class BinaryTree {
public:
    struct Node {
        char val;
        Node* left;
        Node* right;
        Node(char v, Node* l = NULL, Node* r = NULL):
        val(v), left(l), right(r) {
        }
    };
BinaryTree::BinaryTree(const BinaryTree& other) {
	root = NULL;
	root = copyNode(other.root, root);
}
BinaryTree::BinaryTree(std::vector<char>& other) {
	queue<Node*> que;
	int size = other.size();
	if (size == 0 || other[0] == EMPTY_ELE) {
		root = NULL;
	} else {
		root = new Node(other[0]);
		que.push(root);
		int index = 1;
		Node* temp;
		while (index < size && !que.empty()) {
			temp = que.front();
			que.pop();
			if (other[index] != EMPTY_ELE) {
				temp->left = new Node(other[index]);
				que.push(temp->left);
			}
			index++;
			if (index >= size) break;
			if (other[index] != EMPTY_ELE) {
				temp->right = new Node(other[index]);
				que.push(temp->right);
			}
			index++;
		}
	}
}
// created by preorder and inorder
BinaryTree::BinaryTree(const std::vector<char>& preOrder,
           const std::vector<char>& inOrder) {
	
}
BinaryTree::~BinaryTree() {
	clear();
}

Node* BinaryTree::getRoot() const {return root;}
void BinaryTree::clear() {
    queue<Node*> que;
    if (root != NULL) {
    	que.push(root);
    }
    Node* temp;
    while (!que.empty()) {
    	temp = que.front();
    	que.pop();
    	if (temp->left != NULL) {
    		que.push(temp->left);
    	}
    	if (temp->right != NULL) {
    		que.push(temp->right);
    	}
    	delete temp;
    }
    root = NULL;
}

void BinaryTree::preOrder(void (*visite)(BinaryTree::Node*), Node* root_) {
	if (root_ == NULL) return;
	visite(root_);
	preOrder(visite, root_->left);
	preOrder(visite, root_->right);
}
void BinaryTree::inOrder(void (*visite)(BinaryTree::Node*), Node* root_) {
    if (root_ == NULL) return;
	preOrder(visite, root_->left);
	visite(root_);
	preOrder(visite, root_->right);
}
void BinaryTree::postOrder(void (*visite)(BinaryTree::Node*), Node*) {
	if (root_ == NULL) return;
	preOrder(visite, root_->left);
	preOrder(visite, root_->right);
	visite(root_);
}
    


Node * BinaryTree::copyNode(Node * oldNode, Node * newNode) {
	if (oldNode == NULL) {
		newNode = NULL;
		return newNode;
	} else {
		newNode = new Node(oldNode->val);
		newNode->left = copyNode(oldNode->left, newNode->left);
		newNode->right = copyNode(oldNode->right, newNode->right);
	}
}
