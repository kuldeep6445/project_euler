#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> primes;
vector<long long> sum;



bool prime(long long x){
	if(x%2==0)
	return false;
	for(int i=2;i<=sqrt(x);i++){
		i++;
		if(x%i==0){
			return false;
		}
	}
	return true;
}

void get_list(){
	for(int i=5;i<1000000;i++){
		if(prime(i)){
			primes.push_back(i);
			sum.push_back(sum[sum.size()-1]+i);
		}
	}
}

void print_list(){
	for(int i=0;i<10;i++)
		cout<<sum[i]<<"\n";
}

int max1(vector<int> &a){
	int m=0;
	for(int i=0;i<a.size();i++){
		if(m<a[i])
			m=a[i];
	}
	return m;
}

void solve(){
	int dec=0,j=0;
	int max_length=0;
	int max_prime=0;
	while(sum[j]<1000000){
		int sum1=0;
		for(int i=0;sum1<1000000;i++){
			sum1 = sum[i]-dec;
			if(prime(sum[i]-dec)&&sum[i]-dec<1000000){
				if(max_length<i-j){
					max_prime = sum[i]-dec;
					max_length = i-j;
				}
			}
		}
		dec = sum[j];
		j++;
	}
	cout<<"max_length : "<<max_length<<"\nmax_prime : "<<max_prime;
}

int main(){
	primes.push_back(2);
	primes.push_back(3);
	sum.push_back(2);
	sum.push_back(5);
	get_list();
	cout<<primes.size()<<" "<<sum.size()<<"\n\n\n";
	solve();
	
	
}
