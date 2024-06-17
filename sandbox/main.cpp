#include <NPlot/NPlot.h>

int main(int argc, char *argv[])
{
    np::Scene scene("3DPlot");

    while (true)
    {
        scene.Update();
    }
    return 0;
}
