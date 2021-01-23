#include<stdio.h> 
#include<time.h>
#define SiZE 2000
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
void sort(int a[],int lo,int hi){
    if (hi<=lo) {
        return ;
    }
    int mid = lo + (hi-lo)/2;
    sort(a,lo,mid);

    sort(a,mid+1,hi);

    merge(a,lo,mid,hi);

}
int main() {
    int n =1; 
    for(int i=0;i<SiZE;i++) {
        a[i] = i;
    }
    start = clock();
    for(int i=0;i<n;i++){
       sort(a,0,SiZE-1);
    }
    stop = clock();
    printf("%lfms",((double)(stop-start)/(double)n));

    return 0;
}