#include <iostream>
#include <fstream>
#include <string>

#include <format>

using namespace std;

const string readConfigFile(const string &filename)
{
    ifstream file(filename);
    if (!file.good())
    {
        throw runtime_error(
            std::format("Failed to open configuration file: {}.", filename));
    }

    string line;
    string text;
    while (getline(file, line))
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main()
{
    try
    {
        cout << "Reading configuration:" << endl;
        string text = readConfigFile("configu-ration.txt");
        cout << text;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}
