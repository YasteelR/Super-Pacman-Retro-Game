#ifndef B5A97AA2_DF14_43C3_88A9_C49E15AF5231
#define B5A97AA2_DF14_43C3_88A9_C49E15AF5231

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "BaseObject.h"

using namespace std;

class FileReader
{
    public:
        FileReader(){};
        FileReader(string ReadInFile);

        void SetMapFile(string FileName);
        void OpenFile();
        void OpenFile(string FileName);//Overload OpenFile to take in a file name
        void CloseFile();
        bool FileIsOpen();

        //Reads the Map txt file.
        void ObjectType(string NameOfObject); //The Name of the object i.e rectangles, lines, circles, etc...

        //This is a standard template for reading in different objects from the text file.
        //It's for objects that have two coordinates
        template <typename T>
        void ReadData2(vector<shared_ptr<T>> &StoreObjects);
        template <typename T>
        void ReadData2(shared_ptr<T> &StoreObjects);
        template <typename T>
        void ReadData4(vector<shared_ptr<T>> &StoreObjects);

    private:
        string MapFile;
        ifstream InputFile;
        string Object;
        string HeaderLine;
        bool DataWasRead;
};

template <typename T>
void FileReader::ReadData2(vector<shared_ptr<T>>& StoreObjects)
{
    static_assert(std::is_base_of<BaseObject, T>::value, "T must be derived from BaseObject");
    InputFile.seekg(0, std::ios::beg);

    while (HeaderLine != Object && !InputFile.eof())
    {
        getline(InputFile, HeaderLine);
    }
    
    int xpos;
    int ypos;
    while (InputFile >> xpos >> ypos)
    {
        StoreObjects.emplace_back(make_shared<T>());
        StoreObjects.back()->set_location(xpos, ypos);
        DataWasRead = true;
    }

    if (DataWasRead == false)
    {
        throw runtime_error("File contained no coordinates");
    }
    
    DataWasRead = false;
    InputFile.clear();
};

template <typename T>
void FileReader::ReadData2(shared_ptr<T>& StoreObjects)
{
    static_assert(std::is_base_of<BaseObject, T>::value, "T must be derived from BaseObject");
    InputFile.seekg(0, std::ios::beg);
    while (HeaderLine != Object && !InputFile.eof())
    {

        getline(InputFile, HeaderLine);
    }
    
    int xpos;
    int ypos;
    while (InputFile >> xpos >> ypos)
    {
        StoreObjects = make_shared<T>();
        StoreObjects->set_location(xpos, ypos);
        DataWasRead = true;
    }

    if (DataWasRead == false)
    {
        throw runtime_error("File contained no coordinates");
    }
    DataWasRead = false;
    InputFile.clear();
};

template <typename T>
void FileReader::ReadData4(vector<shared_ptr<T>>& StoreObjects)
{
    static_assert(std::is_base_of<BaseObject, T>::value, "T must be derived from BaseObject");
    InputFile.seekg(0, std::ios::beg);
    while (HeaderLine != Object && !InputFile.eof())
    {

        getline(InputFile, HeaderLine);
    }
    
    int xpos;
    int ypos;
    int width;
    int height;

    while (InputFile >> xpos >> ypos >> width >> height)
    {
        StoreObjects.emplace_back(make_shared<T>());
        StoreObjects.back()->set_location(xpos, ypos);
        StoreObjects.back()->setWidth(width);
        StoreObjects.back()->setHeight(height);
        DataWasRead = true;
    }

    if (DataWasRead == false)
    {
        throw runtime_error("File contained no coordinates");
    }
    DataWasRead = false;
    InputFile.clear();
};

#endif /* B5A97AA2_DF14_43C3_88A9_C49E15AF5231 */
