#include <drivera4988.h>;
#define pin_DIR 2
#define pin_STEP 3
#define pin_M1 3
#define pin_M2 4
#define pin_M3 5
#define STEP 200
#define SPEED 10

Drivera ds(pin_STEP, pin_DIR, pin_M1, pin_M2, pin_M3,STEP, SPEED);

void setup() {}

void loop() {
  ds.moverot(360,1); // поворот на 360 градусов 
  delay(1000);
  ds.moverot(360,0); //поворот обратно
  delay(1000);
}