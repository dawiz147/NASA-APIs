#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>
#include <QFile>

enum class eFileType {
    ini
};


class FileHandler
{
public:
    FileHandler(eFileType fileType);
    ~FileHandler();
    bool SaveApiKey(QString&  key);
    QString LoadApiKey();



private:
    bool OpenFile(QString& filePatch, QIODevice::OpenMode typeOfOpenFileFlags);
    bool CloseFile();
    bool WriteToFile(QString& lineToWrite);
    QString ReadFromFile();





private:
    eFileType m_FileType;
    QFile m_File;



};

#endif // FILEHANDLER_H
