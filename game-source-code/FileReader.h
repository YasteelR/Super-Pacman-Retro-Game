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
        void ReadData4(vector<shared_ptr<T>> &StoreObjects);

    private:
        string MapFile;
        ifstream InputFile;
        string Object;

};
#endif /* B5A97AA2_DF14_43C3_88A9_C49E15AF5231 */
