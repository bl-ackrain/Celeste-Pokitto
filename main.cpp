#include "Celeste/game.h"
extern const uint8_t pico8[];

Game game;

Pokitto::Core pb;

int main () {
    pb.begin();
    Pokitto::Sound::ampEnable(true);
    pb.setFrameRate(60);

    pb.display.loadRGBPalette(palettePico);
    pb.display.setInvisibleColor(BLACK);
    pb.display.setFont(pico8);
#ifdef POK_SIM
    pb.setFrameRate(30);
    pb.wait(100);
#endif // POK_SIM
    game.init();
    while (pb.isRunning()) {
        if (pb.update())
        {
            game.update();
            game.draw();
        }
    }
    return 0;
}

