#ifndef RTC_DS3131_H
#define RTC_DS3131_H

#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string.h>

//установка времени в системе - неуспешна
#define ERR_NO_SET_TIME_SYS     -1

//запись времени в модуль RTC - неуспешна
#define ERR_NO_SET_TIME_HARD    -2

//синхронизация системного времени с аппаратным - неуспешна
#define ERR_NO_SYNC_TIME        -3

//получение аппаратного времени - неуспешно
#define ERR_NO_HARDWARE_TIME    -4

class RTC_DS3131
{
public:
    RTC_DS3131();
    ~RTC_DS3131();

    //получить значение времени без преобразований
    //вернет количество секунд
    time_t get_rawtime_from_RTC();

    //получить текущее местное время
    //вернет Си-строку
    char* get_localtime_from_RTC();

    //установить время в модуль RTC
    //вернет 0 в случае успеха или
    //ERR_NO_SET_TIME_SYS  или
    //ERR_NO_SET_TIME_HARD

    //передать аргументом переменную типа time_t
    //вернет ERR_NO_SET_TIME_SYS или ERR_NO_SET_TIME_HARD, или 0 при успехе
    int8_t set_time_in_RTC(time_t);

    //передать аргументом переменную типа string, где формат должен быть следующим:
    //пример ввода даты: "2004-02-29 16:21:42"
    //вернет ERR_NO_SET_TIME_SYS или ERR_NO_SET_TIME_HARD, или 0 при успехе
    int8_t set_time_in_RTC_string(std::string);

    //синхронизировать системное время с аппаратным
    //вернет ERR_NO_SYNC_TIME в случае ошибки или 0 при успехе
    int8_t get_command_sync_sys_hw();

    //получить значение аппаратного времени
    //вернет ERR_NO_HARDWARE_TIME в случае ошибки или 0 при успехе
    int8_t get_command_hardware_time();

private:
    //    записываем время в модуль RTC
    //    в случае неудачи верннется ERR_NO_SET_TIME_HARD
    int8_t get_command_hwclock();

    //    вызов системной команды system
    //    в случае неудачи верннется -1
    int8_t system_send_command(std::string);
};

#endif // RTC_DS3131_H
