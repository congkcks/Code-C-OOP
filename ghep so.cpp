#include<bits/stdc++.h>


using namespace std;


string s,t,miin = "999999999999999999",maax = "0";


void backtracking(int x,int y,string res){


    if(res.length() == s.length() + t.length()){


        miin = min (res,miin);


        maax = max (res,maax);
    }


    if(x<s.length()) backtracking(x+1,y,res + s[x]);


    if(y<t.length()) backtracking(x,y+1,res + t[y]);


}


int main (){


    cin >> s >> t;


    backtracking(0,0,"");


    cout << miin << "\n" << maax ;


}
