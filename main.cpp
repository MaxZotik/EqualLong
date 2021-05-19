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
        if(str[0] == '.' || (str[0] == '-' && str[1] == '.')){
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

//
std::string substrStartZero(std::string str){
    std::string strTemp;
    bool zero = true;

    for(int i = 0; i < str.length(); i++){
        if(zero && str[0] == '-'){
            std::cout << "if(str[0] == '-')" << std::endl;
            strTemp += str[0];
            zero = false;
        }else if(str[i] != '0'){
            std::cout << "else if(str[i] != '0')" << std::endl;
            strTemp += str.substr(i, str.length());
            break;
        }
    }

    return strTemp;
}

//
std::string substrEndZero(std::string str){
    std::string strTemp;
    std::cout << str << "\n";

    for(int i = str.length() - 1; i >= 0; i--){
        std::cout << "for(int i = str.length() - 1; i > 0; i--) " << i << "\n";
        if(str[i] != '0'){
            strTemp = str.substr(0, i + 1);
            std::cout << "if(str[i] == '0') " << strTemp << "\n";
        }
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

    if(strOne.length() > strTwo.length()){

        std::cout << "if(substrStartZero(strOne).length() > substrStartZero(strTwo).length())" << "\n";
        std::cout << strOne << strTwo << "\n";
        return 1;
    }else if(strOne.length() < strTwo.length()){
        std::cout << "if(substrStartZero(strOne).length() < substrStartZero(strTwo).length())" << "\n";
        std::cout << strOne << strTwo << "\n";
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

/*
    if(substrEndZero(strOne).length() > substrEndZero(strTwo).length()){
        return 1;
    }

    if(substrEndZero(strOne).length() < substrEndZero(strTwo).length()){
        return -1;
    }

    if(substrEndZero(strOne).length() == substrEndZero(strTwo).length()){

        for(int i = 0; i < substrEndZero(strOne).length(); i++){
            if(substrEndZero(strOne)[i] < substrEndZero(strTwo)[i]){
                return -1;
            }
            if(substrEndZero(strOne)[i] > substrEndZero(strTwo)[i]){
                return 1;
            }
        }
    }
*/
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

    std::cout << ((oneIndexPoint != -1) ? strOne.substr(0, oneIndexPoint) : strOne) << " " << ((oneIndexPoint != -1) ? strOne.substr(oneIndexPoint + 1) : "") << " " << ((twoIndexPoint != -1) ? strTwo.substr(0, twoIndexPoint) : strTwo) << " " << ((twoIndexPoint != -1) ? strTwo.substr(twoIndexPoint + 1) : "") << "\n";
    std::cout << strOneLeft << " " << strOneRight << " " << strTwoLeft << " " << strTwoRight << "\n";

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

    std::string numberOne = "00100.110";
    std::string numberTwo = "100.1";

    /*
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
*/
    if (!correctNumber(numberOne) || !correctNumber(numberTwo)) {
        std::cout << "invalid number entered \n";
    }

    std::cout << substrStart(numberOne) << std::endl;
    std::cout << std::endl;
	std::cout << equalsNumber(numberOne, numberTwo) << std::endl;

	/*
	int i = numberTwo.find('.');
	std::cout << numberTwo.substr(0, i) << std::endl;
    std::cout << numberTwo.substr(i + 1) << std::endl;

    int a = numberOne.find('.');
    std::cout << a << std::endl;
    std::cout << substrStartZero(numberOne) << std::endl;
    std::cout << substrEndZero(numberTwo) << std::endl;
    */


}
