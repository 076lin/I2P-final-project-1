#include "scene.h"

ALLEGRO_BITMAP *img_menu = NULL;
ALLEGRO_BITMAP *img_info = NULL;
ALLEGRO_BITMAP *img_cloud1 = NULL;
ALLEGRO_BITMAP *img_cloud2 = NULL;
ALLEGRO_BITMAP *img_catus1 = NULL;
ALLEGRO_BITMAP *img_catus2 = NULL;
ALLEGRO_BITMAP *img_floor = NULL;

void menu_init()
{
    printf("menu init\n");
    img_menu = al_load_bitmap("./asset/menu.png");
    img_info = al_load_bitmap("./asset/information.png");
}
void menu_draw()
{
    al_draw_bitmap(img_menu, 0, 0, 0);
}
void menu_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_UP){
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            judge_to_info = true;
            printf("get enter\n");
        }
    }
}
void start_game_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_UP){
        if (event.keyboard.keycode == ALLEGRO_KEY_SPACE){
            judge_to_game = true;
            printf("get backspace\n");
        }   
    }
}
void info_draw()
{
    al_draw_bitmap(img_info, 0, 0, 0);
}

void game_scene_init(){
    printf("game scene init\n");
    img_cloud1 = al_load_bitmap("./asset/cloud1.png");
    img_cloud2 = al_load_bitmap("./asset/cloud2.png");
    img_floor = al_load_bitmap("./asset/floor.png");
    img_catus1 = al_load_bitmap("./asset/catus1.png");
    img_catus2 = al_load_bitmap("./asset/catus2.png");
}

void game_scene_draw(){
    al_clear_to_color(al_map_rgb(252, 252, 252));
    //printf("game scene draw\n");
}

void menu_destroy(){
    printf("menu destroy\n");
    al_destroy_bitmap(img_menu);
    al_destroy_bitmap(img_info);
}
void info_destroy(){
    al_destroy_bitmap(img_menu);
    al_destroy_bitmap(img_info);
}   