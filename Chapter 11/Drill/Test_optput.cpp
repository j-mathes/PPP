// Jared Mathes
// 2018-09-01
// Chapter 11
// Drill

#include "../../std_lib_facilities.h"

int main()
try
{
	int birth_year{ 1900 };
	cout << "Birth year: " << showbase << dec << '\t' << birth_year << endl;
	cout << "In Hex : " << hex << '\t' << birth_year << endl;
	cout << "In Oct : " << oct << '\t' << birth_year << endl;
	cout << "My current age : " << dec << '\t' << 2018 - birth_year << endl;

	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	
	double new_number{ 1234567.89 };

	cout << defaultfloat << new_number << endl;
	cout << fixed << new_number << endl;
	cout << scientific << new_number << endl;

	struct personal_information
	{
		string lastname;
		string firstname;
		string phone;
		string email;
	};

	constexpr char tab{ '\t' };
	vector<personal_information> addressbook;

	addressbook.push_back(personal_information{ "Mathes", "Jared", "123-1111", "mail1@mail.com" });
	addressbook.push_back(personal_information{ "Mathes", "Juanita", "123-2222", "mail2@mail.com" });
	addressbook.push_back(personal_information{ "Mathes", "McKinley", "123-3333", "mail3@mail.com" });
	addressbook.push_back(personal_information{ "Mathes", "Kennedy", "123-4444", "mail4@mail.com" });
	addressbook.push_back(personal_information{ "Mathes", "Cage", "123-5555", "mail5@mail.com" });

	cout << setw(13) << "Last Name" << tab << setw(13) << "First Name" << tab << setw(9) << "Phone" << tab << setw(15) << "Email" << endl;
	cout << setw(13) << "------------" << tab << setw(13) << "-------------" << tab << setw(9) << "--------" << tab << setw(15) << "----------------" << endl;
	for (auto entry : addressbook)
	{
		cout << setw(13) << entry.lastname << tab << setw(13) << entry.firstname << tab << setw(9) << entry.phone << tab << setw(15) << entry.email << endl;
	}

	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}