#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

const int BOARD_WIDTH = 40;
const int BOARD_HEIGHT = 25;

void generate_board(int snake_x, int snake_y, int fruit[])
{
    system("cls");
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            if (i == 0 || i == BOARD_HEIGHT - 1)
            {
                printf("#");
            }
            else if ((i > 0 && i < BOARD_HEIGHT) && (j == 0 || j == BOARD_WIDTH - 1))
            {
                printf("#");
            }
            else if (snake_x == j && snake_y == i)
            {
                printf("0");
            }
            else if (fruit[0] == j && fruit[1] == i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move(int *x, int *y, char *direction, int *is_game_over)
{
    Sleep(100);
    if (kbhit())
    {
        char key = getch();
        switch (key)
        {
        case 'w':
            *y = *y - 1;
            *direction = 'w';
            break;
        case 's':
            *y = *y + 1;
            *direction = 's';
            break;
        case 'a':
            *x = *x - 1;
            *direction = 'a';
            break;
        case 'd':
            *x = *x + 1;
            *direction = 'd';
            break;
        case 'x':
            *is_game_over = 1;
        default:
            break;
        }
    }
    else
    {
        switch (*direction)
        {
        case 'w':
            *y = *y - 1;
            break;
        case 's':
            *y = *y + 1;
            break;
        case 'a':
            *x = *x - 1;
            break;
        case 'd':
            *x = *x + 1;
            break;
        default:
            break;
        }
    }
}

int main()
{
    int score = 0;
    int is_game_over = 0;

    char direction = 'a';
    int snake_x = 20;
    int snake_y = 20;

    int fruit[2] = {rand() % (1 - BOARD_WIDTH) + 1, rand() % (1 - BOARD_HEIGHT) + 1};

    while (!is_game_over)
    {
        generate_board(snake_x, snake_y, fruit);
        move(&snake_x, &snake_y, &direction, &is_game_over);
        if (snake_x == 0 || snake_x == BOARD_WIDTH - 1 || snake_y == 0 || snake_y == BOARD_HEIGHT - 1)
        {
            is_game_over = 1;
        }
        if (snake_x == fruit[0] && snake_y == fruit[1])
        {
            score += 10;
            fruit[0] = rand() % (1 - BOARD_WIDTH) + 1;
            fruit[1] = rand() % (1 - BOARD_HEIGHT) + 1;
        }
        printf("Score: %d", score);
    }

    return 0;
}