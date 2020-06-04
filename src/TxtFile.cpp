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


void TxtFile::setTxtFileName(string const& txtFileName ) { m_txtFileName=txtFileName;}
void TxtFile::setTxtFolderPath(string const& txtFolderNamer) { m_txtFolderPath=txtFolderNamer;}
void TxtFile::setPtrNext(TxtFile *ptrNext) { m_ptrNext=ptrNext; } 


/*********/
/*STACTIC*/
/*********/

/* Function : getExtension
*
*  Description : Get the extension of a file
*  INPUT : -fileName --> give the name of a file as str
*  OUTPUT : return the extension as a "string" element
*/
std::string TxtFile::getExtension(std::string const& fileName)
{
	string extension="";
	unsigned int fileNameSize=fileName.length();
	for (unsigned int i = 0; i <fileNameSize ; i++)
	{
		if(fileName[i]=='.'){
			for (unsigned int j = i+1; j < fileNameSize; j++)
			{
				extension+=fileName[j];
			}
			return extension;
		}
	}
	return extension;
	
}