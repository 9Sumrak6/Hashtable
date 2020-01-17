#pragma once
#include <iostream>

using namespace std;

template <typename K, typename T> 
class HashTable{
	struct Node{
		K key;
		T value;
		Node *next;
	};
	Node** cells;
	int capacity;
	int size;
	int (*h)(K);
public:
	HashTable(int capacity, int (*h)(K));
	void Insert(K key, T value);
	T* Find(K key);
	void Print();
	~HashTable();
};

template <typename K, typename T> 
HashTable<K, T>::HashTable(int capacity, int (*h)(K)){
	this->capacity = capacity;
	this->h = h;
	size = 0;
	cells = new Node*[capacity];
	for (int i = 0; i < capacity; i++)
		cells[i] = NULL;
}

template <typename K, typename T> 
void HashTable<K, T>::Insert(K key, T value){
	int index = h(key) % capacity;
	Node *node = new Node;
	node->key = key;
	node->value = value;
	node->next = cells[index];
	cells[index] = node; 
	size++;
}

template <typename K, typename T> 
T* HashTable<K, T>::Find(K key){
	int index = h(key) % capacity;
	Node *node = cells[index];

	while (node != NULL){
		if (node->key == key)
			return &node->value;
	
		node = node->next;
	}
	
	return NULL;
}

template <typename K, typename T> 
void HashTable<K, T>::Print(){
	for (int i = 0; i < capacity; i++){
		if (!cells[i])
			continue;
		cout << i << ": ";
		for (Node* node = cells[i]; node; node = node->next)
			cout << "[" << node->key << ", " << node->value << "]  ";
		cout << endl;
	}
	cout << "size: " << size << endl;
}

template <typename K, typename T> 
HashTable<K, T>::~HashTable(){
	for (int i = 0; i < capacity; i++){
		while(cells[i]){
			Node *tmp = cells[i];
			cells[i] = cells[i]->next;
			delete tmp;
		}
	}
	delete[] cells;
}