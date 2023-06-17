#pragma once
#include <iostream>
#include "Linked.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
static int stat() 
{
	static int p = 0;
	p++;
	return p;
}

//                   DIJKASTRA 


// Smallest 
int findSmallestElement(int arr[], int n)
{
	int temp = arr[0];
	for (int i = 0; i < n; i++) 
	{
		if (temp > arr[i]) 
		{
			temp = arr[i];
		}
	}
	return temp;
}


// ************************************************************
// ************************************************************
// ************************************************************
// Checking 2nd shortest distance of one node to other 
vector<int>return_edges(string str)
{
	str.push_back('/');
	vector <int> x;
	int number = 0;
	int size = str.length();

	for (int i = 0; i < size; i++)
	{
		string st = "";
		for (i; str[i] != '/'; i++)
		{
			st.push_back(str[i]);
		}
		x.push_back(stoi(st));
	}

	// Removes duplicates of a vector 
	for (int i = 0; i < x.size() - 1; i++)
	{
		if (x[i] == x[i + 1])
		{
			x.erase(x.begin() + i);
		}
	}

	return x;
}


// ************************************************************
// Display Vector
template <class T>
void display(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] ;
	}
	cout << endl;
}


// ----------------------------------------------------------------
// ****************************************************************
// Floyd's Algorithm
int** floids_algo(int**& arr, int& size, string**& shortest_city_path)

{

	shortest_city_path = new string * [size];
	for (int i = 0; i < size; i++)
	{
		shortest_city_path[i] = new string[size];
	}
	// Appending paths on the shortest string
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			shortest_city_path[i][j].append(to_string(i));
			shortest_city_path[i][j].append("/");
			shortest_city_path[i][j].append(to_string(j));
		}
	}

	// Making a new array Graph to copy the original
	int** graph = new int* [size];
	for (int i = 0; i < size; i++)
	{
		graph[i] = new int[size];
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			graph[i][j] = arr[i][j];
		}
	}

	// Applying floyd's algorithm 
	int index = 0, num1 = 0, num2 = 0;
	while (index < size)
	{
		for (int i = 0; i < size; i++) // The node we are going to keep as the middle node 
		{
			for (int j = 0; j < size; j++)
			{
				// shortest_city_path[i][j]
				if ((i != j) && (index != i) && (index != j))
				{
					num1 = graph[i][index];
					num2 = graph[index][j];

					if (graph[i][j] > (num1 + num2))
					{
						// Storing the names of cities in the array sgortest_city_path
						graph[i][j] = (num1 + num2);
						shortest_city_path[i][j] = "";
						shortest_city_path[i][j].append(shortest_city_path[i][index]);
						shortest_city_path[i][j].append("/");
						shortest_city_path[i][j].append(shortest_city_path[index][j]);
					}
				}
			}
		}
		index++;
	}
	return graph;
}



// ***************************************************************
// Second shortest 
void second_shortest(int source, int dest, int size, int** original, string** shortest_city, string **&str)
{

	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = original[i][j];
		}
	}
	string s = shortest_city[source][dest]; // 1/2/3
	// Return edges of path
	vector <int> path = return_edges(s);    // 1 2 3 
	display(path);
	
	// Deleting all the edges to th eshortest path 
	for (int i = 0; i < path.size() - 1; i++)
	{
		arr[path[i]][path[i + 1]] = 9999;
		arr[path[i + 1]][path[i]] = 9999;
	}
	
	int ** alpacca= floids_algo(arr, size, str);


}




//  Makes a 2d square matrix in the form of array 
int** make_arr(int x) 
{
	int** arr = new int* [x];
	for (int i = 0; i< x; i++) 
	{
		arr[i] = new int[x];
	}
	return arr;
}

// initializes an array
int** intitialize_arr(int** arr, int x, int size)
{
	// int** arr = new int* [x];
	for (int i = 0; i< size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			arr[i][j] = x;
		}
		
	}
	return arr;
}

// Read from a file csv
int** ReadFromFile() 
{

	ifstream csv_file;
	csv_file.open("C:\\Users\\Zunaira\\Downloads\\Assignment 3\\GraphData.csv");
	string line = "";

	// Making Array
	 int **arr = new int* [25];
	for (int i = 0; i < 25; i++) 
	{
		arr[i] = new int[25];
	}

	getline(csv_file, line, '\n');
	for (int i = 0; i < 25; i++) 
	{
		
		getline(csv_file, line, ',');

		for (int j = 0; j < 25; j++) 
		{
			if (j == 24) 
			{
				getline(csv_file, line, '\n');
				arr[i][j] = stoi(line);  // converting from string to integer
			}
			else 
			{
				getline(csv_file, line, ',');
				arr[i][j] = stoi(line);  // converting from string to integer
			}
		}
	}
	csv_file.close();
	
	return arr;
	
}

List<string> read_cities_from_file(int x) 
{
	List <string> l;
	ifstream csv_file;	int i = 0;
	csv_file.open("C:\\Users\\Zunaira\\Downloads\\Assignment 3\\GraphData.csv");
	string line = "";
	getline(csv_file, line, ',');
	while (csv_file.is_open()) 
	{
	
		
			if (i == x - 1)
			{
				getline(csv_file, line, '\n');
				l.enque(line);
				//break;

			}
			else
			{
				getline(csv_file, line, ',');
				l.enque(line);
			}
		i++;
		if (i > x - 1)
		{
			csv_file.close();
			return l;
		}
	}
	//csv_file.close();
	
}

// GRAPH CLASS
class Graph
{
private:
	
	

public:
	vector <string>cities;     // Linked List of cities  
	int** arr;               // Original arr
	int** shortest_dist;
	bool t;
	//string** csd;
	int vertices;


	//----------------------------------------------------
	Graph(int x = 0)
	{
		string str[25] = { "Mansehra","Hassan Abdal","Peshawar","Attock","Islamabad","Murree","Rawat","Balkasar","Chakwal","Mianwali","Bhera","Sargoda","Pindi Bhattian","Jhang","Faisalabad","Lahore","Dina","Gujranwala",	"Multan","DG Khan","Bahwalpur","Sukkur","Quetta","Khuzdar","Karachi" };

		this->vertices = x;
		//make_arr(x);
		this->arr = ReadFromFile();     // Original Array 
		// Ccities not initialized 

		for (int i = 0; i < this->vertices; i++) 
		{
			cities.push_back(str[i]);
		}
		t = 0;

	}

	void set_vertices_arr(int x) 
	{
		this->vertices = x;
		arr = new int* [this->vertices];
		for (int i = 0; i < this->vertices; i++) 
		{
			arr[i] = new int[this->vertices];
		}
	}
	Graph  addNode(string data)
	{
		// add city into the list
		this->cities.push_back(data);
		//this->cities.display();
		// increase the size of arr
		int** temp;
		this->vertices = this->vertices + 1;
		temp = make_arr(this->vertices);
		temp = intitialize_arr(temp, 0, this->vertices);
		// Now make THE GRAPH array point to this array
		for (int i = 0; i < this->vertices - 1; i++) 
		{
			for (int j = 0; j < this->vertices - 1; j++)
			{
				temp[i][j] = this->arr[i][j];
			}
		}

		delete[]this->arr;
		this->arr = temp;

		return *this;

	}

	string printsingleLink(string data) 
	{
		
		// Print only this if no edges present otherwise
		string str;
		str.append(data);
		str.push_back(':');


		// Now check if there are any links present
		int search_index= 0;

		// Return index at the city is present at which index
		search_index = search(this->cities, data);
		int check = 0;  int edges = 0;
		if (t == 0) 
		{
			// If the city is actually a node 
			if (search_index != -1)
			{
				for (int i = this->vertices - 1; i >= 0; i--)
				{
					// check for non zero edges
					if (this->arr[search_index][i] != 0)
					{
						edges++;
						if (edges == 1) // for first index
						{
							str.push_back(' ');
						}
						str.append("-> ");
						str.append(this->cities[i]);
					}
				}
			}
		}
		else 
		{
			if (search_index != -1)
			{
				for (int i = 0; i<this->vertices; i++)
				{
					// check for non zero edges
					if (this->arr[search_index][i] != 0)
					{
						edges++;
						if (edges == 1) // for first index
						{
							str.push_back(' ');
						}
						str.append("-> ");
						str.append(this->cities[i]);
					}
				}
			}
		}

		cout << "The single printed list is " << str << endl;
		return str;
	}

	void find_city_index(int &data1, int &data2, string &d1, string &d2) 
	{
		data1= search(this->cities, d1);
		data2 = search(this->cities, d2);
	}

	void add_Edge(int src, int dest, int weight)
	{
		this->arr[src][dest] = weight;
		this->arr[dest][src] = weight;

	}

	void delete_node(string city) 
	{
		this->t = 1;
		int index =search(this->cities, city);
		this->cities.erase(this->cities.begin() + index);
		
		// Now deleting node from adjacency matrix
		int** temp;
		temp = make_arr(this->vertices - 1);
		// Copying array while deleting the node 
		for (int i = 0; i < index; i++) 
		{
			for (int j = 0; j < this->vertices-1; j++) 
			{
				if (j >= index) 
				{
					temp[i][j] = this->arr[i][j+1];
				}
				else 
				{
					temp[i][j] = this->arr[i][j];
				}
			}
		}
		// Skipping the node 
		int p = index, q = 0;
		for (int i = index+1 ; i < this->vertices; i++) 
		{
			for (int j = 0 ; j < this->vertices- 1; j++) 
			{
				if (j >= index)
				{
					temp[p][j] = this->arr[i][j + 1];
				}
				else
				{
					temp[p][j] = arr[i][j];
				}
				q++;
			}
			p++;
		}
		this->vertices = vertices - 1;
		delete[]this->arr;
		arr = temp;
		for (int i = 0; i < this->vertices; i++) 
		{
			for (int j = 0; j < this->vertices; j++) 
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
			
		}
		cout << endl;

	}

	void del_edge(int src, int dest) 
	{
		this->arr[src][dest] = 0;
		this->arr[dest][src] = 0;
	}
	
	void printGraph()
	{
		display(this->cities);
		for (int i = 0; i < this->vertices; i++) 
		{
			for (int j = 0; j < this->vertices; j++) 
			{
				cout << this->arr[i][j] << " ";
			}
			cout <<endl;
			
		}
	}
	
};
