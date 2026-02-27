#include <iostream>
#include "NumberList.h"
int main()
{
	NumberList n;
	n.Init();
	n.Add(10); n.Add(4); n.Add(5); n.Add(3); n.Add(17);
	n.Print();
	n.Sort();
	n.Print();
}