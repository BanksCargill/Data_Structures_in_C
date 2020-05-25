/* Constructing a bag using a linked list

Bag: add, contains, remove

Contains: Loops over links, returns true if it's found
Remove: Loops over links, if a matching value is found, _removeLink is called
Add: Adds new value to front

This implementation is for a double linked list with 2 sentinels
*/

struct dLink{
	TYPE value;
	struct dLink *next;
	struct dLink *prev;
}

struct linkedList{
	struct dLink *frontSentinel;
	struct dLink *backSentinel;
}


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

	lnk->next->prev = lnk->prev;
	lnk->prev->next = lnk->next;

	free(lnk);
	lnk = 0;

	q->size--;
}

int linkedListContains(struct linkedList *lst, TYPE val){		//the sentinels are links in this ADT, next and prev of first and last link point to sentinels
	assert (lst!=0);
	assert (!linkedListIsEmpty(lst));
	//loop through list, return 1 if found, 0 if not
	struct dlink *temp = lst->frontSentinel->next;
	while(temp!=lst->backSentinel){
		if (temp->value = val){
			return 1
		}
		temp = temp->next;
	}
	return 0;
}

void linkedListRemove (struct linkeList *lst, TYPE val){
	assert (lst!=0);
	assert (!linkedListIsEmpty(lst));

	struct dlink *temp = lst*frontSentinel->next;
	while (temp != lst->backSentinel){
			if(temp->value == val){
				_removeLink(lst, temp);
				return;
			}
			temp = temp->next;
	}
}
/*
What are the algorithmic complexities of the three principle Bag operations?

Add:
	O(1)
Contains:
	Best case: O(1) if it's the first link in the list
	worst and average case: O(n)
Remove:
	Best case: O(1) if it's the first link in the list
	worst and average case: O(n)
*/
