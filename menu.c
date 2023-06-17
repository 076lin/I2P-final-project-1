#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h> // ANS: include the head file of ttf
#include <allegro5/allegro_image.h>// ANS: include the head file of image
#include <allegro5/allegro_primitives.h>
#define GAME_TERMINATE 666

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT *font;
ALLEGRO_BITMAP *img_start;
ALLEGRO_BITMAP *img_intro;
ALLEGRO_BITMAP *img_dino;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT event;

bool key_state[ALLEGRO_KEY_MAX];

/*
    TODO: Declare display variable.
*/

const int window_width = 1400;
const int window_height = 450;

const int button_width1 = 520;
const int button_height1 = 200;
const int button_width2 = 400;
const int button_height2 = 300;

void show_err_msg(int msg);
void game_init();
void game_menu();
int game_run();
void game_destroy();
//int process_event();

int main(int argc, char *argv[]) {
    int msg = 0;
    int i = 0; 
    game_init();
    printf("Hello world!!!\n");
    //al_rest(2);
    game_menu();

    while(i<GAME_TERMINATE){
        al_rest(2);
        i++;
    }
    
    game_destroy();
    return 0;
}


void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(9);
}
/*
    The function above aims to show the error message and terminate the game.
    You may use it in any function need to deal with some error message.
    The program would not get any error if you don't utilize it,
    But you may get a tough debugging time when some mistakes happen.
    You can modify it to fit for your habit.
*/

void game_init() {
    al_init();    
    display  = al_create_display(window_width, window_height);
    al_set_window_position(display, 0 ,0);
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
}

void game_menu() {
    al_clear_to_color(al_map_rgb(190,190,190));
    // 記得路徑
    font  = al_load_ttf_font("./font/PressStart.ttf", 50, 0); 
    al_draw_text(font, al_map_rgb(99,98,99), 670, 114, ALLEGRO_ALIGN_CENTRE,  "Dinosaur game");
    img_start = al_load_bitmap("./asset/start.png");
    img_intro = al_load_bitmap("./asset/howtoplay.png");
    img_dino = al_load_bitmap("./asset/d1.png");
    al_draw_bitmap(img_start, button_width1 , button_height1, 0);
    al_draw_bitmap(img_intro, button_width2, button_height2, 0);
    // al_draw_bitmap(img_dino, 0, 0, 0);
    //al_draw_filled_rectangle(button_width1, button_height1, button_width1+300, button_height1+70, al_map_rgb(0,0,0));
    //al_draw_filled_rectangle(button_width2, button_height2, button_width2+300, button_height2+70, al_map_rgb(0,0,0));
    al_flip_display();
}


void game_destroy() {
    al_destroy_display(display);
    al_destroy_font(font);
    al_destroy_bitmap(img_start);
    //al_destroy_bitmap(img_dino);
    al_destroy_bitmap(img_intro);
}

