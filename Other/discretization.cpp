// a原序列，v暂存离散化
sort(v.begin(),v.end());
v.resize(unique(v.begin(),v.end())-v.begin()); 
for(int i=0;i<n;++i)
    a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;