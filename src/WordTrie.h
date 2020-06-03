#ifndef DEF_WORDTRIE
#define DEF_WORDTRIE

#include "Node.h"
#include <fstream>

using namespace std;

class WordTrie
{
    public:
        WordTrie();
		~WordTrie();
        void insert(std::string word , std::string fileName); 
        TxtFile* search(std::string word); 

        void initTree(std::string fileName,std::string directoryPath);

    private:
        Node *head;

};
 
#endif