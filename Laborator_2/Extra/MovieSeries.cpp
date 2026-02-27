#include "MovieSeries.h"

void MovieSeries::init()
{
	count = 0;
}
bool MovieSeries::add(Movie* m)
{
	if (count >= 16)
		return false;
	series[count++] = m;
	return true;
}

void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
	{
		printf("Name: %s \nYear: %d \nScore: %.1f \nLength: %d min\nPassed Years: %d\n",series[i]->get_name(), series[i]->get_year(), series[i]->get_score(), series[i]->get_length(), series[i]->passed_years());
	}


}
void MovieSeries::sort()
{
	bool swap = true;
	Movie* aux;
	for (int i = 0; i < count; i++)
	{

		for (int j = i + 1; j < count - 1; j++)
		{
			if (series[i]->passed_years() <= series[j]->passed_years())
			{
				aux = series[i];
				series[i] = series[j];
				series[j] = aux;

				swap = true;
			}
		}

		if (!swap)
			break;
	}

}