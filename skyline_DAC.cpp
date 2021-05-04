//Divide and conquer solution

#include <bits/stdc++.h>

using namespace std;
using vvi=vector<vector<int>>;

vvi merge(vvi& sl1, vvi& sl2){
    int i=0,j=0;
    int h1=0,h2=0,hmax=0;
    int x,x1,x2;
    int len1=sl1.size(), len2=sl2.size();
    vvi res;
    while(i<len1 && j<len2){
        x1=sl1[i][0];
        x2=sl2[j][0];
        if (x1<x2){
            h1=sl1[i++][1];
            x=x1;
        }
        else if(x1>x2){
            h2=sl2[j++][1];
            x=x2;
        }
        else{
            h1=sl1[i++][1];
            h2=sl2[j++][1];
            x=x1;
            }

            hmax=max(h1,h2);
            if (!res.empty()){
            vector<int> rb=res.back();
            if (hmax==rb.back())  continue;
            if (x==rb.front()){
                res.back().back()=max(rb.back(),hmax);
                continue;
            }
        }
        res.push_back({x,hmax});
    }

    while (i<len1){
        res.push_back(sl1[i++]);
    }

    while (j<len2){
        res.push_back(sl2[j++]);
    }
    return res;
}

vvi helper(vvi & buildings, int left, int right){
    if(left==right ){
        return vvi{{buildings[left][0],buildings[left][1]},{buildings[left][2],0}};
    }
    int mid;
    mid=left+(right-left)/2;
    vvi lsl=helper(buildings,left,mid);
    vvi rsl=helper(buildings,mid+1,right);
    return merge(lsl,rsl);
}

vvi getSkyline(vvi& buildings){
    int n=buildings.size();
    int left=0;
    int right=n-1;
    return helper(buildings,left,right);
}


int main()
{
	vvi input= { { 1, 11, 5 }, { 2, 6, 7 },
                { 3, 13, 9 }, { 12, 7, 16 },
                { 14, 3, 25 }, { 19, 18, 22 },
                { 23, 13, 29 }, { 24, 4, 28 } };

    vvi c=getSkyline(input);
    int i;

    cout<<"Input\nLeft - Height - Right\n";
    for(i=0;i<input.size();i++){
        cout<<input[i][0]<<" "<<input[i][1]<<" "<<input[i][2]<<"\n";
    }

    cout<<"\nSkyline points-\nX - Y\n";
    for(i=0;i<c.size();i++){
        cout<<c[i][0]<<" "<<c[i][1]<<"\n";
    }
    return 0;
}
