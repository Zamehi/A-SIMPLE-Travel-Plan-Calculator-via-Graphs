#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
using namespace std;


// Using floyds algorithm to find the pathsof vertices

Graph* Returner()
{
	Graph* foo_ptr = new Graph();
	return foo_ptr;
}

// **************************        ADD NODE      ******************************
Graph* addNode(string data)
{
	Graph* p= Returner();
	Graph * g= new Graph(25);
	g->addNode(data);
	
	return g;
}


//  *************************        ADD EDGE      ****************************** 
Graph* addEdge(string data, string data1, int weight)
{
	
	Graph* g = new Graph(25);
	int index1 = 0, index2 = 0;
	g->find_city_index(index1, index2, data, data1);
	g->add_Edge(index1, index2, weight);
	//p = &g;
	return g;
}


//  *************************       DELETE NODE    ******************************* 
Graph* deleteNode(string city) 
{
	Graph* g = new Graph(25);
	g->delete_node(city);

	return g;
}

//  *************************        DELETE EDGE      **************************** 
Graph* deleteEdge(string city1, string city2) 
{
	Graph* g = new Graph(25);
	int index1 = 0, index2 = 0;
	g->find_city_index(index1, index2, city1, city2); // return at which index city is present
	g->del_edge(index1, index2);
	return g;
}

//  *************************        Shortest Path      ************************** 
void shortestPathfromOnetoall(string city) 
{
	//Graph* p = NULL; 
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}
	}
	string** str_cities; vector <int> p; 

	g.shortest_dist = floids_algo(g.arr, g.vertices, str_cities);
	index = search(g.cities, city);

	// Getting words of the cities
	// Initializing new string 
	string** str2;
	str2 = new string * [25];
	for (int i = 0; i < 25; i++)
	{
		str2[i] = new string[25];
	}
	for(int i =0;i<25;i++)
	{
		for (int j = 0; j < 25; j++) 
		{
			
			p = return_edges(str_cities[i][j]);
			
			// Check which cities 

			for (int q = 0; q < p.size(); q++)
			{
				str2[i][j].append(g.cities[p[q]]);
				if (q != p.size() - 1)
				{
					str2[i][j].append("-> ");
				}
			}
			//cout << str2[i][j]<< endl;
			p.clear();
		}
	}
	
	// check on which index lahore is present 
	for (int i = 0; i < 25; i++) 
	{
	     cout << str2[index][i] << endl;

	}
	
}

void shortestPathfromalltoone(string city)
{
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}

	}
	string** str_cities;
	g.shortest_dist = floids_algo(g.arr, g.vertices, str_cities);
	index = search(g.cities, city);
	// check on which index lahore is present 
	// Getting words of the cities
	// Initializing new string 
	string** str2;
	vector <int> p;
	str2 = new string * [25];
	for (int i = 0; i < 25; i++)
	{
		str2[i] = new string[25];
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{

			p = return_edges(str_cities[i][j]);

			// Check which cities 

			for (int q = 0; q < p.size(); q++)
			{
				str2[i][j].append(g.cities[p[q]]);
				if (q != p.size() - 1)
				{
					str2[i][j].append("-> ");
				}
			}
			//cout << str2[i][j] << endl;
			p.clear();
		}
	}

	// check on which index lahore is present 
	for (int i = 0; i < 25; i++)
	{
		cout << str2[i][index] << endl;
	}
	
}

string ShortestRoutefrompair(string city1, string city2)
{
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}
		//cout << endl;
	}
	string** str_cities;
	g.shortest_dist = floids_algo(g.arr, g.vertices, str_cities);
	// str_cities have all the indices
	index = search(g.cities, city1);
	int index2 = search(g.cities, city2);
	// check on which index lahore is present 
    //cout << "The shortest distance from "<< city1 << " to "<< city2<< " is "<< g.shortest_dist[index][index2] <<endl;

	// Getting words of the cities
	// Initializing new string 
	string** str2;
	vector<int>p;
	str2 = new string * [25];
	for (int i = 0; i < 25; i++)
	{
		str2[i] = new string[25];
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{

			p = return_edges(str_cities[i][j]);

			// Check which cities 

			for (int q = 0; q < p.size(); q++)
			{
				str2[i][j].append(g.cities[p[q]]);
				if (q != p.size() - 1)
				{
					str2[i][j].append("-> ");
				}
			}
			//cout << str2[i][j] << endl;
			p.clear();
		}
	}

	// check on which index lahore is present 

		cout << str2[index][index2] << endl;
		return  str2[index][index2];

}



// ************************************************************
// Second Shortest Path
void  secondshortestPathfromOnetoall(string city) 
{
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}
		//cout << endl;
	}
	string** str_cities;
	vector <int> p;
	// FLOIDS ALGO 1
	g.shortest_dist = floids_algo(g.arr, g.vertices, str_cities);

	index = search(g.cities, city);
	string** str;
	for (int i = 0; i < 25; i++) 
	{
		second_shortest(index, i, g.vertices, g.arr, str_cities, str);
		// Getting words of the cities
	// Initializing new string 
		string** str2;
		str2 = new string * [25];
		for (int i = 0; i < 25; i++)
		{
			str2[i] = new string[25];
		}
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{

				p = return_edges(str[i][j]);

				// Check which cities 

				for (int q = 0; q < p.size(); q++)
				{
					str2[i][j].append(g.cities[p[q]]);
					if (q != p.size() - 1)
					{
						str2[i][j].append("-> ");
					}
				}
				//cout << str2[i][j] << endl;
				p.clear();
			}
		}

		// check on which index lahore is present 
		
			cout << str2[index][i] << endl;
		
	}

	
}

void secondshortestPathfromalltoone(string city) 
{
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}
		//cout << endl;
	}
	string** str_cities;
	g.shortest_dist = floids_algo(g.arr, g.vertices,  str_cities);
	index = search(g.cities, city);
	string** str;
	vector<int>p;
	for (int i = 0; i < 25; i++)
	{
		second_shortest(i, index, g.vertices, g.arr, str_cities, str);
		// Getting words of the cities
	    // Initializing new string 
		string** str2;
		str2 = new string * [25];
		for (int i = 0; i < 25; i++)
		{
			str2[i] = new string[25];
		}
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{

				p = return_edges(str[i][j]);

				// Check which cities 

				for (int q = 0; q < p.size(); q++)
				{
					str2[i][j].append(g.cities[p[q]]);
					if (q != p.size() - 1)
					{
						str2[i][j].append("-> ");
					}
				}
				//cout << str2[i][j] << endl;
				p.clear();
			}
		}

		// check on which index lahore is present 
		
			cout << str2[i][index] << endl;
		
	}
}

string secondShortestRoutefrompair(string city1, string city2) 
{
	vector<int>p;
	int vertices; int index = 0;
	Graph g(25);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i != j)
			{
				if (g.arr[i][j] == 0)
				{
					g.arr[i][j] = 9999;
				}
			}
		}
		//cout << endl;
	}
	string** str_cities;
	g.shortest_dist = floids_algo(g.arr, g.vertices, str_cities);
	index =search(g.cities,city1);
	int index2 = search(g.cities, city2);
	string** str;
		second_shortest(index, index2, g.vertices, g.arr, str_cities, str);
		// Getting words of the cities
	    // Initializing new string 
		string** str2;
		str2 = new string * [25];
		for (int i = 0; i < 25; i++)
		{
			str2[i] = new string[25];
		}
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{

				p = return_edges(str[i][j]);

				// Check which cities 

				for (int q = 0; q < p.size(); q++)
				{
					str2[i][j].append(g.cities[p[q]]);
					if (q != p.size() - 1)
					{
						str2[i][j].append("-> ");
					}
				}
				//cout << str2[i][j] << endl;
				p.clear();
			}
		}

		// check on which index lahore is present 
		
			cout << str2[index][index2] << endl;
			return str2[index][index2];
	
}

