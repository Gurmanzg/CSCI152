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
    // ... do nothing ... do not change the signature or implementation of this function
    std::cout << "\nSuccess!\n";
}

ostream& operator<<(ostream& out, const Color& c)
{
    out << c.red << ", " << c.green << ", " << c.blue;
    return out;
}

int main() {

    std::cout << "Hello, World\n";

    // 1. overload the output stream operator so that you can print this color directly to the output stream
    auto c = Color::random();
    std::cout << "\nFirst color is: " << c << "\n\n";

    // 2. here is a list of ten colors, print them out in order, and then in reverse order
    std::vector<Color> colors;
    for (int i = 0; i < 10; i++) {
        colors.push_back(Color::random());
    }

    cout << "Colors initial order: \n";
    for (Color& c : colors) {
        cout << c << "\n";
    }

    cout << "\n\nColors reversed order\n";
    reverse(colors.begin(), colors.end());
    for (Color& c : colors)
        cout << c << "\n";
    // 3. find the color in the list that is darkest and print it out
    // the darkest color is defined as the color where the sum of the red, green, and blue components is the smallest

    int darkestColorIndex = 0;
    int smallestValue = 1000; //stupid value lol
    for (int i = 0; i < 10; i++) {
        auto currentColorSum = colors.at(i).red + colors.at(i).green + colors.at(i).blue;
        if (currentColorSum < smallestValue) {
            smallestValue = currentColorSum;
            darkestColorIndex++;
        }
    }

    cout << "\nThe darkest color: " << colors.at((darkestColorIndex));

    // 4. order the colors from smallest 'blue' value to largest 'blue' value and print them out
    std::vector<float> blueValues(10);
    for (int i = 0; i < 10; i++) {
        blueValues.at(i) = colors.at(i).blue;
    }

    std::sort(blueValues.begin(), blueValues.end());
    std::vector<Color> properValues(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (blueValues.at(i) == colors.at(j).blue) {
                properValues.at(i) = colors.at(j);
            }
        }
    }

    cout << "\n\nOrdered based off the color blue\n";
    for (Color& c : properValues) {
        cout << c << "\n";
    }

    // 5. create a std::unique_ptr to a color on the free-store and call it 'colorPtr', pass this color to the
    // 'colorSink' function.
    // i.e. auto colorPtr = ...
    cout << "\n\n";
    unique_ptr<Color> colorPtr = unique_ptr<Color>(new Color());
    colorSink(move(colorPtr));
}