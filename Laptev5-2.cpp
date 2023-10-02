#include <iostream>
#include <vector>
#include <algorithm>
class massive
{
public:
	int i_min, i_max, cons;
	bool zero = false;
	std::vector <int> arr1, arr2;
	void input()
	{
		int temp;
		std::cin >> i_min >> i_max;
		for (int i = i_min; i <= i_max; i++)
		{
			std::cin >> temp;
			arr1.push_back(temp);
		}
		for (int i = i_min; i <= i_max; i++)
		{
			std::cin >> temp;
			arr2.push_back(temp);
			if (temp == 0)
				zero = true;
		}
		std::cin >> cons;
		print_math();
		menu();
	}
	void menu()
	{
		int point = -1, ind;
		while (point != 0)
		{
			std::cout << std::endl;
			std::cin >> point;
			if (point == 0)
				break;
			else if (point == 1)
			{
				std::cin >> ind;
				std::cout << "\nArray1";
				print_mass_el(arr1, ind);
			}
			else if (point == 2)
			{
				std::cin >> ind;
				std::cout << "\nArray2";
				print_mass_el(arr2, ind);
			}
		} 
	}
	void print_math()
	{
		std::cout << "\nArray1= ";
		print_mass(arr1);
		arr_arith(arr1, 1);
		sort(arr1, 1);
		std::cout << "\nArray2= ";
		print_mass(arr2);
		arr_arith(arr2, 2);
		sort(arr2, 2);
		std::cout << "\nsumma= ";
		for (int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] + arr2[i] << ' ';
		std::cout << "\nraznost= ";
		for (int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] - arr2[i] << ' ';
		std::cout << "\nproizv= ";
		for (int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] * arr2[i] << ' ';
		if (zero)
			std::cout << "\ndelenie na 0";
		else {
			std::cout << "\ndelenie= ";
			for (int i = 0; i < arr1.size(); i++)
					std::cout << arr1[i] / arr2[i] << ' ';
		}
	}
	void arr_arith(std::vector <int> arr, int t)
	{
		std::cout << "\nArray" << t << "+const= ";
		for (int i = 0; i < arr.size(); i++)
			std::cout << arr[i] + cons << ' ';
		std::cout << "\nArray" << t << "-const= ";
		for (int i = 0; i < arr.size(); i++)
			std::cout << arr[i] - cons << ' ';
		std::cout << "\nArray" << t << "*const= ";
		for (int i = 0; i < arr.size(); i++)
			std::cout << arr[i] * cons << ' ';
	}
	void sort(std::vector <int> arr, int t)
	{
		std::vector <int> temp = booble(arr);
		std::cout << "\nsort up Array" << t << "= ";
		print_mass(temp);
		reverse(temp.begin(), temp.end());
		std::cout << "\nsort down Array" << t << "= ";
		print_mass(temp);
	}
	std::vector <int> booble(std::vector <int> arr)
	{
		int temp;
		for (int i = 1; i < arr.size(); i++)
		{
			for (int j = 0; j < arr.size() - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return arr;
	}
	void print_mass_el(std::vector <int> arr, int ind)
	{
		if (ind >= i_min && ind <= i_max)
			std::cout << "[" << ind << "]= " << arr[ind + abs(i_min)];
		else
			std::cout << " wrong index " << ind;
	}
	void print_mass(std::vector <int> arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << ' ';
		}
	}
};
int main()
{
	massive M;
	M.input();
	return 0;
}