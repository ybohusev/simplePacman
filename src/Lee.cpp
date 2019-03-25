#include "Lee.h"

void lee(char map[H][W], int &startx, int &starty, int finx, int finy) {
    int len; 
    int dx[4] = {2, 0, -2, 0};
    int dy[4] = {0, 1, 0, -1};
    int d;

    d = 0;
    map[starty][startx] = 0;
    do {
        for (int y = 0; y < H; ++y ) {
            for (int x = 0; x < W; ++x ) {
                if (map[y][x] == d) {
                    for (int k = 0; k < 4; ++k) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
                            map[iy][ix] == BLANK)
                            map[iy][ix] = d + 1;
                    }
                }
            }
        }
        d++;
    } while (map[finy][finx] == BLANK);

    len = map[finy][finx];
    int x = finx;
    int y = finy;
    d = len;
    while (d > 1) {
        d--;
        for (int k = 0; k < 4; ++k) {
            int iy=y + dy[k], ix = x + dx[k];
            if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
                map[iy][ix] == d) {
                x = x + dx[k];
                y = y + dy[k];
                break;
            }
        }
    }
    startx = x;
    starty = y;
}