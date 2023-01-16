#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class HashTable
{

    private:
        struct Hcont{
            string content; // the word being kept
            int counter; // the number of times the word appears
        };

        Hcont** HT; // the Hash Table Array
        int sizeT; // sizeT: the size of the Hash Table
        void Insert(string); // the insertion method
        Hcont* Search(string); // the search method


    public:
        HashTable(int);
        void GetIns(string x){Insert(x);} // inserting from main
        void GetSer(string x){Search(x);} // searching from main
        void printsearch(string x,ofstream &y){Hcont* temp=Search(x); y<<temp->content<<":"<<temp->counter<<endl;}//text file output

};

#endif // HASHTABLE_H
