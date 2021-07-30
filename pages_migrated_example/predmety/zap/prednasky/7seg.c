#include <stdio.h>

void draw(const int rows, const int cols, char array[][cols]);
int main(){
    int rows = 5, cols = 4;

    char arr2[][5][4] = {
        {
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        },
        {
        "--|",
        "  |",
        "--|",
        "| ",
        "|__",
        },
        {
        "--|",
        "  |",
        "--|",
        "  |",
        "__|",
        }
    };
    draw(rows, cols, arr2[0]);

    return 0;
}

void draw(const int rows, const int cols, char array[][cols]){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            printf("%c", array[y][x]);
        }
        printf("\n");
    }
}
