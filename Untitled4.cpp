#include<bits/stdc++.h>
#define max 99999999
using namespace std;



int main() {
	int arr[100005], n, left[100005], right[100005];
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    left[0] = 0;
    for(int i=1; i<n; i++) {
        if(arr[i]>arr[i-1]) {
            left[i] = left[i-1] + 1;
        }
        else {
            left[i] = 0;
        }
    }
    right[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        if(arr[i]>arr[i+1]) {
            right[i] = right[i+1] + 1;
        }
        else {
            right[i] = 0;
        }
    }
    int maxHeight = max;
    for(int i=0; i<n; i++) {
        if(right[i]!=0 && left[i]!=0) {
            maxHeight = min(right[i], left[i]);
        }
    }
    
    left[0] = 0;
    for(int i=1; i<n; i++) {
        if(arr[i]<arr[i-1]) {
            left[i] = left[i-1] + 1;
        }
        else {
            left[i] = 0;
        }
    }
    right[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        if(arr[i]<arr[i+1]) {
            right[i] = right[i+1] + 1;
        }
        else {
            right[i] = 0;
        }
    }
    int maxDepth = max;
    for(int i=0; i<n; i++) {
        if(right[i]!=0 && left[i]!=0) {
            maxDepth = min(right[i], left[i]);
        }
    }
    if(maxHeight!=max) {
        cout << maxHeight << " ";
    }
    else {
        cout << "0" << " ";
    }
    if(maxDepth!=max) {
        cout << maxDepth;
    }
    else {
        cout << "0";
    }
}
