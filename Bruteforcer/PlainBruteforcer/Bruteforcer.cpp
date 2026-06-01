// This is the plain version with no vectorisation
#include <iostream>
#include <chrono>
std::string guess;
std::string password;
int currentLength;

bool checkPassword() {
    if (guess == password) {
		std::cout << ("Password found: " + guess) << std::endl;
		return true;
    }
    else {
        return false;
	}
}

bool bruteForcer() {
    if (guess.length() == currentLength) {
        return checkPassword();
    }
    for (int i = 33; i < 127; i++) {
        guess.push_back(static_cast<char>(i));
		//std::cout << guess << std::endl;
        //uncomment this line if you want to see it iterate through different guesses
        if (bruteForcer()) return true;
        guess.pop_back();
    }
    return false;
}


int main()
{
    std::cout << "Enter your password: ";
    std::cin >> password; 
    auto start = std::chrono::high_resolution_clock::now();
    for (currentLength = 4; currentLength <= 10; currentLength++) {
        if (bruteForcer()) break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double secs = std::chrono::duration<double>(end - start).count();
    std::cout << "Elapsed: " << secs << "s\n";
}

