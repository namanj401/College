#include <bits/stdc++.h>

using namespace std;
void merge(int a[], int l,int m, int r) 
{ 
    int n1 = m -l+1; 
    int n2 = r-m; 
       
    int L[n1], R[n2]; 
        
    for(int i=0;i<n1;i++) 
        L[i] = a[l+i]; 
    for(int j=0;j<n2;j++) 
        R[j]=a[m+1+j]; 
  
    
    int i=0;     
    int j=0;      
    int k=l; 
      
    while (i<n1&&j<n2) 
    { 
        if (L[i]<=R[j])  
        { 
            a[k]=L[i]; 
            i++; 
        } 
        else 
        { 
            a[k]=R[j]; 
            j++; 
        } 
        k++; 
  
    }
    while (i<n1)  
    { 
        a[k]=L[i]; 
        i++; 
        k++; 
    }
    while (j<n2) 
    { 
        a[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int a[],int l,int r) 
{ 
    if ( l< r) 
    { 
        int m = l+(r-l)/2; 
   
        mergeSort(a, l, m); 
        mergeSort(a, m + 1, r); 
  
        merge(a, l, m, r); 
    } 
} 


// Complete the closestNumbers function below.
void closestNumbers(int arr[], int n) {


    mergeSort(arr,0,n-1);
    int d=abs(arr[0]-arr[1]);
    for(int i=0;i<n-1;i++)
    {
       if(abs(arr[i]-arr[i+1])<d)
       d=abs(arr[i]-arr[i+1]);
    }
    for(int i=0;i<n-1;i++)
    {
        if(abs(arr[i]-arr[i+1])==d)
        cout<<arr[i]<<" "<<arr[i+1]<<" ";
    }
}

int main()
{
    

    int n;
    cin >> n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    closestNumbers(arr,n);
    
    return 0;
}
