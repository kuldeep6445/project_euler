#include<iostream>
#include<vector>
using namespace std;

void create_map(vector<vector<long double> > &map,int size){
	vector<long double> a;
	a.push_back(1);
	map.push_back(a);
	a.push_back(1);
	map.push_back(a);
	for(int i=2;i<=size;i++){
		vector<long double> row;
		row.push_back(1);
		for(int j=0;j<a.size()-1;j++){
			row.push_back(a[j]+a[j+1]);
		}
		row.push_back(1);
		a = row;
		map.push_back(row);
		
	}
}

void display(vector<vector<long double> > &map){
	for(int i=0;i<map.size();i++){
		for(int j=0;j<map[i].size();j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	vector<vector<long double> > map;
	create_map(map,100);
	int count=0;
	for(int i=0;i<map.size();i++){
		for(int j=0;j<map[i].size();j++){
			if(map[i][j]>1000000){
				count++;
			}
		}
	}
	cout<<count;
}
