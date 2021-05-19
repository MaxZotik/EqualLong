#include <iostream>


bool correctNumber(std::string numberReal){
    bool result = true, point = true, minus = true;

  	for (int i = 0; i < numberReal.length(); i++) {
		if (numberReal[0] == '-' && minus) {
			minus = false;
		} else if (numberReal[i] == '.' && point) {
			point = false;
		} else if (numberReal[i] < '0' || numberReal[i] > '9') {
			result = false;
		}
	}
	return result;
}

std::string substrStartZero(std::string str){
    std::string strTemp;
    bool zero = true;

    for(int i = 0; i < str.length(); i++){
        if(zero && str[0] == '-'){
            strTemp += str[0];
            zero = false;
        }else if(str[i] != '0'){
            strTemp += str.substr(i, str.length());
            break;
        }
    }

    return strTemp;
}

std::string substrEndZero(std::string str){
    std::string strTemp;

    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] != '0'){
            strTemp = str.substr(0, i + 1);
        }
    }

    return strTemp;
}

int equalsTwoNumber(std::string strOne, std::string strTwo){

    //1 - more, 0 - equal, -1 - less

    if(strOne.length() > strTwo.length()){
        return 1;
    }else if(strOne.length() < strTwo.length()){
        return -1;
    }else{
        for(int i = 0; i < strOne.length() || i < strTwo.length(); i++){
            if(strOne[i] < strTwo[i]){
                return -1;
            }
            if(strOne[i] > strTwo[i]){
                return 1;
            }
        }
    }

    return 0;
}

std::string equalsNumber(std::string strOne, std::string strTwo){

    std::string less = "Less", more = "More", equal = "Equal";
    std::string strOneLeft, strOneRight, strTwoLeft, strTwoRight;
    
    int oneIndexPoint = strOne.find('.');
    int twoIndexPoint = strTwo.find('.');

    strOneLeft = substrStartZero((oneIndexPoint != -1) ? strOne.substr(0, oneIndexPoint) : strOne);
    strOneRight = substrEndZero((oneIndexPoint != -1) ? strOne.substr(oneIndexPoint + 1) : "");
    strTwoLeft = substrStartZero((twoIndexPoint != -1) ? strTwo.substr(0, twoIndexPoint) : strTwo);
    strTwoRight = substrEndZero((twoIndexPoint != -1) ? strTwo.substr(twoIndexPoint + 1) : "");

    if(strOne[0] == '-' && strTwo[0] != '-'){
        return less;
    }else if(strOne[0] != '-' && strTwo[0] == '-'){
        return more;
    }else{
        if(equalsTwoNumber(strOneLeft, strTwoLeft) == 1) {
            return more;
        }else if(equalsTwoNumber(strOneLeft, strTwoLeft) == -1){
            return less;
        }else{
            if(equalsTwoNumber(strOneRight, strTwoRight) == 1) {
                return more;
            }else if(equalsTwoNumber(strOneRight, strTwoRight) == -1) {
                return more;
            }
        }
    }

    return equal;
}


int main() {

    std::string numberOne;
    std::string numberTwo;

    for(;;){
        std::cout << "Enter real number one: ";
        std::cin >> numberOne;
        std::cout << "Enter real number two: ";
        std::cin >> numberTwo;

        if (!correctNumber(numberOne) || !correctNumber(numberTwo)) {
            std::cout << "invalid number entered \n";
        }else{
            break;
        }
    }

	std::cout << equalsNumber(numberOne, numberTwo) << std::endl;
}
