#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void int_to_vector(vector<int> &num,int i){
	while(i){
		num.push_back(i%10);
		i/=10;
	}
}

void add(vector<int> &num){
	vector<int> t;
	t = num;
	for(int i=0;i<num.size();i++){
		num[i]+= t[num.size()-1-i];
	}	
	for(int i=0;i<num.size()-1;i++){
		if(num[i]>9){
			num[i+1]+= num[i]/10;
			num[i]=num[i]%10;
		}
	}
	if(num[num.size()-1]>9){
		num.push_back(num[num.size()-1]/10);
		num[num.size()-2]=num[num.size()-2]%10;
	}
}

void print(vector<int> &num){
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<" ";
}

bool pall_check(vector<int> &num){
	vector<int> rev=num;
	reverse(rev.begin(),rev.end());
	if(rev==num)
		return true;
	return false;
}

bool check(vector<int> &num){
	for(int i=0;i<50;i++){
		add(num);
		if(pall_check(num))
			return false;
	}
	return true;
	
}



int main(){
	int count=0;
	for(int i=10;i<10000;i++){
		vector<int> num;
		int_to_vector(num,i);
		if(check(num)){
			count++;
		}
	}
	cout<<count;
	
}
