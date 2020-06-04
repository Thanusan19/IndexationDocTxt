#include "WordTrie.h"

/**************************/
/*Constructor - Destructor*/
/**************************/

WordTrie::WordTrie()
{
    head = new Node;
}


WordTrie::~WordTrie()
{
    delete head;
    head=0;
}


/*********/
/*METHODS*/
/*********/

/* Function : insert
*
*  Description : Insert an element according to the 
*               Trie algorithm. Complexity= O(length(wordToInsert))
*  INPUT : -word -> the word to insert into the tree
*/
void WordTrie::insert(std::string const& word, std::string const& fileName)
{
    Node *current = head;
    //Add a Node for each character of the "Word"
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(!current->isThere(letter)){
            current->addNode(letter,new Node());
        }
        current = current->getNode(letter);
        
    }
    //set the last Node as being a "Word"
    current->setIsWord(true);
    //Add the fileName to the last Node into txtFilesList
    //cout<<"Word to insert : "<<word<<endl; //DEBUG CODE
    current->addTxtFile(fileName);
}


/* Function : search
*
*  Description : Search an element into the Tree
*                Complexity = O( length(word to search ))
*  INPUT : -word -> the word to insert into the tree
*/
TxtFile* WordTrie::search(std::string const& word)
{
    Node *current=head;
    //Search for each character of the seek word 
    //by taking in care the char order
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int letter = (int)word[i] - (int)'a';
        if(!current->isThere(letter)){
            //word is not into the tree
            return 0;
        }
        current=current->getNode(letter);
    }
    //word exist into the tree. Need to check 
    //if it's a stored Word or Not
    //if it's true we return All file Names 
    //which contain the "word"
    if(current->getIsWord()){
        return current->getFilesListHead();
    }else{
        return 0;
    }
}


/* Function : initTree
*
*  Description : Init the tree by extracting and storing all words from
*               the given file into the tree
*  INPUT : -fileName -> the txt file name
*          -directoryPath -> the directory path to the file
*/
void WordTrie::initTree(std::string const& fileName,std::string const& directoryPath)
{
    string filePath = directoryPath+"/"+fileName;
    cout<<"File path : "<<filePath<<endl;
    ifstream myFlux(filePath);
    if(!myFlux){
        cerr<<"ERROR: txt file not open correctly into initTree!"<<endl;
        cerr<<"File path error : "<<filePath<<endl;
    }else{
        string word;
        myFlux>>word;
        //while it's not the end of the file
        //Read and Store Words into the tree
        while (!myFlux.eof())
        {
            this->insert(word,fileName);
            myFlux>>word;
        }
    }
    myFlux.close();
}

/********/
/*STATIC*/
/********/

/* Function : memoryIndexing
*
*  Description : Function that will open each directory and sub_directory 
*                to get all "txt" files words in order to store it 
*                into a Tree Structure
*  INPUT : -wordTrie -> arguemnt by reference in order to complete this tree object
*          -directoryPathString -> the path of the directory to explore in order 
*                                  to find all .txt 
*  OUTPUT : -0 --> if all works well
*           -errno --> an error value if file opeening didn't work
*/
int WordTrie::memoryIndexing(WordTrie& wordTrie, std::string const& directoryPathString)
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

		extension = TxtFile::getExtension(fileName);
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