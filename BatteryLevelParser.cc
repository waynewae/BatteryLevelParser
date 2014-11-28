#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	string line;
	string writefile = "battery.log";
	string readfile = "PowerCalculator@4316001.log";
	int hour_current = 0;
	int hour_pre = 0;
	string time;
	string level;

	fstream read;
	read.open(readfile.c_str(), ios::in);
	if(!read) cout << "Open battery.log failed.\n";
	else cout << "Open battery.log successful.\n\n";

	fstream write;
	write.open(writefile.c_str(), ios::out | ios::trunc);
	if(!write) cout << "Open PowerCalculator@4316001.log failed.\n";
	else cout << "Open PowerCalculator@4316001.log successful.\n\n";

	while(getline(read, line))
	{
		if(line.length() >= 8)
		{
			hour_current = atoi(line.substr(8, 2).c_str());
			if(hour_current != hour_pre)
			{
				hour_pre = hour_current;
				time.assign(line.substr(0, 14));
				level.assign(line.substr(line.find_first_of(')'), line.length()));
				cout << "Before erase: " << level << endl;
				level.erase(0, level.find(',') + 1 );
				level.erase(0, level.find(',') + 1 );
				level.erase(0, level.find(',') + 1 );
				level.erase(0, level.find(',') + 1 );
				cout << "After erase: " << level << endl;
				level.assign(level.substr(0, level.find(',')));
				write << time << ',' << level << endl;
				//write << line << endl;
			}
		}
	}


	return 0;
}
