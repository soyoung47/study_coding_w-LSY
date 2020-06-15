#include <bitset>
#include <string>

int solution(int N) {

    string binary = bitset<32>(N).to_string();

    bool isFirst = false;
    int max = 0; //gap max length
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if (!isFirst && binary[i] == '1')
            isFirst = true;
        else if (isFirst)
        {
            if (binary[i] == '0')
                count++;
            else
            {
                if (max < count)
                    max = count;

                count = 0;
            }
        }
    }

    return max;
}
