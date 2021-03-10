//Tuesday: TODO all players go to the right indefinitely, check why it happens -> fixed
//Wednesday: TODO fix vector path issues, change to stack if all fails -> changed to stack
//Thursday: TODO only one builder follows A*, others don't move -> fixed
//Friday: TODO warriors only follow others during day for no apparent reason, find out why

#include "Player.hh"

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME ObriuBarFib

struct PLAYER_NAME : public Player
{

    /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
    static Player *factory()
    {
        return new PLAYER_NAME;
    }

    /**
   * Types and attributes for your player can be defined here.
   */

    vector<Dir> directions = {Up, Down, Left, Right};

    //data structure that saves each builder id (int) with their respective money interest (Pos)
    map<int, pair<stack<Pos>, Pos>> civilian_path;

    //function that gets initial pos and destination pos and returns the direction in which to go to get there
    const Dir pos2dir(const Pos &ini, const Pos &dest)
    {
        if (ini + Down == dest)
            return Down;
        else if (ini + Up == dest)
            return Up;
        else if (ini + Left == dest)
            return Left;
        else if (ini + Right == dest)
            return Right;
    }

    const void next_pos_money(const Pos &p, const int &id)
    {
        auto it = grid_m.begin();
        double min_dist = infinity;
        while (it != it_m)
        {
            double h_m = heuristics(p, *it);
            if (h_m < min_dist)
            {
                civilian_path[id].second = *it;
                min_dist = h_m;
            }
            it++;
        }
    }

    const int next_pos_bazooka(const Pos &p, const int &id)
    {
        auto it = grid_w.begin();
        double min_dist = infinity;
        while (it != it_w or cell(*it).weapon != Bazooka)
        {
            double h_b = heuristics(p, *it);
            if (h_b < min_dist)
            {
                if (citizen(cell(p).id).weapon == Hammer and cell(*it).weapon == Gun)
                {
                    civilian_path[id].second = *it;
                    min_dist = h_b;
                }
                else if (citizen(cell(p).id).weapon == Hammer and cell(*it).weapon == Bazooka)
                {
                    civilian_path[id].second = *it;
                    min_dist = h_b;
                }
                else if (citizen(cell(p).id).weapon == Gun and cell(*it).weapon == Bazooka)
                {
                    civilian_path[id].second = *it;
                    min_dist = h_b;
                }
            }
            it++;
        }
        //-1 for errors, 1 for new pos found
        if (it == it_w)
            return -1;
        return 1;
    }

    const void next_pos_kill(const Pos &p, const int &id)
    {
        auto it = victims.begin();
        double min_dist = infinity;
        while (it != it_v)
        {
            double h_m = heuristics(p, *it);
            if (h_m < min_dist)
            {
                civilian_path[id].second = *it;
                min_dist = h_m;
            }
            it++;
        }
    }

    int infinity = 2147483447; //infinity declaration, not real infinity but number near int overflow

    bool start = true; //used only for 1st round initialization/setup

    vector<Pos> grid_w; //bazooka vector
    vector<Pos> grid_m; //money vector
    vector<Pos> victims;

    vector<Pos>::iterator it_w; //points to last useful pos in grid_w
    vector<Pos>::iterator it_m; //points to last useful pos in grid_m
    vector<Pos>::iterator it_v; //points to last useful pos in victims

    void read_grid()
    {
        it_w = grid_w.begin();
        it_m = grid_m.begin();
        it_v = victims.begin();
        for (int i = 0; i < board_rows(); ++i)
        {
            for (int j = 0; j < board_cols(); ++j)
            {
                if (cell(i, j).weapon == Bazooka or cell(i, j).weapon == Gun)
                {
                    *it_w = Pos(i, j);
                    it_w++;
                }
                if (cell(i, j).bonus == Money)
                {
                    *it_m = Pos(i, j);
                    it_m++;
                }
                if (cell(i, j).id != -1 and citizen(cell(i, j).id).player != me() and citizen(cell(i, j).id).type == Builder)
                {
                    *it_v = Pos(i, j);
                    it_v++;
                }
            }
        }
    }

    const double heuristics(const Pos &x, const Pos &y)
    {
        return abs(x.i - y.i) + abs(x.j - y.j);
    }

    //map of which position came from where
    map<Pos, Pos> came_from;

    //function to reconstruct the path from the astar algorithm into a more easy to traverse vector. Don't touch first push_back, it's not a good idea
    const void reconstruct_path(const Pos &start, const Pos &end, const int &id)
    {
        Pos current = end;
        civilian_path[id].first.push(current);
        while (current != start)
        {
            auto it = came_from.find(current);
            civilian_path[id].first.push(it->second);
            current = it->second;
        }
        civilian_path[id].first.pop();
    }

    //function that uses the A* algorithm with the Manhattan heuristic to calculate the optimal path from the civilian position to the position
    //I have searched. It calculates the path and stores it into the came_from map, which is then reconstructed into astar_path for an easier time
    //reading and using it. passes on type of entity searched for
    const void astar(const Pos &start, const Pos &end, const int &id, const char &aggro)
    {
        while (!civilian_path[id].first.empty())
            civilian_path[id].first.pop();
        came_from.clear();
        //priority queue for (double f_score, Pos start)
        priority_queue<pair<double, Pos>, vector<pair<double, Pos>>, greater<pair<double, Pos>>> open_set;
        open_set.push(make_pair(double(0), start));

        //matrix of g scores, same sizes as board used in game, all initialized to infinity except start pos, g score = 0
        vector<vector<int>> g_score(board_rows(), vector<int>(board_cols()));
        for (int i = 0; i < board_rows(); ++i)
            for (int j = 0; j < board_cols(); ++j)
                g_score[i][j] = infinity;
        g_score[start.i][start.j] = 0;

        //matrix of f scores, same sizes as board used in game, all initialized to infinity except start pos, f score = g(0) + h(from start to end)
        //heuristics used is Manhattan
        vector<vector<int>> f_score(board_rows(), vector<int>(board_cols()));
        for (int i = 0; i < board_rows(); ++i)
            for (int j = 0; j < board_cols(); ++j)
                f_score[i][j] = infinity;
        f_score[start.i][start.j] = heuristics(start, end);

        //set that saves the same positions as open set, but is easier to access than the priority queue, and doesn't have all the internal complicated stuff
        //at start it only has start pos, exactly like open_set p.q.
        set<Pos> open_set_hash = {start};
        vector<Pos> neighbors;

        //loop that actually does the magic, while p.q. is not empty
        while (!open_set.empty())
        {
            Pos current = open_set.top().second;
            open_set.pop();
            open_set_hash.erase(current);

            if (current == end)
            {
                reconstruct_path(start, end, id);
                break;
            }

            //erases neighbors that are not valid, doesn't keep in mind if neighbor is already visited or not, the g_score will do the work for that
            // vector<Pos> neighbors = {Pos(current + Down), Pos(current + Up), Pos(current + Left), Pos(current + Right)};

            for (int i = 0; i < 4; i++)
            {
                Pos candidate = Pos(current + directions[i]);
                if (aggro == 'k')
                {
                    if (pos_ok(candidate) and cell(candidate).type == Street and cell(candidate).resistance == -1)
                    {
                        if (cell(candidate).id != -1 and citizen(cell(candidate).id).player != me())
                            neighbors.push_back(candidate);
                        if (cell(candidate).id == -1)
                            neighbors.push_back(candidate);
                    }
                }
                else if (aggro == 'n')
                {
                    if (pos_ok(candidate) and cell(candidate).type == Street and cell(candidate).resistance == -1 and cell(candidate).id == -1)
                        neighbors.push_back(candidate);
                }
            }

            //for every neighbor of current, calculate g and f scores and see if it's worth even looking at the neighbor. If it's a good candidate for the
            //path, insert the neighbor into the p.q. and the open_set_hash
            for (auto n : neighbors)
            {
                double temp_g_score = g_score[current.i][current.j] + 1;

                if (temp_g_score < g_score[n.i][n.j])
                {
                    came_from.insert(make_pair(n, current));
                    g_score[n.i][n.j] = temp_g_score;
                    f_score[n.i][n.j] = temp_g_score + heuristics(n, end);
                    if (pos_ok(n) and open_set_hash.find(n) == open_set_hash.end())
                    {
                        open_set.push(make_pair(f_score[n.i][n.j], n));
                        open_set_hash.insert(n);
                    }
                }
            }
            neighbors.clear();
        }
    }

    Pos prev_pos;
    Pos current_pos;

    map<int, bool> moved;

    // vector<pair<Pos, int>> i_barricade;

    /**
   * Play method, invoked once per each round.
   */
    virtual void play()
    {
        if (start == true)
        {
            grid_w.resize(num_ini_bazookas() + num_ini_guns() + num_ini_money());
            grid_m.resize(num_ini_money());
            victims.resize(18); //has a bit of size overhead TODO fix
            // i_barricade.resize(num_ini_builders(), make_pair(Pos(), 0));
            start = false;
        }

        read_grid();
        //what to do during the day
        if (is_day())
        {
            //builders
            //store the ids of the builders to use later
            vector<int> handymen = builders(me());
            for (int i : handymen)
            {
                Pos p = citizen(i).pos;
                next_pos_money(p, i);
                astar(p, civilian_path[i].second, i, 'n');
                if (!civilian_path[i].first.empty())
                {
                    Pos next_pos = civilian_path[i].first.top();
                    if (pos_ok(next_pos) and cell(next_pos).type == Street and cell(next_pos).id == -1)
                    {
                        civilian_path[i].first.pop();
                        move(i, pos2dir(p, next_pos));
                    }
                }
            }

            // //warriors
            vector<int> fighters = warriors(me());

            for (int i : fighters)
            {
                Pos p = citizen(i).pos;
                int res;
                if (citizen(i).weapon == Bazooka)
                    next_pos_money(p, i);
                else
                {
                    res = next_pos_bazooka(p, i);
                    if (res == -1)
                        next_pos_money(p, i);
                }
                astar(p, civilian_path[i].second, i, 'n');
                Pos fight_pos = civilian_path[i].second;
                if (!civilian_path[i].first.empty())
                {
                    if (cell(fight_pos).weapon == Bazooka or cell(fight_pos).weapon == Gun)
                    {
                        Pos next_pos = civilian_path[i].first.top();
                        if (pos_ok(next_pos) and cell(next_pos).type == Street and cell(next_pos).id == -1)
                        {
                            civilian_path[i].first.pop();
                            move(i, pos2dir(p, next_pos));
                        }
                    }
                }
            }
        }

        //what to do during the night
        else if (is_night())
        {
            //builders
            //store the ids of the builders to use later
            vector<int> handymen = builders(me());
            for (int i : handymen)
            {
                Pos p = citizen(i).pos;
                next_pos_money(p, i);
                astar(p, civilian_path[i].second, i, 'n');
                if (!civilian_path[i].first.empty())
                {
                    Pos next_pos = civilian_path[i].first.top();
                    if (pos_ok(next_pos) and cell(next_pos).type == Street and cell(next_pos).id == -1)
                    {
                        civilian_path[i].first.pop();
                        move(i, pos2dir(p, next_pos));
                    }
                }
            }

            vector<int> fighters = warriors(me());

            for (int i : fighters)
            {
                //search and kill
                Pos p = citizen(i).pos;
                next_pos_kill(p, i);
                astar(p, civilian_path[i].second, i, 'k');
                if (!civilian_path[i].first.empty())
                {
                    Pos next_pos = civilian_path[i].first.top();
                    if (pos_ok(next_pos) and cell(next_pos).type == Street)
                    {
                        civilian_path[i].first.pop();
                        move(i, pos2dir(p, next_pos));
                    }
                }
                cerr << p << endl;
                // cerr << "is it night: " << is_night() << endl;
            }
        }
    }
};

/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);