#include<iostream>
#include "min_cost_ropes.h"
#include<queue>

using namespace std;
class Cost
{
public:
	Cost(int *arr, int n);
	int getMinCost();
private:
	priority_queue<int> q;
	int total;
};

Cost::Cost(int *arr, int n)
{
	for(int i = 0; i<n; i++)
	{
		q.push(-1*arr[i]);
	}
	total = 0;
}

int Cost::getMinCost()
{
	while(!q.empty())
	{
		int first = -1*q.top();
		q.pop();
		int second = -1*q.top();
		q.pop();

		int local = first+second;
		total+=local;
		if(q.empty())
			return total;

		q.push(-1*local);
	}

	return total;
}
int main()
{
	int arr[4] = {8,4,6,12};
	Cost cost(arr,4);
	cout<<cost.getMinCost();
	return 0;
}