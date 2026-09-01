class Solution {
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();

        vector lampId(rows, vector<int>(cols, 0));

        int startX = 0, startY = 0;
        int lampCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    lampId[i][j] = 1 << lampCount++;
                }
            }
        }

        int totalMasks = 1 << lampCount;

        vector bestEnergy(
            rows,
            vector(cols, vector<int>(totalMasks, -1))
        );

        struct State {
            int x;
            int y;
            int mask;
            int energy;
            int moves;
        };

        queue<State> q;

        bestEnergy[startX][startY][0] = energy;
        q.push({startX, startY, 0, energy, 0});

        int allCollected = totalMasks - 1;

        while (!q.empty()) {
            State current = q.front();
            q.pop();

            if (current.mask == allCollected) {
                return current.moves;
            }

            if (current.energy == 0) {
                continue;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nextX = current.x + dx[dir];
                int nextY = current.y + dy[dir];

                if (nextX < 0 || nextX >= rows ||
                    nextY < 0 || nextY >= cols ||
                    classroom[nextX][nextY] == 'X') {
                    continue;
                }

                int nextEnergy;

                if (classroom[nextX][nextY] == 'R') {
                    nextEnergy = energy;
                } else {
                    nextEnergy = current.energy - 1;
                }

                int nextMask =
                    current.mask | lampId[nextX][nextY];

                if (nextEnergy > bestEnergy[nextX][nextY][nextMask]) {
                    bestEnergy[nextX][nextY][nextMask] = nextEnergy;

                    q.push({
                        nextX,
                        nextY,
                        nextMask,
                        nextEnergy,
                        current.moves + 1
                    });
                }
            }
        }

        return -1;
    }
};