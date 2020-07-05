#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int getMinSwaps(int *arr, int n)
{
	vector< pair<int, int> > v; // sort the elements based on the value while storing their original position in the pair.second.
	for(int i = 0;i<n; i++)
	{
		v.push_back(make_pair(arr[i],i));
	}
	sort(v.begin(), v.end());
	vector<bool> visited(n,0); //to figure out what nodes have been visited. assume each value as a node that has to be swapped with another node.
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		if(visited[i] || v[i].second==i) // if visited or already at the correct position no need to calculate.
			continue;
		int j = i;
		int cycle_size = 0;
		while(visited[j]!=true)
		{
			visited[j] = 1;
			cycle_size++;
			j = v[j].second;
		}
		if(cycle_size>0)
		{
			ans+=cycle_size-1;
		}
	}

return ans;

}
int main()
{
	int arr[5] = {2,4,5,1,3};
	cout<<getMinSwaps(arr, 5);
	return 0;
}