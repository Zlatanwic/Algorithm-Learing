#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;
int n, m;
int matrix[MAXN][MAXN];
bool visited[MAXN][MAXN];

// 定义四个方向的偏移量
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isEdge(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

void dfs(int x, int y, bool& isRegion) {
    visited[x][y] = true;
    if (!isEdge(x, y)) {
        isRegion = true;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && matrix[nx][ny] == 1) {
            dfs(nx, ny, isRegion);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int regionCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                bool isRegion = false;
                dfs(i, j, isRegion);
                if (isRegion) {
                    regionCount++;
                }
            }
        }
    }

    cout << regionCount << endl;
    return 0;
}
