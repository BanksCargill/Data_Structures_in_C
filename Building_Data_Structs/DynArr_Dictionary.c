/* Dynamic Array Dictionary

Dictionary: indexed collection class
Elements are always provided in a pair: conisting of a key and a value
	Called an association

Elements must have unique keys
	Within put(), call containsKey. If found, call remove to delete it before adding

Complexity: O(n) They all loop through the array.
containsKey:
get():
put:
remove:

*/

# ifndef DYARRAYDICTH
# define DYARRAYDICTH

# ifndef KEYTYPE
# define KEYTYPE char *
# endif

# ifndef VALUETYPE
# define VALUETYPE double
# endif

struct association{
	KEYTYPE key;
	VALUETYPE value;
}

void dyArrayDictionaryPut (struct dynArray *da, KEYTYPE key, VALUETYPE val) {
  struct association * ap;
  if (dyArrayDictionaryContainsKey(da, key))
    dyArrayDictionaryRemoveKey (da, key);
  ap = (struct association *) malloc(sizeof(struct association));
  assert(ap != 0);
  ap->key = key;
  ap->value = val;
  dyArrayAdd(da, ap);
}

//rather than returning the association element, change what *valptr points to
void dyArrayDictionaryGet(struct dynArray *da, KEYTYPE key, VALUETYPE *valptr){
	for(int i =0; i<da->size;i++){
		if(strcmp(da->data[i]->key, key) == 0){
			*valptr = da->data[i]->value;
		}
	}
}

int dyArrayDictionaryContainsKey (struct dynArray *da, KEYTYPE key) {
	for(int i=0; i<da->size; i++){
		if(strcmp(key, da->data[i]->key)==0){
			return 1;
		}
		return 0;
	}

}
//pretty straightforward here, using removeAtDynArray is the only part to remember
//create association pointer so that you can delete an association.
void dyArrayDictionaryRemoveKey(struct dymArray *da, KEYTYPE key){
	struct association *temp;

	for(int i=0; i<da->size; i++){
		if(strcmp(key, da->data[i]->key)==0){
			temp=da->data[i];
			removeAtDynArray(da, i);
			/*without removeAtDynArray
			for(int j=i; j<da->size; j++){
				da->data[j] = da->data[j+1];
			}
			da->size--;
			*/
			free(temp);
			break;
		}
	}

}
