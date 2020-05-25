/*
 DynArr Deque and Queue

Using DynArr but allowing the starting location of the block of elements to "float"
Logical index != physical index

Adding to the front: Decrement the starting location, place in the new element in the new starting place
Add to the back: increase size, place value in location determined by the addition of the starting location and size

Implement methods add, retrieve, remove from front or back

Algorithmic complexity:

addBack
Best: O(1)				Worst:	O(n)				Average:	O(1+)

RemoveBack
Best:	O(1)				Worst:	O(1)				Average:	O(1)

AddFront
Best:	O(1)				Worst:	O(n)				Average:	O(1+)

RemoveFront:
Best:	O(1)				Worst:	O(1)				Average: O(1)

*/


void _dequeSetCapacity(struct deque *d, int newCap){											//STUDY THIS MORE
	//create a new underlying array
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData!=0);

	//copy elements to it
	int j = d->beg;
	for(int i=0; i< d->size; i++){
		newData[i] = d->data[j];
		j++;
		if(j>=d->capacity){
			j=0;
		}
	}
	//delete old underlying array
	free(d->data);
	//update capacity, size, data
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
}

struct deque{
	TYPE *data;
	int capacity;
	int size;
	int beg;
}

void dequeInit(struct deque *d, int initCapacity){
	d->size = d->beg = 0;
	d->capacity = initCapacity;
	assert(initCapacity>0);

	d->data = malloc(initCapacity*sizeof(TYPE));
	assert(d->data!=0);
}

int dequeSize (struct deque *d){ return d->size;}

//Finish writing these functions

void dequeAddFront (struct deque *d, TYPE newValue){
	assert (d!-0);
	if (d->size >= d->capacity){
		_dequeSetCapacity(d, 2*d->capacity);
	}
//increase size, place new value in location determined by the addition of the starting location and size (able to wrap around)
	//compute index for placement:
	int index = d->beg - 1;
	if (index <= 0){	//need to wrap
		index= d->capacity - 1;
	}
	d->data[index] = newValue;
	d->beg = index;
	d->size++;

/*much faster/easier way
	d->beg--;
	if(d->beg<0){
		d->beg = d->capacity-1;
	}
	d->data[d->beg] = newValue;
	d->size++;
*/
}

void dequeAddBack (struct deque *d, TYPE newValue){
	assert (d!-0);
	if (d->size >= d->capacity){
		_dequeSetCapacity(d, 2*d->capacity);
	}
//increase size, place new value in location determined by the addition of the starting location and size (able to wrap around)
	//compute index for placement:
	int index = d->beg + d->size;
	if (index >= d->capacity){	//need to wrap
		index = index - d->capacity;
	}
	d->data[index] = newValue;
	d->size++;
}

TYPE dequeFront (struct deque *d){
	assert (d!=);
	assert (d->size >0);	//make sure it's not empty
	return d->data[d->beg];
}

TYPE dequeBack (struct deque *d){
	assert (d!=0);
	assert(d->size >0);
	int index = d->beg + d->size-1;	//watch out for the minus one on size. Want to get last element where if you don't subtract 1, you get
	if(index >=d->capacity){
		index = index - d->capacity;
	}
	return d->data[index];
}

void dequeRemoveFront(struct deque *d){
	assert (d!=0);
	assert(d->size > 0);
	int index = d->beg + 1;
	if (index >= d->capacity){
		index = index - d->capacity;	//if incrementing beg by 1 makes it >=, able to reset to 0
		//could just do d->beg = 0;
	}
	 d->beg = index;
	 d->size--;
}

void dequeRemoveBack(struct deque *d){
	assert (d!=0);
	d->size--;
}

/*Explain why each of these function has constant (or amortized constant) execution time

The only times the execution time could be worse than constant is when the array has to be resized [O(n)]
which can only occur in the addFront and addBack operations.

*/
