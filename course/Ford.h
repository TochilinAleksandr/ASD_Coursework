#ifndef FORD_H
#define FORD_H
#define infinity INT_MAX

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

bool isContain(char* arr, char ch) {
	for (int i = 0; i < 26; i++) {
		if (arr[i] == ch)
			return true;
	}
	return false;
}

struct set {
	char* arr = new char[26];
	int size = 0;
};

class Ford
{
public:
	int Tops;
	int** graphMat;
	int from, to;
	int _stream;
	char* TopsName;

	int dfs(int u, int Cmin, bool* visited) {
		if (u == to)
			return Cmin;
		visited[u] = true;
		int delta;
		for (int v = 0; v < Tops; v++)
		{
			if (!visited[v] && (graphMat[u][v] > 0))
			{
				delta = dfs(v, min(Cmin, graphMat[u][v]), visited);
				if (delta > 0)
				{
					graphMat[u][v] -= delta;
					graphMat[v][u] += delta;
					return delta;
				}
			}
		}
		return 0;
	}


	int MaxFlow() {
		_stream = 0;
		int toAdd = 0;
		int buf1, buf2;
		bool* visited = new bool[Tops];
		do
		{
			for (int i = 0; i < Tops; i++)
				visited[i] = false;
			toAdd = dfs(from, infinity, visited);
			_stream += toAdd;
		} while (toAdd > 0);
		return _stream;
	};

	void inputData(string fileName) {
		string temp;
		fstream file;
		char firstNode, secondNode;
		int weight;
		int edge = 0;
		int CountTopName = 0;
		file.open(fileName);
		set _set;

		while (!file.eof()) {
			temp = "";
			getline(file, temp);
			if (!isContain(_set.arr, temp[0])) {
				_set.arr[_set.size] = temp[0];
				_set.size++;
			}
			if (!isContain(_set.arr, temp[2])) {
				_set.arr[_set.size] = temp[2];
				_set.size++;
			}
			edge++;
		}
		Tops = _set.size;

		file.close();
		file.open(fileName);

		TopsName = new char[Tops];
		int** arr_check = new int* [Tops];

		graphMat = arr_check;

		for (int i = 0; i < Tops; i++)
		{
			arr_check[i] = new int[Tops];
			graphMat[i] = arr_check[i];
			for (int j = 0; j < Tops; j++) {
				graphMat[i][j] = 0;
			}

		}

		int found1, found2;
		for (int i = 0; i < edge; i++)
		{
			file >> firstNode >> secondNode >> weight;

			found1 = -1;
			for (int j = 0; j < CountTopName; j++)
				if (TopsName[j] == firstNode)
					found1 = j;
			if (found1 == -1)
			{
				TopsName[CountTopName] = firstNode;
				found1 = CountTopName;
				CountTopName++;
			}

			found2 = -1;
			for (int j = 0; j < CountTopName; j++)
				if (TopsName[j] == secondNode)
					found2 = j;
			if (found2 == -1)
			{
				TopsName[CountTopName] = secondNode;
				found2 = CountTopName;
				CountTopName++;
			}
			graphMat[found1][found2] = weight;
		}
		file.close();
		for (int i = 0; i < Tops; i++)
		{
			if (TopsName[i] == 'A')
				from = i;
			else if (TopsName[i] == 'Z')
				to = i;
		}
	};
};

#endif // 