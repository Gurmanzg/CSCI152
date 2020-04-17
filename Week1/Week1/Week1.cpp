#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

using namespace std;

struct Color {
    float red;
    float green;
    float blue;

    static Color random() {
        static std::mt19937 engine{ std::random_device{}() };
        static std::uniform_real_distribution<float> dist{ 0, 1 };

        return Color{ dist(engine), dist(engine), dist(engine) };
    }

};

void colorSink(std::unique_ptr<Color> color) {
    std::cout << "Success!\n";
}

ostream& operator<<(ostream& os, const Color& c) {
    os << c.red << ',' << c.green << ',' << c.blue << "\n";
    return os;
}

int main() {

    std::cout << "Hello, World\n";
    auto c = Color::random();
    std::cout << "First color is: " << c << "\n";
    //#1 IS COMPLETE 


    // 2. here is a list of ten colors, print them out in order, and then in reverse order
    std::cout << "Here I am showing what the original list is" << '\n';
    std::vector<Color> colors;
    for (int i = 0; i < 10; i++) {
        Color::random();
        colors.push_back(Color::random());
        std::cout << colors[i] << '\n';
    }


    std::cout << "Here is the REVERESED version of the list" << '\n';


    // 3. find the color in the list that is darkest and print it out
    // the darkest color is defined as the color where the sum of the red, green, and blue components is the smallest




    // 4. order the colors from smallest 'blue' value to largest 'blue' value and print them out




    // 5. create a std::unique_ptr to a color on the free-store and call it 'colorPtr', pass this color to the
    // 'colorSink' function.
    // i.e. auto colorPtr = ...
}