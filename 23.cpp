#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> map_plan;
vector<vector<int>> dist;
pair<int,int> start_pos;

pair<int,int> nearest_exit;

vector<pair<int, int>> moves = {
    {0,1}, // up
    {-1,0}, // left
    {1,0}, // right
    {0,-1} // down
};

struct G{
    int x;
    int y;
    int n;
};

bool CanEnter(G pos){
    //in borders, not visited, not wall
    if(pos.x < 0)
        return false;
    if(pos.y < 0)
        return false;
    if(pos.x > m)
        return false;
    if(pos.y > n)
        return false;

    if(map_plan[pos.x][pos.y] == '#')
        return false;
    if(dist[pos.x][pos.y] != -1)
        return false;

    return true;
}

void BFS(){
    queue<G> Q;
    Q.push({start_pos.first, start_pos.second, 0});
    dist[start_pos.first][start_pos.second] = 0;

    while(!Q.empty()){
        G temp = Q.front();
        Q.pop();

        if(map_plan[temp.x][temp.y] == 'X'){
            nearest_exit = {temp.x, temp.y};
            return;
        }

        for(auto &mov : moves){
            G temp2 =  temp;
            temp2.x += mov.first;
            temp2.y += mov.second;
            temp2.n++;

            if(CanEnter(temp2)){
                dist[temp2.x][temp2.y] = temp2.n;

                Q.push(temp2);
            }
        }

    }

}

void make_path(){
    G pos;
    pos.x = nearest_exit.first;
    pos.y = nearest_exit.second;
    pos.n = dist[pos.x][pos.y];

    while(pos.n >= 2){
        for(auto &mov : moves){
            G temp = pos;
            temp.x += mov.first;
            temp.y += mov.second;
            temp.n--;

            if(dist[temp.x][temp.y] == temp.n){
                pos = temp;
                map_plan[temp.x][temp.y] = '.';
                break;
            }
        }
    }

}

int main(){
    cin>>n>>m;
    map_plan.resize(n);
    dist.resize(n);

    string dummy;
    getline(cin, dummy);

    for(int i = 0; i < n; i++){
        string buff;
        getline(cin, buff);
        map_plan[i].resize(m,-1);
        dist[i].resize(m,-1);

        for(int j = 0; j < buff.size(); j++){
            map_plan[i][j] = buff[j];
            if(buff[j] == 'o'){
                start_pos = {i,j};
            }
        }
    }

    BFS();
    make_path();

    cout<<endl;
    for(auto &e : map_plan){
        for(auto &e2 : e){
            cout<<e2;
        }
        cout<<endl;
    }

}
