//https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
//time O(1), space O(1)
int countDigitOne(int n) {
    int cntOne = 0, pre = 0;
    for(long long i = 10, j = 0; i / 10 <= n; i *= 10, ++j){
		int tmp = (n % i - pre) / (i / 10);
		int ones = j * (i / 100);
		cntOne += tmp * ones;
		if(tmp > 1) cntOne += (i / 10);
		//include 0; exp: tmp=1, pre=3: 13(10,11,12,13)
		if(tmp == 1)cntOne += pre + 1;
		pre = n % i;
	}
    return cntOne;
}
};

/*
92075(47618)
i       n%i     tmp     pre     tmp>1   tmp=1   ones            tmp*ones
10		5		5		0       +1      0+1     0-0:    0       0
100		75		7		5       +10     5+1     0-9:    1       7
1000	75	    0		7       +100    7+1     0-99:   20      0
10000	2075	2		0       +1000   0+1     0-999:  300     600
100000	92075   9   	2       +10000  2+1     0-9999: 4000    36000

0-9:	1
0-99:	20
0-999:	10*20+100=300
0-9999:	10*300+1000=4000
0-99999:10*4000+10000=500000
*/
