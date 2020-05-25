/*
Linked list and List Stack
*/

struct link {
	TYPE value;
	struct link *next;
}

struct linkedListStack{
	struct link *firstLink;
}

void initLinkedListStack(struct linkedListStack *stack){
	stack->firstLink = 0;
}

void freeLinkedListStack(struct linkedListStack *stack){
	while (!isEmptyLinkedListStack(stack)){
		linkedListStackPop(stack);
	}
}

/*

Each operation should have constant time performance
Use assert statements to ensure that when a top or pop is performed the stack has at least one element
When pop is used, make sure you free the link field

Study Notes:

firstLink is a pointer to a link. It will always point to either null/0 or the first link

*/

void pushLinkedListStack(struct linkedListStack *stack, TYPE value){
	struct link *newLink = malloc(sizeof(struct link));
	assert (newLink != 0);
	newLink->value = value;
	//ensure stack has been initialized
	assert (stack!= 0);

	if (stack->firstLink == 0){	//if stack is empty
		newLink->next = 0;
	}
	else{
		newLink->next = stack->firstLink;
	}
	stack->firstLink = newLink;
}

TYPE topLinkedListStack (struct linkedListStack *stack){
	assert (!stack->firstLink == 0);	//ensuring that the stack is not empty [assert(!isEmptyLinkedListStack(stack));]
	assert(stack!=0);
	return stack->firstLink->value;
}

void popLinkedListStack(struct linkedListStack *stack){
	assert (stack!=0)
	assert (!stack->firstLink == 0);	//assert(!isEmptyLinkedListStack(stack));

	//set temp link  equal to first link
	struct link *tempLink = stack->firstLink;

	//if list is empty at this point, the next will be nulling, resetting firstLink to 0/NULL
	stack->firstLink = stack->firstLink->next;
	//free the old first link and set to null
	free(tempLink);
	tempLink = 0;
}

int isEmptylinkedListStack(struct linkedListStack *stack){
	assert (stack!=0);

	if (stack->firstLink == 0){
		return 1;
	}
	else{
		return 0;
	}
}
