/* Hash Tables (Open Address Hashing)

Fast bag abstraction

Can we do better than O(logn)-from skip lists and avl trees
	The goal is to reach O(1)

Open Address Hashing: All elements stored in a single large table. Positions that are not filled
											are given a null value

tombstone: marker that replaces a deleted value. Can be replaced by another newly inserted value but
					does not halt the searchpath


loadfactor: should be less than .75
						=size/capacity

Collision: when two values result in the same index
*/

struct openHashTable {
  TYPE ** table;	//double pointer since table holds pointers
  int tablesize;
  int count;	//represents the # of elements in the table
};

void initOpenHashTable (struct openHashTable * ht, int size) {
  int i;
  assert (size > 0);
  ht->table = (TYPE **) malloc(size * sizeof(TYPE *));
  assert(ht->table != 0);
  for (i = 0; i < size; i++)
		ht->table[i] = 0; /* initialize empty */
  ht->tablesize = size;
  ht->count = 0;
}

int openHashTableSize (struct openHashTable *ht) {
	return ht->count;
}

void openHashTableAdd (struct openHashTable * ht, TYPE  newValue) {
  int idx;
	//By incrementing count before checking the load factor, it ensures that the table is resized so it can never be completely filled
	ht->count++;
  /* Make sure we have space and under the load factor threshold*/
  if ((ht->count / (double) ht->tablesize) > 0.75)
		_resizeOpenHashTable(ht);

  idx = HASH(newValue) % ht->tablesize;
  if (idx < 0){
		idx += ht->tablesize;
	}

	//traverse table
	while(idx>=0){
		//loop back to beginning if you hit the end
		if(idx==ht->tablesize)
			idx=0;
		//found an empty slot, so add the value
		if(ht->table[idx] == 0){
			ht->table[idx]=newValue;
			idx=-1;
		}//didn't hit the end or find an empty slot so increment index
		else
			idx++;
	}
}

int openHashTableBagContains (struct openHashTable *ht, TYPE  newValue) {

	int idx;

	idx = HASH(newValue) % ht->tablesize;
  if (idx < 0)
		idx += ht->tablesize;

	while(idx>=0){
		if(compare(ht->table[idx], newValue)==0){
			return 1;
		}
		idx++;

		if(idx==ht->tablesize){
			idx=0;
		}
	}

}

void _resizeOpenHashTable (struct openHashTable *ht) {
	int oldSize = ht->tablesize;
	int newSize = oldSize*2;
	TYPE **temp = ht->table;
	initOpenHashTable(ht, newSize);
	for(int i = 0; i<ht->oldSize; i++){
		if(temp[i]!=0){
			openHashTableAdd(ht, temp[i]);
		}
	}
	free(temp);
}
