#include<iostream>
#include<cassert>
using namespace std;


class IntArray {
	int* arr;
	size_t size = 0;

	void SetSize( const size_t& size) {
		assert(size > 0 && "Array Size cannot be less than 0");
		this->size = size;
	}
public:
	IntArray() :arr(nullptr), size(0) {}

	IntArray operator=(const IntArray& other) {
		SetArray(other.GetArray());
		return *this;
	}

	IntArray(int* arr, const size_t& size)
	{
		SetArray(arr);
		SetSize(size);
	}

	int* GetArray()const {
		return arr;
	}
	size_t GetSize()const {
		return size;
	}

	void SetArray(int* arr) {
		this->arr = arr;
	}

	void AddElementToStart(int a) {
		auto newarray = new int[size + 1]{};
		int index = 0;
		newarray[index] = a;
		index++;
		for (size_t i = 0; i < size; i++)
		{
			newarray[index] = arr[i];
		}
		size++;
		arr = newarray;
		newarray = nullptr;
	}

	void AddElementToEnd(int a) {
		auto newarray = new int[size + 1]{};
		int index = 0;
		for (size_t i = 0; i < size; i++)
		{
			newarray[index] = arr[i];
		}
		newarray[index] = a;
		size++;
		arr = newarray;
		newarray = nullptr;

	}

	void Copy(int*&newarr) {
		newarr = new int [size] {};
		newarr = arr;
	}
	void print() {
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}cout << endl;
	}
	void Update(int index, int a) {
		assert(index < size && "Index Value cannot be more than size");
		arr[index] = a;
	}
};

void main() {
	size_t size = 0;
	int* myarray = {};
	int* mynewarray;
	IntArray arr(myarray);

	cout << "1 ci array	"; arr.AddElementToEnd(10);
	arr.print();
	cout << "2 ci array	"; arr.AddElementToEnd(20);
	arr.print();
	cout << "3 ci array	"; arr.AddElementToEnd(90);
	arr.print();
	cout << "add element	"; arr.AddElementToEnd(1000);
	arr.print();
	cout << "update element	"; arr.Update(3, 55);
	arr.print();
	cout << "Copy array	"; arr.Copy(mynewarray);
	arr.print();

}
