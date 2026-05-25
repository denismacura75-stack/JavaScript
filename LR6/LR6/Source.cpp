#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <cmath>

using namespace std;

class Series {
public:
    virtual double getJ(int j) = 0;
    virtual double getSum(int n) = 0;
    virtual void print() = 0;
    virtual ~Series() = 0;
};

Series::~Series() {}

class Linear : public Series {
private:
    double a1, d;

public:
    Linear(double a1, double d) : a1(a1), d(d) {}

    double getJ(int j) override {
        return a1 + (j - 1) * d;
    }

    double getSum(int n) override {
        return (n / 2.0) * (2 * a1 + (n - 1) * d);
    }

    void print() override {
        cout << "Arithmetic: a1=" << a1 << " d=" << d << endl;
    }

    void specialFunc() {
        cout << "Special function of Linear\n";
    }
};

class Exponential : public Series {
private:
    double a1, r;

public:
    Exponential(double a1, double r) : a1(a1), r(r) {}

    double getJ(int j) override {
        return a1 * pow(r, j - 1);
    }

    double getSum(int n) override {
        if (r == 1)
            return a1 * n;
        return a1 * (pow(r, n) - 1) / (r - 1);
    }

    void print() override {
        cout << "Geometric: a1=" << a1 << " r=" << r << endl;
    }
};

void showSeries(Series& s) {
    s.print();
    cout << "j=3: " << s.getJ(3) << endl;
    cout << "sum(5): " << s.getSum(5) << endl;
    cout << "------------------\n";
}

int main() {
    srand(time(0));

    Series* arr[8];

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            arr[i] = new Linear(rand() % 10 + 1, rand() % 5 + 1);
        }
        else {
            arr[i] = new Exponential(rand() % 5 + 1, rand() % 3 + 2);
        }
    }

    for (int i = 0; i < 8; i++) {
        showSeries(*arr[i]);

        if (typeid(*arr[i]) == typeid(Linear)) {
            Linear* l = dynamic_cast<Linear*>(arr[i]);
            if (l) {
                l->specialFunc();
            }
        }

        cout << endl;
    }

    for (int i = 0; i < 8; i++) {
        delete arr[i];
    }

    return 0;
}