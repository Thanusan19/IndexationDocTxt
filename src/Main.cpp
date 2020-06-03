#include <iostream>
#include <fstream>
#include <string> // NEDD TO CREATE MY OWN STRING CLASS !!!
#include <dirent.h>

#include "Node.h"
#include "WordTrie.h"
#include "TxtFile.h"


using namespace std;

std::string getExtension(std::string const& fileName)
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




int memoryIndexing(WordTrie& wordTrie, std::string const& directoryPathString)
{
	//Open the Directory
	DIR *directoryPath=opendir(directoryPathString.c_str());
	if(directoryPath==NULL) 
	{ //Handle Exception when opening file
		cout<<"ERROR ( "<<errno<<" ) when opening "<< directoryPathString<<endl;
		perror("openDirectory");
		return errno;
	}
	
	struct dirent *entry;
	string fileName="";
	int fileType=0;
	string extension="";

	//Get all file with extension ".txt"
 	while ((entry = readdir(directoryPath)) != NULL) {
		fileName = entry->d_name;
		fileType=entry->d_type;
		//cout<<"File type into the Directory : "<<fileType<<endl; //DEBUG CODE

		extension = getExtension(fileName);
		if(extension=="txt"){
			cout<<"File extension : "<<extension<<endl;
			//Init the data Structure
			wordTrie.initTree(fileName,directoryPathString);
		}else if((fileType==4) && (fileName!=".") && (fileName!="..")){ 
			//Linux System : 4 --> directory
			cout<<"This is a Sub directory"<<endl;
			memoryIndexing(wordTrie,directoryPathString+"/"+fileName);
		}
		
	}

	closedir (directoryPath);
	return 0;
}

int main(int argc, char const *argv[])
{
	//Get the Directory path
	if(argv[1]==NULL){
		cout<<"ERROR : Directory path is empty!"<<endl;
		cout<<"Give a Directory path as a command argument"<<endl;
		return 0;
	}
	string directoryPathString=argv[1];
	cout<<"Given Directory Path : "<<directoryPathString<<endl;

	//Memory Indexing
	cout<<endl;
	cout<<"Memory Indexing Start."<<endl;
	WordTrie wordTrie;
	memoryIndexing(wordTrie,directoryPathString);
	cout<<"Memory Indexing END."<<endl;



	//Ask for "Word" to Search
	cout<<endl;
	cout<<"Give the Word to Search : ";
	string wordToSearch;
	cin>>wordToSearch;

	//Search Files containing the given Word
	TxtFile *filesListPtr= wordTrie.search(wordToSearch);
	if(!(filesListPtr==0)){
		cout<<"Word is the following files : "<<endl;
		filesListPtr->DisplayTxtFilesList(filesListPtr);
	}else{
		cout<<"The asked word is not into this directory's or sub-Distrectory's '.txt' files."<<endl;
	}

	return 0;
}
