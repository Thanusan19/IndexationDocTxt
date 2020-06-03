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

        std::string getTxtFileName() const;
        std::string getTxtFolderPath() const;
        TxtFile* getPtrNext() const;

        void setTxtFileName(std::string fileName);
        void setTxtFolderPath(std::string folderPath);
        void setPtrNext(TxtFile *ptrNext);         

    private:
        std::string m_txtFileName;
        std::string m_txtFolderPath;
        TxtFile *m_ptrNext;

};
 
#endif




