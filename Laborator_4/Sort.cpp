#include "Sort.h"

int atoic(char* t) //for char constructor
{
	int nr = 0, c, len;
	len = strlen(t);
	for (int i = 0; i < len; i++)
	{
		if (t[i] >= '0' && t[i] <= '9')
		{
			c = t[i] - '0';
			nr = nr * 10 + c;
		}
	}
	return nr;
}

int Partition(int a[], int low, int high, bool ascendent) //for quick sort method
{
	int pivot = a[high], i = low - 1;
	int aux;

	for (int j = low; j < high; j++)
	{
		if (ascendent ? (a[j] < pivot) : (a[j] > pivot))
		{
			i++;
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}
	aux = a[i+1];
	a[i+1] = a[high];
	a[high] = aux;

	return i + 1;
}

void QuickSortFunc(int a[], int low, int high, bool ascendent)
{
	int p;
	if (low < high)
	{
		p = Partition(a, low, high, ascendent);

		QuickSortFunc(a, low, p - 1, ascendent);
		QuickSortFunc(a, p + 1, high, ascendent);
	}
}

//----------------------------------------------
Sort::Sort(int nrelem, int mini, int maxi) //random
{
	(nrelem < 100) ? n = nrelem : n = 100;
	srand(time(0));

	for (int i = 0; i < n; i++)
		a[i] = mini + (rand() % (maxi-mini+1));
}

Sort::Sort(std::initializer_list<int> list)
{
	n = 0;
	for (int val : list)
		if (n < 100)
			a[n++] = val;
}

Sort::Sort(int arr[], int m)
{
	(m < 100) ? n = m : n = 100;
	for (int i = 0; i < n; i++)
		a[i] = arr[i];
}

Sort::Sort(int count, ...)
{
	(count < 100) ? n = count : n = 100;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < n; i++)
		a[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(const char* s)
{
	char* p;
	n = 0;
	char aux[256];
	strcpy(aux, s);
	p = strtok(aux,",");
	while (p != NULL && n < 100)
	{	
		a[n++] = atoic(p);
		p = strtok(NULL, ",");
	}

}

//------------------------------------
void Sort::InsertSort(bool ascendent)
{
	int key, j;

	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && (ascendent ? (a[j] > key) : (a[j] < key)))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortFunc(a, 0, n - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	bool swap = true;
	int aux;

	
	for (int i = 0; i < n; i++)
	{
		swap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ascendent?(a[j] > a[j+1]) : (a[j] < a[j+1]))
			{
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;

				swap = true;
			}
		}

		if (!swap)
			break;
	}
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int  Sort::GetElementsCount()
{
	return n;
}

int  Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < n)
		return a[index];
}