#include<iostream>
#include<vector>

using namespace std;

const int maxn = 1e6+10;

vector<vector<int>> e(maxn);
vector<int> in(maxn), out(maxn), f(maxn);

int findf(int x)
{
	if(x == f[x]) return x;
	else return f[x] = findf(f[x]);
}

int main()
{
	int u,v,cnt = 0;
	while(true)
	{
		fill(e.begin(), e.end(), vector<int>());
		fill(in.begin(), in.end(), 0);
		fill(out.begin(), out.end(), 0);
		cnt++;
		cin >> u >> v;
		if(u == -1 && v == -1) break;
		int max_node = 0;
		while(true)
		{
			if(u == 0 && v == 0) break;
			max_node = max(max_node, max(u, v));
			e[u].push_back(v);
			out[u]++;
			in[v]++;
			cin >> u >> v;
		}
		bool is_tree = true;
		int root = -1, root_nums = 0;
		//check unique root and connected
		for(int i = 1; i <= max_node; i++)
		{
			f[i] = i;
			if(in[i] == 0) {root = i; root_nums++;}
			if(root != i && in[i] != 1) is_tree = false;
		}
		if(root_nums != 1) is_tree = false;
		if(is_tree)
		{
			for(int i = 1; i <= maxn && is_tree; i++)
			{
				for(int j:e[i])
				{
					if(!is_tree) break;
					if(findf(i) == findf(j)) is_tree = false;
					else f[i] = findf(j);
				}
			}			
		}
		if(is_tree) cout << "Case " << cnt << " is a tree." << endl;
		else cout << "Case " << cnt << " is not a tree" << endl;
	}	
	return 0;
}
