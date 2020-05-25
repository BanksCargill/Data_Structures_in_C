/*

Linked list queue, pointer to tail (sentinel)

Queue: elements added to one end and removed from the other
firstLink and lastLink pointers used to track
	both set to null when list is empty


*/

struct link{
	TYPE value;
	struct link *next;
}

struct listQueue{
	struct link *firstLink;
	struct link *lastLink;
}

void listQueueInit(struct listQueue *q){
	struct link *lnk = malloc(sizeof(struct link));
	assert(lnk!=0) //lnk is the sentinel
	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}

//function above were provided

void listQueueAddBack(struct listQueue *q, TYPE value){
	assert (q!=0);

	//creating new link, assigning values and asserting its creation
	struct link *newLink = malloc(sizeof(struct link));
	newLink->value = value;
	newLink->next = 0; //0 or NULL
	assert (newLink!=0);

	//set lastLink's next to the newLink, then set lastLink to newLink
	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

TYPE listQueueFront (struct listQueue *q){
	assert (q!=0);
	assert(!listQueueIsEmpty(q));

	return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue*q){																					//PRACTICE WRITING THIS FUNCTION AGAIN
	assert (q!=0);
	assert(!listQueueIsEmpty(q));

	struct link *temp = q->firstLink->next;

	//this is where we need to deal with the potential of an empty list, resetting first and last links to sentinel
//	if (q->firstLink->next->next == NULL){ //queue will be empty after removal
				//this works too. Checking to see if the links next is null which would indicate it is the last link in the queue

	if (q->firstLink->next == q->lastLink){ //queue will be empty after removal
		q->lastLink = q->firstLink;
		q->firstLink->next = NULL;
	}
	else{
		q->firstLink->next = q->firstLink->next->next;
	}
	free(temp);
	temp = 0;
}

int listQueueIsEmpty(struct listQueue *q){
	assert(q!=0);
	if (q->firstLink != q->lastLink)
		return 1;
	return 0;
}

/* Questions:
Algorithmic complexity of each of the queue operations:

addBack: O(1)
front: O(1)
removeFront: O(1)
isEmpty: O(1)

How difficult would it be to write the method addFront(newValue) that inserts a new element into
the front of the collection?
	Not very difficult.
		pseudocode: create new link
								set newLink->next = to firstLink->next
								set firstLink->next = newLink;

Why would removing the value from the back be difficult for this container?
	Since the links do not have pointers to previous links, you would need to travers the entire list
	to find the penultimate link, adjust it's next pointer and set lastLink to point to it. You could then safely remove the link

	-Answer from instructors: If we removed the last node we would need to set the "next" point of the previous node to NULL. In order to do that we
														need to be able to address the previous to last node. No direct way to get that address other than raversing the entire
														queue from beginning to almost end.
What would the algorithmic complexity of the removeLast operation be?
	O(n)
*/
