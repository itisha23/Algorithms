void func(ll s,ll d,ll visited[],ll &count)
{
	visited[s]==0;
	for(i=0;i<vec[s].size();i++)
	{
		if(visited[vec[s][i]]==d)
			count++;
		else
			func(vec[s][i],d,visited,count);
	}
	visited[vec[s][i]]=0;
}


int main()
{
	cin>>s>>d;
	ll visited[V];
	f(i,0,V)
	  visited[i]=0;
    func(s,d,visited,count);
}
