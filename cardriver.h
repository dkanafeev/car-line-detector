#ifndef CARDRIVER_H
#define CARDRIVER_H

#include <QtSerialPort/QSerialPort>
#include <opencv2/core.hpp>

using cv::Vec2i;

/**
@class CarDriver
@brief Данный класс реализует отправку данных на микрокотроллер
@details В данной версии программы, отправляются данные следующие данные:
 - данные о скорости
 - данные об угле поворота колес
*/
class CarDriver
{
public:
    /// @brief Конструктор по умолчанию
    /// @details Происходит соединение с автомобилем, посылаются тестовые данные
    CarDriver();
    /// @brief Перечисление отправителей
    /// @attention В данной версии программы используется
    /// только один отправитель - детектор линий.
    enum Sender
    {
        LINE_DETECTOR, /**< детектор линий  */
        SIGN_DETECTOR  /**< детектор знаков */
    };
    /// @name Группа методов для отправки данных на МК
    /// @attention В данной версии реализован механизм отправки только
    /// сообщений о скорости и угле поворота колес.
    /// @{
    /// @brief Отправляет данные о скорости и угле поворота колес на микроконтроллер
    void sendData(Sender, Vec2i);
    /// @}
};

#endif // CARDRIVER_H
