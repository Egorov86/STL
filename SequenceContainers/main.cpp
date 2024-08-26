#include<iostream>
#include<array>
#include<vector>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_LIST

template<typename T> void vector_properties(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - контейнер, который хранит  данные в виде статического массива.
	const int SIZE = 5;
	std::array<int, SIZE> arr = {3, 5, 8};
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - контейнер который хранит данные в виде динамического массива.
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec.at(i) << tab;
			//cout << vec[i] << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);

	vec.push_back(144);
	vector_properties(vec);

	//vec.resize(15); // задаёт фактический размер Вектора.
	vec.shrink_to_fit(); //урезает вместительность до фактического размера.
	vec.reserve(120);   // резервирует память до нужного объёма памяти до 120, метод выполняется 
	//если мы передаём значение больше текущего capacity().
	for (int i : vec)cout << i << tab; cout << endl;
	vector_properties(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << vec.data() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << *(vec.data()+i) << tab;
		//cout << vec.data()[i] << tab;
	}
	cout << endl;
	cout << "Iterators:" << endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int index;
	int value;
	cout << "Введите индекс элемента для вставки (от 0 до " << vec.size() << "): ";
	cin >> index;
	while (index < 0 || index >= vec.size()) 
	{
		cout << "Неверный индекс. Пожалуйста, введите число от 0 до " << vec.size() << ": ";
		cin >> index;
	}
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	std::vector<int>::iterator position = vec.begin();
	std::advance(position, index);
	vec.insert(position, value);
	//vec.insert(vec.begin() + index, value); //  Добавление элемента с клавиатуры и по значению индекса.
	vector_properties(vec);
	cout << vec.data() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << *(vec.data() + i) << tab;
	}

	vec.erase(vec.begin() + index); //  Удаление элемента по значению индекса.
	vector_properties(vec);
	cout << vec.data() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << *(vec.data() + i) << tab;
	}
	
#endif // STL_VECTOR

#ifdef STL_LIST

	std::list<int> list = { 3, 5, 8, 13, 21, 34, 55 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;
	int index;
	int value;
	cout << "Введите индекс элемента :"; cin >> index;
	cout << "Введите значение элемента :"; cin >> value;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)++position;
	std::advance(position, index);
	list.insert(position, value);
	for (int i : list) cout << i << tab; cout << endl;

#endif // STL_LIST


}


template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "SIZE:\t" << vec.size() << endl;
	cout << "CAPACITY:" << vec.capacity() << endl;
	cout << "MAX_SIZE:" << vec.max_size() << endl;
	cout << delimiter << endl;
}