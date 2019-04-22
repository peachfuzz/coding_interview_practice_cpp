#include <string>
#include <cstring>
// #include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string line = "ababcbacadefegdehijhklij";
    map<char, int> element_and_count;

    // getline(cin, line);
    int len = line.length();
    for (int i = 0; i < len; i++)
    {
        // this would check if the value exists in the string
        // if (element_and_count.find(line[i]) == element_and_count.end())
        // { // not found
        //     element_and_count.insert(make_pair(line[i], 1));
        // }
        // else
        // {
        //     element_and_count[line[i]]++;
        // }

        // apparently no need for checking
        element_and_count[line[i]]++;
    }
    cout << "done\n";

    for (auto x : element_and_count)
        cout << x.first << " " << x.second << endl;

    cout << "done\n";
    return 0;
}