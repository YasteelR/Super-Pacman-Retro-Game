#ifndef DCFC5681_4E68_4E0A_AF25_1C9FDF03378B
#define DCFC5681_4E68_4E0A_AF25_1C9FDF03378B

#include "FileReader.h"

/**
 * @class AssetLoader
 * @brief Class responsible for loading various types of objects from files.
 */
class AssetLoader
{
    public:
        /**
         * @brief Default constructor for AssetLoader.
         */
        AssetLoader(){};

        /**
         * @brief Opens the file at the specified filepath.
         * @param filepath The path to the file to open.
         */
        void OpenPath(string filepath);

        /**
         * @brief Closes the file at the specified filepath.
         * @param filepath The path to the file to close.
         */
        void ClosePath(string filepath);

        /**
         * @brief Loads a vector of shared_ptr objects of type T.
         * @tparam T The type of the objects to be loaded.
         * @param Object A vector of shared pointers to objects of type T.
         * @param ObjectName The name of the object to be loaded.
         */
        template <typename T>
        void LoadObject4(vector<shared_ptr<T>>& Object, string ObjectName);

        /**
         * @brief Loads a vector of shared_ptr objects of type T.
         * @tparam T The type of the objects to be loaded.
         * @param Object A vector of shared pointers to objects of type T.
         * @param ObjectName The name of the object to be loaded.
         */
        template <typename T>
        void LoadObject2(vector<shared_ptr<T>>& Object, string ObjectName);

        /**
         * @brief Loads a shared_ptr object of type T.
         * @tparam T The type of the object to be loaded.
         * @param Object A shared pointer to an object of type T.
         * @param ObjectName The name of the object to be loaded.
         */
        template <typename T>
        void LoadObject(shared_ptr<T>& Object, string ObjectName);

        /**
         * @brief Loads a unique_ptr object of type T.
         * @tparam T The type of the object to be loaded.
         * @param Object A unique pointer to an object of type T.
         * @param ObjectName The name of the object to be loaded.
         */
        template <typename T>
        void LoadObject(unique_ptr<T>& Object, string ObjectName);

    private:
        /**
         * @brief An instance of FileReader to handle file operations.
         */
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
void AssetLoader::LoadObject2(vector<shared_ptr<T>>& Object, string ObjectName)
{
    ObjectFile.ObjectType(ObjectName);
    ObjectFile.ReadData2(Object);
}

/**
 * @brief Template specialization for loading a vector of shared_ptr objects.
 * @tparam T The type of the objects being loaded.
 * @param Object A vector of shared pointers to objects of type T.
 * @param ObjectName The name of the object to be loaded.
 */
template <typename T>
void AssetLoader::LoadObject4(vector<shared_ptr<T>>& Object, string ObjectName)
{
    ObjectFile.ObjectType(ObjectName);
    ObjectFile.ReadData4(Object);
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
