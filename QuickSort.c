#include<stdio.h> 
#include<time.h>
#define SiZE 100000
clock_t start,stop;
double duration;
int a[SiZE];

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

int PartitionFirst(int a[],int lo,int hi){
    int LeftPointer = lo;   // 左扫描指针
    int RightPointer = hi;  // 右扫描指针
    int temp = a[lo];       // 划分元素
    LeftPointer++;          // 左扫描指针从划分元素右边开始

    while(1){
        while(a[LeftPointer] <= temp){ //<=划分元素左指针右移
            LeftPointer++;
            if(LeftPointer==hi){
                break;
            }
        }
        while (a[RightPointer] >= temp){ //右扫描指针>=左移
            RightPointer--;
            if(RightPointer==lo){
                break;
            }
        }

        if(LeftPointer >= RightPointer){ //左指针 >= 右指针终止循环
            break;
        }
        swap(&a[LeftPointer],&a[RightPointer]); //交换左指针和右指针中的元素
    }
    swap(&a[lo],&a[RightPointer]); //交换划分点元素的值和交换值
                                   //注意：这里再最后一次交换时，本来为 big(<-left),less(<-right)
                                   //交换后，左右指针再一次移动变为，less(<-right),big(<-left)
                                   //所有这里要将temp与less<-right 的值交换。

    return RightPointer;
}

void QuickSort(int a[],int lo,int hi) {
    if (hi <= lo){
        return ;
    }
    int flag = PartitionFirst(a,lo,hi);

    QuickSort(a,lo,flag-1);
    QuickSort(a,flag+1,hi);
}
int main() {
    int n =1; 
    for(int i=0;i<SiZE;i++) {
        a[i] = i;
    }
    start = clock();
    QuickSort(a,0,SiZE-1);
    stop = clock();
    printf("%lfms",((double)(stop-start)));

    return 0;
}