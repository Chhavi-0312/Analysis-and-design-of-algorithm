#include <bits/stdc++.h>
#include<chrono>
using namespace std;
float avg_time = 0;
void mergearr(int a[],int low,int mid,int high)
{
 int n1=mid-low+1;
int n2=high-mid;
 int A[n1],B[n2];
 for(int i=0;i<n1;i++)
 {
 A[i]=a[low+i];
 }
 for(int j=0;j<n2;j++)
 {
 B[j]=a[mid+1+j];
 }
 int i=0,j=0,k=low;
 while(i<n1&&j<n2)
 {
 if(A[i]<=B[j])
 {
 a[k]=A[i];
 i++;
 }
 else{
 a[k]=B[j];
 j++;
 }
 k++;
 }
 while(i<n1){
 a[k]=A[i];
 i++;
 k++;
 }
 while(j<n2){
 a[k]=B[j];
 j++;
 k++;
 }
}
void mergesort(int a[],int l,int r)
{
 if(l>=r)
 {
 return;
 }
 int m=(l+(r-l)/2);
mergesort(a,l,m);
mergesort(a,m+1,r);
mergearr(a,l,m,r);
}
int main()
{
int key,range1,range2,step_count,avg;
 cout<<"Enter Range"<<endl;
 cin>>range1>>range2;
 cout<<"Enter Step count"<<endl;
 cin>>step_count;
 cout<<"Enter average count"<<endl;
 cin>>avg;
srand(time(0));
for(int n=range1; n<=range2; n=n+step_count)
 {
 avg_time=0;
int a[n];
 cout<<n<<"\t";
for(int i=0; i<avg; i++)
 {
for(int j=0; j<n; j++)
 {
a[j]=(rand()%(n+50))+1;
 }
auto begins = std::chrono::high_resolution_clock::now();
mergesort(a, 0, n-1);
auto ends = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = ends - begins;
 avg_time=avg_time+(elapsed.count()*1000000);
 }
 cout<<avg_time/avg<<"\n";
 }
return 0;
}
