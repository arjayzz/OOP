#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count++] = x;
	return true;
}

void NumberList::Sort()
{
	bool swap = true;
	int aux;

	swap = false;
	for (int i = 0; i < count; i++)
	{
	
		for (int j = i+1; j < count-1; j++)
		{
			if (numbers[i] >= numbers[j])
			{
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;

				swap = true;
			}
		}

		if (!swap)
			break;
	}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		printf("%d ", numbers[i]);
	printf("\n");
}