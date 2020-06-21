#include <bits/stdc++.h> 
#define pii pair<int, int> 
#define mp make_pair 
using namespace std; 
  
int BFS(int a, int b, int target) 
{ 

    map<pii, int> visited; 
    map<pii, int> deep;
    queue<pii> q;  
     q.push({ 0, 0 }); 
     deep[{0,0}]=0;
    int count;
    while (!q.empty()) { 
  
        pii u = q.front(); 
  
        q.pop(); 
  
        if (visited[{ u.first, u.second }] == 1) 
            continue; 

        if ((u.first > a || u.second > b || 
            u.first < 0 || u.second < 0)) 
            continue; 
  

  
        visited[{ u.first, u.second }] = 1; 
        count = deep[{u.first,u.second}]+1;
        if (u.first == target || u.second == target) { 
            return  deep[{ u.first, u.second }];

        q.push({ u.first, b }); if(deep[{ u.first, b }]==0)deep[{ u.first, b }]=count;
        q.push({ a, u.second });if(deep[{ a, u.second}]==0)deep[{ a, u.second }] =count;
  
        for (int ap = 0; ap <= max(a, b); ap++) { 
  
            int c = u.first + ap; 
            int d = u.second - ap; 
  
            if ((c == a || d == 0) && d >= 0) 
            {
            	q.push({ c, d }); 	
            	if(deep[{ c, d }]==0)deep[{ c, d }]=count;
			}
                
            c = u.first - ap; 
            d = u.second + ap; 
            if (c >= 0 && (c == 0 || d == b) ){
                q.push({ c, d }); 
              	
                if(deep[{ c, d }]==0)deep[{ c, d }]=count;	
			}
      }  q.push({ u.first, 0 }); 
         if(deep[{ u.first, 0 }]==0)deep[{ u.first, 0 }]=count;	
          q.push({ 0, u.second }); 
         if(deep[{ 0, u.second }]==0)deep[{ 0, u.second }]=count;	
      
         
    } 
  
    return -1;
} 
  
int main() 
{ 
    int Jug1 , Jug2 , target ; 
    cin>>Jug1>>Jug2>>target;
    cout << BFS(Jug1,Jug2,target);
    return 0; 
} 
