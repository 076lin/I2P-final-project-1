#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 1400;
const int HEIGHT = 450;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_to_info = false;
bool judge_to_game = false;
bool render = false;
struct Background FLOOR;
