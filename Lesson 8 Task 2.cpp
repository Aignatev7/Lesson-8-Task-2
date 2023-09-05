#include <iostream>

class Exception : public std::domain_error {
public:
	using domain_error::domain_error;
};

class Figure // ����� ������
{
protected:
	std::string figure_name;
	int number_of_sides;

public:
	Figure() {
		figure_name = "������";
		number_of_sides = 0;
	}

	virtual void check() {}

	std::string get_figure_name() { return figure_name; }
	int get_number_of_sides() { return number_of_sides; }

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
	}

	void check() override {
		Figure::check();
		if (number_of_sides != 3) {
			throw std::runtime_error("���������� ������ �� ����� 3!");
		}
		if ((corner_A + corner_B + corner_C) != 180) {
			throw std::runtime_error("����� ����� �� ����� 180!");
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
		std::cout << get_figure_name() << " (������� " << get_side_a() << ", "
			<< get_side_b() << ", " << get_side_c() << "; ���� "
			<< get_corner_A() << ", " << get_corner_B() << ", "
			<< get_corner_C() << ") ������\n" << std::endl;
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
	}

	void check() override {
		Triangle::check();
		if (corner_C != 90) {
			throw std::runtime_error("���� �� ����� 90 ��������!");
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
	}

	void check() override {
		Triangle::check();
		if (side_a != side_c) {
			throw std::runtime_error("C������ a � c �� �����!");
		}
		if (corner_A != corner_C) {
			throw std::runtime_error("���� A � C �� �����!");
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
	}

	void check() override {
		Triangle::check();
		if (side_a != side_b != side_c) {
			throw std::runtime_error("�� ��� ������� �����!");
		}
		if ((corner_A = corner_B = corner_C) != 60) {
			throw std::runtime_error("�� ��� ���� ����� 60!");
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
			throw std::runtime_error("���������� ������ �� ����� 4!");
		}
		if ((corner_A + corner_B + corner_C + corner_D) != 360) {
			throw std::runtime_error("����� ����� �� ����� 360!");
		}
	}

	void print_myself() override {
		std::cout << get_figure_name() << " (������� " << get_side_a() << ", "
			<< get_side_b() << ", " << get_side_c() << ", " << get_side_d()
			<< "; ���� " << get_corner_A() << ", " << get_corner_B() << ", "
			<< get_corner_C() << ", " << get_corner_D() << ") ������\n" << std::endl;
	}
};

class Rectangle : public Quadrangle // ����� �������������
{
public:
	Rectangle() {}

	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "�������������";
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
			throw std::runtime_error("������� �� ����� �������!");
		}
		if ((corner_A = corner_B = corner_C = corner_D) != 90) {
			throw std::runtime_error("�� ��� ���� ����� 90!");
		}
	}
};

class Square : public Rectangle // ����� �������
{
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "�������";
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
			throw std::runtime_error("�� ��� ������� �����!");
		}
		if ((corner_A = corner_B = corner_C = corner_D) != 90) {
			throw std::runtime_error("�� ��� ���� ����� 90!");
		}
	}
};

class Parallelogram : public Quadrangle // ����� ��������������
{
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) {
		figure_name = "��������������";
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
			throw std::runtime_error("������� �� ����� �������!");
		}
		if ((corner_A == corner_C) || (corner_B == corner_D)) {
			throw std::runtime_error("���� ������� �� �����!");
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
	}

	void check() override {
		Quadrangle::check();
		if (side_a != side_b != side_c != side_d) {
			throw std::runtime_error("�� ��� ������� �����!");
		}
		if ((corner_A == corner_C) || (corner_B == corner_D)) {
			throw std::runtime_error("���� ������� �� �����!");
		}
	}
};

void print_info(Figure* f) { f->print_myself(); }

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		Figure fig; // ������ ������ ������

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

		Rectangle rect(23, 57, 79, 45, 90, 90, 90, 90); // ������ ������ �������������
		print_info(&rect);

		Square square(45, 18, 76, 35, 65, 85, 45, 75); // ������ ������ �������
		print_info(&square);

		Parallelogram paral(85, 52, 64, 38, 45, 15, 84, 31); // ������ ������ ��������������
		print_info(&paral);

		Rhomb rhomb(15, 30, 60, 85, 36, 125, 77, 95); // ������ ������ ����
		print_info(&rhomb);

	}
	catch (
		std::exception ex) //����� ��� ���������� - ���������� �� std::exception
	{
		std::cout << "������ �������� ������. �������: " << ex.what();
	}
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