/*Ordered Bag using a Sorted Array

Binary search used

When adding, binary search is invoked to find where to add the element,
then everything has to be moved over to make room for the element addition.
Finally, the element can be added to the array.

Memorize chart with O() execution times:

				Dynamic Array Bag					LinkedList Bag					Ordered Array Bag
Add						O(1+)										O(1)										O(n)
Contains			O(n)										O(n)										O(log n)
Remove				O(n)										O(1)										O(n)
*/

//method addAt much check that the size is less than capacity
//loop over elements to open a hole for the new value,
//insert element into hole
//update variable count

void dynArrayAddAt (struct dynArray *array, int index, TYPE newElement){
	assert (index >= 0 && index <= array->size);	//should be: index < array->size
	if (array->size >= array->capacity){
		dynArrayDoubleCapacity(array);
	}
	//just shifting elements from passed index over and inserting newElement in this function
	for (int i = array->size-1; i>=index; i--){
		array->data[i+1] = array->data[i];
	}
	array->data[index] = newElement;
	array->size++;
}

//_binarySearch is included as internal function for these

int orderedArrayContains(struct dynArray *array, TYPE value){
	//boolean function
	assert(array!=0);
	assert(array->size!=0);

	int index= binarySearch(array->data, array->size, value);
	if(index<0 || index>array->size || array->data[index]!=value){
		return 0;
	}
	else{
		return 1;
	}
	/* This would be O(n), negating the benefit of having the array sorted
	for (int i = 0; i<size; i++){
		if(array->data[i]==value){
			valueFound=1;
		}
	}
	return valueFound;
	*/
}

void orderedArrayRemove(struct dynArray *array, TYPE value){
	assert(array!=0);

	int index = binarySearch(array->data, array->size, value);
	if (index>0 && index<array->size && array->data[index]==value){
		dynArrayRemoveAt(array, index);
	}
}
