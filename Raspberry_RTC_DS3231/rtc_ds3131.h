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

class RTC_DS3131
{
public:
    RTC_DS3131();
    ~RTC_DS3131();

    //получить значение времени без преобразований
    time_t get_rawtime_from_RTC();

    //получить текущее местное время
    char* get_localtime_from_RTC();

    //установить время в модуль RTC
    //вернет 0 в случае успеха или
    //ERR_NO_SET_TIME_SYS  или
    //ERR_NO_SET_TIME_HARD

    //передать аргументом переменную типа time_t
    int8_t set_time_in_RTC(time_t);

    //передать аргументом переменную типа string, где формат должен быть следующим:
    //"2004-02-29 16:21:42"
    int8_t set_time_in_RTC_string(std::string);
private:
    //    устанавливаем время в системе
    //    в случае неудачи верннется ERR_NO_SET_TIME_SYS
    int8_t get_command_date(std::string&);

    //    записываем время в модуль RTC
    //    в случае неудачи верннется ERR_NO_SET_TIME_HARD
    int8_t get_command_hwclock();

    //синхронизируем системное время с аппаратным
    int8_t get_command_sync_sys_hw();

};

#endif // RTC_DS3131_H
