
/*
 * problem: special average
 *
 * read n, followed by reading n numbers
 * print averages in odd positions and even positions.
 *
 * Test cases
 * Input: 7 11 101 21 201 31 602 78
 *
 * Output: 35.25 301.333
 */

#include<iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	int  cnt_even = 0, cnt_odd = 0;
	double sum_odd = 0, sum_even = 0;
	int cnt = 1;
	while(cnt <= n){
	    double num;
	    cin>>num;
	    if(cnt % 2 == 0)
	        sum_even += num, cnt_even++;
	    else
	        sum_odd += num, cnt_odd++;
	   cnt++;
	}
	cout<<sum_even/ cnt_even<<" "<<sum_odd/cnt_odd<<endl;
    return 0;
}
