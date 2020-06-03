#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void output(vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void bubble_sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = vec.size() - 1; j > i; --j)
		{
			if (vec[j - 1] > vec[j])
			{
				swap(vec[j - 1], vec[j]);
			}
		}
	}
}

void quick_sort(vector<int>& vec, int L, int R)
{
	int i = L;
	int j = R;
	int x = vec[(i + j) / 2];

	while (i <= j)
	{
		while (vec[i] < x)
		{
			i++;
		}
		while (vec[j] > x)
		{
			j--;
		}

		if (i <= j)
		{
			swap(vec[i], vec[j]);
			++i;
			--j;
		}
	}

	if (L < j)
	{
		quick_sort(vec, L, j);
	}
	if (R > i)
	{
		quick_sort(vec, i, R);
	}
}

void insertion_sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int x = vec[i];
		int j = i;
		while (j > 0 && vec[j - 1] > x)
		{
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = x;
	}
}

void merge(vector<int>& vec, int L, int mid, int R)
{
	vector<int> temp(R + 1);
	int i = L;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= R)
	{
		if (vec[i] <= vec[j])
		{
			temp[k] = vec[i];
			++k;
			++i;
		}
		else
		{
			temp[k] = vec[j];
			++k;
			++j;
		}
	}

	while (i <= mid)
	{
		temp[k] = vec[i];
		++k;
		++i;
	}

	while (j <= R)
	{
		temp[k] = vec[j];
		++k;
		++j;
	}
	--k;

	while (k >= 0)
	{
		vec[L + k] = temp[k];
		--k;
	}
}

void merge_sort(vector<int>& vec, int L, int R)
{
	int mid;

	if (L < R)
	{
		mid = (L + R) / 2;
		merge_sort(vec, L, mid);
		merge_sort(vec, mid + 1, R);
		merge(vec, L, mid, R);
	}
}

int main()
{
	srand(time(NULL));
	vector<int> vec(100);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = rand() % vec.size();
		cout << vec[i] << " ";
	}
	cout << endl;

	//int t = clock();

	//bubble_sort(vec);
	quick_sort(vec, 0, vec.size() - 1);
	//insertion_sort(vec);
	//merge_sort(vec, 0, vec.size() - 1);

	output(vec);

	//cout << clock() - t << endl;

	return 0;
}
