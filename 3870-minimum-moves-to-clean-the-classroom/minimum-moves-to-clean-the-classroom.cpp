class Solution {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
public:
    struct State {
        int row;
        int col;
        int energy;
        int mask;
        int moves;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startRow = 0;
        int startCol = 0;

        // litterId[i][j] tells which bit belongs to this L
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        // Find S and assign IDs to all L cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }

                else if(classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter
        if(litterCount == 0) {
            return 0;
        }

        int finalMask = (1 << litterCount) - 1;

        /*
            visited[row][col][energy][mask]

            mask tells us which litter cells
            have already been collected.
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<State> q;

        q.push({startRow, startCol, energy, 0, 0});
        visited[startRow][startCol][energy][0] = true;

        // up, down, left, right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {

            State curr = q.front();
            q.pop();

            int row = curr.row;
            int col = curr.col;
            int currEnergy = curr.energy;
            int mask = curr.mask;
            int moves = curr.moves;

            // All litter collected
            if(mask == finalMask) {
                return moves;
            }

            // Can't move without energy
            if(currEnergy == 0) {
                continue;
            }

            for(int d = 0; d < 4; d++) {

                int newRow = row + dr[d];
                int newCol = col + dc[d];

                // Boundary check
                if(newRow < 0 || newRow >= m ||
                   newCol < 0 || newCol >= n) {
                    continue;
                }

                // Cannot cross obstacle
                if(classroom[newRow][newCol] == 'X') {
                    continue;
                }

                // Every move costs 1 energy
                int newEnergy = currEnergy - 1;

                // If we enter R, energy resets
                if(classroom[newRow][newCol] == 'R') {
                    newEnergy = energy;
                }

                int newMask = mask;

                // Collect litter
                if(classroom[newRow][newCol] == 'L') {

                    int id = litterId[newRow][newCol];

                    newMask = newMask | (1 << id);
                }

                if(!visited[newRow][newCol][newEnergy][newMask]) {

                    visited[newRow][newCol][newEnergy][newMask] = true;

                    q.push({
                        newRow,
                        newCol,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};