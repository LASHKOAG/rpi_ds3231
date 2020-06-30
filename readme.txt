useful information how to add DS3231 real-time clock module to Raspberry Pi

Raspberry Pi RTC: Adding a Real Time Clock
https://pimylifeup.com/raspberry-pi-rtc/


g++ ./main.cpp ./rtc_ds3131.h ./rtc_ds3131.cpp -o ./ds

//turn off
sudo shutdown -h now

//reboot
sudo shutdown -r now


sudo date --set "2004-02-29 16:21:42"


//аппаратное время запись
sudo hwclock -w

//аппаратное время чтение
sudo hwclock -r

//синхронизация системного времени с аппаратным
sudo hwclock --hctosys
