#include <allegro.h>
#include <stdint.h>
#include <stdlib.h>

int main() 
{
    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    BITMAP *buffer = create_bitmap(640,480);
    while (!key[KEY_ESC])
    {
        circlefill(buffer, 400, 250, 50, makecol(255,69,0));
        textprintf_ex(buffer, font, 360, 250, makecol(0,0,0), -1, "Discreta");
        blit(buffer,screen,0,0,0,0,640,480);
        clear_bitmapa(buffer);
    }
    destroy_bitmap(buffer);
    return 0;
}
