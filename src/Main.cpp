#include <iostream>
#include <fstream>
#include <string> // NEDD TO CREATE MY OWN STRING CLASS !!!
#include <dirent.h>

#include "Node.h"
#include "WordTrie.h"


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




	cout<<endl;
	cout<<"Memory Indexation Start."<<endl;

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
	string extension="";
	WordTrie wordTrie;

	//Get all file with extension ".txt"
 	while ((entry = readdir(directoryPath)) != NULL) {
		fileName = entry->d_name;
		extension = getExtension(fileName);
		if(extension=="txt"){
			cout<<"File extension : "<<extension<<endl;
			//Init the data Structure
			wordTrie.initTree(fileName,directoryPathString);
		}
	}

	closedir (directoryPath);
	cout<<"Memory Indexation END."<<endl;




	//Ask for "Word" to Search
	cout<<endl;
	cout<<"Give the Word to Search : ";
	string wordToSearch;
	cin>>wordToSearch;

	//Search Files containing the given Word

	bool state = wordTrie.search(wordToSearch);
	cout<<state<<endl;



	return 0;
}
