#ifndef B5A97AA2_DF14_43C3_88A9_C49E15AF5231
#define B5A97AA2_DF14_43C3_88A9_C49E15AF5231

#include <fstream>
#include <string>
#include <vector>

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
        void ReadData(vector<int>& StoreData, int& NumberOfObjects);

    private:
        string MapFile;
        ifstream InputFile;
        string Object;

};
#endif /* B5A97AA2_DF14_43C3_88A9_C49E15AF5231 */
