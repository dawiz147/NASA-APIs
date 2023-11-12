#include "FileHandler.h"
#include <QTextStream>
#include <QtDebug>
#include <memory>


FileHandler::FileHandler(eFileType fileType, const QString &filePatch, const QString& fileName)
{
    m_FileType=fileType;
    PrepareFilePatch(filePatch, fileName);
    m_File.setFileName(m_FilePatch);
}

FileHandler::~FileHandler()
{
    if (m_File.isOpen()) {
        CloseFile();
    }
}

bool FileHandler::SaveStringAsFile(QString &fileContent)
{
    bool successfullySaveFile=false;
    if(OpenFile(QIODevice::WriteOnly | QIODevice::Text))
    {
        m_File.resize(0);
        m_File.seek(0);
        WriteToFile(fileContent);
        if(CloseFile())
        {
            successfullySaveFile=true;
        }
    }
    return successfullySaveFile;
}

QString FileHandler::LoadFileAsString()
{
    QString fileContent;

    if(OpenFile(QIODevice::ReadOnly | QIODevice::Text))
    {
        fileContent=ReadFromFile();
        CloseFile();
    }
    return  fileContent;
}


bool FileHandler::OpenFile( QIODevice::OpenMode typeOfOpenFileFlags)
{
    bool isCorrectlyLoadedFile = false;
    if (m_File.isOpen()) {
#ifdef ENABLE_ASSERTIONS
        qWarning() << "File is already open."; // TODO: string to const!
        Q_ASSERT("File is already open." && false);
#endif
    }
    else if (!m_FilePatch.isEmpty()) {
        if (m_File.open(typeOfOpenFileFlags)) {
            isCorrectlyLoadedFile =true;
        }
    }
    return isCorrectlyLoadedFile;
}


bool FileHandler::CloseFile()
{
    bool isCorrectlyClosedFile = false;
    if (m_File.isOpen()) {
        m_File.close();
        isCorrectlyClosedFile=true;
    }
    else
    {
#ifdef ENABLE_ASSERTIONS
        qWarning() << "File is not open."; // TODO: string to const!
        Q_ASSERT("File is not open." && false);
#endif
    }

    return isCorrectlyClosedFile;
}

void FileHandler::WriteToFile(QString& lineToWrite)
{
    QTextStream fileStreamIn(&m_File);
    fileStreamIn << lineToWrite;
}

QString FileHandler::ReadFromFile()
{
    QTextStream fileStreamOut(&m_File);
    return fileStreamOut.readAll();
}

bool FileHandler::PrepareFilePatch(const QString &filePatch, const QString &fileName)
{
    bool successfullyCreateFilePatch = false;
    if(filePatch.isEmpty() || fileName.isEmpty())
    {
#ifdef ENABLE_ASSERTIONS
        qWarning() << "File patch or file name is empty"; // TODO: string to const!
        Q_ASSERT("File patch or file name is empty" && false);
#endif
    }
    else
    {
        QString extensionOfFile="";
        switch (m_FileType) {
        case eFileType::ini:
            extensionOfFile = ".ini";
            break;
        default:
#ifdef ENABLE_ASSERTIONS
            qWarning() << "Undefined  file type"; // TODO: string to const!
            Q_ASSERT("Undefined  file type" && false);
#endif
            break;
        }
        m_FilePatch= filePatch + "/" + fileName + extensionOfFile;
    }
    return successfullyCreateFilePatch;
}
