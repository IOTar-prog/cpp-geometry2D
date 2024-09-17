
#include <fstream> 
#include <iostream>
#include <string>

using namespace std;

class ConsoleConfig {
public:
    string geometryFileFormat;
    string geometryFilePath;

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
};

class GeometreDescription {
public:
    int geometryFragmentSizeX;
    int geometryFragmentSizeY;
    int geometryFragmentNumX;
    int geometryFragmentNumY;
    int* data;

    //выводим содержимое файла
    void Print(string& filePath) {
        ifstream file(filePath);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << "\n";
            }
            file.close();
        }
        else {
            cout << "Error. File is not opened! \n" << filePath << endl;
        }
    }

    //вносим модель в динамический массив
    void PushToDynamicArr(string& filePath) {
        ifstream file(filePath);
        if (file.is_open()) {
            string line;
            getline(file, line);
            int data_i = 0;
            while (getline(file, line)) {
                // проверка комментариев
                if (line[0] == char("/") and line[1] == char("/")) {
                    continue;
                }
                else {
                    for (int i = 0; i < size(line); i++) {
                        data[data_i] = line[i];
                        data_i++;
                    }
                }
            }
            file.close();
        }
        else {
            cout << "Error. File is not opened! \n" << filePath << endl;
        }
    }

};

int main(int argc, char* argv[])
{   
    setlocale(LC_ALL, "Russian");

    ConsoleConfig ConsConf;
    GeometreDescription Geometry2D;

    ConsConf.ReadCommandLineArgs(argc, argv, ConsConf);
    ConsConf.geometryFilePath = "C:/Users/ilyat/Desktop/cpp geometry/cpp-geometry2D/data/txt.txt";
    ifstream file(ConsConf.geometryFilePath); 
    if (file.is_open()) {
        
        file >> Geometry2D.geometryFragmentSizeX;
        file >> Geometry2D.geometryFragmentSizeY;
        file >> Geometry2D.geometryFragmentNumX;
        file >> Geometry2D.geometryFragmentNumY;
        
        file.close();
    }
    else cout << "Error. File is not opened! \n";
    
    cout << " Print: ";
    Geometry2D.Print(ConsConf.geometryFilePath);

   // Geometry2D.data = new int[Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY];//!
    //Geometry2D.PushToDynamicArr(ConsConf.geometryFilePath);                                      //!

    //for (int i = 0; i < Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY; i++) {
    //    cout << Geometry2D.data[i];
    //}
    int *new_data = new int[Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY];
 
}

