/*	DynArrStack:
		Uses partially filled array (size doesn't have to be specified when array created)
		New element inplemented to keep track of the number of elements in the array that have been filled (dataSize)
		pop & top have algorithmic complexity of O(1)
		push has best case O(1), worst case O(n) when resizing is necessary

	Stack, Queue, Deque
		All maintain values in the order they were inserted

*/

#ifndef TYPE
#define TYPE int
#endif
/*
DynArrStack - implemented using previously defined functions

Questions:
1. What is the algorithmic execution time for pop and top
	O(1)
2. Push, assuming there is sufficient capacity for the new elements.
	O(1)
3. _dynArraySetCapacity?
	O(n)
4. Push, assuming that a new array must be created?
	O(n)

//write functions for : push, pop, top, and isEmpty
		//use assertions to check that the stackhas at least one element when the functions top or pop are called
*/
void dynArrPush(struct DynArr *array, TYPE value){
	assert(array != 0);
	addDynArr(array, value);
}

void dynArrPop(struct DynArr *array){
	assert(array != 0);
	assert(array->size>0);

	removeAtDynArr(array, array->size-1);
}

TYPE dynArrTop(struct DynArr *array){
	assert(array != 0);
	assert(array->size > 0);

	return getDynArr(array, array->size-1);
}

int dynArrIsEmpty(struct DynArr *array){
	assert(array != 0);

	if(array->size <=0){
		return 1;
	}
	else{
		return 0;
	}
}
