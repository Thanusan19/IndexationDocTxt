#include "TxtFile.h"

using namespace std;

/**************************/
/*Constructor - Destructor*/
/**************************/

TxtFile::TxtFile(string txtFileName)
    :m_txtFileName(txtFileName),m_txtFolderPath(""),m_ptrNext(NULL)
{
}


TxtFile::TxtFile(string txtFileName, string txtFolderPath)
    :m_txtFileName(txtFileName),m_txtFolderPath(txtFolderPath),m_ptrNext(NULL)
{
}


TxtFile::~TxtFile()
{
}


/*********/
/*METHODS*/
/*********/

/* Function : DisplayTxtFilesList
*
*  Description : Display fileName extracted from the given list ptr
*  INPUT : -ptrTxtFilesList --> head pointor of the files names list
*/
void TxtFile::DisplayTxtFilesList(TxtFile *ptrTxtFilesList) const
{
    TxtFile *current=ptrTxtFilesList;
    while (current!=NULL)
    {
        cout<<" - FILE :   "<<current->getTxtFileName()<<endl;
        current = current->getPtrNext();
    }
    
}


/***********/
/*Accessors*/
/***********/


string TxtFile::getTxtFileName() const { return m_txtFileName; }
string TxtFile::getTxtFolderPath() const { return m_txtFolderPath; }
TxtFile* TxtFile::getPtrNext() const { return m_ptrNext; }


void TxtFile::setTxtFileName(string txtFileName ) { m_txtFileName=txtFileName;}
void TxtFile::setTxtFolderPath(string txtFolderNamer) { m_txtFolderPath=txtFolderNamer;}
void TxtFile::setPtrNext(TxtFile *ptrNext) { m_ptrNext=ptrNext; } 
