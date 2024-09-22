#ifndef B5A97AA2_DF14_43C3_88A9_C49E15AF5231
#define B5A97AA2_DF14_43C3_88A9_C49E15AF5231

#include <fstream>
#include <string>

class FileReader
{
    public:
        FileReader();

        //Reads the Map file
        void SetMapFile(string& FileName);
        void OpenFile();
        void OpenFile(string& FileName);//Overload OpenFile to take in a file name
        void CloseFile();
        bool FileIsOpen();
        void ReadData();

    private:
        string MapFile;
}
#endif /* B5A97AA2_DF14_43C3_88A9_C49E15AF5231 */
