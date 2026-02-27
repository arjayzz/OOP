
#include "CompareMovies.h"

int movie_compare_name(const Movie m1, const Movie m2)
{
	return strcmp(m1.get_name(), m2.get_name());
}

int movie_compare_year(const Movie m1, const Movie m2)
{
	if (m1.get_year() > m2.get_year())
		return 1;
	else if (m1.get_year() == m2.get_year())
		return 0;
	return -1;
}

int movie_compare_score(const Movie m1, const Movie m2)
{
	if (m1.get_score() > m2.get_score())
		return 1;
	else if (m1.get_score() == m2.get_score())
		return 0;
	return -1;
}

int movie_compare_length(const Movie m1, const Movie m2)
{
	if (m1.get_length() > m2.get_length())
		return 1;
	else if (m1.get_length() == m2.get_length())
		return 0;
	return -1;
}

int movie_compare_passed_years(const Movie m1, const Movie m2)
{
	if (m1.passed_years() > m2.passed_years())
		return 1;
	else if (m1.passed_years() == m2.passed_years())
		return 0;
	return -1;
}