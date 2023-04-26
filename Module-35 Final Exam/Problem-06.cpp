#include<bits/stdc++.h>
using namespace std;
int a;
vector<vector<string>>solve;

bool solution_found(int id,vector<string>state)
{
    return id==a;
}

vector<string>get_candidates(int id,vector<string>state,vector<string>st)
{
    int m=state.size();
    vector<string>candidates;

    if(m==0){
        candidates=st;
        return candidates;
    }

    for(string x : st){
        if(x==state[m-1]) continue;
        candidates.push_back(x);
    }

    return candidates;
}

void back_track(int id,vector<string>state,vector<string>st)
{
    if(solution_found(id,state)){
        solve.push_back(state);
        return ;
    }

    vector<string>candidetes=get_candidates(id,state,st);

    for(string x : candidetes){
        state.push_back(x);

        back_track(id+1,state,st);

        state.pop_back();
    }
}

int main()
{
    vector<string>s;
    s.push_back("white");
    s.push_back("blue");
    s.push_back("orange");
    cin>>a;
    vector<string>initial_state(a);
    back_track(0,initial_state,s);
    int cont=0;
    for(vector<string>x:solve){
        for(string y:x)
            cout<<y<<" ";
        cont++;
        cout<<endl;
    }
    cout<<cont<<endl;
    return 0;
}
