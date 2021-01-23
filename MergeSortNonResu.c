#include<stdio.h> 
#include<time.h>
#define SiZE 1000000
clock_t start,stop;
double duration;
int a[SiZE];
int atemp[SiZE];
void merge(int a[],int lo,int mid,int hi){
    int i = lo;
    int j = mid +1;
    for (int k=lo;k <= hi; k++){
        atemp[k] = a[k];
    }
    for (int k=lo;k <= hi; k++){
        if (i>mid){
            a[k] = atemp[j];
            j++;
        }else if(j > hi){
            a[k] = atemp[i];
            i++;
        }else{
            if(atemp[j]<atemp[i]){
                a[k] = atemp[j];
                j++;
            }else
            {
                a[k] = atemp[i];
                i++;
            }
        }
    }

    return ; 
}
void sort(int a[],int n){
    /*if (hi<=lo) {
    **    return ;
    **}
    **int mid = lo + (hi-lo)/2;
    **sort(a,lo,mid);
    **sort(a,mid+1,hi);
    **merge(a,lo,mid,hi);
    **int mid = lo+(hi-lo)/2;*/

    /*
    **@1st for:
    **0 1 2 3 4 5 6 7 8 9
    **a b c d e f g h j k
    **size = 1 2 4 8(merge length/2)
    **@2nd for:
    **lo = startIndex,
    **lo = 0 2 4 6 8 if(10>n-size=9) stop
    **hi = lo+    size+size   -1
    **       +the merge length+
    **eg: if lo =0 ;hi may be 1;
    **0 + (the size equals to 2) = 2 is the next lo
    **sub 1 get the hi;
    **if lo+size+size-1 > n-1
    **the hi min is n then overflow stop
    **ok~
    **size是每次迭代时，该迭代内容一半的长度，同时也象征着迭代的次序。
    **我们知道 loMax + size*2 >n，因为如果小于时，就还能对数组进行划分。
    **
    */
    int hi;
    for(int size=1;size<n;size = size*2){
        for(int lo=0;lo+size+size <= n+1;lo += size*2){
            if(lo+size+size-1 <= n-1){
                hi = lo+size+size-1;
            }else
            {
                hi = n-1;
            }       
            merge(a,lo,lo+size-1,hi);
        }
    }

}
int main() {
    int n =10; 
    for(int i=0;i<SiZE;i++) {
        a[i] = i;
    }

    start = clock();
    for(int i=0;i<n;i++){
       sort(a,SiZE-1);
    }
    stop = clock();
    printf("%lfms",((double)(stop-start)/(double)n));

    return 0;
}