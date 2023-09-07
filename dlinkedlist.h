#pragma once

template<typename T>
class D_Node {
	D_Node<T>* _prev;
	T _data;
	D_Node<T>* _next;
public:
	D_Node() :_prev(), _data(), _next() {}

	void setPrev(D_Node<T>* prev);
	void setData(T data);
	void setNext(D_Node<T>* next);

	D_Node<T>* getPrev() { return _prev; }
	D_Node<T>* getNext() { return _next; }
	T getData() { return _data; }

};


template<typename T>
void D_Node<T>::setPrev(D_Node<T>* prev) {
	this->_prev = prev;
}

template<typename T>
void D_Node<T>::setData(T data) {
	this->_data = data;
}

template<typename T>
void D_Node<T>::setNext(D_Node<T>* next) {
	this->_next = next;
}



template<typename T>
class Double_Linked_List {
	D_Node<T>* _head;
public:
	Double_Linked_List() :_head() {}

	void AddBegin(D_Node<T>* item);
	void AddBegin(T data);

	void AddEnd(T data);
	void AddEnd(D_Node<T>* item);

	void AddAfter(D_Node<T>*& node, T data);
	void AddAfter(D_Node<T>*& node, D_Node<T>* item);

	void AddBefore(D_Node<T>*& node, T data);
	void AddBefore(D_Node<T>*& node, D_Node<T>* item);

	void DeleteBegin();
	void DeleteEnd();
	void DeleteByValue(D_Node<T>* item);
	void DeleteByValue(const T data);

	D_Node<T>* SearchByValue(D_Node<T>* item);
	D_Node<T>* SearchByValue(T data);

};

template<typename T>
void Double_Linked_List<T>::AddBegin(D_Node<T>* item) {
	item->setNext(this->_head);
	

	if (_head != nullptr)
		_head->setPrev(item);
	_head = item;
}


template<typename T>
void  Double_Linked_List<T>::AddBegin(T data) {
	D_Node<T>* newNode = new D_Node<T>();
	newNode->setData(data);
	this->AddBegin(newNode);

}


template<typename T>
void Double_Linked_List<T>::AddEnd(T data) {
	D_Node<T>* newNode = new D_Node<T>();
	newNode->setData(data);
	this->AddEnd(newNode);

}

template<typename T>
void Double_Linked_List<T>::AddEnd(D_Node<T>* item) {
	D_Node<T>* newNode = new D_Node<T>();
	newNode = _head;

	while (newNode->getNext() != nullptr) {
		newNode = newNode->getNext();
	}

	item->setPrev(newNode);
	newNode->setNext(item);
}



template<typename T>
void Double_Linked_List<T>::AddAfter(D_Node<T>*& node, T data) {
	D_Node<T>* newNode = new D_Node<T>();
	newNode->setData(data);
	this->AddAfter(node,newNode);
}

template<typename T>
void Double_Linked_List<T>::AddAfter(D_Node<T>*& node, D_Node<T>* item){
	D_Node<T>* temp=node->getNext();
	node->setNext(item);
	item->setPrev(node);
	item->setNext(temp);

}


template<typename T>
void Double_Linked_List<T>::AddBefore(D_Node<T>*& node, T data) {
	D_Node<T>* temp = new D_Node<T>();
	temp->setData(data);
	this->AddBefore(node,temp);
}


template<typename T>
void Double_Linked_List<T>::AddBefore(D_Node<T>*& node, D_Node<T>* item) {
	D_Node<T>* temp = node->getPrev();
	node->setPrev(item);
	item->setNext(node);
	item->setPrev(temp);
}


template<typename T>
void Double_Linked_List<T>::DeleteBegin() {
	D_Node<T>* temp = _head->getNext();
	delete[]_head;
	_head = temp;
}


template<typename T>
void Double_Linked_List<T>::DeleteEnd() {
	D_Node<T>* temp = _head;
	while (temp->getNext()!=nullptr)
	{
		temp= temp.getNext();
	}
	temp->getPrev()->setNext(nullptr);
	delete[]temp;
}


template<typename T>
void Double_Linked_List<T>::DeleteByValue(D_Node<T>* item) {
	this->DeleteByValue(item->getData());

}


template<typename T>
void Double_Linked_List<T>::DeleteByValue(const T data) {
	D_Node<T>* temp = _head;
	while (temp->getNext() != nullptr)
	{
		if (temp->getData() == data)break;
		temp = temp.getNext();
	}
	temp->getPrev()->setNext(temp->getNext());
	temp->getNext()->setPrev(temp->getPrev());
	delete[]temp;

}


template<typename T>
D_Node<T>* Double_Linked_List<T>::SearchByValue(D_Node<T>* item) {
	return this->SearchByValue(item->getData());
}


template<typename T>
D_Node<T>* Double_Linked_List<T>::SearchByValue(T data) {
	D_Node<T>* temp = _head;
	while (temp->getNext() != nullptr)
	{
		if (temp->getData() == data)return temp;
	}
}














