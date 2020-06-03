#ifndef DEF_WORDTRIE
#define DEF_WORDTRIE

#include "Node.h"

 
class WordTrie
{
    public:
        WordTrie();
		~WordTrie();
        void insert(std::string word); //Don't forgot to change string to String
        bool search(std::string word); //Don't forgot to change string to String

    private:
        Node *head;

};
 
#endif