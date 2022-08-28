#include "htable.h"

int HashMap::Match(string key)
{
    bool flag = false;
    int hashval=HashFunc(key);
    int value;
    HashNode* entry = htable[hashval];
    while (entry!=NULL)
    {
        
        if (entry->key == key)
        {
            value=1;
            flag=true;
        }
        entry = entry -> next;
    }
    if (!flag)
    {
        value=0;
    }

    return value;
}

int HashMap::getValue(string key)
{
    bool flag = false;
    int hashval=HashFunc(key);
    int value;
    HashNode* entry = htable[hashval];
    while (entry!=NULL)
    {
        
        if (entry->key == key)
        {
            value=entry->value;
            flag=true;
        }
        entry = entry -> next;
        
    }


    if (!flag && key!="none")
    {
        value=0;
    }

    else if (key=="none")
    {
        value=-1;
    }

    return value;

}
