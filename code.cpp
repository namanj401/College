#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pa;
#define pb push_back
#define  MAX 2509
#define ll long long int
#define ld long double
long long int mod=998244353;
long long int MOD=1e9+7;
long long int INF=1e18;
ld PI=3.14159265358979323846264338327950;
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
ll dis[MAX];
ll par[MAX];
ll vis[MAX];
pa ans;
ll node;
bool check(vector<pa> adj[],int n)
{
    dis[1]=0;
    for(int i=2;i<=n;i++)
    dis[i]=INF;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto k:adj[j])
            {
                ll x,y,w;
                x=j;
                y=k.first;
                w=k.second;
                if(dis[y]>dis[x]+w)
                dis[y]=dis[x]+w;
            }
        }
    }
     for(int j=1;j<=n;j++)
        {
            for(auto k:adj[j])
            {
                ll x,y,w;
                x=j;
                y=k.first;
                w=k.second;
                if(dis[y]>dis[x]+w)
                {
                    ans={x,y};
                    return 1;
                }
            }
        }
        return 0;
}
void dfs(vector<pa> adj[],ll x,ll t,ll tmp)
{
    vis[x]=1;
    for(auto j:adj[x]){
        if(!vis[j.first])
        {
            par[j.first]=x;
            dfs(adj,j.first,t+j.second,tmp);
        }
        else
        {
            if(j.first==tmp&&t+j.second<0)
            {
                node=x;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pa> adj[n+1];
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
    }
    if(check(adj,n))
    {
        cout<<"YES"<<endl;
       /* for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
        cout<<endl;
        cout<<ans.first<<" "<<ans.second<<endl;*/
        par[ans.first]=ans.first;
        dfs(adj,ans.first,0,ans.first);
        vector<ll> v;
        v.pb(ans.first);
        //cout<<node<<endl;
        while(par[node]!=node)
        {
            v.pb(node);
            node=par[node];
        }
        v.pb(node);
        reverse(v.begin(),v.end());
        for(auto j:v)
        cout<<j<<" ";
    }
    else
    cout<<"NO"<<endl;
    return 0;
}



