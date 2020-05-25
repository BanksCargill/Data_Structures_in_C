/* Hash Tables Using Buckets

Bucket: linked list added to

LoadFactor: count/tablesize
In this structure it can be larger than 1. Typical structures resize at LF=10

*/


struct hlink {
	TYPE value;
	struct hlink *next;
}

struct hashTable {
	struct hlink ** table; int tablesize;
	int count;
}

void initHashTable (struct hashTable * ht, int size) {
	assert(size>0);
	ht->table = malloc(sizeof(struct hlink*)*size);
	assert(ht->table!=0);

	for (int i = 0; i<size; i++){
		ht->table[i]=0;
	}

	ht->tablesize = size;
	ht->count = 0;
}

int hashTableSize (struct hashTable * ht) { return ht->count; } void hashTableAdd (struct hashTable *ht, TYPE newValue) {
//compute hash value to find the correct bucket

	int hashIndex = HASH(newValue) % ht->tablesize; if (hashIndex < 0) hashIndex += ht->tablesize;
	struct hlink * newLink = (struct hlink *) malloc(sizeof(struct hlink)); assert(newLink);
	newLink->value = newValue;
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink; /* add to bucket */ ht->count++;
	if ((ht->count / (double) ht->tablesize) > 8.0) _resizeHashTable(ht);
}

//performed as a loop but only on the linked list stored at the table index
int hashTableContains (struct hashTable * ht, TYPE testElement) {
	assert(ht);
	assert(testElement!=0);

	int hashIndex = HASH(testElement) %ht->tablesize;

	//set current to the bucket indicated by HASH
	struct hlink *current = ht->table[hashIndex];

	//iterate through bucket
	while(current!=0){
		if(strcmp(current->value, testElement)==0){
			return 1;
		}
		current=current->next;
	}
	return 0;
}

//easiest to maintain a pointer to the current element and to the previous element
//When the current element is found, the next pointer for the previous is modified
void hashTableRemove (struct hashTable * ht, TYPE testElement) {
	assert(ht);
	assert(testElement!=0);

	hashIndex = HASH(testElement)%ht->tablesize;

	struct hlink *current = ht->table[hashIndex];
	struct hlink *previous = 0;

	while(current!=0){
		if(current->value == testElement){
			//if value is foind at first entry, set beginning to the next entry
			if(previous==0){
				ht->table[hashIndex]=current->next;
			}
			else{
				previous->next = current->next;
			}
			free(current);
			ht->count--;
			return;
		}
		//move forward through links
		previous = current;
		current=current->next;
	}

}

void resizeTable (struct hashTable *ht) {
	struct hashTable *newTable;
	initHashTable(newTable, ht->tablesize*2);
	struct *hlink current;

	//loop through old table and traverse links.Add value to new table
	for(int i=0; i<ht->tablesize; i++){
		current = ht->table[i];
		while(current!=0){
			hashTableAdd(newTable, current->value);
			current = current->next;
		}
	}
	//delete old hash table. Set old table value equal to new table
	free(ht->table);
	free(ht);
	ht=newTable;
	newTable = 0;
}
