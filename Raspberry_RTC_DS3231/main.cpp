#include "rtc_ds3131.h"


int main()
{
    RTC_DS3131 *rtc = new RTC_DS3131();

    std::cout << "Number of hours, since 01 01 1970 = "
              << rtc->get_rawtime_from_RTC()<< std::endl;

    std::cout << "Current local time and date = "
              <<  rtc->get_localtime_from_RTC() << std::endl; // текущая дата в понятной для человека форме

    rtc->set_time_in_RTC(1593421771);
    rtc->set_time_in_RTC_string("2004-02-29 16:21:42");


    // Проверка, доступен ли командный процессор
//    if ( system(NULL) ) std::cout << "Командный процессор доступен\n";
//    else exit (1);                                      // выход из программы

//    std::cout << "Выполнение команды dir...\n\n";
//    int i = system ("dir");                               // показать файлы текущей директории
//    std::cout << "\nВозвращаемое значение: " << i << "\n";


    //  system ("echo 1 > /home/energ/Desktop/test_system_cpp/testOutFile.txt");
    //  D:\1ENERG\code\test_system_cpp\test_system
//    system ("ECHO 1 > D:/1ENERG/code/test_system_cpp/test_system/file.txt");
    delete rtc;
    return 0;
}
