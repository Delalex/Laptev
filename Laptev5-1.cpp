#include <iostream>
#include <vector>
#include <cmath>

class massiv
{
public:
	std::vector <double> mass;
	int n;

	void new_mass()
	{
		double temp;

		std::cin >> n;

		for (int i = 0; i < n; i++)
		{
			std::cin >> temp;
			mass.push_back(temp);
		}

		std::cout << mass.size() << std::endl;
		result_cout();

		menu();
	}

private:

	void menu()
	{
		int point = -1;

		while (point != 0)
		{
			std::cin >> point;

			if (point == 0)
			{
				break;
			}
			else if (point == 1)
			{
				add_el();
			}
			else if (point == 2)
			{
				del_el();
			}

			result_cout();
		}
	}

	void add_el()
	{
		double temp;
		std::cin >> temp;

		mass.push_back(temp);

		std::cout << "+: " << mass.size() << std::endl;
	}

	void del_el()
	{
		mass.pop_back();

		std::cout << "-: " << mass.size() << std::endl;
	}

	void math_methods()
	{
		double summ = 0, arith_mean = 0;

		for (int i = 0; i < mass.size(); i++)
		{
			summ += mass[i];
		}

		arith_mean = summ / mass.size();

		mass.push_back(summ);
		mass.push_back(arith_mean);
	}

	void dop_quest()
	{
		double first_otric = 1;

		for (int i = 0; i < mass.size(); i++)
		{
			if (mass[i] < 0)
			{
				first_otric = mass[i];
				break;
			}
		}

		for (int i = 0; i < mass.size(); i++)
		{
			int temp = trunc(mass[i]);

			if (temp % 2 == 0)
				mass[i] *= first_otric;
		}
	}

	void result_cout()
	{
		print_mass();

		math_methods();
		print_mass();

		dop_quest();
		print_mass();
	}

	void print_mass()
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(3);

		for (int i = 0; i < mass.size(); i++)
		{
			std::cout << round((mass[i] * 1000) / 1000) << " ";
		}
		std::cout << std::endl;
	}
};


int main()
{
	massiv M;

	M.new_mass();

	return 0;
}
