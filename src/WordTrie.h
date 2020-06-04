#ifndef DEF_WORDTRIE
#define DEF_WORDTRIE

#include "Node.h"
#include <fstream>
#include <dirent.h>


using namespace std;

class WordTrie
{
    public:
        WordTrie();
		~WordTrie();

        //Tree methods
        void insert(std::string const& word , std::string const& fileName); 
        TxtFile* search(std::string const& word); 
        void initTree(std::string const& fileName,std::string const& directoryPath);

        //Static methods
        static int memoryIndexing(WordTrie& wordTrie, std::string const& directoryPathString);

    private:
        Node *head;

};
 
#endif