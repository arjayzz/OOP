#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
	head = nullptr;
	count = 0;
}

bool NumberList::Add(int x)
{
	nod* q = new nod;
	q->info = x;
	q->urm = nullptr;
	if (head == nullptr)
		head = q;
	else
	{
		nod* temp = head;
		while (temp->urm != nullptr)
			temp = temp->urm;
		temp->urm = q;
	}
	count++;
	return true;
}

void NumberList::Sort()
{	
	if (head == nullptr || head->urm == nullptr)
		return;

	nod* inod = head;
	nod* jnod;
	int aux;
	while(inod->urm != nullptr)
	{	
		bool swap = false;
		jnod = inod->urm;
	
		while(jnod->urm != nullptr)
		{
			if (inod->info >= jnod->info)
			{
				aux=inod->info;
				inod->info = jnod->info;
				jnod->info = aux;

				swap = true;
			}
			jnod = jnod->urm;
		}

		if (!swap)
			break;
		inod = inod->urm;
	}
}

void NumberList::Print()
{
	nod* inod = head;
	for (int i = 0; i < count; i++)
	{
		printf("%d ", inod->info);
		inod = inod->urm;
	}
	printf("\n");
}

NumberList::~NumberList()
{
	nod* inod = head;
	while (inod != nullptr)
	{
		nod* jnod = inod->urm;
		delete inod;
		inod = jnod;
	}
}