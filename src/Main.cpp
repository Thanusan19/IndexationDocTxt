/* TEST: SUJET1 
*		 "Indexation de document texte"
*
*  File : Main.cpp
*
*  Author : SATHIAKUMAR Thanusan
*  Release Date : 03/06/2020
*/

#include "Node.h"
#include "WordTrie.h"
#include "TxtFile.h"


using namespace std;


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
	WordTrie::memoryIndexing(wordTrie,directoryPathString);
	cout<<"Memory Indexing END."<<endl;

	//Loop the Search Process
	while (1){
		//Ask for "Word" to Search 
		cout<<endl;
		cout<<"Write 'exit()' to quit the search process"<<endl;
		cout<<"Give the Word to Search : ";
		string wordToSearch;
		cin>>wordToSearch;

		if(wordToSearch=="exit()"){
			break;
		}

		//Search for txt files containing the given Word
		TxtFile *filesListPtr= wordTrie.search(wordToSearch);
		if(!(filesListPtr==0)){
			cout<<"Searched Word is in following files : "<<endl;
			filesListPtr->DisplayTxtFilesList(filesListPtr);
		}else{
			cout<<"The asked word is not into this directory's or sub-Distrectory's '.txt' files."<<endl;
		}
		
	}
	

	return 0;
}
