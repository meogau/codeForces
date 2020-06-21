int list[100];
int a[100];
list[0] = 1;
int cache = 1;
for(int i = 1; i < 100; i++){
    if(a[i] > a[i-1]){
        list[i] = max(list[i-1], cache+1);
        cache++;
    }else{
        cache = 0;
        list[i] = list[i-1];
    }
}

