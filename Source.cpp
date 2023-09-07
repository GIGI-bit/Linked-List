#include<iostream>
#include<string>
#include<cassert>
using namespace std;
#include"Header.h"
#include"Header1.h"

int main() {

	Single_Linked_List<int> arr;
	arr.AddEnd(43);
	Node<int>* node = new Node<int>();
	node->setData(65);
	arr.AddBegin(node);

	cout << arr;
}

