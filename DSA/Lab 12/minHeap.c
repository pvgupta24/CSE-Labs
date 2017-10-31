#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define LC(x) minHeap[(2*x+1)]
#define RC(x) minHeap[(2*x+2)]
#define leftIndex(x) (2*x+1)
#define rightIndex(x) (2*x+2)
#define parIndex(x) ((x-1)/2)
#define LOOP(i,n) for(i=0;i<n;++i)

#define SIZE 100

int minHeap[SIZE];
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
    minHeap[heapIndex++]=n;
    int i=heapIndex-1;
    int par=parIndex(i);
    while(par>=0 && minHeap[par] > minHeap[i]){
        swap(minHeap+par , minHeap+i);
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
        if(LC(rootIndex) < minHeap[rootIndex])
            swap(minHeap+rootIndex , minHeap + leftIndex(rootIndex));
        return;
    }

    //both
    if(minHeap[rootIndex]<=LC(rootIndex) && minHeap[rootIndex]<=RC(rootIndex))
        return;
    
    int minIndex = LC(rootIndex) < RC(rootIndex) ? leftIndex(rootIndex) : rightIndex(rootIndex);
    swap(minHeap + minIndex , minHeap + rootIndex);
    heapify(minIndex);
}

void deleteRoot(){
    --heapIndex;
    swap(minHeap + heapIndex , minHeap);
    heapify(0);
}

void print(){
    int i;
    LOOP(i,heapIndex){
        printf("%d ",minHeap[i]);
    }
    printf("\n");
}

void sort(){
    while(heapIndex){
        printf("%d ",minHeap[0]);
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
