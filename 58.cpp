#include<iostream>
#import<cmath>
using namespace std;

bool prime(long long x){
	if(x<0){
		cout<<"error\n";
	}
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

int main(){
	long long index=1;
	float prime_count=0;
	float total_count=1;
	float perc = 100.0;
	while(perc>=10){
		if(prime((index*index)*4-(2*index)+1))
			prime_count++;
		if(prime(4*(index*index)+1))
			prime_count++;
		if(prime((4*index)*index + 2*index+1))
			prime_count++;
		total_count+=4;
		perc=(prime_count/total_count)*100;
		index++;
	}
	cout<<index-1<<"\n"<<(index-1)*2 +1<<"\n"<<perc;
}
