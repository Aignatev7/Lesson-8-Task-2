#include <iostream>

class Exception : public std::domain_error { public: using domain_error::domain_error; };

class Figure  // ����� ������
{
protected:
	std::string figure_name;
	int number_of_sides;

public:
	Figure() {
		figure_name = "������";
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

class Triangle : public Figure // ����� �����������
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
		figure_name = "�����������";
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
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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
			std::cout << get_figure_name() << " (������� " << get_side_a() << ", "
				<< get_side_b() << ", " << get_side_c() << "; ���� "
				<< get_corner_A() << ", " << get_corner_B() << ", "
				<< get_corner_C() << ") ������\n" << std::endl;
		}
		else if ((corner_A + corner_B + corner_C) != 180) {
			std::cout << get_figure_name()
				<< ": ������ �������� ������. �������: ����� ����� �� ����� 180"
				<< "\n" << std::endl;
		}
	}
};

class RightTriangle : public Triangle // ����� ������������� �����������
{
public:
	RightTriangle(int a, int b, int c, int A, int B, int �) {
		figure_name = "������������� �����������";

		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = �;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class IsoscelesTriangle : public Triangle // ����� �������������� �����������
{
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) {
		figure_name = "�������������� �����������";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_C = C;
		this->corner_B = B;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class EquilateralTriangle : public Triangle // ����� �������������� �����������
{
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) {
		figure_name = "�������������� �����������";
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class Quadrangle : public Figure // ����� ��������������
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
		figure_name = "��������������";
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
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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
			std::cout << get_figure_name() << " (������� " << get_side_a() << ", "
				<< get_side_b() << ", " << get_side_c() << ", " << get_side_d()
				<< "; ���� " << get_corner_A() << ", " << get_corner_B() << ", "
				<< get_corner_C() << ", " << get_corner_D() << ") ������\n"	<< std::endl;
		}
		else if ((corner_A + corner_B + corner_C + corner_D) != 360) {
			std::cout << get_figure_name()
				<< ": ������ �������� ������. �������: ����� ����� �� ����� 360" << "\n"	<< std::endl;
		}
	}
};

class Rectangle : public Quadrangle // ����� �������������
{
public:
	Rectangle() {}

	Rectangle(int c, int d, int A, int B, int C, int D) {
		figure_name = "�������������";
		this->side_a = this->side_c = c;
		this->side_b = this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class Square : public Rectangle // ����� �������
{
public:
	Square(int d, int A, int B, int C, int D) {
		figure_name = "�������";
		this->side_a = this->side_b = this->side_c = this->side_d = d;
		this->corner_A = A;
		this->corner_B = B;
		this->corner_C = C;
		this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class Parallelogram : public Quadrangle // ����� ��������������
{
public:
	Parallelogram(int c, int d, int C, int D) {
		figure_name = "��������������";
		this->side_a = this->side_c = c;
		this->side_b = this->side_d = d;
		this->corner_A = this->corner_C = C;
		this->corner_B = this->corner_D = D;

		try {
			if (!(check()));
		}
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

class Rhomb : public Quadrangle // ����� ����
{
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "����";
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
		catch (std::exception ex) //����� ��� ���������� - ���������� �� std::exception
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

		Figure fig; // ������ ������ ������
		print_info(&fig);

		Triangle tri(20, 30, 40, 55, 65, 60); // ������ ������ �����������
		print_info(&tri);

		RightTriangle rig_tri(22, 32, 55, 45, 45, 90); // ������ ������ ������������� �����������
		print_info(&rig_tri);

		IsoscelesTriangle isos_tri(32, 44, 52, 62, 43, 68); // ������ ������ �������������� �����������
		print_info(&isos_tri);

		EquilateralTriangle eq_tri(32, 44, 52, 62, 43, 68); // ������ ������ �������������� �����������
		print_info(&eq_tri);

		Quadrangle quad(12, 45, 89, 23, 65, 115, 110, 70); // ������ ������ ��������������
		print_info(&quad);

		Rectangle rect(79, 45, 90, 90, 90, 90); // ������ ������ �������������
		print_info(&rect);

		Square square(45, 65, 85, 45, 75); // ������ ������ �������
		print_info(&square);

		Parallelogram paral(45, 15, 84, 31); // ������ ������ ��������������
		print_info(&paral);

		Rhomb rhomb(15, 30, 60, 85, 36, 125, 77, 95); // ������ ������ ����
		print_info(&rhomb);
}



	/*
	������ 2. ���������� � �������������
	� ���� ������� �� ��������� ��������� ���������� ������� �������������� ����� � ������������� �������.

	�������� ����������� ����� ���������� ��� ������ �������� �������������� ������. ���������, �� ������ ���� ��� ������������, � �� �������� ��������� ����� ����� � ��������� ���� ������.

	�������� �������� ������� �� ����������� �������. ������ ��� �������� ����������� ������� ��� ����� ��������� ���������, ������� ��������� �� ���� ������������. ���� ��������� �� ������������� ������������, ������ �� ������ ���� ������, � �� ������� ������ ���� �������� ��������������� ���������. ������� ������ ������ ���� �������������� �� ������ ������������ � �������� �� ����� ��� ��������� ������.

	�����������:

	����������� (������� � ���� ������������, ���������� ������ ����� 3, ����� ����� ����� 180);
	������������� ����������� (���� C ������ ����� 90);
	�������������� ����������� (������� a � c �����, ���� A � C �����);
	�������������� ����������� (��� ������� �����, ��� ���� ����� 60);
	�������������� (������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
	������������� (������� a,c � b,d ������� �����, ��� ���� ����� 90);
	������� (��� ������� �����, ��� ���� ����� 90);
	�������������� (������� a,c � b,d ������� �����, ���� A,C � B,D ������� �����);
	���� (��� ������� �����, ���� A,C � B,D ������� �����).
	��� �������� ���������� ������� ������ �������������� ������ � ���������� � ������������. � ������ ��������� �������� �������� �� ����� ��������� �� �������� �������� � ��������� ������. � ������, ���� �������� �� �������, �������� ������� ������.

	������ ������ ���������
	�������
	������������� ����������� (������� 3, 4, 5; ���� 30, 60, 90) ������
	������ �������� ������. �������: ����� ����� �� ����� 180
	*/