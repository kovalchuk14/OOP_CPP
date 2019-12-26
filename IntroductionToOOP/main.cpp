#include<iostream>
class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (abs(x) <= 100) //abs() - ������ �����.
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		//if - ��������������� ������������ ��������.
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	/*Point()
	{
	x = y = 0;
	std::cout << "Default constructor:\t" << this << std::endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Point(const Point&other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~Point()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	//Point operator+(const Point& other)const
	//{
	//	Point result;
	//	result.x=this->x + other.x;
	//	result.y =this->y + other.y;
	//	return result;
	//}
	Point operator-(const Point& other)const
	{
		Point result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;
		return result;
	}
	Point operator*(const Point& other)const
	{
		Point result;
		result.x = this->x * other.x;
		result.y = this->y * other.y;
		return result;
	}
	Point operator/(const Point& other)const
	{
		Point result;
		result.x = this->x / other.x;
		result.y = this->y / other.y;
		return result;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	void operator=(const Point&other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignement:" << this << std::endl;
	}
	// Methods:
	void print() const
	{
		std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
	}
};
Point operator+(const Point& left, const Point& right)
{
	//Point result;
	//result.set_x(left.get_x() + right.get_x());
	//result.set_y(left.get_y() + right.get_y());
	std::cout << "G operator +" << std::endl;
	return Point(left.get_x() + right.get_x(), left.get_y() + right.get_y());
}
double distance(const Point A,const Point B);
//#define BASICS
//#define ENCAPSULATION
//#define CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a; //���������� ���������� 'a', ���� 'int'.
	Point A; //���������� ���������� 'A', ���� 'Point'.
	//�������� (����������) ������� 'A', ���� 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //���������� ��������� �� 'Point'  'pA'...
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif 
#ifdef ENCAPSULATION
	Point A;
	A.set_x(5);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif  
#ifdef CONSTRUCTORS 
	const Point B;
	/*std::cout << A.get_x() << std::endl;*/
	B.print();

	Point C = 5;
	C.print();

	Point D = 6;
	D.print();

	Point E(5,2);
	E.print();

	Point F = E;
	F.print();
	Point G;
	G = E; 
	G.print();
#endif
	Point A(5, 2);
	Point B(1,5);//Default 
	Point C;
	C = A + B;
	A.print();
	B.print();
	C.print();
	std::cout << "\n--------------\n";
	
	std::cout << "\n--------------\n";
	std::cout<<distance(A,B)<<std::endl;
}
double distance(const Point A, const Point B)
{
	double x = A.get_x() - B.get_x();
	double y = A.get_y() - B.get_y();
	double distance = sqrt(x*x + y * y);
	return distance;
}