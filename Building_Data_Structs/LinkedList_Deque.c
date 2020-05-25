/*
	Linked list deque

	This version of linked list will have double links and sentinels on the fron and back of the list

Conceptual deque operations:
	void addFront (TYPE val);
	void addBack (TYPE val);
	TYPE front();
	TYPE back();
	void removeFront();
	void removeBack();
	int isEmpty();

	Using internal methods:
	_addLink: adds a link before a given location
	_removeLink: removes its argument link

	Algorithmic complexity of each of the deque operations:
		O(1) - they are all just pointer assignment operations

*/

//Functions written for us:
struct dlink{
	TYPE value;
	struct dlink *next;
	struct dlink *prev;
}

struct linkedList{
	int size;
	struct dlink *frontSentinel;
	struct dlink *backSentinel;
}

void linkedListInit(struct linkedList *q){
	q->frontSentinel = malloc(sizeof(struct dlink));
	assert (q->frontSentinel != 0);
	q->backSentinel = malloc(sizeof(struct dlink));
	assert(q->backSentinel ! = 0);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinel;
	q->size = 0;
}

void linkedListFree(struct linkedList*q){
	while (q->size >0){
		linkedListRemoveFront(q);
	}
	free(q->frontSentinel);
	free(q->backSentinel);
	q->frontSentinel = q->backSentinel = NULL;
}

void linkedListAddFront(struct linkedList *q, TYPE val){
	_addLink(q, q->frontSentinel->next, val);
}

void linkedListAddBack(struct linkedList *q, TYPE val){
	_addLink(q, q->backSentinel, val);
}

void linkedListRemoveFront(struct linkedList *q){
	assert (!linkedListIsEmpty(q));
	_removeLink(q, q->frontSentinel->next);
}

void linkedListRemoveBack(struct linkedList *q){
	assert(!linkedListIsEmpty(q));
	_removeLink(q, q->backSentinel->prev);
}

int linkedListIsEmpty(struct linkedList *q){
	return q->size == 0;
}

/*Write addLink and removeLink
		//be sure they update the size field correctly

//addLink places a new link before the provided link
*/
void _addLink(struct linkedList *q, struct dlink *lnk, TYPE val){				//what if it's the first link? (the sentinels make it so you don't have to micromanage it)
	assert(q!=0);
	//use the link location in the argument and insert + adjust pointers
	//create link and assign values to it's elements
	struct dlink *newLink = malloc(sizeof(struct dlink));
	assert(newLink!=0);

	newLink->value = val;
	newLink->next = lnk;
	newLink->prev = lnk->prev;
	//set pointers to either side of the new link
	lnk->prev->next = newLink;
	lnk->prev = newLink;
	//adjust linked list size
	q->size++;
}

void _removeLink (struct linkdList *q, struct dlink *lnk){
	assert (q!=0);

	//struct dlink *temp = lnk;		not necessary since you have the *lnk in the argument you can just free that.

	lnk->next->prev = lnk->prev;
	lnk->prev->next = lnk->next;

	free(lnk);
	lnk = 0;

	q->size--;
}

TYPE linkedListFront(struct linkedList *q){
	assert (q!=0);
	//also want to be sure the list isn't empty
	assert(!linkedListIsEmpty(q));
	return q->frontSentinel->next->value;

}

TYPE linkedListBack(struct linkedList *q){
	assert (q!=0);
	assert(!linkedListIsEmpty(q));

	return q->backSentinel->prev->value;
}
