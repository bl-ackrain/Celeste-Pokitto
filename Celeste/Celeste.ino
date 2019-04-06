#include "game.h"

Game game;
void setup()
{
  pb.begin();
  //Serial.begin(115200);
  pb.setFrameRate(60);
  pb.display.setFont(pico8);
  game.init();
}

void loop()
{
  if(pb.update())
  {
    pb.display.setTextColor(WHITE);
    game.update();
    game.draw();
    pb.display.setCursor(92,0);
    pb.display.setTextColor(WHITE,BLACK);
    pb.display.printf("%d FPS",1000000/pb.frameDurationMicros);
  }
}
