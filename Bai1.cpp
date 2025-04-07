#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;
struct date {
	int day, month, year;
};
struct tim {
	int hour, minute, second;
	int operator - (time const& obj) {
		return (hour - obj.hour) * 60 * 60 + (minute - obj.minute) * 60 + second - obj.second;
	}
};
struct log {
	string from_number, to_number;
	date date = { 1,1,1 };
	struct time from_time = { 0,0,0 }, end_time = { 0,0,0 };
};
vector<string> split(const string& str, char delim = ' ')
{
	vector<string> result;

	string substr;
	stringstream ss(str);
	while (ss.good())
	{
		getline(ss, substr, delim);
		result.push_back(substr);
	}

	return result;
}
int main()
{
	vector<struct log> logs;
	bool quering = false;
	string line;
	struct log log;
	vector<string> words, tokens;
	do {
		getline(cin, line);
		words = split(line);
		if (words[0] == "#")
			if (quering)
				break;
			else {
				quering = true;
				continue;
			}
		if (!quering) {
			if (words[0] == "call") {
				log.from_number = words[1];
				log.to_number = words[2];
				tokens = split(words[3], '-');
				log.date.year = stoi(tokens[0]);
				log.date.month = stoi(tokens[1]);
				log.date.day = stoi(tokens[2]);
				tokens = split(words[4], ':');
				log.from_time.hour = stoi(tokens[0]);
				log.from_time.minute = stoi(tokens[1]);
				log.from_time.second = stoi(tokens[2]);
				tokens = split(words[5], ':');
				log.end_time.hour = stoi(tokens[0]);
				log.end_time.minute = stoi(tokens[1]);
				log.end_time.second = stoi(tokens[2]);
				logs.push_back(log);
			}
			continue;
		}
		if (words[0] == "?check_phone_number") {
			size_t i, result = 1;
			for (i = 0; i < logs.size(); ++i) {
				if (!regex_match(logs[i].from_number, regex("^[0-9]{10}$")))
					result = 0;
				if (!regex_match(logs[i].to_number, regex("^[0-9]{10}$")))
					result = 0;
				if (result == 1)
					break;
			}
			cout << result << endl;
			continue;
		}
		if (words[0] == "?number_calls_from") {
			size_t i, result = 0;
			for (i = 0; i < logs.size(); ++i) {
				if (logs[i].from_number == words[1])
					++result;
			}
			cout << result << endl;
			continue;
		}
		if (words[0] == "?number_total_calls") {
			cout << logs.size() << endl;
			continue;
		}
		if (words[0] == "?count_time_calls_from") {
			size_t i, result = 0;
			for (i = 0; i < logs.size(); ++i) {
				if (logs[i].from_number == words[1])
					result += logs[i].end_time - logs[i].from_time;
			}
			cout << result << endl;
			continue;
		}
	} while (true);
}
