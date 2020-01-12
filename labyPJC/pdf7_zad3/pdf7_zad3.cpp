#include <iostream>
#include <ostream>

class Resistor {
private:
	double resistance;

public:
	Resistor() : resistance(0) {}
	Resistor(double resistance) : resistance(resistance) {}

	double r() {
		return resistance;
	}
	void r(double newValue) {
		resistance = newValue;
	}

	Resistor operator + (const Resistor&) const;
	Resistor operator * (const Resistor&) const;
	friend std::ostream& operator << (std::ostream& stream, const Resistor& L);
};

inline Resistor Resistor::operator + (const Resistor& res) const {
	return Resistor(resistance + res.resistance);
}
inline Resistor Resistor::operator * (const Resistor& res) const {
	return Resistor((resistance * res.resistance) / (resistance + res.resistance));
}

std::ostream& operator << (std::ostream& stream, const Resistor& res) {
	return stream << "[Resistance: " << res.resistance << "]";
};

int main()
{
	Resistor r1, r2(6);
	r1.r(3);
	std::cout << (r1 + r2) << " " << (r1 * r2) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
