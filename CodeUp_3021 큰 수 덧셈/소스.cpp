#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int i = 1, j, up = 0, m, max_index;
	string num[2];
	stack<int> s[2], result;
	cin >> num[0] >> num[1];
	m = num[0].length() > num[1].length() ? num[0].length() : num[1].length();
	for (int i = 0; i < 2; i++)
	{
		for (j = 0; j < m - num[i].length(); j++)
			s[i].push(0);
		for (j = 0; num[i][j]; j++)
			s[i].push(num[i][j] - '0');
	}
	max_index = s[0].size() > s[1].size() ? 0 : 1;
	for (i = 0; i < 2; i++)
	{
		for (j = s[i].size(); j < m && i != max_index; j++) 
			s[i].push(0);
	}

	while (s[0].size())
	{
		int t[2];
		for (i = 0; i < 2; i++)
		{
			t[i] = s[i].top();
			s[i].pop();
		}
		t[0] += t[1] + up;
		up = 0;
		if (t[0] >= 10)
			up++;
		result.push(t[0] % 10);
	}
	if (up)
		result.push(1);

	while (result.size())
	{
		cout << result.top();
		result.pop();
	}

	return 0;
}