#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(int argc,const char * argv [])
{
	int n = 8;
	vector<vector<int>> graf(n);
	graf[0].push_back(1);
	graf[0].push_back(2);

	graf[1].push_back(3);
	graf[1].push_back(4);

	graf[2].push_back(5);

	graf[4].push_back(6);
	graf[4].push_back(7);

	vector<bool> visited(n, false);
	queue<int> kolejka;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			cout << i;
			kolejka.push(i);
			
			while (!kolejka.empty())
			{
				int x = kolejka.front();
				kolejka.pop();
				for (int y: graf[x])
				{
					if (visited[y] == false)
					{
						visited[y] = true;
						cout << y;
						kolejka.push(y);
					}
				}
			}
		}
	}
}