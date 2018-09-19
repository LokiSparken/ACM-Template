const double exps=1e-5;
double F(double x)
{
       return 0;
}
double simpson(double a,double b,double A,double B)
{
    double c=a+(b-a)/2;
    return (A+4*F(c)+B)*(b-a)/6;
}
double asr(double a,double b,double eps,double A,double l,double r)// 必要时加一个deep
{
    double c=a+(b-a)/2;
    double m=F(c);
    double L=simpson(a,c,l,m),R=simpson(c,b,m,r);
    if(fabs(L+R-A)<=15*eps)return L+R+(L+R-A)/15.0;
    return asr(a,c,eps/2,L,l,m)+asr(c,b,eps/2,R,m,r);
}
double asr(double a,double b,double eps)
{
    double x=F(a),y=F(b);
    return asr(a,b,eps,simpson(a,b,x,y),x,y);
}












