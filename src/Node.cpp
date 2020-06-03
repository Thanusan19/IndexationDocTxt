#include "Node.h"

/**************************/
/*Constructor - Destructor*/
/**************************/

Node::Node():m_isWord(false)
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



/* Function : setIsWord
*
*  Description : set the status as isWord if this Node is the end of one 
*               of the stored Word
*  INPUT : -isWord -> bool to state the Node as a Word End or Not
*/
void Node::setIsWord(bool isWord)
{
    m_isWord=isWord;
}


/* Function : getIsWord
*
*  Description : Get the state of the Node as a Word or Not
*  OUTPUT : return the bool value of "m_isWord"
*/
bool Node::getIsWord() const
{
    return m_isWord;
}