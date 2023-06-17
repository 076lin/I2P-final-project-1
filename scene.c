#include "scene.h"

ALLEGRO_BITMAP *img_menu = NULL;
ALLEGRO_BITMAP *img_info = NULL;
ALLEGRO_BITMAP *img_cloud1 = NULL;
ALLEGRO_BITMAP *img_cloud2 = NULL;
ALLEGRO_BITMAP *img_catus1 = NULL;
ALLEGRO_BITMAP *img_catus2 = NULL;
ALLEGRO_BITMAP *img_floor = NULL;
ALLEGRO_TIMER *timer;

// ALLEGRO_TIMER *timer;

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
    InitBackground(&FLOOR, 0, 300, 5, 0, 1400, 450, -1, 1, img_floor);
    timer = al_create_timer(1.0 / 60);
}

void game_scene_draw(){
    al_clear_to_color(al_map_rgb(252, 252, 252));
    // al_draw_bitmap(img_floor, 0, 300, 0);
    // al_draw_bitmap(img_catus1, 700, 300-99, 0);
    // al_draw_bitmap(img_catus2, 800, 300-99, 0);
    DrawBackground(&FLOOR);
}

void InitBackground(struct Background *back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image){
    back->x = x;
	back->y = y;
	back->velX = velx;
	back->velY = vely;
	back->width = width;
	back->height = height;
	back->dirX = dirX;
	back->dirY = dirY;
	back->image = image;
}

void UpdateBackground(struct Background *back){
	back->x += back->velX * back->dirX;
    printf("Background update: %f %f\n", back->x, back->y);
	if(back->x + back->width <= 0) back->x = 0;
}

void DrawBackground(struct Background *back){
    //printf("DrawBackground");
	al_draw_bitmap(back->image, back->x, back->y, 0);
    printf("Background draw: %f %f\n", back->x, back->y);
    // x = 0
    // y = 300
	if(back->x + (back->width) < WIDTH) al_draw_bitmap(back->image, back->x + back->width, back->y, 0);
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
void game_scene_destroy(){ 
    printf("game scene destroy\n");
    al_destroy_bitmap(img_floor);
}