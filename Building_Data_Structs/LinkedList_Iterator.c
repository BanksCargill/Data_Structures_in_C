
/*LinkedList Iterator

Double linked list with 2 sentinels (dlinks)

Reminder of
struct linkedList{
	struct dLink *frontSentinel;
	struct dLink *backSentinel;
}

struct dLink{
	int value;
	struct dLink *next;
	struct dLink *prev;
}

*/

struct linkedListIterator{
	struct linkedList *lst;
	struct dLink *currentLink;
}

void linkedListIteratorIni(struct linkedList *lst, struct dLink *lnk){
	itr->lst = lst;
	itr->currentLink = itr->lst->frontSentinel;
}

void _removeLink (struct linkedList *lst, struct dLink *lnk);

int linkedListIteratorHasNext(struct linkedListIterator *itr){
	assert (itr!=0);

	int existsNext = 0;
	//if next is not the back sentinel, there is a next link
	if(itr->currentLink->next != itr->lst->backSentinel){
		existsNext = 1;
	}
	return existsNext;
}

TYPE linkedListIteratorNext(struct linkedListIterator *itr){
	assert (itr!=0);

	itr->currentLink = itr->currentLink->next;
	return itr->currentLink->value;
}

//think about what itr->currentLink should be pointing to after the remove operations
void linkedListIteratorRemove(struct linkedListIterator *itr){
	assert (itr!=0);

	struct dLink *temp = itr->currentLink;

	itr->currentLink = itr->currentLink->prev;

	_removeLink(itr->lst, temp);
}
