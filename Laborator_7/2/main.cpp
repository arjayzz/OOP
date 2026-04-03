#include <stdio.h>
#include "Tree.h"
bool eq(const int& a, const int& b)
{
	return a == b;
}

int main()
{
	Tree<int> s;
	s.add_node(nullptr, 2);
	Node<int>* rad = s.get_node(nullptr);

	s.add_node(rad, 13);
	s.add_node(rad, 14);
	s.add_node(rad, 12);
	
	s.insert(rad, 10, 1);
	printf("Nodurile din arbore sunt:\n");
	printf("%d ", rad->value);
	for (int i = 0; i < rad->count; i++)
		printf("%d ", rad->children[i]->value);
	printf("\n");
	printf("Nr de noduri din arbore sunt: %d", s.count(nullptr));
	printf("\n\n");

	Node<int>* found = s.find(eq, 10, rad);
	if (found)
		printf("Nodul cu valoarea %d a fost gasit", found->value);
	else
		printf("Nodul nu a fost gasit");
	printf("\n\n");

	Node<int>* notfound = s.find(eq, 120, rad);
	if (notfound)
		printf("Nodul cu valoarea %d a fost gasit", notfound->value);
	else
		printf("Nodul cu valoarea 120 nu a fost gasit");
	printf("\n\n");
	
	s.sort(rad);
	printf("Nodurile radacinii dupa sortare sunt:\n");
	for (int i = 0; i < rad->count; i++)
		printf("%d ", rad->children[i]->value);
	printf("\n\n");

	if (found)
	{
		printf("Stergand nodul %d", found->value);
		s.delete_node(found);
	}
	printf("\n");
	for (int i = 0; i < rad->count; i++)
		printf("%d ", rad->children[i]->value);
	printf("\n");
	
	printf("Numarul de noduri dupa stergere: %d\n\n", s.count(nullptr));

}
