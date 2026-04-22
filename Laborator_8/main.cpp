#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>

struct winfo
{
	std::string t;
	int len;
};
struct comp
{
	bool operator()(winfo a, winfo b)
	{
		if (a.len != b.len)
			return a.len < b.len;
		return a.t > b.t;
	}
};

int main()
{
	std::string text = "", line, word = "", sep = " .,!?";
	std::ifstream f("lab08.txt");

	if (!f.is_open())
	{
		std::cout << "error when opening file";
		return 1;
	}

	while (getline(f, line))
	{
		text.append(line);
		text.append(" ");
	}

	std::map<std::string, int> wcount;

	size_t start = text.find_first_not_of(sep, 0);
	size_t end;
	while (start < text.length())
	{
		end = text.find_first_of(sep, start);

		std::string word = text.substr(start, end - start);

		for (unsigned int i = 0; i < word.length(); i++)
			word[i] = tolower(word[i]);

		if (word.length() > 0)
			wcount[word]++;
		start = text.find_first_not_of(sep, end);
	}

	std::priority_queue<winfo, std::vector<winfo>, comp> que;

	for (auto& j : wcount)
	{
		winfo aux;
		aux.t = j.first;
		aux.len = j.second;
		que.push(aux);
	}

	while (!que.empty())
	{
		winfo aux = que.top();
		std::cout << aux.t << " => " << aux.len << std::endl;
		que.pop();
	}
}