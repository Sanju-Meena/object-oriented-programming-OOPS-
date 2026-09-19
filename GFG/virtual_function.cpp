#include<bits/stdc++.h>
using namespace std;

int main(){
    int score = 95;
int &bonusScore = score; // bonusScore is an alias for score

bonusScore += 5; 

cout<<score<<endl;
cout<<bonusScore<<endl;
cout<<&bonusScore<<endl;
// score is now 100 because bonusScore 
// and score are the same variable in memory
}