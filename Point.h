/**
 * @file Point.h
 * @brief Объявление класса Point (лабораторная работа 4, вариант 3).
 *
 * Точка на плоскости с перегруженными операциями.
 */

#ifndef LAB4_POINT_H_
#define LAB4_POINT_H_

#include <iosfwd>
#include <string>

namespace lab4 {

/**
 * @brief Точка на плоскости.
 *
 * @note Координаты всегда конечные числа (не NaN и не бесконечность).
 */
class Point {
public:
	/**
	 * @brief Создаёт точку в начале координат (0, 0).
	 */
	Point();

	/**
	 * @brief Создаёт точку с заданными координатами.
	 *
	 * @param x Координата x.
	 * @param y Координата y.
	 * @throw std::invalid_argument Если координата не является конечным
	 * числом.
	 */
	Point(double x, double y);

	/**
	 * @brief Конструктор копирования.
	 */
	Point(const Point& other) = default;

	/**
	 * @brief Оператор присваивания копированием.
	 */
	Point& operator=(const Point& other) = default;

	/**
	 * @brief Возвращает координату x.
	 *
	 * @return Координата x.
	 */
	double x() const { return x_; }

	/**
	 * @brief Возвращает координату y.
	 *
	 * @return Координата y.
	 */
	double y() const { return y_; }

	/**
	 * @brief Задаёт координату x.
	 *
	 * @param x Новая координата x.
	 * @throw std::invalid_argument Если x не является конечным числом.
	 */
	void set_x(double x);

	/**
	 * @brief Задаёт координату y.
	 *
	 * @param y Новая координата y.
	 * @throw std::invalid_argument Если y не является конечным числом.
	 */
	void set_y(double y);

	/**
	 * @brief Вычисляет расстояние до другой точки (задание 1).
	 *
	 * @param other Другая точка.
	 * @return Евклидово расстояние между точками.
	 */
	double DistanceTo(const Point& other) const;

	/**
	 * @brief Возвращает текстовое представление.
	 *
	 * @return Строка вида "(x; y)".
	 */
	std::string ToString() const;

	/**
	 * @brief Выводит текстовое представление на экран.
	 */
	void Print() const;

	/**
	 * @brief Префиксный ++: увеличивает координату x на 1.
	 *
	 * @return Ссылка на изменённую точку.
	 */
	Point& operator++();

	/**
	 * @brief Постфиксный ++: увеличивает координату x на 1.
	 *
	 * @return Копия точки до изменения.
	 */
	Point operator++(int);

	/**
	 * @brief Префиксный --: уменьшает координату x на 1.
	 *
	 * @return Ссылка на изменённую точку.
	 */
	Point& operator--();

	/**
	 * @brief Постфиксный --: уменьшает координату x на 1.
	 *
	 * @return Копия точки до изменения.
	 */
	Point operator--(int);

	/**
	 * @brief Явное приведение к int.
	 *
	 * @return Целая часть координаты x (дробная часть отбрасывается).
	 * @throw std::out_of_range Если целая часть x не помещается в int.
	 */
	explicit operator int() const;

	/**
	 * @brief Неявное приведение к double.
	 *
	 * @return Координата y.
	 */
	operator double() const;

	/**
	 * @brief Вычисляет расстояние до точки other.
	 *
	 * @param other Другая точка.
	 * @return Расстояние между точками.
	 */
	double operator+(const Point& other) const;

	/**
	 * @brief Увеличивает координату x на целое число.
	 *
	 * @param d Приращение координаты x.
	 * @return Новая точка (исходная не изменяется).
	 */
	Point operator+(int d) const;

	/**
	 * @brief Выводит точку в поток в виде "(x; y)".
	 */
	friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
	double x_;
	double y_;
};

}  // namespace lab4

#endif  // LAB4_POINT_H_
