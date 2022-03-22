#include<vector>

using namespace std;

template<typename T>
class Stack {
public:
	Stack();
	bool empty() const;
	int size() const;
	T& top();
	void push(T);
	void pop();
private:
	vector<T> v;
};

template<typename T>
Stack<T>::Stack() {
	this->v = {};
}

// checks if container is empty
template<typename T>
bool Stack<T>::empty() const {
	return (v.size() == 0);
}

// return the size of container
template<typename T>
int Stack<T>::size() const {
	return v.size();
}

// access top element
template<typename T>
T& Stack<T>::top() {
	return v.back();
}

// adds element to top of stack
template<typename T>
void Stack<T>::push(T t) {
	v.push_back(t);
	return;
}

// remove element from top of stack
template<typename T>
void Stack<T>::pop() {
	if(v.size() > 0) {
		v.pop_back();
	} else {
		cout << "Stack is empty" << endl;
	}
	return;
}