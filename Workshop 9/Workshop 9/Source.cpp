#include<iostream>

void test(bool, bool);
void test(double, double);

class point
{
public:
	float x;
	float y;

	point()
	{
		this->x = 0.0;
		this->y = 0.0;
	}

	point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

class rect
{
public:
	point upperright;
	point lowerleft;
	float length = 0.0;
	float breadth = 0.0;

	rect()
	{
		point p1(0, 0), p2(0, 0);
		this->upperright = p1;
		this->lowerleft = p2;
	}

	rect(point upperright, point lowerleft)
	{
		this->upperright = upperright;
		this->lowerleft = lowerleft;
		calculateLenBre();
	}

	void calculateLenBre()
	{
		length = abs(upperright.y - lowerleft.y);
		breadth = abs(upperright.x - lowerleft.x);
	}

	double area()
	{
		float area = length * breadth;
		return area;
	}

	double perimeter()
	{
		float peri = (2 * (length + breadth));
		return peri;
	}

	bool operator == (const rect &r)
	{
		if ((length == r.length && breadth == r.breadth) || (length == r.breadth && breadth == r.length))
			return true;
		return false;
	}

	rect operator+ (const rect& r)
	{
		point UR, BL;
		if (r.length == length)
		{
			UR= this->upperright;
			BL.x = this->lowerleft.x+r.breadth;
			BL.y = this->lowerleft.y;
		}
		else if (r.breadth == length)
		{
			UR = this->upperright;
			BL.x = this->lowerleft.x+r.length;
			BL.y = this->lowerleft.y;
		}
		rect obj(UR, BL);
		return obj;
	}

	friend std::ostream& operator<< (std::ostream& out, const rect& r);

};

std::ostream& operator<< (std::ostream& out, const rect& r)
{
	std::string s = "";
	for (int i = 1; i <= (int)r.length; i++)
	{
		for (int j = 1; j <= (int)r.breadth; j++)
		{
			if (i == 1 || i == r.length || j == 1 || j == r.breadth)
			{
				s += "* ";
			}
			else
			{
				s += "  ";
			}
		}
		s += "\n";
	}

	out << s;
	return out;
}

class square:public rect
{
	public:
		double length=0.0;
		double breadth = 0.0;

		square(point upperright, point lowerleft)
		{
			this->upperright = upperright;
			this->lowerleft = lowerleft;
			calculateLen();
		}
	
		void calculateLen()
		{
			length = abs(upperright.y - lowerleft.y);
			breadth = length;
		}

		bool operator == (const square& r)
		{
			if (r.length == length)
				return true;
			return false;
		}

		square operator+ (const square& r)
		{
			point UR, BL;

			if (r.length == length)
			{
				UR = this->upperright;
				BL.x = this->lowerleft.x + length;
				BL.y = this->lowerleft.y;
			}

			square obj(UR, BL);
			return obj;
		}

		friend std::ostream& operator<< (std::ostream& out, const square& s);

};

std::ostream& operator<< (std::ostream& out, const square& s)
{
	std::string st = "";
	for (int i = 1; i <= (int)s.length; i++)
	{
		for (int j = 1; j <= (int)s.length; j++)
		{
			if (i == 1 || i == s.length || j == 1 || j == s.length)
			{
				st += "* ";
			}
			else
			{
				st += "  ";
			}
		}
		st += "\n";
	}

	out << st;
	return out;
}

int main()
{
	//Rectangle 1
	point p1(3, 4), p2(9, 9);
	rect r1(p1, p2);
	std::cout << "Rectangle 1\n";
	std::cout << r1;
	std::cout << "\n";

	//Rectangle 2
	point p3(1, 10), p4(8, 5);
	rect r2(p3, p4);
	std::cout << "Rectangle 2\n";
	std::cout << r2;
	std::cout << "\n";

	//Adding rectangle 1 and Rectangle 2 and storing it in rectangle 3
	rect r3 = r1 + r2;
	std::cout << "Rectangle 3 after Adding rectangle 1 and 2\n";
	std::cout << r3;
	std::cout << "\n";

	//Rectangle 4
	point p5(1, 7), p6(6, 0);
	rect r4(p5, p6);
	std::cout << "Rectangle 4\n";
	std::cout << r4;
	std::cout << "\n";
	

	//Adding rectangle 1 and Rectangle 4 and storing it in rectangle 5
	rect r5 = r1 + r4;
	std::cout << "Rectangle 5 after Adding rectangle 1 and 4\n";
	std::cout << r5;
	std::cout << "\n";

	//Square 1
	point p9(4, 4), p10(8, 0);
	square s1(p9, p10);
	std::cout << "Square 1\n";
	std::cout << s1 << std::endl;

	//Square 2
	point p11(4, 5), p12(8, 1);
	square s2(p11, p12);
	std::cout << "Square 2\n";
	std::cout << s2 << std::endl;

	//Square 3
	point p13(7, 8), p14(12, 3);
	square s3(p13, p14);
	std::cout << "Square 3\n";
	std::cout << s3 << std::endl;

	
	std::cout << "Comparing Square 1 and Square 2\n";
	test(s1 == s2, 1);
	std::cout << "Comparing Square 1 and Square 3\n";
	test(s1 == s3, 0);
	std::cout << "Comparing Rectangle 1 and Rectangle 5\n";
	test(r1 == r5, 0);
	std::cout << "Comparing Rectangle 1 and Rectangle 5\n";
	test(r3 == r5, 1);

	test(r1.area(), 30);
	test(r1.perimeter(), 22);
}

void test(bool actual, bool expected)
{
	if (expected == actual)
	{
		std::cout << "Test Passed!" << std::endl;
	}
	else
	{
		std::cout << "Test Failed" << std::endl;
	}
	std::cout << "Expected value : " << expected << " Actual : " << actual << "\n\n";
}

void test(double actual, double expected)
{
	if (expected == actual)
	{
		std::cout << "Test Passed!" << std::endl;
	}
	else
	{
		std::cout << "Test Failed" << std::endl;
	}
	std::cout << "Expected value : " << expected << " Actual : " << actual << "\n\n";
}