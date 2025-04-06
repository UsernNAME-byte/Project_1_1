#include "readArrayFromFile.h"

vector<Shop> readArrayFromFile(const string& filename)
{
    fstream file;
    file.open(filename, fstream::in);
    vector<Shop> arr;

    if (!file)
    {
        cerr << "Помилка відкриття файлу: " << filename << endl;
        return arr;
    }

    while (!file.eof())
    {
        Shop num;
        file >> num;
        arr.push_back(num);
    }

    file.close();
    return arr;
}