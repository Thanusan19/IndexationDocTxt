#include "Node.h"

using namespace std;
/**************************/
/*Constructor - Destructor*/
/**************************/

Node::Node():m_isWord(false),m_filesListHead(0)
{
    for (int i = 0; i < alphabetSize; i++)
    {
        childNodes[i]=NULL;
    }
}


Node::~Node()
{
}


/*********/
/*METHODS*/
/*********/

/* Function : isThere
*
*  Description : Check is the letter which is the ASCII table
*               number associated to one "char" is into 
*               the current Node
*  INPUT : -letter -> ASCII table associate number for a "char"
*  OUTPUT : true if the character key already exist into the tree
*/
bool Node::isThere(int const letter) const
{
    if(childNodes[letter]==NULL){
        return false;
    }
    return true;
}


/* Function : addNode
*
*  Description : Add a new Node with new chacter letter as a key
*  INPUT : -letter -> ASCII table associate number for a "char" key 
*                   associate to the Node
*          -newNode -> ptr of the node to insert
*/
void Node::addNode(int const letter, Node *newNode)
{
    childNodes[letter]=newNode;
}


/* Function : getNode
*
*  Description : get the ptr of the Node associated to the key "letter"
*  INPUT : -letter -> ASCII table associate number for a "char" key 
*                   of a Node
*  OUTPUT : the Node ptr of the associated Key "letter"
*/
Node* Node::getNode(int const letter) const
{
    return childNodes[letter];
}


/* Function : addTxtFile
*
*  Description : Crete a TxtFile object, affect the fileName 
*                and link it at the last of the txtFiles List
*  INPUT : -fileName --> the fileName to affect
*/
void Node::addTxtFile(std::string fileName)
{
    if(m_filesListHead==0){
        m_filesListHead = new TxtFile(fileName);
    }else{
        //previous contain the TxtFile object addr 
        //which is before the current one
        //previous ptr is need in order to set ptrNext
        TxtFile *previous = m_filesListHead;
        TxtFile *current = m_filesListHead->getPtrNext();
        while(current!=NULL){
            previous = current;
            current=current->getPtrNext();
        }
        //DEBUG CODE
        //cout<<"File Names : "<<fileName<<endl;
        //cout<<"Pointed addr : "<<m_filesListHead<<endl; 
        previous->setPtrNext(new TxtFile(fileName));
    }
}



/***********/
/*ACCESSORS*/
/***********/

void Node::setIsWord(bool isWord) { m_isWord=isWord; }
void Node::setFilesListHead(TxtFile* ptrHead) { m_filesListHead=ptrHead; }


bool Node::getIsWord() const { return m_isWord; }
TxtFile* Node::getFilesListHead() const { return m_filesListHead; }
