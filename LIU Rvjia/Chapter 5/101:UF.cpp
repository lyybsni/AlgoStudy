/* lyybsni 101 C++ "The Blocks Problem" */

#define MAX_BLOCK 30
#define QUIT "quit"
#define MOVE "move"
#define ONTO "onto"
#define PILE "pile"
#define OVER "over"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct block{
    static int count;
    int id;
    int pile;
    block(){
        count++;
        id = count;
        pile = count;
    }

};

bool operator == (const block& blc1, const block& blc2){
    return blc1.id == blc2.id;
}

int block::count = 0;

void move(block& blk, int pile, vector<vector<block> >& ls){
    blk.pile = pile;
    ls[pile].push_back(blk);
    cout << blk.id << " is moved to " << pile << endl;
}

void clear_above(block& blk, vector<vector<block> >& ls){
    int pile = blk.pile;
    int loc = distance(ls[pile].begin(),find(ls[pile].begin(),ls[pile].end(),blk));
    cout << "Found " << loc << " on " << pile << " with size " << ls[pile].size() << endl;
    for(int i = loc + 1; i < ls[pile].size(); i++){
        block& temp = ls[pile][i];
        move(temp, temp.id, ls);
    }
    ls[pile].resize(loc + 1);
}

void pile_onto(block& blk, int target, vector<vector<block> >& ls){
    int pile = blk.pile;
    int loc = (int) distance(ls[pile].begin(),find(ls[pile].begin(),ls[pile].end(),blk));
    cout << "Prepare to move " << loc << " on " << pile << " with size " << ls.size() << endl;
    for(int i = loc; i < ls[pile].size(); i++){
        block& temp = ls[pile][i];
        move(temp, target, ls);
    }
    ls[pile].resize(loc + 1);
}

void print(int number, vector<vector<block> >& ls){
    for(int i = 0; i < number; i++){
        cout << i + 1 << ": " ;
        for(block it: ls[i]){
            cout << it.id << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<block> > ls;

    int block_number;
    cin >> block_number;

    vector<block> blc;
    for(int i = 0; i < block_number; i++){
        blc.push_back(block());
        ls.push_back(vector<block>());
        ls[i].push_back(blc[i]);
    }

    string cmd1, cmd2;
    int id1, id2;

    while(cin >> cmd1){
        if(cmd1 == QUIT) {
            print(block_number, ls);
            return 0;
        }else if(cmd1 == "print"){
            print(block_number, ls);
        }
        else {
            cin >> id1 >> cmd2 >> id2;
        }

        if(blc[id1].pile == blc[id2].pile) continue;
        if(cmd2 == ONTO) clear_above(blc[id2], ls);
        if(cmd1 == MOVE) clear_above(blc[id1], ls);
        pile_onto(blc[id1], id2, ls);
    }

    return 0;
}