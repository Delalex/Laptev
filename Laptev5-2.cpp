#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class massive
{
public:
	int i_min, i_max, cons;
	bool zero = false;
	vector <int> arr1, arr2;

	void input()
	{
		int temp;
		cin >> i_min >> i_max;

		for (int i = i_min; i <= i_max; i++)
		{
			cin >> temp;
			arr1.push_back(temp);
		}

		for (int i = i_min; i <= i_max; i++)
		{
			cin >> temp;
			arr2.push_back(temp);
			
			if (temp == 0)
				zero = true;
		}

		cin >> cons;

		print_math();

		menu();
	}

	void menu()
	{
		int point = -1, ind;

		while (point != 0)
		{
			cout << endl;
			cin >> point;

			if (point == 0)
				break;
			else if (point == 1)
			{
				cin >> ind;
				cout << "\nArray1";
				print_mass_el(arr1, ind);
			}
			else if (point == 2)
			{
				cin >> ind;
				cout << "\nArray2";
				print_mass_el(arr2, ind);
			}
		} 
	}


	void print_math()
	{
		cout << "\nArray1= ";
		print_mass(arr1);
		arr_arith(arr1, 1);
		sort(arr1, 1);

		cout << "\nArray2= ";
		print_mass(arr2);
		arr_arith(arr2, 2);
		sort(arr2, 2);

		cout << "\nsumma= ";
		for (int i = 0; i < arr1.size(); i++)
			cout << arr1[i] + arr2[i] << ' ';

		cout << "\nraznost= ";
		for (int i = 0; i < arr1.size(); i++)
			cout << arr1[i] - arr2[i] << ' ';

		cout << "\nproizv= ";
		for (int i = 0; i < arr1.size(); i++)
			cout << arr1[i] * arr2[i] << ' ';

		if (zero)
			cout << "\ndelenie na 0";
		else {
			cout << "\ndelenie= ";
			for (int i = 0; i < arr1.size(); i++)
				if (arr2[i] != 0)
					cout << arr1[i] / arr2[i] << ' ';
		}
	}

	void arr_arith(vector <int> arr, int t)
	{
		cout << "\nArray" << t << "+const= ";
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] + cons << ' ';

		cout << "\nArray" << t << "-const= ";
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] - cons << ' ';

		cout << "\nArray" << t << "*const= ";
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] * cons << ' ';
	}

	void sort(vector <int> arr, int t)
	{
		vector <int> temp = booble(arr);
		
		cout << "\nsort up Array" << t << "= ";
		print_mass(temp);

		reverse(temp.begin(), temp.end());
		cout << "\nsort down Array" << t << "= ";
		print_mass(temp);
	}

	vector <int> booble(vector <int> arr) 
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


	void print_mass_el(vector <int> arr, int ind)
	{
		if (ind >= i_min && ind <= i_max)
			cout << "[" << ind << "]= " << arr[ind + abs(i_min)];
		else
			cout << " wrong index " << ind;
	}
	void print_mass(vector <int> arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << ' ';
		}
	}
};

int main()
{
	massive M;

	M.input();

	return 0;
}