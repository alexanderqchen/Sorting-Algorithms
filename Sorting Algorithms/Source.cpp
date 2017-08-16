#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSorted(const vector<int>& v);
void bubbleSort(vector<int>& v);
void selectionSort(vector<int>& v);
void insertionSort(vector<int>& v);

int main()
{
	vector<int> v = { 4, 1, 5, 2, 6, 9, 2, 4, 9, 193, 918, 93, 8, 283, 23, 1, 38, 83 };
	vector<int> temp = v;
	vector<int> test = v;
	sort(test.begin(), test.end());

	bubbleSort(temp);
	if (temp != test)
	{
		cout << "Bubble Sort failed" << endl;
		exit(1);
	}
	else
		cout << "Bubble Sort passed" << endl;
	temp = v;

	selectionSort(temp);
	if (temp != test)
	{
		cout << "Selection Sort failed" << endl;
		exit(1);
	}
	else
		cout << "Selection Sort passed" << endl;
	temp = v;

	insertionSort(temp);
	if (temp != test)
	{
		cout << "Selection Sort failed" << endl;
		exit(1);
	}
	else
		cout << "Selection Sort passed" << endl;
	temp = v;
	

	cout << "Great job!!" << endl;
}

bool isSorted(const vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
		if (v[i] < v[i - 1])
			return false;
	return true;
}

void bubbleSort(vector<int>& v)
{
	for (int n = 1; n < v.size(); n++)
	{
		for (int i = 0; i < v.size() - n; i++)
		{
			if (v[i] > v[i + 1])
			{
				int temp = v[i + 1];
				v[i + 1] = v[i];
				v[i] = temp;
			}
		}
	}
}

void selectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int biggest = 0;
		for (int j = 0; j < v.size() - i; j++)
			if (v[j] > v[biggest])
				biggest = j;
		int temp = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = v[biggest];
		v[biggest] = temp;
	}
}

void insertionSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int n = v[i];
		for (int j = i; j >= 0; j--)
		{
			if (j == 0)
				v[j] = n;
			else if (n > v[j - 1])
			{
				v[j] = n;
				break;
			}
			else
				v[j] = v[j - 1];
		}
	}
}