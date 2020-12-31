#include <drivera4988.h>;
#define pin_DIR 2// пинн направления
#define pin_STEP 3// пин шагов
#define pin_M1 7// пин м1 для микрошагов
#define pin_M2 6// пин м2 для микрошагов
#define pin_M3 5// пин м3 для микрошагов
#define STEP 96//базовые шаги двигателя
#define SPEED 10// скорость двигателя
#define ACCEL 10// ускорение
#define MINSPEED 100// минимальная скорость (чем больше - тем медленнее )
Drivera ds(pin_STEP, pin_DIR, pin_M1, pin_M2, pin_M3,STEP, SPEED, ACCEL , MINSPEED);


void setup() {}

void loop() {
  ds.linmove(180); // поворот до 180 градусов
  delay(1000);
}