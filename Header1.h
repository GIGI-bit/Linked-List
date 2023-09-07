#pragma once

// NODE 

template<typename T>
void Node<T>::setData(T data) {
	if (data != NULL || data != '\0')
		_data = data;
	else throw - 1;
}

template<typename T>
void Node<T>::setNext(Node* next) {
	_next = next;
}

//SINGLE LINKED LIST




template<typename T>
void Single_Linked_List<T>::AddBegin(const T& item) {
	Node<T>* newNode = new Node<T>();
	newNode->setData(item);
	this->AddBegin(&newNode);

}

template<typename T>
void Single_Linked_List<T>::AddBegin(Node<T>*& item) {
	Node<T>* temp = item;

	temp->setNext(this->_head);
	this->_head = temp;

}


template<typename T>
void Single_Linked_List<T> ::AddEnd(const T& item) {
	Node<T>* newNode = new Node<T>();
	newNode->setData(item);
	this->AddEnd(newNode);
}



template<typename T>
void Single_Linked_List<T>::AddEnd(Node<T>*& item) {
	if (this->_head != nullptr)
	{
		Node<T>* temp = this->_head;


		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}

		temp->setNext(item);
	}
	else {
		this->_head = item;
		return;
	}
}


template<typename T>
void Single_Linked_List<T>::AddBefore(Node<T>*& node, const T& data) {
	Node<T>* temp = new Node<T>();
	temp->setData(data);

	this->AddBefore(node, temp);
}


template<typename T>
void Single_Linked_List<T>::AddBefore(Node<T>*& node, Node<T>*& item) {

	Node<T>* temp = this->_head;

	while (true)
	{
		if (temp->getNext() == NULL)return;
		if (temp->getNext()->getData() == node->getData() && temp->getNext()->getNext() == node->getNext()) {
			break;
		}
		temp = temp->getNext();
	}

	Node<T>* newNode = new Node<T>();
	newNode->setNext(temp->getNext());
	temp->setNext(item);
	item->setNext(newNode->getNext());

}


template<typename T>
void Single_Linked_List<T>::AddAfter(Node<T>*& node, T& data) {
	Node<T>* newNode = new Node<T>();
	newNode->setData(data);

	this->AddAfter(newNode);
}


template<typename T>
void Single_Linked_List<T>::AddAfter(Node<T>*& node, Node<T>*& item) {
	Node<T>* temp = this->_head;

	while (true)
	{
		if (temp->getNext() == NULL)return;
		if (temp->getData() == node->getData() && temp->getNext() == node->getNext())break;
		temp = temp->getNext();
	}

	Node<T>* newNode = new Node<T>();
	newNode->setNext(temp->getNext());

	temp->setNext(node);
	node->setNext(newNode->getNext());

}

template<typename T>
void Single_Linked_List<T>::DeleteBegin() {

	if (this->_head = NULL)throw - 1;

	Node<T>* temp = this->_head;
	delete[]this->_head;
	this->_head = temp->getNext();
	delete[] temp;
}


template<typename T>
void Single_Linked_List<T>::DeleteEnd() {
	Node<T>* temp = this->_head;
	while (temp->getNext()->getNext() != NULL)
	{
		temp = temp->getNext();
	}

	delete[]temp->getNext();
	temp->setNext(NULL);
}


template<typename T>
void Single_Linked_List<T>::DeleteByValue(Node<T>*& item) {

	Node<T>* temp = this->_head;

	if (temp->getData() == item->getData())this->DeleteBegin();

	while (temp->getNext() != NULL)
	{
		if (temp->getNext()->getData() == item.getData()) {
			Node<T>* newNode = temp->getNext()->getNext();
			delete[]temp->getNext();
			temp->setNext(newNode);
			delete this->_head;
			this->_head = temp;
			return;
		}
		temp = temp->getNext();
	}
	throw "Node Not Found";
}


template<typename T>
void Single_Linked_List<T>::DeleteByValue(const T& data) {

	Node<T>* newNode = new Node<T>();
	newNode->setData(data);
	this->DeleteByValue(newNode);

}


template<typename T>
Node<T>* Single_Linked_List<T>::SearchByValue(Node<T>*& item) {
	Node<T>* temp = this->_head;

	while (temp->getNext() != NULL)
	{
		if (temp->getData() == item->getData()) {
			return temp;
		}
		temp = temp->getNext();
	}


}


template<typename T>
Node<T>* Single_Linked_List<T>::SearchByValue(const T& data) {

	Node<T>* temp = this->_head;
	temp->setData(data);
	this->SearchByValue(temp);
}




