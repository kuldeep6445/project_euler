#include<iostream>
#include<set>
using namespace std;

void get_set(set<int> &s,long num){
	int a;
	while(num!=0){
		a = num%10;
		num=num/10;
		s.insert(a);
	}
}

bool check(long num){
	set<int> s1,s2;
	get_set(s1,num);
	get_set(s2,num*2);
	if(s1!=s2)
		return false;

	set<int>s3;
	get_set(s3,num*3);
	if(s1!=s3)
		return false;

	set<int>s4;
	get_set(s4,num*4);
	if(s1!=s4)
		return false;

	set<int>s5;
	get_set(s5,num*5);
	if(s1!=s5)
		return false;

	set<int>s6;
	get_set(s6,num*6);
	if(s1!=s6)
		return false;
	return true;
}

int main(){
	long num=10;
	while(!check(num)){
		num++;
	}
	cout<<num;
}
