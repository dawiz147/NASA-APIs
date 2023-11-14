#ifndef INIFILEPARSER_H
#define INIFILEPARSER_H
#include "FileHandler.h"

class IniFileParser
{
public:
    IniFileParser(const QString& filePatch, const QString& fileName);
    ~IniFileParser();

    QString LoadKeyFromSection(const QString& section, const QString& key);
        QString LoadKeyWithoutSection(const QString& key);
private:

    bool LoadFileToString();
    bool ConvertIniFileStringToContent(QString fileContent);


private:
    std::map<std::string, std::map<std::string, std::string>> m_FileIniContent;
    FileHandler m_FileHandler;
};

#endif // INIFILEPARSER_H
