//v.push_back(old);
sort(v.begin(),v.end());
int size=unique(v.begin(),v.end())-v.begin();
for(int i=1;i<=N;++i)
{
    newData=lower_bound(v.begin(),v.begin()+size,oldData)-v.begin()+1;
}
