#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const int BOARD_WIDTH = 40;
const int BOARD_HEIGHT = 25;

typedef struct {
  void *next;
  int x;
  int y;
} SnakeNode;

void print_at(int x, int y, char c) { printf("\033[%d;%dH%c", y, x, c); }

void generate_board(int fruit[]) {
  system("cls");
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      if (i == 0 || i == BOARD_HEIGHT - 1) {
        printf("#");
      } else if ((i > 0 && i < BOARD_HEIGHT) &&
                 (j == 0 || j == BOARD_WIDTH - 1)) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void draw_snake(SnakeNode *snake_head) {
  SnakeNode *current = snake_head;
  while (current != NULL) {
    print_at(current->x, current->y, '0');
    current = current->next;
  }
}

void draw_fruit(int fruit[]) { print_at(fruit[0], fruit[1], '*'); }

void move(SnakeNode *snake_head, char *direction, int *is_game_over) {
  SnakeNode *current = snake_head;
  int prev_x = current->x;
  int prev_y = current->y;

  Sleep(100);
  if (kbhit()) {
    char key = getch();
    switch (key) {
      case 'w':
        if (*direction == 's') break;
        *direction = 'w';
        break;
      case 's':
        if (*direction == 'w') break;
        *direction = 's';
        break;
      case 'a':
        if (*direction == 'd') break;
        *direction = 'a';
        break;
      case 'd':
        if (*direction == 'a') break;
        *direction = 'd';
        break;
      case 'x':
        *is_game_over = 1;
      default:
        break;
    }
  }

  switch (*direction) {
    case 'w':
      current->y = current->y - 1;
      break;
    case 's':
      current->y = current->y + 1;
      break;
    case 'a':
      current->x = current->x - 1;
      break;
    case 'd':
      current->x = current->x + 1;
      break;
    default:
      break;
  }

  print_at(prev_x, prev_y, ' ');
  current = current->next;
  while (current != NULL) {
    print_at(current->x, current->y, ' ');
    int curr_x = current->x;
    int curr_y = current->y;
    current->x = prev_x;
    current->y = prev_y;
    prev_x = curr_x;
    prev_y = curr_y;
    current = current->next;
  }
}

SnakeNode *add_node(SnakeNode *snake_head, int x, int y) {
  SnakeNode *current = snake_head;
  SnakeNode *new = malloc(sizeof(SnakeNode));
  if (new == NULL) {
    perror("Error while allocating memory");
  }
  new->x = x;
  new->y = y;
  new->next = NULL;

  while (current != NULL) {
    if (current->next == NULL) {
      current->next = new;
      break;
    }
    current = current->next;
  }
}

int main() {
  int score = 0;
  int is_game_over = 0;
  char direction = 's';

  SnakeNode *head = malloc(sizeof(SnakeNode));
  if (head == NULL) {
    perror("Error while allocating memory");
  }
  head->next = NULL;
  head->x = 15;
  head->y = 10;

  int fruit[2] = {rand() % (1 - BOARD_WIDTH) + 1,
                  rand() % (1 - BOARD_HEIGHT) + 1};

  generate_board(fruit);
  draw_fruit(fruit);

  while (!is_game_over) {
    move(head, &direction, &is_game_over);
    draw_snake(head);
    if (head->x == 0 || head->x == BOARD_WIDTH - 1 || head->y == 0 ||
        head->y == BOARD_HEIGHT - 1) {
      is_game_over = 1;
    }
    if (head->x == fruit[0] && head->y == fruit[1]) {
      score += 10;
      add_node(head, head->x, head->y);
      fruit[0] = rand() % (1 - BOARD_WIDTH) + 1;
      fruit[1] = rand() % (1 - BOARD_HEIGHT) + 1;
      draw_fruit(fruit);
    }
  }

  return 0;
}