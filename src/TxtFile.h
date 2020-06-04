#ifndef DEF_TXTFILE
#define DEF_TXTFILE

#include <iostream>
#include <string>


class TxtFile
{
    public:
        TxtFile(std::string txtFileName);
        TxtFile(std::string txtFileName, std::string txtFolderPath);
		~TxtFile();

        void DisplayTxtFilesList(TxtFile *ptrTxtFilesList) const;

        //Accessors
        std::string getTxtFileName() const;
        std::string getTxtFolderPath() const;
        TxtFile* getPtrNext() const;

        void setTxtFileName(std::string const& fileName);
        void setTxtFolderPath(std::string const& folderPath);
        void setPtrNext(TxtFile *ptrNext);

        //Static methods
        static std::string getExtension(std::string const& fileName);

    private:
        std::string m_txtFileName;
        std::string m_txtFolderPath;
        TxtFile *m_ptrNext;

};
 
#endif




