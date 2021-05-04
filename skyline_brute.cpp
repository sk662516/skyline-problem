//Skyline brute force

#include<bits/stdc++.h>
using namespace std;

struct sky{
    int l,h,r;
};

struct coord{
    int x,y;
};

int main(){
    struct sky input[]={ { 1, 11, 5 }, { 2, 6, 7 },
                        { 3, 13, 9 }, { 12, 7, 16 },
                        { 14, 3, 25 }, { 19, 18, 22 },
                        { 23, 13, 29 }, { 24, 4, 28 } };

    int h1,h2,i,j,k,z,q,n=sizeof(input)/sizeof(input[0]);

    //a is input co-ordinate
    //b is temporary co-ordinate
    //c is final co-ordinate
    vector<struct coord> a(2*n),b(2),c(2*n);

    a[0].x=input[0].l;
    a[0].y=input[0].h;
    a[1].x=input[0].r;
    a[1].y=0;

    for(i=1;i<n;i++){
        b[0].x=input[i].l;
        b[0].y=input[i].h;
        b[1].x=input[i].r;
        b[1].y=0;
        j=0;
        k=0;
        z=0;
        h1=0;
        h2=0;
        while(j<2*i && k<2){
            if(a[j].x<b[k].x){
                h1=a[j].y;
                c[z].x=a[j].x;
                j++;
                c[z++].y=max(h1,h2);    //maximum height save
            }

            else if(a[j].x>b[k].x){
                h2=b[k].y;
                c[z].x=b[k].x;
                k++;
                c[z++].y=max(h1,h2);
            }

            else{
                if(a[j].y>b[k].y){
                    h1=a[j].y;
                    c[z].x=a[j].x;
                    j++;
                    c[z++].y=h1;
                }

                else{
                    h2=b[k].y;
                    c[z].x=b[k].x;
                    k++;
                    c[z++].y=h2;
                }
            }
        }
        while(j<2*i){
            c[z].x=a[j].x;
            c[z++].y=a[j++].y;
        }
        while(k<2){
            c[z].x=b[k].x;
            c[z++].y=b[k++].y;
        }
        for(q=0;q<=2*i+1;q++){
            a[q].x=c[q].x;
            a[q].y=c[q].y;
        }
    }

    int g=0,v;
    for(i=0;i<2*n;i++){
        c[g].x=a[i].x;
        c[g++].y=a[i].y;
        if(a[i].y==a[i+1].y){
            v=i;
            while(a[i].y==a[v+2].y){
                v++;
            }
            i=v+1;
        }
    }
    c.resize(g);

    cout<<"Input\nLeft - Height - Right\n";
    for(i=0;i<n;i++){
        cout<<input[i].l<<" "<<input[i].h<<" "<<input[i].r<<"\n";
    }

    cout<<"\nSkyline points-\nX - Y\n";
    for(i=0;i<g;i++){
        cout<<c[i].x<<" "<<c[i].y<<"\n";
    }

    return 0;
}
