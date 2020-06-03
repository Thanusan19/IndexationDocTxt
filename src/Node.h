#ifndef DEF_NODE
#define DEF_NODE

#include <iostream>
#include <string>

//Global Variable
int const alphabetSize =26;
 
class Node
{
    public:
        Node();
		~Node();

        bool isThere(int const letter) const;
        void addNode(int const letter, Node *newNode);
        Node* getNode(int const letter) const;
        void setIsWord(bool isWord);
        bool getIsWord() const;

    private:
        bool m_isWord;
        Node* childNodes[alphabetSize];

};
 
#endif




