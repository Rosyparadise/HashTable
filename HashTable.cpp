#include "HashTable.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


HashTable::HashTable(int Tsize){

    HT = new Hcont*[Tsize*2]; // dynamically allocating memory for the Hash Table
    sizeT = Tsize*2; // the Hash Table array size is twice as long as the number of words the file has, so that it can save the words faster
    for(int i=0;i<sizeT;i++)
        HT[i] = NULL;//setting all array nodes to NULL symbolizing that there is no word in this node
}

void HashTable::Insert(string cont){

    int i, code = 0, hc;
    for(i=0;cont[i]!='\0';i++)
        code+=(cont[i]+128); //this is the code of the word being inserted; adding each character's ASCII value

    //first hc
    hc = code%sizeT; // hc: hash code, the first one
    i=0;

    while(HT[hc]){//while  HT[hc] is not NULL, there is another word in this node and we must keep on searching

        if(HT[hc]->content == cont){//in case the word we need to insert is the same as the one in  HT[hc]->content, the counter is increased by one
            HT[hc]->counter++;
            return;
        }
        hc = (hc+i*i)%sizeT; //if nothing works out, a new hash code is created
        i++;
    }//this process goes on until an array node is non taken

    HT[hc] = new Hcont;//a new struct is created
    HT[hc]->content = cont;
    HT[hc]->counter = 1;

    //inserted the word successfully
}


HashTable::Hcont* HashTable::Search(string cont){

    int i, code = 0, hc;
    //searching is almost the same as inserting the word, following the same steps
    for(i=0;cont[i]!='\0';i++)
        code+=(cont[i]+128);
    i=0;
    //first hc
    hc = code%sizeT;
    //using the same method we used in the insertion, we are going to search for the given word in our Hash Table
    if(HT[hc]){
        if(HT[hc]->content == cont){ // if it matches, it is found!
            return HT[hc];
    }else{
        while (HT[hc]){
            if(HT[hc]->content == cont){
            return HT[hc];
            }
            i++;
            hc = (hc+i*i)%sizeT;
            }
    }


}//if we get here, this means that the word was not found
    cout<<cont<<" was not found."<<endl;
    return 0;
}
