#include <iostream>

class Bochka {
private:
    double volume;  // объем бочки в литрах
    double concentration;  // концентрация вещества в бочке (в процентах)

public:
    Bochka(double initialVolume, double initialConcentration)
        : volume(initialVolume), concentration(initialConcentration) {}

    double GetVolume() const {
        return volume;
    }

    double GetConcentration() const {
        return concentration;
    }

    void Pereliv(Bochka& other) {
        double perelivVolume = 1.0;
        double transferredConcentration = (concentration * perelivVolume) / volume;

        concentration -= transferredConcentration;
        volume -= perelivVolume;

        other.concentration += transferredConcentration;
        other.volume += perelivVolume;
    }
};

class IterativePereliv {
public:
    static int FindIterationNumber(Bochka& spirt, Bochka& water) {
        int iteration = 0;

        while (spirt.GetConcentration() > 50.0) {
            spirt.Pereliv(water);
            water.Pereliv(spirt);

            iteration++;
        }

        return iteration;
    }
};

int main() {
    Bochka spirt(10.0, 96.0);
    Bochka water(10.0, 0.0);

    int iteration = IterativePereliv::FindIterationNumber(spirt, water);

    std::cout << "Number of iterations: " << iteration << std::endl;

    return 0;
}
