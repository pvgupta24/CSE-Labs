#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define LC(x) maxHeap[(2*x+1)]
#define RC(x) maxHeap[(2*x+2)]
#define leftIndex(x) (2*x+1)
#define rightIndex(x) (2*x+2)
#define parIndex(x) ((x-1)/2)
#define LOOP(i,n) for(i=0;i<n;++i)

#define SIZE 100

int maxHeap[SIZE];
int heapIndex = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int n){
    if(heapIndex == SIZE){
        printf("Heap Full.......\n");
        return;
    }
    maxHeap[heapIndex++]=n;
    int i=heapIndex-1;
    int par=parIndex(i);
    while(par>=0 && maxHeap[par] < maxHeap[i]){
        swap(maxHeap+par , maxHeap+i);
        i=par;
        par=parIndex(i);        
    }
}
void heapify(int rootIndex){
    //no child
    if(leftIndex(rootIndex) >= heapIndex){
        return;
    }
    //only left
    if(rightIndex(rootIndex)>=heapIndex){
        if(LC(rootIndex) > maxHeap[rootIndex])
            swap(maxHeap+rootIndex , maxHeap + leftIndex(rootIndex));
        return;
    }

    //both
    if(maxHeap[rootIndex]>=LC(rootIndex) && maxHeap[rootIndex]>=RC(rootIndex))
        return;
    
    int maxIndex = LC(rootIndex) > RC(rootIndex) ? leftIndex(rootIndex) : rightIndex(rootIndex);
    swap(maxHeap + maxIndex , maxHeap + rootIndex);
    heapify(maxIndex);
}

void deleteRoot(){
    --heapIndex;
    swap(maxHeap + heapIndex , maxHeap);
    heapify(0);
}

void print(){
    int i;
    LOOP(i,heapIndex){
        printf("%d ",maxHeap[i]);
    }
    printf("\n");
}

void sort(){
    while(heapIndex){
        printf("%d ",maxHeap[0]);
        deleteRoot();
    }
    printf("\n");
}



int main(){
    int c,data;
    printf("Max Heap");
    again:

    printf("\n1. Insert Element         2. Delete Root          3. Sort\n");
	scanf("%d",&c);

	switch(c){
		case 1:	printf("Enter data\n");
                scanf("%d",&data);
                insert(data);
				break;

		case 2:	/*printf("Enter data to delete\n");
                scanf("%d",&data);*/
                deleteRoot();
				break;		

		case 3: sort();
				break;
	}
    print();
    goto again;
    
    return 0;
}
