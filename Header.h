#pragma once

template<typename T>
class Node {
public:
	T _data;
	Node<T>* _next;
	Node() :_data(), _next() {}
	Node(T data, Node<T> next) {
		setData(data);
		setNext(next);
	}

	void setData(T data);
	void setNext(Node<T>* next);

	T getData() { return _data; }
	Node<T>* getNext() { return _next; }


};


template<typename T>
class Single_Linked_List {
	Node<T>* _head;
public:
	Single_Linked_List() :_head() {}

	void AddBegin(Node<T>*& item);
	void AddBegin(const T& item);

	void AddEnd(Node<T>*& item);
	void AddEnd(const T& item);

	void AddBefore(Node<T>*& node, const T& data);
	void AddBefore(Node<T>*& node, Node<T>*& item);

	void AddAfter(Node<T>*& node, T& data);
	void AddAfter(Node<T>*& node, Node<T>*& item);

	void DeleteBegin();
	void DeleteEnd();
	void DeleteByValue(Node<T>*& item);
	void DeleteByValue(const T& data);

	Node<T>* SearchByValue(Node<T>*& item);
	Node<T>* SearchByValue(const T& data);

	template<typename T>
	friend ostream& operator<<(ostream& print, const Single_Linked_List<T> item) {
		Node<T>* temp = item._head;

		while (temp != NULL)
		{
			print << temp->getData() << endl;
			temp = temp->getNext();
		}
		return print;
	}

};

