#include <ncurses.h>

#include <screen.h>

int main() {

  initscr();
  if (!has_colors()) {
    return -1;
  }
  // raw();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  start_colors();
  use_default_colors();

  char *main_menu_options[] = {"List expenses", "Add an expense",
                               "Remove an expense", "Exit"};
  int num_options = sizeof(main_menu_options) / sizeof(main_menu_options[0]);
  int choice = 1;
  int ch;
  while (choice > 0) {
    clear();
    print_menu("Choose an option:", main_menu_options, num_options, choice);
    ch = getch();
      if (ch >= '0' && ch <= '9')
      choice = ch - '0';

    switch (ch) {
    case KEY_LEFT:
      if (choice > 1)
        choice--;
      break;
    case KEY_RIGHT:
      if (choice < num_options)
        choice++;
      break;
    case KEY_UP:
      if (choice > 1)
        choice--;
      break;
    case KEY_DOWN:
      if (choice < num_options)
        choice++;
      break;
    }

  }

  refresh();
  endwin();

  return 0;
}
