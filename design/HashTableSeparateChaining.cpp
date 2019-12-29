#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 2e18

class hashing{
    int buckets;
    list<int>*table;
   
   public:

   hashing(int buck);

   int hashingFunction(int key);

   void insertItem(int key);

   void deleteItem(int key);

   void printHashTable();
};

hashing::hashing(int buck){
    this->buckets = buck;
    this->table = new list<int>[buck]; // array of list
}

int hashing::hashingFunction(int key){
    return key%(this->buckets);
}

void hashing::insertItem(int key) {
    int index = this->hashingFunction(key);

    this->table[index].push_back(key);
}

void hashing::deleteItem(int key){
    int index = this->hashingFunction(key);

    int flag=0;
    list<int>::iterator it;

    for(it= this->table[index].begin() ;it!=this->table[index].end();it++){
        if(*it == key){
            flag=1;
            break;
        }
    }

    if(flag==1){
        this->table[index].erase(it);
        return;
    }

    return;
}

void hashing::printHashTable() {

    int i;
    for(i=0;i<this->buckets;i++){

        list<int>::iterator it;
        for(it=this->table[i].begin(); it!=this->table[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int main(){

    hashing obj(7);
    obj.insertItem(10);
    obj.insertItem(3);
    obj.insertItem(12);
    obj.printHashTable();
    obj.deleteItem(10);
    obj.printHashTable();
}
