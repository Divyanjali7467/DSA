class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();
        
        int sr = -1, sc = -1;
        
        // Give every litter cell an index
        vector<vector<int>> id(m, vector<int>(n, -1));
        int litterCount = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                
                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }
        
        int allMask = (1 << litterCount) - 1;
        
        // State: row, col, remaining energy, mask
        struct State {
            int r, c, e, mask;
        };
        
        queue<State> q;
        
        q.push({sr, sc, energy, 0});
        
        // visited[r][c][energy][mask]
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
        
        visited[sr][sc][energy][0] = true;
        
        int moves = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            
            int sz = q.size();
            
            while (sz--) {
                
                State cur = q.front();
                q.pop();
                
                int r = cur.r;
                int c = cur.c;
                int e = cur.e;
                int mask = cur.mask;
                
                // All litter collected
                if (mask == allMask) {
                    return moves;
                }
                
                for (int d = 0; d < 4; d++) {
                    
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    
                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;
                    
                    // Cannot move with zero energy
                    if (e == 0)
                        continue;
                    
                    int ne = e - 1;
                    int nmask = mask;
                    
                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask |= (1 << bit);
                    }
                    
                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }
                    
                    if (!visited[nr][nc][ne][nmask]) {
                        
                        visited[nr][nc][ne][nmask] = true;
                        
                        q.push({
                            nr,
                            nc,
                            ne,
                            nmask
                        });
                    }
                }
            }
            
            moves++;
        }
        
        return -1;
    }
};