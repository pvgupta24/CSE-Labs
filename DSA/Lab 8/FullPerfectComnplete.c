#include<stdio.h>
#include<limits.h>


int tree={1,2,3,4,5,6,7,8};

int isFull(int i){
	if(tree[i]==INT_MAX){
		return 1;
	}
	if(tree[2*i+1]==INT_MAX&&tree[2*i+2]!=INT_MAX){
		return 0;
	}
	if(tree[2*i+1]==INT_MAX&&tree[2*i+2]!=INT_MAX){
		return 0;
	}

	return isFull(2*i+1) & isFull(2*i+2);
}

int main(){


	if(isFull){

	}

	return 0;
}
