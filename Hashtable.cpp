//Using Open Addressing or Seperate Chaining
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
	T key;
	T value;
	node<T> *next;

	node(string key, T val)
	{
		this->key = key;
		this->value = val;
		next = NULL;
	}

	~node()
	{
		if (next != NULL)
		{
			delete next;
		}
	}
};

template <typename T>
class hashtable
{
	//Pointer pointing to an array of pointers(which will conatin the head of the linked list used for chaining)
	node<T> **table;
	int current_size;
	int table_size;

	int hashFn(string key)
	{
		int idx = 0;
		int p = 1;
		for (int j = 0; j < key.length(); j++)
		{
			idx += (key[j] * p) % table_size;
			idx = idx % table_size;
			p = (p * 27) % table_size;
		}
		return idx;
	}

	void rehash()
	{
		node<T> **oldTable = table;
		int oldTableSize = table_size;
		table_size = table_size * 2;
		table = new node<T> *[table_size];
		//Initialize new table values with NULL
		for (int i = 0; i < table_size; i++)
		{
			table[i] = NULL;
		}
		current_size = 0;
		//Shifting elements from the old hash-table to new hash-table
		for (int i = 0; i < oldTableSize; i++)
		{
			node<T> *temp = oldTable[i];
			while (temp != NULL)
			{
				insert(temp->key, temp->value);
				current_size++;
				temp = temp->next;
			}
			if (oldTable[i] != NULL)
			{
				//Destructor is called recursively
				//This delete will point to the head of the linked list
				delete oldTable[i];
			}
		}
		delete[] oldTable;
	}

public:
	hashtable(int ts = 7)
	{
		table_size = ts;
		//Making table pointer point to an array of pointers
		table = new node<T> *[table_size];
		current_size = 0;
		for (int i = 0; i < table_size; i++)
		{
			table[i] = NULL;
		}
	}

	void insert(string key, T value)
	{
		int index = hashFn(key);
		//Now we create a linked list
		node<T> *n = new node<T>(key, value);
		//Insert at head of the linked list with id=index
		n->next = table[index];
		table[index] = n;
		current_size++;

		//rehash
		float load_factor = current_size / (1.0 * table_size);

		if (load_factor > 0.7)
		{
			rehash();
		}
	}

	void print()
	{
		for (int i = 0; i < table_size; i++)
		{
			cout << "Bucket " << i << "-->";
			node<T> *temp = table[i];
			while (temp != NULL)
			{
				cout << temp->key << "-->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T *search(string key)
	{
		int idx = hashFn(key);
		node<T> *temp = table[idx];
		while (temp != NULL)
		{
			if (temp->key == key)
			{
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}

	T &operator[](string key)
	{
		T *f = search(key);
		if (f == NULL)
		{
			T garbage;
			insert(key, garbage);
			f = search(key);
		}
		return *f;
	}

	void erase(string key)
	{
		int idx = hashFn(key);
		node<T> *temp = table[idx];
		if (temp->key == key)
		{
			table[idx] = temp->next;
			temp->next = NULL;
			delete temp;
			current_size--;
			return;
		}
		while (temp != NULL)
		{
			if (temp->next->key == key)
			{
				node<T> *ptr = temp->next;
				temp->next = ptr->next;
				ptr->next = NULL;
				delete ptr;
				return;
			}
			temp = temp->next;
		}
	}
};
