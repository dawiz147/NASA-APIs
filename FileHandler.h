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
    FileHandler(eFileType fileType, const QString& filePatch, const QString& fileName);
    ~FileHandler();
    bool SaveStringAsFile(QString&  fileContent);
    QString LoadFileAsString();



private:
    bool OpenFile(QIODevice::OpenMode typeOfOpenFileFlags);
    bool CloseFile();
    void WriteToFile(QString& lineToWrite);
    QString ReadFromFile();
    bool PrepareFilePatch(const QString& filePatch, const QString& fileName);





private:
    eFileType m_FileType;
    QFile  m_File;
    QString m_FilePatch;


};

#endif // FILEHANDLER_H
