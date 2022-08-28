#include "htable.h"

void HashMap::Search(string key)
{
    bool flag = false;
    int hashval=HashFunc(key);
    HashNode* entry = htable[hashval];
    while (entry!=NULL)
    {
        if (entry->key == key)
        {
            //Print out the value at that key
            cout<<entry->key<<" = "<<entry->value;
            flag=true;
        }
        entry = entry -> next;
        cout<<endl;
    }
    if (!flag)
    {
        cout<<"No element found at key "<<key<<endl;
    }
}
