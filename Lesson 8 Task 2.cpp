#include <iostream>

class Exception : public std::domain_error {
public:
	using domain_error::domain_error;
};

class Figure // класс Фигура
{
protected:
	std::string figure_name;
	int number_of_sides;

public:
	Figure() {
		figure_name = "Фигура";
		number_of_sides = 0;
	}

	virtual void check() {}

	std::string get_figure_name() { return figure_name; }
	int get_number_of_sides() { return number_of_sides; }

	virtual void print_myself() {}
};

class Triangle : public Figure // класс Треугольник
{
protected:
	int number_of_sides = 3;
	int side_a = 0;
	int side_b = 0;
	int side_c = 0;
	int corner_A = 0;
	int corner_B = 0;
	int corner_C = 0;

public:
	Triangle() {}

	Triangle(int a, int b, int c, int A, int B, int C) {
		figure_name = "Треугольник";
		number_of_sides = 3;
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
	}

	void check() override {
		Figure::check();
		if (number_of_sides != 3) {
			throw std::runtime_error("Количество сторон не равно 3!");
		}
		if ((corner_A + corner_B + corner_C) != 180) {
			throw std::runtime_error("Сумма углов не равна 180!");
		}
	}

	int get_number_of_sides() { return number_of_sides; }
	int get_side_a() { return side_a; }
	int get_side_b() { return side_b; }
	int get_side_c() { return side_c; }
	int get_corner_A() { return corner_A; }
	int get_corner_B() { return corner_B; }
	int get_corner_C() { return corner_C; }

	void print_myself() override {
		std::cout << get_figure_name() << " (стороны " << get_side_a() << ", "
			<< get_side_b() << ", " << get_side_c() << "; углы "
			<< get_corner_A() << ", " << get_corner_B() << ", "
			<< get_corner_C() << ") создан\n" << std::endl;
	}
};

class RightTriangle : public Triangle // класс Прямоугольный треугольник
{
public:
	RightTriangle(int a, int b, int c, int A, int B, int С) {
		figure_name = "Прямоугольный треугольник";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = С;
	}

	void check() override {
		Triangle::check();
		if (corner_C != 90) {
			throw std::runtime_error("Угол не равен 90 градусам!");
		}
	}
};

class IsoscelesTriangle : public Triangle // класс Равнобедренный треугольник
{
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) {
		figure_name = "Равнобедренный треугольник";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_C = C;
		this->corner_B = B;
	}

	void check() override {
		Triangle::check();
		if (side_a != side_c) {
			throw std::runtime_error("Cтороны a и c не равны!");
		}
		if (corner_A != corner_C) {
			throw std::runtime_error("Углы A и C не равны!");
		}
	}
};

class EquilateralTriangle : public Triangle // класс Равносторонний треугольник
{
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) {
		figure_name = "Равносторонний треугольник";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
	}

	void check() override {
		Triangle::check();
		if (side_a != side_b != side_c) {
			throw std::runtime_error("Не все стороны равны!");
		}
		if ((corner_A = corner_B = corner_C) != 60) {
			throw std::runtime_error("Не все углы равны 60!");
		}
	}
};

class Quadrangle : public Figure // класс Четырёхугольник
{
protected:
	int number_of_sides = 4;
	int side_a = 0;
	int side_b = 0;
	int side_c = 0;
	int side_d = 0;
	int corner_A = 0;
	int corner_B = 0;
	int corner_C = 0;
	int corner_D = 0;

public:
	Quadrangle() {}

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "Четырёхугольник";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;
	}

	int get_number_of_sides() { return number_of_sides; }
	int get_side_a() { return side_a; }
	int get_side_b() { return side_b; }
	int get_side_c() { return side_c; }
	int get_side_d() { return side_d; }
	int get_corner_A() { return corner_A; }
	int get_corner_B() { return corner_B; }
	int get_corner_C() { return corner_C; }
	int get_corner_D() { return corner_D; }

	void check() override {
		Figure::check();
		if (number_of_sides != 4) {
			throw std::runtime_error("Количество сторон не равно 4!");
		}
		if ((corner_A + corner_B + corner_C + corner_D) != 360) {
			throw std::runtime_error("Сумма углов не равна 360!");
		}
	}

	void print_myself() override {
		std::cout << get_figure_name() << " (стороны " << get_side_a() << ", "
			<< get_side_b() << ", " << get_side_c() << ", " << get_side_d()
			<< "; углы " << get_corner_A() << ", " << get_corner_B() << ", "
			<< get_corner_C() << ", " << get_corner_D() << ") создан\n" << std::endl;
	}
};

class Rectangle : public Quadrangle // класс Прямоугольник
{
public:
	Rectangle() {}

	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "Прямоугольник";
		this->side_a = a;
		this->side_c = c;
		this->side_b = b;
		this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;
	}

	void check() override {
		Quadrangle::check();
		if ((side_a != side_c) || (side_b != side_d)) {
			throw std::runtime_error("Стороны не равны попарно!");
		}
		if ((corner_A = corner_B = corner_C = corner_D) != 90) {
			throw std::runtime_error("Не все углы равны 90!");
		}
	}
};

class Square : public Rectangle // класс Квадрат
{
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "Квадрат";
		this->side_a = a;
		this->side_c = c;
		this->side_b = b;
		this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;
	}

	void check() override {
		Quadrangle::check();
		if (side_a != side_b != side_c != side_d) {
			throw std::runtime_error("Не все стороны равны!");
		}
		if ((corner_A = corner_B = corner_C = corner_D) != 90) {
			throw std::runtime_error("Не все углы равны 90!");
		}
	}
};

class Parallelogram : public Quadrangle // класс Параллелограмм
{
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "Параллелограмм";
		this->side_a = a;
		this->side_c = c;
		this->side_b = b;
		this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;
	}

	void check() override {
		Quadrangle::check();
		if ((side_a != side_c) || (side_b != side_d)) {
			throw std::runtime_error("Стороны не равны попарно!");
		}
		if ((corner_A == corner_C) || (corner_B == corner_D)) {
			throw std::runtime_error("Углы попарно не равны!");
		}
	}
};

class Rhomb : public Quadrangle // класс Ромб
{
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "Ромб";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;
	}

	void check() override {
		Quadrangle::check();
		if (side_a != side_b != side_c != side_d) {
			throw std::runtime_error("Не все стороны равны!");
		}
		if ((corner_A == corner_C) || (corner_B == corner_D)) {
			throw std::runtime_error("Углы попарно не равны!");
		}
	}
};

void print_info(Figure* f) { f->print_myself(); }

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		Figure fig; // объект класса Фигура

		Triangle tri(20, 30, 40, 55, 65, 60); // объект класса Треугольник
		print_info(&tri);

		RightTriangle rig_tri(22, 32, 55, 45, 45, 90); // объект класса Прямоугольный треугольник
		print_info(&rig_tri);

		IsoscelesTriangle isos_tri(32, 44, 52, 62, 43, 68); // объект класса Равнобедренный треугольник
		print_info(&isos_tri);

		EquilateralTriangle eq_tri(32, 44, 52, 62, 43, 68); // объект класса Равносторонний треугольник
		print_info(&eq_tri);

		Quadrangle quad(12, 45, 89, 23, 65, 115, 110, 70); // объект класса Четырёхугольник 
		print_info(&quad);

		Rectangle rect(23, 57, 79, 45, 90, 90, 90, 90); // объект класса Прямоугольник
		print_info(&rect);

		Square square(45, 18, 76, 35, 65, 85, 45, 75); // объект класса Квадрат
		print_info(&square);

		Parallelogram paral(85, 52, 64, 38, 45, 15, 84, 31); // объект класса Параллелограмм
		print_info(&paral);

		Rhomb rhomb(15, 30, 60, 85, 36, 125, 77, 95); // объект класса Ромб
		print_info(&rhomb);

	}
	catch (
		std::exception ex) //ловим все исключения - наследники от std::exception
	{
		std::cout << "Ошибка создания фигуры. Причина: " << ex.what();
	}
}



/*
Задача 2. Исключения в конструкторах
В этом задании вы запретите создавать экземпляры классов геометрических фигур с неправильными данными.

Создайте собственный класс исключения для ошибки создания геометрической фигуры. Подумайте, от какого типа его унаследовать, и не забудьте поместить новый класс в отдельную пару файлов.

Возьмите иерархию классов из предыдущего задания. Теперь при создании экземпляров классов вам нужно проверять аргументы, которые поступают на вход конструктору. Если аргументы не соответствуют ограничениям, объект не должен быть создан, а на консоль должно быть выведено соответствующее сообщение. Причина ошибки должна быть сформулирована на уровне конструктора и выведена на экран при обработке ошибок.

Ограничения:

треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Для проверки попробуйте создать разные геометрические фигуры — правильные и неправильные. В случае успешного создания выводите на экран сообщение об успешном создании и параметры фигуры. В случае, если создание не удалось, выведите причину ошибки.

Пример работы программы
Консоль
Прямоугольный треугольник (стороны 3, 4, 5; углы 30, 60, 90) создан
Ошибка создания фигуры. Причина: сумма углов не равна 180
*/