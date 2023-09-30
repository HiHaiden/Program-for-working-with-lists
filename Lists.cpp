#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <math.h>

using namespace std;

template<typename T>
class List
{
	public:
		List();
		~List();
		
		void pop_front();
		void push_back(T data);
		void clear();
		void push_front(T data);
		void insert(T value, int index);
		void removeAt(int index);
		void pop_back();
		
		int GetSize() 
		{
		return Size;
		}
		
		T& operator[](const int index);
		
	private:
		template<typename D>
		class Node
		{
			public:
				Node *pNext;
				T data;
				Node(T data=T(), Node *pNext = NULL)
				{
					this->data = data;
					this->pNext = pNext;
				}
		};
	
	int Size;	
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = NULL;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		
		while(current->pNext !=NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	
	Size++;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while(current != NULL)
	{
		if(counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}	
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while(Size)
	{
		pop_front();
	}	
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if(index == 0)
	{
		push_front(data);
	}
	else
	{	
		Node<T> *previous = this->head;
			
		for (int i = 0; i < index - 1; i++)
		previous = previous->pNext;
			
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
			
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
			
		for (int i = 0; i < index - 1; i++)
		previous = previous->pNext;
			
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size-1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	
	List<string> lst;
	lst.push_back("523");
	lst.push_back("1350");
	lst.push_back("3217");
	lst.push_back("327");
	lst.push_back("549");
	lst.push_back("421");
	lst.push_back("535");
	lst.push_back("308");
	
	int d = 0;
	do
	{
		int val;
		cout << "Введите 1 для отображения списка." << endl;
		cout << "Введите 2 для удаления последнего элемента списка." << endl;
		cout << "Введите 3 для удаления первого элемента списка." << endl;
		cout << "Введите 4 для добавления элемента в начало списка." << endl;
		cout << "Введите 5 для добавления элемента в конец списка." << endl;
		cout << "Введите 6 для добавления элемента в середину списка." << endl;
		cout << "Введите 7 для определения количества элементов в списке." << endl;
		cout << "Введите 8 для проверки списка на пустоту." << endl;
		cout << "Введите 9 для поиска значения данных в списке по номеру." << endl;
		cout << "Введите любой другой символ для выхода из программы и вывода конечного списка." << endl;
		cin >> val;
		cout << "\n";
			
		if (val == 1)
		{
			if(lst.GetSize() == 0)
			{
				cout << "Список пустой." << endl;
				cout << "\n";
			}
			if(lst.GetSize() != 0)
			{
				cout << "Список:" << endl;
				for (int i = 0; i < lst.GetSize(); i++)
				{
					cout << i+1 << ". " << lst[i] << endl;	
				} 
				cout << "\n";
			}
		}
			
		if (val == 2)
		{
			if(lst.GetSize() == 0)
			{
			cout << "Больше нечего удалять." << endl;
			cout << "\n";
			}
			if (lst.GetSize() != 0)
			lst.pop_back();
		}
				
		if (val == 3)
		{
			if(lst.GetSize() == 0)
			{
			cout << "Больше нечего удалять." << endl;
			cout << "\n";
			}
			if (lst.GetSize() != 0)
			lst.pop_front();
		}
				
		if (val == 4)
		{
			cout << "Какой элемент добавить в начало списка?" << endl;
			string front;
			cin >> front;
			cout << "\n";
			lst.push_front(front);
		}
			
		if (val == 5)
		{
			cout << "Какой элемент добавить в конец списка?" << endl;
			string back;
			cin >> back;
			cout << "\n";
			lst.push_back(back);
		}
		
		if (val == 6)
		{
			cout << "Какой элемент добавить в середину списка?" << endl;
			string insert;
			cin >> insert;
			cout << "\n";
			lst.insert(insert, round(lst.GetSize()/2));
		}
		
		if (val == 7)
		{
			cout << "Количество элементов в списке: ";
			cout<<lst.GetSize()<<endl;
			cout << "\n";
		}
		
		if (val == 8)
		{
			if(lst.GetSize() == 0)
			{
				cout << "Список пуст." << endl;
				cout << "\n";
			}
			else
			{
				cout << "Список не пуст. В нём " << lst.GetSize() << " элементов." << endl;
				cout << "\n";
			}
		}
		
		if (val == 9)
		{
			if(lst.GetSize() == 0)
			{
				cout << "Эмм... В списке нет элементов." << endl;
				cout << "\n";
			}
			if(lst.GetSize() == 1)
			{
				cout << "В списке всего лишь 1 элемент. Вот его значение: " << lst[0] << endl;
				cout << "\n";
			}
			if(lst.GetSize() != 0 && lst.GetSize() != 1)
			{
				cout << "Если будут введены другие значения, то программа самоуничтожится." << endl;
				cout << "Введите номер элемента в списке(от 1 до " << lst.GetSize() <<  "): ";
				int numb;
				cin >> numb;
				cout << "\n";
				cout << "Значение данных в списке под номером " << numb << ": " << lst[numb-1] << endl;
				cout << "\n";
			}
		}
		
		if (val != 1 && val != 2 && val != 3 && val != 4 && val != 5 && val != 6 && val != 7 && val != 8 && val != 9)
		{
			break;
		}
		
		cout << "Продолжаем работу с программой?\n1 - Да.\nЛюбая другая клавиша - Нет + вывод конечного списка." << endl;
		cin >> d;
		cout << "\n";
		if (d != 1)
		d = 0;
	}
	while(d);
	
	if(lst.GetSize() == 0)
			{
			cout << "Упс... Весь список удалён тобою..." << endl;
			}
	if (lst.GetSize() != 0)
	{
		cout << "Конечный список:" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << i+1 << ". " << lst[i] << endl;	
		} 
	}
	cout << "\n";
	system("pause");
	return 0;
}