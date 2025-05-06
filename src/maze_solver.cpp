#include "maze_solver.h"
#include <stack>
using namespace std;

// Out of bounds, wall, or already visited → not a valid move
if (!maze.inBounds(r, c)  maze.isWall(r, c)  visited[r][c]) {
    return false;
}

// Check if we reached the finish
if (r == maze.finish.row && c == maze.finish.col) {
    maze.path.push_back({r, c});
    return true;
}

// Mark the current cell as visited
visited[r][c] = true;

// Explore all 4 directions: up, right, down, left
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

for (int i = 0; i < 4; i++) {
    int newRow = r + dRow[i];
    int newCol = c + dCol[i];

    if (dfs(maze, newRow, newCol, visited)) {
        maze.path.push_back({r, c});
        return true;
    }
}

return false;
}
