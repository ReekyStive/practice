#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100000;

struct Player
{
    int id;
    int score;
    int ability;
    bool operator<(const Player &player) const
    {
        if (this -> score == player.score)
            return this -> id < player.id;
        else
            return this -> score < player.score;
    }
};

int main()
{
    int N, R, Q;
    cin >> N >> R >> Q;

    priority_queue<Player, vector<Player>, greater<Player> > players;
    priority_queue<Player, vector<Player>, greater<Player> > temp_pq;
    queue<Player> temp_que;

    Player player;
    for (int i = 1; i <= 2 * N; i++)
    {
        player.id = i;
        cin >> player.score;
        temp_que.push(player);
    }
    for (int i = 1; i <= 2 * N; i++)
    {
        player = temp_que.front();
        temp_que.pop();
        cin >> player.ability;
        players.push(player);
    }

// todo:
// players ==> temp_pq
// temp_pq ==> players

    return 0;
}
