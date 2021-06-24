#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Player
{
    int id = -1;
    int score = -1;
    int ability = -1;
    bool operator<(const Player &player) const
    {
        if (this -> score == player.score)
            return this -> id > player.id;
        else
            return this -> score < player.score;
    }
};

int main()
{
    int N, R, Q;
    cin >> N >> R >> Q;

    priority_queue<Player> players;
    priority_queue<Player> temp_pq;
    queue<Player> temp_que;

    Player player, temp_player;
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

    priority_queue<Player, vector<Player>, less<Player> > *pq_a = &players;
    priority_queue<Player, vector<Player>, less<Player> > *pq_b = &temp_pq;
    for (int i = 0; i < R; i++)
    {
        while (!pq_a -> empty())
        {
            player = pq_a -> top();
            pq_a -> pop();
            temp_player = pq_a -> top();
            pq_a -> pop();
            if (player.ability > temp_player.ability)
                player.score++;
            else
                temp_player.ability++;
            pq_b -> push(player);
            pq_b -> push(temp_player);
        }
        swap(pq_a, pq_b);
    }

    for (int i = 0; i < Q - 1; i++)
        pq_a -> pop();
    
    cout << pq_a -> top().id << endl;

    return 0;
}
