#include<bits/stdc++.h>
using namespace std;
class dsu{
	public:
	vector<int> parent, size;
	int no_of;
	int mxsize;

	dsu(int n){
		parent.resize(n);
		size.resize(n, 1);
		no_of = n;
		mxsize = 1;
		for(int i = 0; i < n; i++){
			parent[i] = i; 
		}
	}

	int findPar(int num){
		if(num == parent[num]){
			return num;
		}
		return parent[num] = findPar(parent[num]);  
	}

	void unionbysize(int u, int v){
		int p1 = findPar(u);
		int p2 = findPar(v);
		if(p1 != p2){
			if(size[p1] > size[p2]){
				parent[p2] = p1;
				size[p1] += size[p2];
				mxsize = max(size[p1], mxsize);
			}
			else{
				parent[p1] = p2;
				size[p2] += size[p1];
				mxsize = max(size[p2], mxsize);
			}
			no_of--;
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	dsu ds(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;  
		ds.unionbysize(u, v);
		cout << ds.no_of << " ";
		cout << ds.mxsize << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();  
    return 0;
}
