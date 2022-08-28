#include "htable.h"
#include <iostream>
#include <string>



void HashMap::Update(string key, int value)
{
    bool flag = false;
    int hashval=HashFunc(key);
    HashNode* entry = htable[hashval];
    while (entry!=NULL)
    {
        if (entry->key == key)
        {
            entry->value = value;
            flag=true;
        }
        entry = entry -> next;
    }
    if (!flag)
    {
        cout<<"No element found at key "<<key<<endl;
    }
    return;
}