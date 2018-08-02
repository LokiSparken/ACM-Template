
import java.util.*;
import java.math.*;

public class IO {// 比赛要用Main
		public static class point { BigDecimal x,y; }// 自己定义的类
		
        public static point temp=new point();
        // 全局变量
		
		public static point center(point a,point b,point c)
		{
			BigDecimal son=BigDecimal.valueOf(2);
			BigDecimal a1=b.x.subtract(a.x);
			BigDecimal b1=b.y.subtract(a.y);
			BigDecimal c1=((a1.multiply(a1)).add(b1.multiply(b1))).divide(son);
			temp.x=a1;temp.y=b1;
			BigDecimal a2=c.x.subtract(a.x);
			BigDecimal b2=c.y.subtract(a.y);
			BigDecimal c2=((a2.multiply(a2)).add(b2.multiply(b2))).divide(son);
			BigDecimal dd=(a1.multiply(b2)).subtract(a2.multiply(b1));
			temp.x=a.x.add((c1.multiply(b2).subtract(c2.multiply(b1))).divide(dd,20,0));
			temp.y=a.y.add((a1.multiply(c2).subtract(a2.multiply(c1))).divide(dd,20,0));
			return temp;
		}
	static point a=new point();
	static point b=new point();
	static point c=new point();
	static point d=new point();
	public static void main(String[] args) // 主函数格式
	{
		Scanner in=new Scanner(System.in);// 输入
		int T=in.nextInt();
		while(T-->0) 
		{
			a.x=in.nextBigDecimal();a.y=in.nextBigDecimal();
			b.x=in.nextBigDecimal();b.y=in.nextBigDecimal();
			c.x=in.nextBigDecimal();c.y=in.nextBigDecimal();
			d.x=in.nextBigDecimal();d.y=in.nextBigDecimal();
            temp=center(a,b,c);// 函数调用
            // 运算也特么是函数没错！
			BigDecimal r=((temp.x.subtract(a.x)).multiply(temp.x.subtract(a.x))).add(((temp.y.subtract(a.y)).multiply(temp.y.subtract(a.y))));
			BigDecimal dis=((temp.x.subtract(d.x)).multiply(temp.x.subtract(d.x))).add(((temp.y.subtract(d.y)).multiply(temp.y.subtract(d.y))));
			if(dis.compareTo(r)>0)
					System.out.println("Accepted");
			else System.out.println("Rejected");// 输出
		}
	}
}
