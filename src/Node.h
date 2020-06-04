#ifndef DEF_NODE
#define DEF_NODE

#include <iostream>
#include <string>

#include "TxtFile.h"
#include "GLOBAL_VARIABLE.h"


 
class Node
{
    public:
        Node();
		~Node();

        bool isThere(int const& letter) const;
        void addNode(int const& letter, Node *newNode);
        Node* getNode(int const& letter) const;

        void addTxtFile(std::string const& fileName);

        //Accessors
        void setIsWord(bool const& isWord);
        void setFilesListHead(TxtFile* ptrHead);

        bool getIsWord() const;
        TxtFile* getFilesListHead() const;


    private:
        bool m_isWord;
        Node* childNodes[alphabetSize];
        //If this node is the last node of a "word"
        //"m_filesListHead" is the Head ptr of a list
        //This is a file Names list which contain this word
        TxtFile *m_filesListHead;

};
 
#endif




