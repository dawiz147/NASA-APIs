#include "FileHandler.h"
#include <QTextStream>
#include <QtDebug>

FileHandler::FileHandler(eFileType fileType)
{
    m_FileType=fileType;
}

FileHandler::~FileHandler()
{
    if (m_File.isOpen()) {
        CloseFile();
    }
}


bool FileHandler::OpenFile(QString& filePatch, QIODevice::OpenMode typeOfOpenFileFlags)
{
    bool isCorrectlyLoadedFile = false;
    if (m_File.isOpen()) {
#ifdef ENABLE_ASSERTIONS
        qWarning() << "File is already open."; // TODO: string to const!
        Q_ASSERT("File is already open." && false);
#endif
    }
    else if (!filePatch.isEmpty()) {
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
