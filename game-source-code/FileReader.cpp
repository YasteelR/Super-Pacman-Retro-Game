#include "FileReader.h"

FileReader::FileReader(string ReadInFile)
{
    MapFile=ReadInFile;
    Object="Rectangles";
    OpenFile(MapFile);
    DataWasRead = false;
}
void FileReader::OpenFile()
{
    if(InputFile.is_open())
    {
        throw runtime_error("Map File is already open");
    }
    else 
        InputFile.open(MapFile);
}

void FileReader::OpenFile(string FileName)
{
    MapFile=FileName;
    if(InputFile.is_open())
    {
        throw runtime_error("Map File is already open");
    }
    else 
        InputFile.open(MapFile);
}

void FileReader::CloseFile()
{
    InputFile.close();
}

void FileReader::SetMapFile(string FileName)
{
    MapFile=FileName;
    OpenFile();
    if(!FileIsOpen())
    {
        throw runtime_error("File did not open");
    }
    CloseFile();
}

bool FileReader::FileIsOpen()
{
    if(InputFile.is_open())
    {
        return true;
    }
    else 
        return false;
}

void FileReader::ObjectType(string NameOfObject)
{
    Object=NameOfObject; 
}
