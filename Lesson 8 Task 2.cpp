#include <iostream>

class Exception : public std::domain_error { public: using domain_error::domain_error; };

class Figure  // класс Фигура
{
protected:
	std::string figure_name;
	int number_of_sides;

public:
	Figure() {
		figure_name = "Фигура";
		number_of_sides = 0;
	}
	std::string get_figure_name() { return figure_name; }
	int get_number_of_sides() { return number_of_sides; }

	virtual bool check() {
		if (number_of_sides == 0) {
			return true;
		}
		else {
			return false;
		}
	}

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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();
			
		}
	}

	int get_number_of_sides() { return number_of_sides; }
	int get_side_a() { return side_a; }
	int get_side_b() { return side_b; }
	int get_side_c() { return side_c; }
	int get_corner_A() { return corner_A; }
	int get_corner_B() { return corner_B; }
	int get_corner_C() { return corner_C; }

	bool check() override {
		if ((number_of_sides == 3) && ((corner_A + corner_B + corner_C) == 180)) {
			return true;
		}
		else {
			return false;
		}
	}

	void print_myself() override {
		if (check()) {
			std::cout << get_figure_name() << " (стороны " << get_side_a() << ", "
				<< get_side_b() << ", " << get_side_c() << "; углы "
				<< get_corner_A() << ", " << get_corner_B() << ", "
				<< get_corner_C() << ") создан\n" << std::endl;
		}
		else if ((corner_A + corner_B + corner_C) != 180) {
			std::cout << get_figure_name()
				<< ": Ошибка создания фигуры. Причина: сумма углов не равна 180"
				<< "\n" << std::endl;
		}
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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Triangle::check()) {
			return false;
		}
		else if (corner_C == 90) {
			return true;
		}
		else {
			return false;
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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Triangle::check()) {
			return false;
		}
		if ((side_a == side_c) && (corner_A == corner_C)) {
			return true;
		}
		else {
			return false;
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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Triangle::check()) {
			return false;
		}
		else if ((side_a == side_b == side_c) && (corner_A = corner_B = corner_C == 60)) {
			return true;
		}
		else {
			return false;
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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
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

	bool check() override {
		if ((number_of_sides == 4) && ((corner_A + corner_B + corner_C + corner_D) == 360)) {
			return true;
		}
		else {
			return false;
		}
	}

	void print_myself() override {
		if (check()) {
			std::cout << get_figure_name() << " (стороны " << get_side_a() << ", "
				<< get_side_b() << ", " << get_side_c() << ", " << get_side_d()
				<< "; углы " << get_corner_A() << ", " << get_corner_B() << ", "
				<< get_corner_C() << ", " << get_corner_D() << ") создан\n"	<< std::endl;
		}
		else if ((corner_A + corner_B + corner_C + corner_D) != 360) {
			std::cout << get_figure_name()
				<< ": Ошибка создания фигуры. Причина: сумма углов не равна 360" << "\n"	<< std::endl;
		}
	}
};

class Rectangle : public Quadrangle // класс Прямоугольник
{
public:
	Rectangle() {}

	Rectangle(int c, int d, int A, int B, int C, int D) {
		figure_name = "Прямоугольник";
		this->side_a = this->side_c = c;
		this->side_b = this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Quadrangle::check()) {
			return false;
		}
		if (((side_a == side_c) && (side_b == side_d)) &&
			((corner_A = corner_B = corner_C = corner_D) == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Square : public Rectangle // класс Квадрат
{
public:
	Square(int d, int A, int B, int C, int D) {
		figure_name = "Квадрат";
		this->side_a = this->side_b = this->side_c = this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Rectangle::check()) {
			return false;
		}
		if ((side_a == side_b == side_c == side_d) && ((corner_A = corner_B = corner_C = corner_D) == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Parallelogram : public Quadrangle // класс Параллелограмм
{
public:
	Parallelogram(int c, int d, int C, int D) {
		figure_name = "Параллелограмм";
		this->side_a = this->side_c = c;
		this->side_b = this->side_d = d;
		this->corner_A = this->corner_C = C;
		this->corner_B = this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Quadrangle::check()) {
			return false;
		}
		if (((side_a == side_c) && (side_b == side_d)) && ((corner_A == corner_C) && (corner_B == corner_D))) {
			return true;
		}
		else {
			return false;
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

		try {
			if (!(check()));
		}
		catch (std::exception ex) //ловим все исключения - наследники от std::exception
		{
			std::cout << "Catch exception. Message:" << ex.what();

		}
	}

	bool check() override {
		if (!Quadrangle::check()) {
			return false;
		}
		if ((side_a == side_b == side_c == side_d) && ((corner_A == corner_C) && (corner_B == corner_D))) {
			return true;
		}
		else {
			return false;
		}
	}
};

void print_info(Figure* f) { f->print_myself(); }

int main() {
	setlocale(LC_ALL, "Russian");

		Figure fig; // объект класса Фигура
		print_info(&fig);

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

		Rectangle rect(79, 45, 90, 90, 90, 90); // объект класса Прямоугольник
		print_info(&rect);

		Square square(45, 65, 85, 45, 75); // объект класса Квадрат
		print_info(&square);

		Parallelogram paral(45, 15, 84, 31); // объект класса Параллелограмм
		print_info(&paral);

		Rhomb rhomb(15, 30, 60, 85, 36, 125, 77, 95); // объект класса Ромб
		print_info(&rhomb);
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