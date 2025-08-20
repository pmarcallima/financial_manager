#ifndef SCREEN_H
#define SCREEN_H


void print_menu(char *title, char **options, int num_options, int choice);

void start_colors();

void turn_colors_on(int color_pair);

void turn_colors_off(int color_pair);


#endif //SCREEN_H
