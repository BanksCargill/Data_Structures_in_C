
/*
Worksheet 29

BST: every nodes value is greater than all nodes L
			Every nodes value is less than all nodes R

Vocabulary:
Leaf
Length: # of arcs traversed
Height: max length to leaf
Depth: length from root to node
Siblings: nodes that have the same parent node
Balanced

FULL binary tree: every leaf at same depth
									every internal node has 2 childern

Complete Binary Tree: full except for bottom level, filled from L to R

Application: animal game
	start at root, asking a yes or no question
		yes, go left and repeat
		no, go right and repeat
			if leaf node, guess: is it a...
				If correct: done
				otherwise: ask a question that distinguishes the new animal from the guess
*/

struct node{
	TYPE value;
	struct node *left;
	struct node *right;
};

struct BinarySearchTree{
	struct node *root;
	int size;
};

void initBST (struct BinarySearchTree *tree){
	tree->size = 0;
	tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue){
	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}

int sizeBST(struct BinarySearchTree *tree){
	return tree->size;
}

//Our code below

struct Node *_nodeAddBST (struct Node *current, TYPE newValue){
	struct Node *node;
	//if current is leaf
	if (current==0){
		//create node
		node = (struct Node *)malloc(sizeof(struct Node));
		assert (node!=0);		//ensure it's proper creation

		//set it's value and its childrens values
		node->value = newValue;
		node->left = node->right = 0;

		return node;
	}
	//recursive call if less than current's value
	else if (newValue<current->value){
		current->left = _nodeAddBST(current->left, newValue);
	}
	//recursive call if greater than current's value
	else{
		current->right = _nodeAddBST(current->right, newValue);
	}

	return current;
}

int containsBST (struct BinarySearchTree *tree, TYPE d){
	struct Node *curr = tree->root;

	//loop until d is found (return statement) or current is NULL/0 (not found)
	while(curr !=0){
		if(d==curr->value){
			return 1;	//value found
		}
		else if (d<curr->value){
			curr = curr->left;	//go left
		}
		else{
			curr = curr->right;	//go right (dependent on the value 'd')
		}
	}
	return 0;	//value not found, return false
}

//Provided function

void removeBST (struct BinarySearchTree *tree, TYPE d){
	if(containsBST(tree, d)){
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}
}

//Our code below

TYPE _leftMostChild (struct Node *current){
	//traverse tree until finding leftmostChild
	while (current->left!=0){
		current = current->left;
	}
	return current->val;
}

struct Node *_removeLeftmostChild(struct Node *current){
	struct Node *node;

	//recursive base case
	if(current->left == 0){
		node = current->right;
		free(current);
		return node;
	}
	//recursive
	else{
		current->left = _removeLeftmostChild(current->left);
		return current;
	}
}

struct Node *_nodeRemoveBST(struct Node *current, TYPE d){
	struct Node *node;

	//if value is found
	if(current->value == d){
			//Special case: No right child to the removal node, return left child
			if (current->right == 0){
				node = current->left;
				free(current);
				return node;
			}
			else{
				//current is replaced by leftmost child of right branch
				current->value = _leftMostChild(current->right);
				//remove leftmost child of right branch
				current->right = _removeLeftmostChild(current->right);
			}
	}
	//value not found: call function on left and right childern of the root
	else if(current->value < d){
			current->right = _nodeRemoveBST(current->right, d);
	}
	else{
			current->left = _nodeRemoveBST(current->left, d);
	}
//I DON'T UNDERSTAND THIS RETURN STATEMENT
	return current;
}
