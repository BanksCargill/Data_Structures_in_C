/*
AVL Trees: self-balancing BST, difference between heights of left and right subtrees cannot be more than one for all nodes

WHY AVL: able to guarantee a upper bound of O(logn) for all operations
height of AVL tree: always O(logn) where n is the number of nodes in the tree

Rotations!
Single or double rotation:
Pseudocode:
If Left child/subtree is tallest (by more than one)
	if left child is heavy on right side (double rotation needed)
		rotate Left child to the left
	Rotate unbalanced node(top) to the right
Else if R child is tallest
	if right child is heavy on the left side (double rotation needed)
		rotate R child right
	Rotate Unbalanced node (top) to the left


Heavy: height of subtree is taller than other subtree
Rotations can be a result of adding or removing

*/

struct AVLnode {
   TYPE value;
   struct AVLnode *left;
   struct AVLnode *right;
   int height;
};

int _h(struct AVLnode * current){
	 if (current == 0) return -1;
	 return current->height;
}

void _setHeight (struct AVLnode * current) {
   int lch = _h(current->left);
   int rch = _h(current->right);
   if (lch < rch) current->height = 1 + rch;
   else current->height = 1 + lch;
}

struct AVLnode * _AVLnodeAdd (struct AVLnode* current, TYPE newValue) {
  struct AVLnode * newnode;
  if (current == 0) {
		newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
    assert(newnode != 0);
    newnode->value = newValue;
    newnode->left = newnode->right = 0;
    return newnode;  //no need to balance since it is the only node in the tree
  }
	else if (LT(newValue, current->value))
      current->left = _AVLnodeAdd(current->left, newValue);
  else current->right = _AVLnodeAdd(current->right, newValue);
  return _balance(current);    /* <-   NEW  the call on balance */
}

//returns balance factor  = rightHeight-leftHeight
int _bf (struct AVLnode * current) {
	return _h(current->right) - _h(current->left);
}

struct AVLnode * _balance (struct AVLnode * current) {
  int cbf = _bf(current);
  if (cbf < -1) {
    if (_bf(current->left) > 0) // double rotation
      current->left = _rotateLeft(current->left);
    return _rotateRight(current); // single rotation
  } else if (cbf > 1) {
      if (_bf(current->right) < 0)
        current->right = _rotateRight(current->right);
			return _rotateLeft(current);
  }
	_setHeight(current);
  return current;
}

//Both of these should call setHeight on the new interior node that has been changed on the new root
//returns a pointer to ...
struct AVLnode *_rotateRight(struct AVLnode *current){
	struct AVLnode *newTop = current->left;
	current->left = newTop->right;
	newTop->right = current;
	_setHeight(current);
	_setHeight(newTop);
	return newTop;
}

struct AVLnode *_rotateLeft(struct AVLnode *current){
	struct AVLnode *newTop = current->right;
	current->right = newTop->left;
	newTop->left = current;
	_setHeight(current);
	_setHeight(newTop);
	return newTop;
}


void removeAVLTree(struct AVLTree *tree, TYPE val) {
  if (containsAVLTree(tree, val)) {
    tree->root = _removeNode(tree->root, val);
    tree->cnt--;
  }
}

TYPE _leftMost(struct AVLNode *cur) {
  while(cur->left != 0) {
    cur = cur->left;
  }
  return cur->val;
}

struct AVLNode *_removeLeftmost(struct AVLNode *cur) {
	struct AVLNode *temp;

  if(cur->left != 0)
  {
    cur->left = _removeLeftmost(cur->left);
    return _balance(cur);
  }

  temp = cur->rght;
  free(cur);
  return temp;
}

//Assume you have access to removeLeftMost and LeftMost which we have already written for the BST.

struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
	assert(cur);
	assert(val!=NULL);

	struct AVLNode *temp;
	//basecase: node found
	if(cur->val ==val){
		//nothing to the right of it
		if(cur->right ==NULL){
			temp=cur->left;
			free(cur);
			return temp;
		}
		//node to the right
		else{
			//set current to its rightchilds leftmost
			cur->val = _leftMost(cur->right);
			//remove that node^
			cur->right = _removeLeftmost(cur->right);
		}
	}
	//search left for node
	else if(val<cur->val){
		cur->left = _removeNode(cur->left, val);
	}
	//search right for node
	else{
		cur->right=_removeNode(cur->right, val);
	}
	//check if a balance is necessary after each return
	return _balance(cur);


}
