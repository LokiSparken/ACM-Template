void get_rev(int bit)//bit��ʾ�����Ƶ�λ��
{
    for(int i=0;i<(1<<bit);i++)//��ôҪ��1~2^bit-1�е�������������Ϊbit�Ķ����Ʒ�ת
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));//?!! SMG ?!!
}
//���õ�dp��˼��

















