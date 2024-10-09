#ifndef DCFC5681_4E68_4E0A_AF25_1C9FDF03378B
#define DCFC5681_4E68_4E0A_AF25_1C9FDF03378B

#include "FileReader.h"

class AssetLoader
{
    public:
        AssetLoader(){};
        void setPath(string filepath);
        template <typename T>
        void LoadObject(vector<shared_ptr<T>>& Object, string ObjectName);

    private:
        FileReader ObjectFile;
};

template <typename T>
void AssetLoader::LoadObject(vector<shared_ptr<T>>& Object, string ObjectName)
{
    if(ObjectName=="Rectangles")
    {
        TextFile.ObjectType(ObjectName);
        TextFile.ReadData4(Object);
    }
    else 
        TextFile.ObjectType(ObjectName);
        TextFile.ReadData2(Object);
}
#endif /* DCFC5681_4E68_4E0A_AF25_1C9FDF03378B */
