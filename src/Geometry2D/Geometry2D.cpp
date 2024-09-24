
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

	//инициализируем массив с заданным размером
	void InitArr(size_t size) {
		data = new int[size];
	}

	//вносим модель в динамический массив
	void PushToDynamicArr(string filePath) {
		ifstream file(filePath);
		if (file.is_open()) {
			string line;

			//пропускаем первую строку в файле
			getline(file, line);

			while (getline(file, line)) {
				// проверка комментариев
				if (line[0] == char("/") and line[1] == char("/")) {
					continue;
				}
				else {
					for (int i = 0; i < size(line); i++) {
						data[i] = line[i] - '0';
					}
				}
			}
			file.close();
		}
		else {
			cout << "Error. File is not opened! \n" << filePath << endl;
		}
	}

	//выводим массив в консоль
	void PrintArr() {
		for (int i = 0; i < geometryFragmentNumX * geometryFragmentNumY; i++) {
		cout << data[i];
		}
	}

};


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	string PATH_test = "C:/Users/ilyat/Desktop/cpp geometry/cpp-geometry2D/data/txt.txt"; // PATH - test

	ConsoleConfig ConsConf;
	GeometryDescription Geometry2D;

	ConsConf.SetPath(PATH_test);														  // PATH - test

	cout << "ConsoleConfig tests: \n";
	ConsConf.ReadCommandLineArgs(argc, argv);
	cout << ConsConf.TakePath() << endl;
	cout << ConsConf.TakeFormat() << endl;
	cout << "ConsoleConfig tests end. \n" << endl;

	cout << "GeometryDescription tests: \n";
	Geometry2D.ReadArgsFromFile(PATH_test);
	cout << Geometry2D.Take(1) << endl;
	cout << Geometry2D.Take(2) << endl;
	cout << Geometry2D.Take(3) << endl;
	cout << Geometry2D.Take(4)<< "\n" << endl;
	Geometry2D.Print(PATH_test);
	cout << "GeometryDescription tests end. \n" << endl;

	//создаём и заполняем массив
	size_t size = Geometry2D.Take(3) * Geometry2D.Take(4);
	Geometry2D.InitArr(size);
	Geometry2D.PushToDynamicArr(ConsConf.TakePath());        

	//выводим массив
	Geometry2D.PrintArr();
}

