#include <iostream>
#include <vector>
#include <list>//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;

class Stack {
	list<int> data; // пример реализации стека на списке
	unsigned int index = 0; // индекс, по которому будет добавляться очередной новый элемент
	// также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент

public:
	void Clear() {
		index = 0;
	}

	bool IsEmpty() const {
		return index == 0;
	}

	bool IsFull() const {
		return false;
	}

	unsigned int GetCount() const {
		return index;
	}

	void Push(int value) {
		data.push_back(value);
		index++;
	}

	void Pop() {
		if (!IsEmpty()) {
			data.pop_back();
			index--;
		}
	}

	int Peek() {
		if (!IsEmpty())
			return data.back();
		else throw "Stack is empty!";
	}



	bool Contains(int value) const 
	{
		if (IsEmpty()) {
			throw "Stack is empty!";
		}

		
		for (auto x = data.begin(); x != data.end(); ++x) {
			if (*x == value) 
			{ 
				return true;
			}
		}
		return false;
	}

	void Print()
	{
		for (auto x = data.begin(); x!=data.end(); ++x)
		{
			cout << (*x)<< "\t";
		}
	}

	void PushLessValue(int value)
	{
		
		if (data.back() > value)
		{
			Push(value);
		}
	}

	void PushUnique(int value)
	{
		if (!Contains(value))
		{
			Push(value);
		}
	}

	bool Correct(const char *exp)
	{

		for (int i = 0; i < strlen(exp); i++)
		{
			if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' || exp[i] == '<')
				Push(exp[i]);
		}
		for (int i = 0; i < strlen(exp); i++)
		{
			if (exp[i] == ')' && data.back() == '(' || exp[i] == ']' && data.back() == '[' || exp[i] == '}' && data.back() == '{' || exp[i] == '>' && data.back() == '<')
				Pop();
		}
		return IsEmpty();		
	}
};

int main() {
	Stack st; // создаём "пустой" стек



	
		// до тех пор, пока стек не заполнился
	for (int i = 0; i < 10; i++)
		st.Push(rand() % 90 + 10); // добавляем элемент на вершину стека
		
	st.Print();
	cout << "\n";


	if (st.Contains(99)) cout << "element is in list\n";
	else cout << "element is not in list\n";

	st.PushLessValue(1);
	st.Print();
	cout << "\n";
	st.PushLessValue(99);
	st.Print();
	cout << "\n";

	st.PushUnique(99);
	st.Print();
	cout << "\n";
	st.PushUnique(2);
	st.Print();
	
	cout << "\n";

	st.Clear();

	cout << st.Correct("{(5-[3+<9>])-4}");
	cout << "\n";

	cout << st.Correct("{(>5-<[3+)9]-4}");

	/*
	// до тех пор, пока в стеке есть какие-либо значения
	while (!st.IsEmpty()) {
		cout << st.Peek() << "  ";
		st.Pop(); // извлечь значение и показать на экране
	}
	*/


}