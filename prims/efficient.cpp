#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define inf INT_MAX
struct node
{
  int key;
  bool mst;
  int par;
  node()
  {
      key=inf;
      mst=false;
      par=-1;
  }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        int sum=0;
        node vt[v];
        vt[0].key=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int nd=pq.top().second,mk=pq.top().first;
            pq.pop();
            vt[nd].mst=true;
            for(auto x:adj[nd])
            {
                int vc=x[0],wt=x[1];
                if(vt[vc].key>wt && vt[vc].mst==false){
                    vt[vc].key=wt;
                    vt[vc].par=nd;
                    pq.push({vt[vc].key,vc});
                }
            }
        }
        for(int i=0;i<v;i++)
            sum += vt[i].key;
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends