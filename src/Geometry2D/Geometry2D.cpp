
#include <fstream> 
#include <iostream>
#include <string>

using namespace std;

class ConsoleConfig {
private:
	string geometryFileFormat;
	string geometryFilePath;

public:
	void ReadCommandLineArgs(int argc, char* argv[]) {
		for (int i = 0; i < argc; i++) {
			if (i + 1 < argc) {
				if (string(argv[i]) == "-ff") {
					SetFormat(string(argv[i + 1]));
				}
				if (string(argv[i]) == "-fp") {
					SetPath(string(argv[i + 1]));
				}
			}
		}
	}

	void SetPath(string Path) {
		geometryFilePath = Path;
	}
	string TakePath() {
		return geometryFilePath;
	}

	void SetFormat(string Format) {
		geometryFileFormat = Format;
	}
	string TakeFormat() {
		return geometryFileFormat;
	}
};

class GeometryDescription {
private:
	int geometryFragmentSizeX;
	int geometryFragmentSizeY;
	int geometryFragmentNumX;
	int geometryFragmentNumY;
	int* data;

public:

	//вводим значения из файла
	void ReadArgsFromFile(string Path) {
		ifstream file(Path);
		if (file.is_open()) {

			file >> geometryFragmentSizeX;
			file >> geometryFragmentSizeY;
			file >> geometryFragmentNumX;
			file >> geometryFragmentNumY;

			file.close();
		}
		else cout << "Error. File is not opened! \n";
	}

	//возвращаем выбранную переменную
	int Take(int id) {
		switch (id)
		{
		case 1:
			return geometryFragmentSizeX;
			break;
		case 2:
			return geometryFragmentSizeY;
			break;
		case 3:
			return geometryFragmentNumX;
			break;
		case 4:
			return geometryFragmentNumY;
			break;
		default:
			cout << " func Take: Error! Wrong id. " << endl;
			break;
		}
	}

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
	string PATH_test = "C:/Users/ilyat/Desktop/cpp geometry/cpp-geometry2D/data/txt.txt";

	ConsoleConfig ConsConf;
	GeometryDescription Geometry2D;

	ConsConf.SetPath(PATH_test);

	ConsConf.ReadCommandLineArgs(argc, argv);
	//ConsConf.SetPath(PATH);									// PATH - test
	//Geometry2D.ReadArgsFromFile(PATH);

	//cout << " Print: ";
	//Geometry2D.Print(PATH);

	// Geometry2D.data = new int[Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY];//!
	//Geometry2D.PushToDynamicArr(ConsConf.geometryFilePath);                                      //!

	 //for (int i = 0; i < Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY; i++) {
	 //    cout << Geometry2D.data[i];
	 //}
	//int* new_data = new int[Geometry2D.geometryFragmentNumX * Geometry2D.geometryFragmentNumY];

}

