#include <iostream>
#include <string> // NEDD TO CREATE MY OWN STRING CLASS !!!

#include "Node.h"
#include "WordTrie.h"


using namespace std;



int main(int argc, char const *argv[])
{
	//Get the Directory path
	if(argv[1]==NULL){
		cout<<"ERROR : Directory path is empty!"<<endl;
		cout<<"Give a Directory path as a command code"<<endl;
		return 0;
	}
	string directoryPath=argv[1];

	cout<<directoryPath<<endl;
	cout<<"Memory Indexation Start."<<endl;

	WordTrie wordTrie;
	wordTrie.insert("bon");
	wordTrie.insert("apple");
	wordTrie.insert("good");

	bool state = wordTrie.search("b");
	cout<<state<<endl;
	bool state2 = wordTrie.search("good");
	cout<<state2<<endl;
	bool state3 = wordTrie.search("apples");
	cout<<state3<<endl;



	return 0;
}
