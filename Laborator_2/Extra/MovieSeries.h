#pragma once
#include "Movie.h"
class MovieSeries
{
private:
	int count;
	Movie* series[16];

public:
	void init();
	bool add(Movie* m);
	void print();
	void sort();
};
