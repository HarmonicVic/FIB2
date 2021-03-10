// struct Node
//   {
//     int x;
//     int y;
//     double f_score;
//     double g_score;
//     double h_score;
//     Node *parent;
//   };

//   const Dir opposite_direction(Dir d)
//   {
//     if (d == Up)
//       return Down;
//     else if (d == Down)
//       return Up;
//     else if (d == Left)
//       return Right;
//     else if (d == Right)
//       return Left;
//   }

//   finds the nearest object searched for from an initial distance and returns the position at which the object is
//   distance can be later calculated outside of the bfs algorithm to avoid useless operations
//   invariant: we suppose i and j are valid positions in the map
//   returns position [1:n],[1:m]
//   pair<int, int> bfs_money(Pos position)
//   {
//     int n = board_rows();
//     int m = board_cols();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     vector<Pos> wherefrom;

//     queue<pair<int, int>> next;
//     queue<Node> next;
//     next.push(make_pair(position.i, position.j));
//     next.push(node(position.i, position.j, nullptr));
//     wherefrom.push_back(position);

//     int x, y;
//     while (!next.empty())
//     {
//       x = next.front().first;
//       y = next.front().second;
//       next.pop();

//       if (cell(x,y).bonus == Money) //insert objective here
//         return {x, y};
//       else if (!visited[x][y])
//       {
//         visited[x][y] = true;
//         if (x != 0 and mat[x - 1][y] != 'X')  //'X' stands for wall / obstacle
//         if(Pos(x,y) != Pos(0,y) and cell(x-1,y).type == Street)   
//           next.push(make_pair(x - 1, y));
//         if (x != n - 1 and mat[x + 1][y] != 'X')
//         if(Pos(x,y) != Pos(n - 1, y) and cell(x+1,y).type == Street)
//           next.push(make_pair(x + 1, y));
//         if (y != 0 and mat[x][y - 1] != 'X')
//         if(Pos(x,y) != Pos(x,0) and cell(x,y-1).type == Street)
//           next.push(make_pair(x, y - 1));
//         if (y != m - 1 and mat[x][y + 1] != 'X')
//         if(Pos(x,y) != Pos(x, m-1) and cell(x,y+1).type == Street)  
//           next.push(make_pair(x, y + 1));
//       }
//     }
//     no such entity found
//     return {-1, -1};
//   }

//const vector<Dir> directions = {Up, Down, Left, Right};


// else
//         {
//           //optimize money search early on, because builders only flee, build barricades and search for money
//           //if money is there, go for it. This part of the algorithm is used during (day_rounds) - 5;

//           //if that checks if min cell still has money and if the astar_path still has the path to that money entity. if doesn't do anything,
//           //just skips the else statements that actually calculate a new astar path.
          
//           cout << "ha llegado el momento de que builder " << i << " busque dinero" << endl;
          
//           //auto it_ap_m = astar_path_m.end();
//           // if (cell(min_m).bonus == Money and *(--it_ap_m) == min_m);
          
//           if (cell(min_m).bonus == Money)
//           {
//             astar(p, min_m, 'm');
//             ap_m = astar_path_m.end();
//           }
//           //finds the nearest money Pos
//           else
//           {
//             auto it = grid_m.begin();
//             double min_dist = infinity;
//             while (it != it_m)
//             {
//               double h = heuristics(p, *it);
//               if (h < min_dist)
//               {
//                 min_m = *it;
//                 min_dist = h;
//               }
//               it++;
//             }
//             if (cell(min_m).bonus == Money) //just making sure
//             {
//               astar(p, min_m, 'm');
//               ap_m = astar_path_m.end();
//             }
//           }

//           //ap_m points at end of vector, and --ap_m points at 1st position to which we move
//           --ap_m;
//           // if (ap_m == astar_path_m.begin())
//           // {
//           //   move(i, pos2dir(p, *ap_m));
//           //   auto it = grid_m.begin();
//           //   double min_dist = infinity;
//           //   while (it != it_m)
//           //   {
//           //     if (heuristics(p, *it) < min_dist)
//           //       min_m = *it;
//           //     it++;
//           //   }
//           //   if (cell(min_m).bonus == Money)
//           //   {
//           //     astar(p, min_m, 'm');
//           //     ap_m = astar_path_m.end();
//           //   }
//           // }
//           // else
//           move(i, pos2dir(p, *ap_m));
//         }

  // Dir available_dir(Pos p)
  // {
  //   if (cell(Pos(p + Down)).type == Street)
  //     return Down;
  //   else if (cell(Pos(p + Up)).type == Street)
  //     return Up;
  //   else if (cell(Pos(p + Left)).type == Street)
  //     return Left;
  //   else if (cell(Pos(p + Right)).type == Street)
  //     return Right;
  // }