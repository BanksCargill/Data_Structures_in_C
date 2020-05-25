/*

Conceptual interface:
	Boolean hasNext();
	TYPE next();
	void remove();

*/

struct dynArrayIterator{
	struct dynArray *array;
	int currentIndex;
}

removeAtDynArr(struct DynArr *array, int index){
	assert (array != 0 && array->size !=0);
	assert (index >= 0 && index < array->size);

	for (int i = index; i < size; i++){	//Watch out for misunderstand on "size" vs "size-1" ( < vs. <= )
		array->data[i] = array->data[i+1];	//putDynArr(array, i, getDynArr(array, i+1));
	}
	array->size--;
}

void dynArrayIteratorInit(struct dynArray *array, struct dynArrayIterator *itr){
	assert(array!=0);
	assert(itr!=0);

	itr->array = array;
	itr->currentIndex = -1; //setting it up for the hasNext -> next movement from beginning of array
}

//hasNext: ask iterator, does the list have another element to traverse to
int dynArrayIteratorHasNext(struct dynArrayIterator *itr){
	assert (itr!=0);

	//if current index is less than the array's size-1, there is another element
	if(itr->currentIndex < itr->array->size-1){
		return 1;
	}
	else{
		return 0;
	}
}
//request return of the next element
TYPE dynArrayIteratorNext (struct dynArrayIterator *itr){
	assert (itr!=0);

	itr->currentIndex++;
	return itr->array->data[currentIndex];
}

//option to remove element as the user is traversing the ADT
void dynArrayIteratorRemove(struct dynArrayIterator *itr){
	assert (itr!=0);

	removeAtDynArr(itr->array, currentIndex);
	itr->currentIndex--;	//check this- I think since you are removing an element, you want to then decrement the 						CORRECT LOGIC
												//currentIndex so that hasNext and Next direct you to the node after the removed node
												//that has taken its place due to the slide effect of removeAtDynArr
}
