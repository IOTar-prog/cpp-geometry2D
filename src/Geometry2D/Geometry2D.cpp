
#include <fstream> 
#include <iostream>

using namespace std;

struct ConsoleConfig {
    string geometryFileFormat;
    string geometryFilePath;
};

struct GeometreDescription {
    int geometryFragmentSizeX;
    int geometryFragmentSizeY;
    int geometryFragmentNumX;
    int geometryFragmentNumY;
    bool* data;
};

void ReadCommandLineArgs(int argc, char* argv[], ConsoleConfig& ConsConf) {
    for (int i = 0; i < argc; i++) {
        if (i + 1 < argc) {
            if (string(argv[i]) == "-ff") {
                ConsConf.geometryFileFormat = string(argv[i + 1]);
            }
            if (string(argv[i]) == "-fp") {
                ConsConf.geometryFilePath = string(argv[i + 1]);
            }
        }
    }
}

int main(int argc, char* argv[])
{   
    
    ConsoleConfig ConsConf;
    GeometreDescription GeomDesc;

    ReadCommandLineArgs(argc, argv, ConsConf);

    ifstream file("C:/Users/ilyat/Desktop/cpp geometry/cpp-geometry2D/data/txt.txt");
    if (file.is_open()) {
        file >> GeomDesc.geometryFragmentSizeX;
        file >> GeomDesc.geometryFragmentSizeY;
        file >> GeomDesc.geometryFragmentNumX;
        file >> GeomDesc.geometryFragmentNumY;
        file.close();

        cout << GeomDesc.geometryFragmentSizeX;
        cout << GeomDesc.geometryFragmentSizeY;
        cout << GeomDesc.geometryFragmentNumX;
        cout << GeomDesc.geometryFragmentNumY;
    }
    else cout << "Error \n";

    //GeomDesc.data = new bool[GeomDesc.geometryFragmentNumX * GeomDesc.geometryFragmentNumY];
 
}

