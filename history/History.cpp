#include <vector>

struct Registry{
	int a;
	std::string operand;
	int b;
	int result;
};

class History{
	private:
		std::vector<Registry> registries;
	public:
		void addRegistry(std::string operand, int a, int b, int result){
			registries.push_back({a, operand, b, result});
		}

		void show(){
			for(const auto& r: registries){
				std::cout << r.a << " " << r.operand << " " << r.b << " = " << r.result << "\n";
			}
		}

};
