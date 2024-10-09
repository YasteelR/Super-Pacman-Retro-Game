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
        template <typename T>
        void LoadObject(shared_ptr<T>& Object, string ObjectName);

    private:
        FileReader ObjectFile;
};

template <typename T>
void AssetLoader::LoadObject(vector<shared_ptr<T>>& Object, string ObjectName)
{
    if(ObjectName=="Walls")
    {
        ObjectFile.ObjectType(ObjectName);
        ObjectFile.ReadData4(Object);
    }
    else 
        ObjectFile.ObjectType(ObjectName);
        ObjectFile.ReadData2(Object);
}

template <typename T>
void LoadObject(shared_ptr<T>& Object, string ObjectName)
{
    if(ObjectName=="Player")
    {
        ObjectFile.ObjectType(ObjectName);
        ObjectFile.ReadData2(Object);
    }
    else 
        Object = make_shared<T>();
}

#endif /* DCFC5681_4E68_4E0A_AF25_1C9FDF03378B */
