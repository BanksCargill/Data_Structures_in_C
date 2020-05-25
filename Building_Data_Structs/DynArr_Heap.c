/* Heaps

Heap: Stores values in a complete binary tree
Heap Order Property: Value of each node is less than or equal to each of its child nodes (pretty much the opposite of what we have been looking at)

Internal representation will be a dynamic array
	Tree in DynArr: children of node i are found at positions 2i+1 and 2i+2, parent of child i found at (i-1)/2

When adding to heap, value added to end (end of array) then it is percolated up until it is not smaller than its parent

When a value is removed it leaves a hole. Filling this with the last element added restores the complete binary tree but not the heap order property
	adjustHeap must be called to restore heap order property
	O(log n)
*/
void heapRemoveFirst(struct dyArray *heap) {
  int last = dyArraySize(heap)-1;
  assert(dyArraySize(heap) > 0);    /* make sure we have at least one element */
  /* Copy the last element to the first  position */
  dyArrayPut(heap, 0, dyArrayrGet(heap, last));
  dyArrayRemoveAt(heap, last); /* Remove last element.*/
  adjustHeap(heap, last, 0);/* Rebuild heap */
}

/*recursive PseudoCode:

void adjustHeap (struct dyArray * heap, int max, int pos){
  int leftChild = 2*pos + 1; int rightChild = 2 * pos + 2;
	if (rightChild < max) { // we have two children
    //get index of smallest child
	}
	if value at pos > value of smallest child{
		//swap with smallest child,  call adjustHeap (max, index of smallest child)
	}
  else if (leftchild < max) {  we have one child
    if value at pos > value of child{
      swap with smallest child, call adjustHeap (max, index of left child)
		} else no children, done
	}
}
*/

void swap (struct dyArray * v, int i, int j) {  /* swap elements i j */
	TYPE temp = dyArrayGet(v, i);
	dyArrayPut(v, i, dyArrayGet(v, j));
	dyArrayPut(v, j, temp);
}

int indexSmallest (struct dyArray * v, int i, int j) {
  /* return index of smallest element */
	if (LT(dyArrayGet(v, i), dyArrayGet(v, j))
		return i;
  return j;
}

TYPE heapGetFirst (struct dyArray *heap) {
  assert(dyArraySize(heap) > 0);
	return dyArrayGet(heap, 0);
}

void heapRemoveFirst(struct dyArray *heap) {
  int last = dyArraySize(heap)-1;
  assert(dyArraySize(heap) > 0);    /* make sure we have at least one element */
         /* Copy the last element to the first  position */
  dyArrayPut(heap, 0, dyArrayrGet(heap, last));
  dyArrayRemoveAt(heap, last);       /* Remove last element.*/
  adjustHeap(heap, last, 0);/* Rebuild heap */
}

//MAX = size
void adjustHeap(struct dyArray * heap, int max, int pos) {
	int leftChild = 2*pos+1;
	int rightChild = 2*pos+2;
	if(rightChild<max){
		//we have 2 children, need to get the index of the smallest child
		int smallest = indexSmallest(heap, leftChild, rightChild);
		if(heap[pos] > heap[smallest]){
			swap(heap, pos, smallest);
			adjustHeap(heap, max, smallest);
		}
	}
	else if(leftChild<max){
		//we have one child
		if(heap[pos]>heap[leftChild){
			swap(heap, pos, leftChild);
			adjustHeap(heap, max, leftChild);
		}
	}
}

//value added at end of array
void heapAdd(struct dyArray * heap, TYPE newValue) {
	dyArrayAdd(heap, newValue); /* adds to end – now need to adjust position */
	int parent;
	//set pos = index of last element added
	int pos = dyArraySize(heap)-1;
	//iterate through array until order has been restored
	while(pos!=0){
		//initialize parent index
		parent=(pos-1)/2;
		//if value of child is less than that of parent, swap
		if(heap[pos]<heap[parent]){
			swap(heap, parent, pos);
			pos=parent;
		}
		else{
			return;
		}
	}
}

/* BuildHeap and Heap Sort

	All values indexed after max/2 are leaves, and are therefore already a heap. The first value that could potentially not be a heap is found at max/2
	Walking backwards from this value until the root is reached eventually makes all nodes into a heap.


*/
//
void buildHeap (struct dyArray *heap){
	int max = dyArraySize(heap);
	for(int i=max/2-1; i>=0; i--){
		_adjustHeap(heap, max, i);
	}
}

void heapSort(struct dyArray *v){
	buildHeap(v);
	for(int i = dyArraySize(v)-1; i>0; i--){
		dyArraySwap(v, o, i);
		_adjustHeap(v, i, 0);
	}
}
