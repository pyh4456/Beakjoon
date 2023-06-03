#include<iostream>

using namespace std;

int dy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int n, m, robot_y, robot_x, robot_direction, ** room;

enum Direction {
    UP, RIGHT, DOWN, LEFT
};

class Robot_vacuum {
public:
    int y, x;
    Direction direct;
    int cleaned = 0;

    Robot_vacuum(int a, int b, Direction dir) {
        this->y = a;
        this->x = b;
        this->direct = dir;
    }
    bool move() {   //움직일 수 있을때 true, 움직일 수 없을 때 false
        bool not_clean = false;   //주변에 청소되지 않은 칸이 있는지 여부
        int ny, nx;

        if (room[y][x] == 0) {
            room[y][x] = 2;      //2가 청소했음을 의미
            cleaned++;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            ny = y + dy[i][0];
            nx = x + dy[i][1];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (room[ny][nx] == 0) {
                not_clean = true;
                break;
            }
        }

        bool fix_direct = false;
        if (not_clean) {
            while (1) {
                switch (direct) {
                case UP:
                    direct = LEFT;
                    if (x > 0 && room[y][x - 1] == 0) {
                        x--;
                        fix_direct = true;
                    }
                    break;
                case RIGHT:
                    direct = UP;
                    if (y > 0 && room[y - 1][x] == 0) {
                        fix_direct = true;
                        y--;
                    }
                    break;
                case DOWN:
                    direct = RIGHT;
                    if (x < m - 1 && room[y][x + 1] == 0) {
                        fix_direct = true;
                        x++;
                    }
                    break;
                case LEFT:
                    direct = DOWN;
                    if (y < n - 1 && room[y + 1][x] == 0) {
                        fix_direct = true;
                        y++;
                    }
                    break;
                }

                if (fix_direct)
                    break;
            }
        }
        else {
            switch (direct) {
            case UP:
                if (y == n - 1) {
                    return false;
                }
                if (room[y + 1][x] != 1) {
                    y++;
                }
                else {
                    return false;
                }
                break;
            case RIGHT:
                if (x == 0) {
                    return false;
                }
                if (room[y][x - 1] != 1) {
                    x--;
                }
                else {
                    return false;
                }
                break;
            case DOWN:
                if (y == 0) {
                    return false;
                }
                if (room[y - 1][x] != 1) {
                    y--;
                }
                else {
                    return false;
                }
                break;
            case LEFT:
                if (x == m - 1) {
                    return false;
                }
                if (room[y][x + 1] != 1) {
                    x++;
                }
                else {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};

void print() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << room[i][j] << " ";
        }cout << endl;
    }
}

int main() {
    Direction dir;
    cin >> n >> m;
    cin >> robot_y >> robot_x >> robot_direction;

    room = new int* [n];

    for (int i = 0; i < n; i++) {
        room[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    switch (robot_direction) {
    case 0:
        dir = UP;
        break;
    case 1:
        dir = RIGHT;
        break;
    case 2:
        dir = DOWN;
        break;
    case 3:
        dir = LEFT;
        break;
    }

    Robot_vacuum robot(robot_y, robot_x, dir);

    while (robot.move()) {
  
    }
    cout << robot.cleaned;
}