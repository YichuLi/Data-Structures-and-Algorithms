#include <vector>
#include <iostream>
using namespace std;

void put_queen(int k, int col, vector<vector<int>>& attack){
    // for 8 dirctions
    static const int dx[] = {-1, -1, 0, 1, 1, 1,   0, -1};
    static const int dy[] = {0,   1, 1, 1, 0, -1, -1, -1};
    attack[k][col] = 1;

    for(int i = 1; i < attack.size(); i++){
        for(int j = 0; j < 8; j++){
            int nx = k + dx[j] * i;
            int ny = col + dy[j] * i;

            if(nx >=0 && nx < attack.size() && ny >= 0 && ny < attack.size()){
                attack[nx][ny] = 1;
            }
        }
    }
}

// k is for kth line
// n is for n queens
// queen stores the pos of queens
// attack stores the attack pos
// solve stores the solution
void backtrack(int k, int n, vector<string>& queen, vector<vector<int>>& attack, vector<vector<string>>& solve){
    // find a solution when k==n
    if(k == n){
        solve.push_back(queen);
        return;
    }

    // traverse
    for(int i = 0; i < n; i++){
        if(attack[k][i] == 0){  // line k, col i can put queen
            vector<vector<int>> temp = attack;  // backup
            queen[k][i] = 'Q';
            put_queen(k, i, attack);
            backtrack(k + 1, n, queen, attack, solve);
            attack = temp;  // recover attack array
            queen[k][i] = '.'; // recover queen array

        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> solve;
    vector<string> queen;   // save pos of queens
    vector<vector<int>> attack;
    
    for(int i = 0; i < n; i++){
        attack.push_back(vector<int>());
        for(int j = 0; j < n; j++){
            attack[j].push_back(0);
        }
        queen.push_back("");
        queen[i].append(n, '.');
    }

    backtrack(0, n, queen, attack, solve);

    return solve;
}

int main()
{
    vector<vector<string>> result = solveNQueens(8);
    cout << "hi";
    cout << result.size() << endl;

    return 0;
}

