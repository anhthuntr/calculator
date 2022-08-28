#ifndef HTABLE
#define HTABLE

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int TABLE_SIZE = 200;
const int PRIME_CONST = 31;

class HashNode
{
    public:     
        string key;
        int value;
        HashNode* next;
            HashNode(string key, int value)
            {
                this->key=key;
                this->value=value;
                this->next=NULL;
            }
};

class HashMap
{
    public:
        HashMap()
        {
            htable = new HashNode*[TABLE_SIZE];
            for (int i=0;i<TABLE_SIZE;++i)
                htable[i]=NULL;
        }
        ~HashMap()
        {
            for (int i=0;i<TABLE_SIZE;++i) {
            HashNode* entry = htable[i];
            while (entry!=NULL)
            {
                HashNode* prev=entry;
                entry=entry->next;
                delete prev;
            }
            }
            delete [] htable;
        }
        int HashFunc(string key)
        {
            size_t sz=0;
            for (int i=0;i<key.length();++i)
            {
                sz+=(key[i]*(int)pow(PRIME_CONST,i) % TABLE_SIZE);
            }
            return sz % TABLE_SIZE;
        }
        void Insert(string key, int value);
        void Delete(string key);
        void Search(string key);
        void Update(string key, int value);
        void Print(string key);
        int Match(string key);
        int getValue(string key);

    private:
        HashNode** htable;
};
#endif //HTABLE
