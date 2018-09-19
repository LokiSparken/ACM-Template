void get_rev(int bit)//bit表示二进制的位数
{//对1~2^bit-1中的所有数做长度为bit的二进制翻转
    for(int i=0;i<(1<<bit);i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));//?!! SMG ?!!
}//运用的dp的思想
