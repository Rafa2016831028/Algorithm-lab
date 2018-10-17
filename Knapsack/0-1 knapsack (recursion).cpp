#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){ (a>b) ? a:b ;}

int knapSack(int w,int val[],int wt[],int n)
{
    if(n==0 ||w==0) return 0;

    if(wt[n-1]>w) return knapSack(w,val,wt,n-1);

    else return max(val[n-1]+knapSack(w-wt[n-1],val,wt,n-1),knapSack(w,val,wt,n-1));
}

int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int w =50;
    int n = sizeof(val)/sizeof(val[0]);

    cout<<"Otimal value : "<<knapSack(w,val,wt,n)<<"\n";
}
