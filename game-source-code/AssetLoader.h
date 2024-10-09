#ifndef DCFC5681_4E68_4E0A_AF25_1C9FDF03378B
#define DCFC5681_4E68_4E0A_AF25_1C9FDF03378B

#include "FileReader.h"

class AssetLoader
{
    public:
        AssetLoader(){};
        void OpenPath(string filepath);
        void ClosePath(string filepath);
        template <typename T>
        void LoadObject(vector<shared_ptr<T>>& Object, string ObjectName);
        template <typename T>
        void LoadObject(shared_ptr<T>& Object, string ObjectName);
        template <typename T>
        void LoadObject(unique_ptr<T>& Object, string ObjectName);

    private:
        FileReader ObjectFile;
};
/// Implementation of template methods

/**
 * @brief Template specialization for loading a vector of shared_ptr objects.
 * @tparam T The type of the objects being loaded.
 * @param Object A vector of shared pointers to objects of type T.
 * @param ObjectName The name of the object to be loaded.
 */
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
/**
 * @brief Template specialization for loading a shared_ptr object.
 * @tparam T The type of the object being loaded.
 * @param Object A shared pointer to an object of type T.
 * @param ObjectName The name of the object to be loaded.
 */
template <typename T>
void AssetLoader::LoadObject(shared_ptr<T>& Object, string ObjectName)
{
    if(ObjectName=="Player")
    {
        ObjectFile.ObjectType(ObjectName);
        ObjectFile.ReadData2(Object);
    }
    else 
        Object = make_shared<T>();
}

/**
 * @brief Template specialization for loading a unique_ptr object.
 * @tparam T The type of the object being loaded.
 * @param Object A unique pointer to an object of type T.
 * @param ObjectName The name of the object to be loaded.
 */
template <typename T>
void AssetLoader::LoadObject(unique_ptr<T>& Object, string ObjectName)
{
    Object = make_unique<T>();
}
#endif /* DCFC5681_4E68_4E0A_AF25_1C9FDF03378B */
