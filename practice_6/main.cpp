#include <iostream>
#include <cmath>

using namespace std;

class SignalGenerator {
protected:
    double amplitude; // Амплитуда сигнала
    double frequency; // Частота сигнала (Гц)
    double phase; // Начальная фаза (радианы)
public:
    // Конструктор с параметрами по умолчанию
    SignalGenerator (double amp = 1.0, double freq = 1.0, double ph = 0.0) :
        amplitude (amp), frequency (freq), phase (ph) {}
    // Виртуальный деструктор
    virtual ~SignalGenerator() = default;
    // Get/Set методы
    virtual double getAmplitude() const { return amplitude; }
    virtual void setAmplitude(double amp) { amplitude = amp; }
    virtual double getFrequency() const { return frequency; }
    virtual void setFrequency(double freq) { frequency = freq; }
    virtual double getPhase() const { return phase; }
    virtual void setPhase(double ph) { phase = ph; }
    // Чисто виртуальный метод для вычисления значения сигнала
    virtual double calculate(double time) const = 0;
    // Виртуальный метод для вывода информации о генераторе
    virtual void printInfo() const {
        cout << "Некий базовый генератор сигнала" << endl;
        cout << "Амплитуда: " << amplitude << endl;
        cout << "Частота: " << frequency << " Гц" << endl;
        cout << "Фаза: " << phase << "рад" << endl;
    }
    // Метод для генерации и вывода N значений сигнала
    virtual void generateAndPrint(int count, double timeStep) const {
        cout << "Базовый сигнал " << count << " отчётов от нуля, шаг "
             << timeStep << "сек:" << endl;
        for (int i = 0; i < count; i++) {
            double t = i * timeStep;
            cout << "s(" << t << ") = " << calculate(t) << endl;
        }
    }
};

class SineGenerator : public SignalGenerator {
public:
    SineGenerator (double amp = 1.0, double freq = 1.0, double ph = 0.0) :
        SignalGenerator (amp, freq, ph) {}

    double calculate (double t) const override {
        return amplitude * sin(2 * M_PI * frequency * t + phase);
    }

    void printInfo () const override {
        cout << "Генератор синусоидального сигнала" << endl;
        cout << "Амплитуда: " << amplitude << endl;
        cout << "Частота: " << frequency << " Гц" << endl;
        cout << "Фаза: " << phase << " рад" << endl;
    }
};

class SquareGenerator : public SignalGenerator {
public:
    SquareGenerator (double amp = 1.0, double freq = 1.0, double ph = 0.0) :
        SignalGenerator (amp, freq, ph) {}

    double calculate (double t) const override {
        return amplitude * (sin(2 * M_PI * frequency * t + phase)) >= 0 ? 1 : -1;
    }

    void printInfo () const override {
        cout << "Генератор квадратного сигнала" << endl;
        cout << "Амплитуда: " << amplitude << endl;
        cout << "Частота: " << frequency << " Гц" << endl;
        cout << "Фаза: " << phase << " рад" << endl;
    }
};

class TriangleGenerator : public SignalGenerator {
public:
    TriangleGenerator (double amp = 1.0, double freq = 1.0, double ph = 0.0) :
        SignalGenerator (amp, freq, ph) {}

    double calculate (double t) const override {
        return (2 * amplitude / M_PI) * asin(sin(2 * M_PI * frequency * t + phase));
    }

    void printInfo () const override {
        cout << "Генератор треугольного сигнала" << endl;
        cout << "Амплитуда: " << amplitude << endl;
        cout << "Частота: " << frequency << " Гц" << endl;
        cout << "Фаза: " << phase << " рад" << endl;
    }
};

int main () {
    // Создание массива указателей на базовый класс
    const int GENERATOR_COUNT = 3;
    SignalGenerator* generators[GENERATOR_COUNT];
    // Инициализация разными типами генераторов
    generators[0] = new SineGenerator(1.0, 2.0, 0.0); // А=1, f=2 Гц, φ=0
    generators[1] = new SquareGenerator(1.0, 2.0, 0.0); // А=1, f=2 Гц, φ=0
    generators[2] = new TriangleGenerator(1.0, 2.0, 0.0); // А=1, f=2 Гц, φ=0
    // Демонстрация полиморфизма
    for (int i = 0; i < GENERATOR_COUNT; ++i) {
        generators[i]->printInfo();
        generators[i]->generateAndPrint(100, 0.01); // 100 значений, шаг 0.01 сек
        cout << "------------------------" << endl;
    }
    // Демонстрация работы через базовый класс
    SignalGenerator* signal = new SineGenerator(0.5, 1.0, 0.0);
    cout << "Значение в t=0.5: " << signal->calculate(0.5) << endl;
    // Замена на другой тип сигнала (полиморфное поведение)
    delete signal;
    signal = new SquareGenerator(0.5, 1.0, 0.0);
    cout << "Значение в t=0.5: " << signal->calculate(0.5) << endl;
    // Освобождение памяти
    for (int i = 0; i < GENERATOR_COUNT; ++i) {
        delete generators[i];
    }
    delete signal;

    return 0;
}
