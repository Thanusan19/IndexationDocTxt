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
void WordTrie::insert(std::string word, std::string fileName)
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
    //Add the fileName to the last Node into txtFilesList
    cout<<"Word to insert : "<<word<<endl;
    current->addTxtFile(fileName);
}


/* Function : search
*
*  Description : Search an element into the Tree
*                Complexity = O( length(word to search ))
*  INPUT : -word -> the word to insert into the tree
*/
TxtFile* WordTrie::search(std::string word)
{
    Node *current=head;
    //Search for each character of the seek word 
    //by taking in care the char order
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(!current->isThere(letter)){
            //word is not into the tree
            return 0;
        }
        current=current->getNode(letter);
    }
    //word exist into the tree. Need to check 
    //if it's a stored Word or Not
    //if it's true we return All file Names 
    //which contain the "word"
    if(current->getIsWord()){
        return current->getFilesListHead();
    }else{
        return 0;
    }
}


/* Function : initTree
*
*  Description : Init the tree by extracting and storing all words from
*               the given file into the tree
*  INPUT : -fileName -> the txt file name
*          -directoryPath -> the directory path to the file
*/
void WordTrie::initTree(std::string fileName,std::string directoryPath)
{
    string filePath = directoryPath+"/"+fileName;
    cout<<"File path : "<<filePath<<endl;
    ifstream myFlux(filePath);
    if(!myFlux){
        cerr<<"ERROR: txt file not open correctly into initTree!"<<endl;
        cerr<<"File path error : "<<filePath<<endl;
    }else{
        string word;
        myFlux>>word;
        //while it's not the end of the file
        //Read and Store Words into the tree
        while (!myFlux.eof())
        {
            this->insert(word,fileName);
            myFlux>>word;
        }
    }
    myFlux.close();
}
