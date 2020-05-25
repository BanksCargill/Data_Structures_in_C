/*
 BST iterator
*/

struct BSTIterator{
	struct DynArr *stk;
	struct BSTree *tree;
}

void BSTIteratorInit (struct BSTree *tree, struct BSTIterator *itr){
	itr->stk=createDynArr();
	assert(itr->stk);

	itr->tree=tree;
}

int BSTIteratorHasNext(struct BSTIterator *itr){
	Node *n;
	if(isEmptyDynArr(itr->stk)){
		_slideLeft(itr->tree->root);
	}
	else{
		n=topDynArr(itr->stk);
		popDynArr(itr->stk;
		_slideLeft(n->right);
	}
	if(!isEmptyDynArr(itr->stk)){
		return 1;
	}
	else{
		return 0;
	}
}

TYPE BSTIteratorNext(struct BSTIterator *itr){
	return (topDynArr(itr->stk))->val;
}

void _slideLeft(struct Node *cur, struct BSTIterator *itr){
	while(cur!=NULL){
		dynArrayPush(itr->stk, cur);
		cur=cur->left;
	}
}
