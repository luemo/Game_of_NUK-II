#include <allegro.h>
#include <time.h>
#include "header_S_value.h"
#include "header_Cfont.h"

void Exit()
{
	close_Cfont();
	remove_keyboard();
	remove_mouse();
	allegro_exit();
}

void close_button_handler(){
//	Exit();
//	exit(0);
	close_button_pressed = TRUE;
}

void Init()
{
	allegro_init();
	set_close_button_callback(close_button_handler);
//	set_color_depth(32);
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	install_keyboard();
	srand(time(0));

	init_Cfont();/*¤å¦r¨t²Î*/
	close_button_pressed = 0;
}



