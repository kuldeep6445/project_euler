#include<iostream>
#include<fstream>
using namespace std;

bool royal_flush(int c){
	if(c[12]==1&&c[11]==1&&c[10]==1&&c[9]==1&&c[8]==1)
		return true;
	return false;
}

bool straight_flush(int count_val[]){
	bool start=false;
	for(int i=0;i<13;i++){
		if(count_val[i]==1){
			start=true;
		}
		if(start){
			for(int j=0;j<5;j++){
				if(count_val[i+j]!=1){
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

int get_rank(string hands){
	char val[5];
	char suit[5];
	for(int i=0;i<5;i++){
		val[i]=hands[i*3];
		suit[i]=hands[i*3+1];
	}
	//for(int i=0;i<5;i++){cout<<suit2[i]<<" ";}
	int count_val[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	//-----------------2 3 4 5 6 7 8 9 T J Q K A
	int count_suit[4]={0,0,0,0};
	//-----------------H D S C
	for(int i=0;i<5;i++){
		if(suit[i]=='H')
			count_suit[0]++;
		else if(suit[i]=='D')
			count_suit[1]++;
		else if(suit[i]=='S')
			count_suit[2]++;
		else if(suit[i]=='C')
			count_suit[3]++;
	}
	for(int i=0;i<5;i++){
		if(suit[i]>=50&&suit[i]<=57)
			count_val[suit[i]-50]++;
		else if(suit[i]=='T')
			count_val[8]++;
		else if(suit[i]=='J')
			count_val[9]++;
		else if(suit[i]=='Q')
			count_val[10]++;
		else if(suit[i]=='K')
			count_val[11]++;
		else if(suit[i]=='A')
			count_val[12]++;
	}
	bool flush=false;
	for(int i=0;i<5;i++){
		if(count_suit[i]==5){
			flush=true;
			break;
		}
	}
	if(flush){
		if(royal_flush(count_val)){
			return 10;
		}
		else if(straight_flush(count_val)){
			return 9;
		}
		else{
			return 6;
		}
	}
	if(four_of_kind(count_val)){
		return 8;
	}
	if(full_house(count_val)){
		return 7;
	}
	if(straight_flush(count_val)){
		return 5;
	}
	if(three_of_kind(count_val)){
		return 3;
	}
	if()
	

}

int main(){
	ifstream f("p054_poker.txt");
	//while(!f.eof()){
		string hands,pl1,pl2;
		getline(f,hands);
		pl1 = hands.substr(0,15);
		pl2 = hands.substr(15);
		int rank1 = get_rank(pl1);
		int rank2 = get_rank(pl2);
	//}
}
