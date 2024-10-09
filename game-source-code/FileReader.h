#ifndef B5A97AA2_DF14_43C3_88A9_C49E15AF5231
#define B5A97AA2_DF14_43C3_88A9_C49E15AF5231

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "BaseObject.h"

using namespace std;

/**
 * @brief Reads game objects from a file.
 * 
 * The FileReader class handles reading in different types of
 * objects from a specified text file.
 */
class FileReader {
public:
    FileReader() {};
    /**
     * @brief Constructor that initializes the file to read.
     * 
     * @param ReadInFile The name of the file to read.
     */
    FileReader(string ReadInFile);
    
    /**
     * @brief Sets the map file.
     * 
     * @param FileName The name of the file to set.
     */
    void SetMapFile(string FileName);
    
    /**
     * @brief Opens the specified map file.
     */
    void OpenFile();
    
    /**
     * @brief Opens the specified file.
     * 
     * @param FileName The name of the file to open.
     */
    void OpenFile(string FileName);
    
    /**
     * @brief Closes the currently open file.
     */
    void CloseFile();
    
    /**
     * @brief Checks if the file is open.
     * 
     * @return true if the file is open, false otherwise.
     */
    bool FileIsOpen();
    
    /**
     * @brief Reads object types from the map file.
     * 
     * @param NameOfObject The name of the object type to read.
     */
    void ObjectType(string NameOfObject);
    
    /**
     * @brief Reads data for objects with two coordinates.
     * 
     * @tparam T The type of object to read.
     * @param StoreObjects The vector to store the read objects.
     */
    template <typename T>
    void ReadData2(vector<shared_ptr<T>>& StoreObjects);
    
    /**
     * @brief Reads data for objects with four coordinates.
     * 
     * @tparam T The type of object to read.
     * @param StoreObjects The vector to store the read objects.
     */
    template <typename T>
    void ReadData4(vector<shared_ptr<T>>& StoreObjects);

private:
    string MapFile; ///< The name of the map file.
    ifstream InputFile; ///< Input file stream.
    string Object; ///< Current object type being read.
    string HeaderLine; ///< Used in readData functions.
    bool DataWasRead;///< Flag to check read functions ran.
};

template <typename T>
void FileReader::ReadData2(vector<shared_ptr<T>>& StoreObjects) {
    static_assert(std::is_base_of<BaseObject, T>::value, "T must be derived from BaseObject");
    InputFile.seekg(0, std::ios::beg);
    while (HeaderLine != Object && !InputFile.eof()) {
        getline(InputFile, HeaderLine);
    }
    int xpos, ypos;
    while (InputFile >> xpos >> ypos) {
        StoreObjects.emplace_back(make_shared<T>());
        StoreObjects.back()->set_location(xpos, ypos);
        DataWasRead = true;
    }
    if (!DataWasRead) {
        throw runtime_error("File contained no coordinates");
    }
    DataWasRead = false;
    InputFile.clear();
}

template <typename T>
void FileReader::ReadData4(vector<shared_ptr<T>>& StoreObjects) {
    static_assert(std::is_base_of<BaseObject, T>::value, "T must be derived from BaseObject");
    InputFile.seekg(0, std::ios::beg);
    while (HeaderLine != Object && !InputFile.eof()) {
        getline(InputFile, HeaderLine);
    }
    int xpos, ypos, width, height;
    while (InputFile >> xpos >> ypos >> width >> height) {
        StoreObjects.emplace_back(make_shared<T>());
        StoreObjects.back()->set_location(xpos, ypos);
        StoreObjects.back()->setWidth(width);
        StoreObjects.back()->setHeight(height);
        DataWasRead = true;
    }
    if (!DataWasRead) {
        throw runtime_error("File contained no coordinates");
    }
    DataWasRead = false;
    InputFile.clear();
}

#endif /* B5A97AA2_DF14_43C3_88A9_C49E15AF5231 */
