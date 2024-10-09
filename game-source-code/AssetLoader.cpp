#include "AssetLoader.h"

void AssetLoader::setPath(string filepath)
{
    ObjectFile.OpenFile(filepath);
}