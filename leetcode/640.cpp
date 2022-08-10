#include <bits/stdc++.h>

std::string slove(std::string s)
{
    int numX = 0, num = 0, dir = 1, sign = 1, tmpNum = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '+') sign = 1;
        else if(s[i] == '-') sign = -1;
        else if(s[i] == '=') {dir = -1; sign = 1; tmpNum=1;}
        else if(s[i] == 'x') numX += dir*sign*tmpNum;
        else {
            tmpNum = 0;
            while(i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
                tmpNum += tmpNum*10 + (s[i]-'0');
                i++;
            }
            if(i == (int)s.size() || s[i] != 'x') {num += dir*sign*tmpNum; tmpNum = 1;}
            i--;
            std::cout << num << std::endl;
        }
        
    }
    std::cout << numX << " " << num << std::endl;

    return numX == 0 ? (num == 0 ? "Infinite solutions" : "No solution"): "x="+std::to_string(-num/numX);

}

int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;
    std::string res = slove(s);
    std::cout << res << std::endl;
    return 0;
}
