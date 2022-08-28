//create by Giang Tran for project 2
#include "htable.h"

void HashMap::Insert(string key, int value) {
    //locate the index in hash table
    int index = HashFunc(key);
    
    HashNode* ptr = NULL;
    HashNode* entry  = htable[index];
    
    while (entry != NULL) {
        ptr = entry;
        entry = entry->next;
    }
    
    //once an empty holder found, add the new hash node
    if (entry == NULL) {
        entry = new HashNode(key, value);
        if (ptr == NULL) {
            htable[index] = entry;
        }
        else {
            ptr->next = entry;
        }
    }
    //in case the node is deleted, not empty from start, assign value
    else {
        entry->value = value;
    }
}
