#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 4e5 + 10;
int n,m;
int pos[MAXN];
struct code{
	int val;
	int add=0;
};
code tree[MAXN];
int a[MAXN];
int build(int p,int l,int r){
	if(l==r){
		pos[l]=p;
		tree[p].val=a[l];
		// cout<<p<<" "<<a[l]<<endl;
		return a[l];
	}
	int mid=(l+r)>>1;
	tree[p].val+=build((p<<1),l,mid);
	tree[p].val+=build((p<<1)+1,mid+1,r);
	return tree[p].val;
}
void pushup(int p,int z){
	tree[p].val+=z;
	if(p==1) return;
	pushup(p/2,z);
}
void add(int p,int x,int y,int l,int r,int z){
	if(x>=l and y<=r){
		tree[p].add+=z;
		if(p>1)pushup(p>>1,(y-x+1)*z);
		return;
	}
	if(l==r) return;
	int mid=(x+y)>>1;
	if((l>=x and l<=mid)or(r>=x and r<=mid)or(x>=l and mid<=r)){
		add(2*p,x,mid,l,r,z);
	}
	if((l>mid and l<=y)or(r>mid and r<=y)or((mid+1)>=l and y<=r)){
		add(2*p+1,mid+1,y,l,r,z);
	}
}
int ask(int p,int x,int y,int l,int r,int z){
	// cout<<p<<" "<<x<<" "<<y<<" "<<tree[p].val<<" "<<z<<endl;
	z+=tree[p].add;
	if(x>=l and y<=r){
		
		return z*(y-x+1)+tree[p].val;
	}
	if(l==r) return 0;
	int mid=(x+y)>>1,ans=0;
	if((l>=x and l<=mid)or(r>=x and r<=mid)or(x>=l and mid<=r)){
		ans+=ask(2*p,x,mid,l,r,z);
	}
	if((l>mid and l<=y)or(r>mid and r<=y)or((mid+1)>=l and y<=r)){
		ans+=ask(2*p+1,mid+1,y,l,r,z);
	}
	return ans;
}
signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	// cout<<ask(1,1,n,1,n,0)<<endl;
	for(int i=1;i<=m;i++){
		int op,x,y,z;
		cin>>op>>x>>y;
		if(op==1){
			cin>>z;
			add(1,1,n,x,y,z);
		}
		else{
			int ans=ask(1,1,n,x,y,0);
			cout<<ans<<endl;
		}
	}
}
/*
Input:
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

Output:
11
8
20
*/
