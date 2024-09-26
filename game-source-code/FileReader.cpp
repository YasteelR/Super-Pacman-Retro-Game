#include "FileReader.h"

FileReader::FileReader(string ReadInFile)
{
    MapFile=ReadInFile;
    Object="Rectangles";
    OpenFile(MapFile);
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

void FileReader::ReadData(vector<int>& StoreData, int& NumberOfObjects)
{

    InputFile.seekg(0, std::ios::beg);
    string HeaderLine;
    while (HeaderLine != Object && !InputFile.eof())
    {

        getline(InputFile, HeaderLine);
    }

    int coordinates;
    int count = 0;
    bool flag = false;
    while (InputFile >> coordinates)
    {
        StoreData.push_back(coordinates);
        count++;

        if (flag == false)
        {
            flag = true;
        }

        if (count == 4)
        {
            NumberOfObjects++;
            count =0;
        }
    }

    if (count != 0)
    {
        NumberOfObjects++;
    }

    if (flag == false)
    {
        throw runtime_error("File contained no coordinates");
    }

    InputFile.clear();
}

void FileReader::ReadDataObject(vector<Key>& StoreKeys, int& NumberOfObjects)
{
    InputFile.seekg(0, std::ios::beg);
    string HeaderLine;
    while (HeaderLine != Object && !InputFile.eof())
    {

        getline(InputFile, HeaderLine);
    }

    int xpos;
    int ypos;
    bool DataWasRead = false;
    while (InputFile >> xpos >> ypos)
    {
        StoreKeys.emplace_back();
        StoreKeys.back().set_location(xpos,ypos);
        NumberOfObjects++;
        DataWasRead = true;
    }

    if (DataWasRead == false)
    {
        throw runtime_error("File contained no coordinates");
    }

    InputFile.clear();
}