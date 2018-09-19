void pushdown(ull len,int rt)
{   // lz+,mul*
    if(mul[rt]!=1 || lz[rt])
    {
        lz[lson]=(lz[lson]*mul[rt])+lz[rt];
        lz[rson]=(lz[rson]*mul[rt])+lz[rt];
        mul[lson]=mul[lson]*mul[rt];
        mul[rson]=mul[rson]*mul[rt];
        sum[lson]=(sum[lson]*mul[rt]+lz[rt]*(len-(len>>1)));
        sum[rson]=(sum[rson]*mul[rt]+lz[rt]*(len>>1));
        mul[rt]=1;
        lz[rt]=0;
    }
}