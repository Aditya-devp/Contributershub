/*
Description of the code:

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

    If the group's length is 1, append the character to s.
    Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

*/

#include<bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    if (chars.size() == 1)
        return 1;
    vector<char> result;

    int count = 1;

    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] != chars[i - 1])
        {
            result.push_back(chars[i - 1]);

            if (count != 1)
            {
                string temp = "";
                while (count > 0)
                {
                    temp += (count % 10) + '0';
                    count /= 10;
                }

                for (int i = temp.size() - 1; i >= 0; i--)
                    result.push_back(temp[i]);
            }
            count = 1;
        }
        else
            count++;
    }

    if (count >= 1)
        result.push_back(chars[chars.size() - 1]);
    if (count > 1)
    {
        string temp = "";
        while (count > 0)
        {
            temp += (count % 10) + '0';
            count /= 10;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
            result.push_back(temp[i]);
    }

    chars = result;
    return result.size();
}

int main(){
    vector<char> chars{'a','a','b','b','c','c','c'};

    cout<<compress(chars);

    return 0;
}