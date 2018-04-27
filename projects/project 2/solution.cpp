#include "mbed.h"
#include "math.h"

#define PI 3.141592653589

class Delay
{
    private:
        float previous_value;
    public:
        float process(float current_value)
        {
            float return_value = previous_value;
            previous_value = current_value;
            return return_value;
        }

        float getValue()
        {
            return previous_value;
        }
};

class Notch
{
    private:
        float a0, a1, a2, b1, b2, k, r, f, bw;
        Delay delay1, delay2;

    public:
        Notch(float fs, float noise, float D_bw)
        {
            f = noise / fs;
            bw = D_bw / fs;
            r = 1 - (3 * bw);
            k = (1 - (2 * r * cos(2 * PI * f)) + pow(r, 2)) / (2 - (2 * cos(2 * PI * f)));
            a0 = k;
            a1 = (-2) * k * cos(2 * PI * f);
            a2 = k;
            b1 = (-2) * r * cos(2 * PI * f);
            b2 = pow(r, 2);
        }

        float process(float value)
        {
            float stage_1 = value - b1 * delay1.getValue() - b2 * delay2.getValue();

            float result = a0 * stage_1 + a1 * delay1.getValue() + a2 * delay2.getValue();

            delay2.process(
                delay1.process(stage_1)
            );

            return result;
        }

};


AnalogIn input(PF_3);
AnalogOut output(PA_5);

int main()
{
    Notch notch1(40000, 1000, 100);
    Notch notch2(40000, 5000, 500);
    Notch notch3(40000, 10000, 500);

    while (1)
    {
        output.write(
            notch1.process(
                notch2.process(
                    notch3.process(
                        input.read()
                    )
                )
            )
        );

        wait(0.000019);
    }
}
