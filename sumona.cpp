#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int g[105][105]; 
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            g[i][j]=1e9;

    for(int i=0;i<m;i++){
        int a,b,w;string s;
        cin>>a>>b>>w>>s;
        if(s=="safe"){
            g[a][b]=w;
            g[b][a]=w;
        }
    }

    int k[105],p[105];bool v[105]={0};
    for(int i=1;i<=n;i++)k[i]=1e9;
    k[1]=0;

    for(int c=1;c<=n;c++){
        int u=-1,mn=1e9;
        for(int i=1;i<=n;i++)
            if(!v[i]&&k[i]<mn)mn=k[i],u=i;
        if(u==-1)break;
        v[u]=1;
        for(int j=1;j<=n;j++)
            if(!v[j]&&g[u][j]<k[j])k[j]=g[u][j],p[j]=u;
    }

    int t=0;
    cout<<"The selected edges:\n";
    for(int i=2;i<=n;i++){
        cout<<"("<<p[i]<<","<<i<<","<<k[i]<<",safe)\n";
        t+=k[i];
    }
    cout<<"Total weight of the MST = "<<t<<endl;
}
