#pragma once
#include <iostream>
#include <vector>
#include <iterator>
//#include "functions.h"

using namespace std;

int search(vector<string>v, string data) 
{
	auto it = find(v.begin(), v.end(), data);
	if (it != v.end()) 
	{
		return it - v.begin();
	}
}


// ****************************************************************************
//                            LINKED LIST
template<class T>
struct Node
{
	Node <T>* next_add;
	Node <T>* prev_add;
	T data;
};
template<class T>
class List
{
private:


public:
	Node <T>* head;
	Node <T>* tail;
	int size;
	// Constructor
	List(Node <T>* ptr = NULL, Node <T>* ptr2 = NULL)
	{
		head = ptr;
		size = 0;
		tail = ptr2;
	}
	Node <T>* get_head()
	{
		return this->head;
	}

	// ---------------------------------------------- INSERTION ------------------------------------
	void insert(int index, T value)
	{
		int ind = 0;
		Node <T>* temp = new Node <T>;
		//temp = head;
		temp->data = value;
		//cout << "my data "<< temp->data << endl;

		if (index == 0)
		{
			// --------------
			//Node <T>* temp = new Node <T>;		
			if (head == NULL)
			{
				head = temp;
				temp->next_add = NULL;
				tail = temp;
			}
			else
			{
				temp->next_add = head;
			}
			head = temp;
		}
		else
		{
			Node <T>* ptr = new Node <T>;
			Node <T>* ptr2 = new Node <T>;
			ptr2 = head, ptr = head;
			// Traversing
			while (ptr2->next_add != NULL)
			{
				if (ind == index)
				{
					break;
				}
				ptr2 = ptr2->next_add;
				/*if (ptr2->next_add != NULL)
				{
					ptr = ptr->next_add;

					ptr2 = ptr2->next_add;
				}*/
				ind++;

			}
			//Node <T>* temp = new Node <T>;
			if (ptr2->next_add == NULL) // If tail
			{
				temp->next_add = NULL;
				tail->next_add = temp;
				tail = temp;
			}
			else
			{
				temp->next_add = ptr->next_add;
				ptr->next_add = temp;
			}

			size++;

		}
	}

	// ----------------------------------------------  SEARCH  -------------------------------------
	int search(T value)
	{
		Node <T>* ptr = new Node <T>;
		ptr = head;
		int ind = 0;
		while (ptr->next_add != NULL)
		{
			ptr = ptr->next_add;
			ind++;
			if (ptr->data == value)
			{
				return ind;
			}

		}
		return -1;
	}

	T return_at_index(int x) 
	{
		Node <T>* ptr = new Node <T>;
		ptr = head;
		int ind = 0;
		while (ptr->next_add != NULL) 
		{
			if (ind != x) 
			{
				ptr = ptr->next_add;
				ind++;
			}
			else 
			{
				return ptr->data;
			}
		}
		if (ind == x) 
		{
			return ptr->data;
		}

	}

	// ----------------------------------------------- ENQUE -------------------------------------
	void enque(T d)
	{
		// insert at end
		Node <T>* temp = new Node <T>;
		temp->data = d;
		temp->next_add = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			size++;
		}
		else
		{
			tail->next_add = temp;
			tail = temp;
			size++;
		}
	}
	// ----------------------------------------------  UPDATE  -------------------------------------
	bool update(int index, T value)
	{
		Node <T>* ptr = new Node <T>;
		ptr = head;
		int ind = 0;
		int check = 0;
		while (ptr->next_add != NULL)
		{
			ptr = ptr->next_add;
			ind++;
			if (ind == index)
			{
				ptr->data = value;
				return true;

			}
			else
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			return false;
		}

	}

	// ----------------------------------------------  DELETE  -------------------------------------
	void del(T value)
	{

		Node <T>* temp = new Node <T>;
		temp = head;
		Node <T>* prev = new Node <T>;
		int check = 0;
		//temp = head;
		while (temp->next_add->data != value)
		{
			temp = temp->next_add;
		}

		prev = temp;
		temp = temp->next_add;
		if (temp->next_add == NULL)
		{
			prev->next_add = NULL;
		}
		else
		{
			prev->next_add = temp->next_add;
		}
		delete temp;

	}

	// -------------------------------------------  Destructor  -------------------------------------
	~List(void)
	{
		Node <T>* current = head;
		while (current != NULL)
		{
			Node <T>* temp = current;
			current = current->next_add;
			delete temp;
		}
	}

	// -------------------------------------------  DISPLAY  ----------------------------------------
	void display(List& g)
	{
		Node <T>* current = new Node <T>;
		current = g.head;
		while (current->next_add != NULL)
		{
			cout << current->data << " ";
			if (current->next_add != NULL)
			{
				current = current->next_add;
			}
		}
		cout << current->data << " ";
		cout << endl;
	}

	// -------------------------------------------  get data  ---------------------------------------
	T get_data()
	{
		return head->data;
	}

	// ------------------------------------------- overloaded data ----------------------------------
	void operator = (const List& D)
	{
		this->head = D.head;
		this->tail = D.tail;
		this->size = D.size;
	}


};

