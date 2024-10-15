#pragma once

#include <iostream>
#include <string>

using namespace std;

class CPU {
private:
	unsigned int freq;
	unsigned short thread_count;
public:

	void SetFreq(unsigned short Hz) {
		freq = Hz;
	}

	void SetThread_count(unsigned short num) {
		thread_num = num;
	}

	unsigned int TakeFreq() {
		return freq;
	}

	unsigned short TakeThread_count() {
		return thread_count;
	}

	void ShowSpecs() {
		cout << " frequencies = " << freq << "\n";
		cout << " CPU have a " << thread_count << "threads" << "\n";
	}

};

class GPU {
private:
	unsigned int amount_of_memory;
	unsigned int core_freq;
	unsigned int memory_freq;
	unsigned short memory_bus_width;
public:

	void SetCoreFreq(unsigned int Hz) {
		core_freq = Hz;
	}

	void SetMemFreq(unsigned int Hz) {
		memory_freq = Hz;
	}

	void SetAmOfMem(unsigned int Mb) {
		amount_of_memory = Mb;
	}

	void SetMemBusWid(unsigned int Bit) {
		memory_bus_width = Bit;
	}

	unsigned int TakeCoreFreq() {
		return core_freq;
	}

	unsigned int TakeMemFreq() {
		return memory_freq;
	}

	unsigned int TakeAmOfMem() {
		return amount_of_memory;
	}

	unsigned short TakeMemBusWid() {
		return memory_bus_width;
	}

	void ShowSpecs() {
		cout << " Amount of memory: " << amount_of_memory << "Mb" << "\n";
		cout << " Core frequency: " << ñore_freq / 1000 << "MHz" << "\n";
		cout << " Memory frequency: " << memory_freq / 1000 << "MHz" << "\n";
		cout << " Memory bus width: " << memory_bus_width << "Bit" << "\n";
	}
}

class Ram {
private:
	string type;
	unsigned int freq;
	unsigned int amount_of_memory;
public:

	void SetType(string DDR_type) {
		type = DDR_type;
	}

	void SetFreq(unsigned int HZ) {
		freq = Hz;
	}

	void AmOfMem(unsigned int Mb) {
		amount_of_memory = Mb;
	}

	string TakeType() {
		return type;
	}

	unsigned int TakeFreq() {
		return freq;
	}

	unsigned int TakeAmOfMem() {
		return amount_of_memory;
	}

	void ShowSpecs() {
		cout << " Amount of memory: " << amount_of_memory << "Mb" << "\n";
		cout << " Frequency: " << freq / 1000 << "MHz" << "\n";
		cout << " Type: " << type << "\n";
	}
};

class Node {
private:
	vector<CPU> CPU_spec;
	vector<GPU> GPU_spec;
	vector<Ram> RAM_spec;
public:

	void SetCpuSpecs(const CPU& CPU_object) {
		CPU_spec.push_back(CPU_object)
	}

	void SetGpuSpecs(const GPU& GPU_object) {
		GPU_spec.push_back(GPU_object)
	}

	void SetRamSpecs(const RAM& RAM_object) {
		RAM_spec.push_back(RAM_object)
	}

	// êîëè÷åñòâî ýëåìåíòîâ â ñîîòâåòñòâóþùåì âåêòîðå
	unsigned short CountOfElem(unsigned short id_of_elem) {
		switch (id_of_elem) {
		case 1:
			return unsigned short(CPU_spec.size());
			break;
		case 2:
			return unsigned short(GPU_spec.size());
			break;
		case 3:
			return unsigned short(RAM_spec.size());
			break;
		default:
			cout << "Node:CountOfElem error. Wrong id of elem!";
			break;
		}
	}

	void TakeCpuSpecs() {
		unsigned short count = CountOfElem(1);

		for (int i = 0; i < count; i++) {
			CPU_spec[i].ShowSpecs();
			cout << "\n";
		}
	}

	void TakeGpuSpecs() {
		unsigned short count = CountOfElem(2);

		for (int i = 0; i < count; i++) {
			GPU_spec[i].ShowSpecs();
			cout << "\n";
		}
	}

	void TakeRamSpecs() {
		unsigned short count = CountOfElem(3);

		for (int i = 0; i < count; i++) {
			RAM_spec[i].ShowSpecs();
			cout << "\n";
		}
	}

};