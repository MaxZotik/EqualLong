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

std::string substrStart(std::string str){
    std::string strTemp;
    for(int i = 0; i < str.length(); i++){
        if(str[0] == '0'){
            strTemp += '0';
            return strTemp;
        }
        if(str[i] == '.'){
            return strTemp;
        }

        strTemp += str[i];
    }

    return strTemp;
}

std::string substrEnd(std::string str){
    bool point = false;
    std::string strTemp;

    for(int i = 0; i < str.length(); i++){
        if(str[0] == '0' || str[i] == '.'){
            point = true;
        }

        if(point){
            strTemp += str[i];
        }
    }

    return strTemp;
}

int equalsTwoNumber(std::string strOne, std::string strTwo){

    //1 - more, 0 - equal, -1 - less

    if(substrStart(strOne).length() > substrStart(strTwo).length()){
        return 1;
    }

    if(substrStart(strOne).length() < substrStart(strTwo).length()){
        return -1;
    }

    if(substrStart(strOne).length() == substrStart(strTwo).length()){

        for(int i = 0; i < substrStart(strOne).length(); i++){
            if(substrStart(strOne)[i] < substrStart(strTwo)[i]){
                return -1;
            }
            if(substrStart(strOne)[i] > substrStart(strTwo)[i]){
                return 1;
            }
        }
    }

    if(substrEnd(strOne).length() > substrEnd(strTwo).length()){
        return 1;
    }

    if(substrEnd(strOne).length() < substrEnd(strTwo).length()){
        return -1;
    }

    if(substrEnd(strOne).length() == substrEnd(strTwo).length()){

        for(int i = 0; i < substrEnd(strOne).length(); i++){
            if(substrEnd(strOne)[i] < substrEnd(strTwo)[i]){
                return -1;
            }
            if(substrEnd(strOne)[i] > substrEnd(strTwo)[i]){
                return 1;
            }
        }
    }

    return 0;
}

std::string equalsNumber(std::string strOne, std::string strTwo){

    std::string less = "Less", more = "More", equal = "Equal";

    if(strOne[0] == '-' && strTwo[0] != '-'){
        return less;
    }
    if(strOne[0] != '-' && strTwo[0] == '-'){
        return more;
    }

    if(strOne[0] != '-' && strTwo[0] != '-'){
        if(equalsTwoNumber(strOne, strTwo) == 1) {
            return more;
        }else if(equalsTwoNumber(strOne, strTwo) == -1){
            return less;
        }else{
            return equal;
        }
    }

    if(strOne[0] == '-' && strTwo[0] == '-'){
        if(equalsTwoNumber(strTwo, strOne) == 1) {
            return more;
        }else if(equalsTwoNumber(strTwo, strOne) == -1){
            return less;
        }else{
            return equal;
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

    std::cout << std::endl;
	std::cout << equalsNumber(numberOne, numberTwo) << std::endl;
}
