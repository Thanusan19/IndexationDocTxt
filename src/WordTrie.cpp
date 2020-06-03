#include "WordTrie.h"

/**************************/
/*Constructor - Destructor*/
/**************************/

WordTrie::WordTrie()
{
    head = new Node;
}


WordTrie::~WordTrie()
{
    delete head;
    head=0;
}


/*********/
/*METHODS*/
/*********/

/* Function : insert
*
*  Description : Insert an element according to the 
*               Trie algorithm. Complexity= O(length(wordToInsert))
*  INPUT : -word -> the word to insert into the tree
*/
void WordTrie::insert(std::string word)
{
    Node *current = head;
    //Add a Node for each character of the "Word"
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(!current->isThere(letter)){
            current->addNode(letter,new Node());
        }
        current = current->getNode(letter);
        
    }
    //set the last Node as being a "Word"
    current->setIsWord(true);
}


/* Function : search
*
*  Description : Search an element into the Tree
*                Complexity = O( length(word to search ))
*  INPUT : -word -> the word to insert into the tree
*/
bool WordTrie::search(std::string word)
{
    Node *current=head;
    //Search for each character of the seek word 
    //by taking in care the char order
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(!current->isThere(letter)){
            //word is not into the tree
            return false;
        }
        current=current->getNode(letter);
    }
    //word exist into the tree. Need to check 
    //if it's a stored Word or Not
    return current->getIsWord();
}