#include "AssetLoader.h"

void AssetLoader::OpenPath(string filepath)
{
    ObjectFile.OpenFile(filepath);
}

void AssetLoader::ClosePath(string filepath)
{
    ObjectFile.CloseFile();
}