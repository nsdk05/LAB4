#include "Point.h"

#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace lab4 {

namespace {

double CheckFinite(double value, const std::string& name) {
	if (!std::isfinite(value)) {
		throw std::invalid_argument("Координата " + name +
				" должна быть конечным числом");
	}
	return value;
}

}

Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y)
		: x_(CheckFinite(x, "x")), y_(CheckFinite(y, "y")) {}

void Point::set_x(double x) {
        x_ = CheckFinite(x, "x");
}

void Point::set_y(double y) {
        y_ = CheckFinite(y, "y");
}

double Point::DistanceTo(const Point& other) const{
    return std::hypot(x_ - other.x_, y_ - other.y_);
}

std::string Point::ToString() const {
    std:: ostringstream stream;
    stream << *this;
    return stream.str();
}

void Point::Print() const {
    std::cout << ToString() << "\n";
}

Point& Point::operator++() {
    x_ += 1;
    return *this;
}

Point Point::operator++(int) {
    Point old(*this);
    ++(*this);
    return old;
}

Point& Point::operator--() {
    x_ -= 1;
    return *this;
}

Point Point::operator--(int) {
    Point old(*this);
    --(*this);
    return old;
}

Point::operator int() const {
	if (!(x_ > INT_MIN - 1.0 && x_ < INT_MAX + 1.0)) {
		throw std::out_of_range("Целая часть x не помещается в int");
	}
	return static_cast<int>(x_);
}

Point::operator double() const {
    return y_;
}

double Point::operator+(const Point& other) const {
	return DistanceTo(other);
}

Point Point::operator+(int d) const {
	return Point(x_ + d, y_);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	return os << "(" << point.x_ << "; " << point.y_ << ")";
}

}
