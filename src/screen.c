#include <screen.h>
#include <ncurses.h>

static bool colors_initialized = false;

void print_menu(char *title, char **options, int num_options, int choice) {
  printw("%s\n", title);
  for (int i = 0; i < num_options; i++) {
    if (choice - 1 == i)
      printw("-> .%d %s\n", i + 1, options[i]);
    else
      printw("   .%d %s\n", i + 1, options[i]);
  }
}
void start_colors() {
  if (has_colors() && !colors_initialized) {
    start_color();
    colors_initialized = true;
  }
}
void turn_colors_on(int color_pair) {
  if (colors_initialized)
    attron(COLOR_PAIR(color_pair));
}
void turn_colors_off(int color_pair) {
  if (colors_initialized)
    attroff(COLOR_PAIR(color_pair));
}
