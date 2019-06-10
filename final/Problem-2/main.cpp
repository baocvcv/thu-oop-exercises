#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <time.h>
#include <cstdlib>
#include "MyTrie.h"

using namespace std;

int main()
{
    MyTrie *trie = new MyTrie();

    //add code here to randomly generate 15 character strings
    // and then insert the character strings into trie

    srand(time(0));
    std::cout << "Generating strings..." << std::endl;
    for (int i = 0; i < 15; i++){
        string s = "";
        for (int j = 0; j < 30; j++){
            char c = rand() % 26 + 'a';
            s += c;
        }
        int val = rand() % 100;
        trie->insert(s.c_str(), val);
        std::cout << s << ' ' << val << endl;
    }

    //......
    //search other prefixes instead of "a" if needed
    trie->searchSubString("a");
    //print all the matches to standard output by cout/printf
    //You may determine the output format
    trie->printMatches();
    
    trie->searchSubString("b");
    //print all the matches to standard output by cout/printf
    //You may determine the output format
    trie->printMatches();

    trie->searchSubString("c");
    //print all the matches to standard output by cout/printf
    //You may determine the output format
    trie->printMatches();

    //destruct the trie
    delete trie;

    return 0;
}
