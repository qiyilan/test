#include<stdio.h> 
#define SiZE 20
int a[SiZE];

//交换两个元素
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}
//首元素划分法
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

//三元素中位数划分法
int median3(int a[],int i,int j,int k){
    if((a[i]>=a[j]) && (a[j]>=a[k]) || (a[k]>=a[j]) && (a[j]>=a[i])){
        return j;
    }
    if((a[j]>=a[i]) && (a[i]>=a[k]) || (a[k]>=a[i]) && (a[i]>=a[j])){
        return i;
    }    
    if((a[i]>=a[k]) && (a[k]>=a[j]) || (a[j]>=a[k]) && (a[k]>=a[i])){
        return k;
    }
}
void MedianQuickSort(int a[],int lo,int hi){ 
    int n = hi-lo+1; 
    int mid3 = median3(a,lo,lo + n/2,hi);
    int flag;
    if (lo >= hi-1){
        if(lo == hi -1){
            swap(&a[lo],&a[hi]);
        }
        return ;
    }
    swap(&a[lo],&a[mid3]);
    flag = PartitionFirst(a,lo,hi);
    MedianQuickSort(a,lo,flag-1);
    MedianQuickSort(a,flag+1,hi);
}

int main() {
    int n;
    printf("Enter the number of the array\n");
    scanf("%d",&n);
    printf("Input the numbres:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    MedianQuickSort(a,0,n-1);
    // 展示最终排序完毕的数据
    printf("---------\n");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}