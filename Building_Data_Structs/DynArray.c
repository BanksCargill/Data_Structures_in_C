//Functions for study

/*Checklist of things to know:
	DynArr:
		Size vs Capacity
		Provides random access (indexing)
		Execution time & cost analysis
			add (when size < capacity, aka no resize necessary) = O(1), worst case is when resize is necessary = O(n)
			remove Best case = O(1) when at the end of the array; Worst case = O(n), when at the beginning of array and entire array has to be shifted (no gaps)

*/

#ifndef TYPE
#define TYPE int
#endif

struct DynArr{
	TYPE *data;
	int size;
	int capacity;
}

void initDynArr(struct DynArr *array, int capacity){
	array->data = malloc(sizeof(TYPE)*capacity);
	assert(array->data!=0);

	array->size = 0;
	array->capacity = capacity;
}

void freeDynArr(struct DynArr *array){
	if (array->data !=0){
		free (array->data);	//Free the space on the heap (allocated memory)
		array->data = 0;		//point to NULL
	}
	array->size = 0;
	array->capacity = 0;
}

int sizeDynArr(struct DynArr *array){
	return array->size;
}

void addDynArr(struct DynArr *array, TYPE val){
	//check if resize necessary
	if (array->size >= array->capacity){
		//call private function to double array capacity
		_setCapacityDynArr(array, 2*array->capacity);
	}
	//add value passed to end of array
	array->data[array->size] = val;
	array->size++;
}

//this needs to create a new array, copy elements over, set old array pointer equal to it, then delete the old array
void _setCapacityDynArr(struct DynArr *array, int newCap){
	assert (array!=0);

	TYPE *temp = malloc(sizeof(TYPE)*newCap);
	assert(temp!=0);

	//copy elements
	for(int i=0; i<array->size, i++){
		temp[i] = array->data[i];
	}

	//free the array then set old pointer equal to it
	free(array->data);
	array->data = temp;

	temp=0;
	//update array capacity
	array->capacity = newCap;
}

//returns element at index
TYPE getDynArr(struct DynArr *array, int position){

	assert(array !=0 && array->size !=0);
	assert(array->size > position && position>=0);

	return array->data[position];
}

//replaces element at index with new value
void putDynArr(struct DynArr *array, int position, TYPE value){
	assert (array!=0 && array->size!=0);
	assert (array->size > position && position >=0);

	array->data[position] = value;
}

//swaps index values
void swapDynArr(struct DynArr *array, int i, int j){
	assert (array != 0 && array->size != 0);
	assert(i >= 0 && j>=0);
	assert(array->size >= i && array->size >= j);

	TYPE temp = array->data[i]; 			//getDynArr(array, i);
	array->data[j] = array->data[i];	//putDynArr(array, i, getDynArr(array, j));
	array->data[i] = temp;						//putDynArr(array, j, temp);
}

//removes a value at a specified index
//ensure no gaps are left, size will need decrementing
removeAtDynArr(struct DynArr *array, int index){
	assert (array != 0 && array->size !=0);
	assert (index >= 0 && index < array->size);

	for (int i = index; i < size; i++){	//Watch out for misunderstand on "size" vs "size-1" ( < vs. <= )
		array->data[i] = array->data[i+1];	//putDynArr(array, i, getDynArr(array, i+1));
	}
	array->size--;
}
