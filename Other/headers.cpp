#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
const int inf=0x3f3f3f3f; // long long则为0x8个3f
const double eps=1e-6; // WA了就加精度，T了就减精度
/*
    整型初始化memset(d,0x3f,sizeof(d));
    浮点初始化memset(d,0x7f,sizeof(d));
    浮点数比大小: 相等 if(fabs(a-b)<=eps)
                大于 if(a>b && fabs(a-b)>eps)
                小于 if(a<b && fabs(a-b)>eps)
*/
/*
 * 热身赛：
 * 1、测pb_ds
 * 2、python3计算器
 * 3、
 */

/*
 * 2=10（二进制）
 * 255 IP位址是一个32位的二进制数，在IPv4中被等分为4段。每一段所支持的最大值"11111111"在十进制中即为255。而默认的子网掩码为255.255.255.0 。
 * 65535：2^16-1。早期许多程序的数据采用16bit无符号整数（C/C++:uint16_t）。有时发生计算错误，得到本来不该有的-1（下溢出），而-1在16bit无符号整数中就会变成这个值。
 * 2147483647：2^31-1。32bit带符号整数（C/C++:int32_t）的最大值。
 * 4294967296：2^32。有时4294967295=2^32-1会作为32bit无符号整数（C/C++:uint32_t）的最大值，出现在类似65535的计算错误场合。
 * 92233720368547758072：2^63-1。64bit带符号整数（C/C++:int64_t）的最大值。可是由于这个数太大，很少被留意
 */

Debug：
1、初始化，清空图，0和n的地方，mem里面sizeof(int)还是ll
2、for里是给本层循环变量++咩？
3、区间l,r为防坑：if(l>r) swap(l,r);
4、考虑小数据有没有发生突变的地方

计算器：
1、终端：(1)分解素因数factor num
        (2)逆串rev+enter string
2、python3：from fractions import *(Fraction, gcd)
             (1)最简分数fraction(a,b)        
             (2)gcd(a,b)
           from math import *
             (3)阶乘factorial(num)

Attention:
1、审题请仔细，题面注意限制条件，不清楚的善用Clarification
2、打表想清楚打哪些量，代码乱改前注意备份。善用打印。