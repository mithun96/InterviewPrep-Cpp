//Implementing Hash table- separate chaining


class HashNode {
	private:
		int key;
		int value;
		HashNode * next;

	public:
		HashNode(int k, int v){
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		int getKey(){
			return key;
		}
		int getValue(){
			return value;
		}
		HashNode* getNext(){
			return next;
		}

		void setKey(int k){
			this->key = k;
		}
		void setValue(int v){
			this->value = v;
		}
		void setNext(HashNode *n){
			this->next = n; 
		}
};

const int TABLE_SIZE = 128;

class HashTable {
private:
	HashNode ** table;
public:	
	HashTable(){
		table = new HashNode *[TABLE_SIZE];
		for (int i = 0; i< TABLE_SIZE; i ++)
			table[i] = NULL;
	}

	void insert(int k, int v){
		int hash = hashFunction(k);

		if (table[hash] == NULL){
			table[hash] = new HashNode(k , v);
		}
		else {
			HashNode * entry = table[hash];
			while (entry->getNext() != NULL){
				entry = entry->getNext();
			}
			if(entry->getKey() == k){
				entry->setValue(v);
			}
			else {
				entry->setNext(new HashNode(k, v))
			} 
		}
	}

	bool remove (int key){
		int hash = hashFunction(key);

		if (table[hash] != NULL){
			HashNode * prev = NULL;
			HashNode * entry = table[hash];
			while (entry->getKey() != key && entry->getKey() != key){
				prev = entry;
				entry = entry->getNext();
			} 
			if (prev == NULL){
				HashNode * next = entry->getNext();
				delete entry;
				table[hash] = next;
			}
			else {
				HashNode *nextNode = entry->getNext();
				delete entry;
				prev->setNext(nextNode);
			}

		}
	}

	int get(int key){
		int hash = hashFunction(key);

		if (table[hash] == NULL){
			return -1;
		}

		else {
			HashNode * entry= table[hash];
			while (entry != NULL && entry->getKey() != key ){
				entry = entry->getNext();
			}
			if (entry == NULL){
				return -1;
			}
			else 
				return entry->getValue();

		}
	}

	int hashFunction (int key) {
		return key % TABLE_SIZE;
	}

	~HashTable(){

		for (int i = 0; i < TABLE_SIZE; i++){
			if (table[i] != NULL){
				HashNode * prev = NULL;
				HashNode * entry = table[i];
				while(entry != NULL){
					prev = entry;
					entry = entry->getNext();
					delete prev;
				}
			}

		}

		delete [] table;
	}


};






























