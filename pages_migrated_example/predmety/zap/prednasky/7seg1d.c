#include <stdio.h>

void draw(const int rows, const int cols, char* array);
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
    draw(rows, cols, (char*)arr2[2]);

    return 0;
}

void draw(const int rows, const int cols, char* array){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            int z = x + cols * y;
            printf("%c", array[z]);
        }
        printf("\n");
    }
}
