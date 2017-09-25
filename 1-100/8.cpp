class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()){
            return 0;
        }
        int sign = 1;
        size_t i = 0;
        for (; i < str.size(); ++i){
            if (str.at(i) != ' '){
                break;
            }
        }
        if (str.at(i) == '+'){
            sign = 1;
            i++;
        }
        else if (str.at(i) == '-'){
            sign = -1;
            i++;
        }

        int digit = 0;
        for (; i < str.size(); ++i){
            if (str.at(i) < '0' || str.at(i) > '9'){
                break;
            }
            // overflow
            if (digit * sign > INT32_MAX / 10 ||
                (digit * sign == INT32_MAX / 10 && (str.at(i) - '0') > INT32_MAX % 10)){
                return INT32_MAX;
            }
            if (digit * sign < INT32_MIN / 10 ||
                (digit * sign == INT32_MIN / 10 && (str.at(i) - '0') * sign < INT32_MIN % 10)){
                return INT32_MIN;
            }
            
            digit = digit * 10 + (str.at(i) - '0');
        }
        
        return digit * sign;
    }
};