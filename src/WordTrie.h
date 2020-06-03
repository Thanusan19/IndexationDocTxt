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
        void insert(std::string word); //Don't forgot to change string to String
        bool search(std::string word); //Don't forgot to change string to String

        void initTree(std::string fileName,std::string directoryPath);

    private:
        Node *head;
        std::string fileName;

};
 
#endif