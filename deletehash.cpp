//created on 7/27 by maddie woolley for prj 2//

#include "htable.h"

void HashMap::Delete(string key){
    int index = HashFunc(key);
    HashNode* entry = htable[index];
    HashNode* ptr = NULL;

    if (entry == NULL || entry ->key !=key){
        cout<<"No element found at key\n";
    }
    while(entry ->next != NULL) {
        ptr = entry;
        entry = entry->next;
    }
    if (ptr !=NULL){
        ptr ->next = entry ->next;
    }
    delete(entry);
    cout<<"Element Deleted\n";
    return;
}
