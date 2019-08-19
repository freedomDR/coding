class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL) return false;
        if(*string == '\0') return false;
        if((*string == '+' || *string == '-') || (*string >= '0' && *string <= '9')) string++;
        else return false;
        bool isDot = false, isE = false;
        while(*string != '\0'){
            if((*string == 'e' || *string == 'E') && !isE) {
                string++;
                if(*(string) == '\0') return false;
                if(*(string)=='+' || *(string) == '-') {string++;isDot=true;continue;}
                if(*(string) >= '0' && *(string) <='9') {string++;isDot=true;continue;}
                return false;
            }
            if(*string == '.' && !isDot) isDot = true;
            else if(*string < '0' || *string > '9') return false;
            else;
            string++;
        }
        return true;
    }

};
