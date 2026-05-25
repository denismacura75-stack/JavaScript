#include <iostream>
#include <vector>

using namespace std;

class Array {
private:
    vector<double> data;

public:
    Array(int n) {
        data.resize(n);
    }

    void input() {
        for (size_t i = 0; i < data.size(); i++) {
            cin >> data[i];
        }
    }

    void output() {
        for (double x : data) {
            cout << x << " ";
        }
        cout << endl;
    }

    double productEvenIndex() {
        double product = 1;
        for (size_t i = 0; i < data.size(); i += 2) {
            product *= data[i];
        }
        return product;
    }

    double sumBetweenZeros() {
        int first = -1, last = -1;

        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == 0) {
                if (first == -1) first = i;
                last = i;
            }
        }

        if (first == -1 || first == last) return 0;

        double sum = 0;
        for (int i = first + 1; i < last; i++) {
            sum += data[i];
        }

        return sum;
    }
};

int main() {
    int n;
    cin >> n;

    Array arr(n);

    arr.input();

    cout << "Array: ";
    arr.output();

    cout << "Product of elements with even indices: "
        << arr.productEvenIndex() << endl;

    cout << "Sum between first and last zero: "
        << arr.sumBetweenZeros() << endl;

    return 0;
}