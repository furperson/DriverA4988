# DriverA4988
Библиотека для Arduino, управление шаговыми двигателями с помощью драйвера A4988
angle - мера в градусах.
mode - 0 или 1. 1 - относительная система координат. 0 - абсолютная система координат.
setspeed() - установка скорости движения ;
setmode() - установка системы координат;
setcoors() - установка координаты данной позиции;
setsplit() - настройка микрошага : 0 = 1/1, 1 = 1/2, 2 = 1/4, 3 = 1/8, 4 = 1/16;
setangle() - поворот до определенного угла;
setherezero() - установка данной позиции как 0 для относительной системы координат;
linmove() - линейное движение в системах координат(0-359)(изначально двигается в одном направлении(1), но можно поменять и на другое (0), как последний аргумент);
moverot() - поворот на определеный угол(0 - int) (изначально двигается в одном направлении(1), но можно поменять и на другое (0), как последний аргумент);
setaccel() - установка ускорение;
getangle() - получить текущий реальный угол вала двигателя;
sethome() - установить точку дома для относительной системы координат;
Вся скорость идет в милисекундах на один шаг, деленых на два .

