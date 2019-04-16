#include <iostream>




int main() {

	class enemy {
	public:
		~enemy() {
			std::cout << "enemy has died" << std::endl;
		}
	protected:
		int health = 100;
		int attackpow;
		int defensepow;
		int attack() {
			return 1;
		}
		int defend() {
			return 0;
		}
	};

	class fish : protected enemy {
		fish() {
			std::cout << "I am fish!" << std::endl;
		}
	protected:
		int attackpow = 5;
		int defensepow = 2;
	};

	fish 


	getchar();
	return 0;
}