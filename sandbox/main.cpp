#include <NPlot/NPlot.h>

int main(int argc, char *argv[])
{
    np::Scene scene("3DPlot");

    while (scene.IsRunning())
    {
        scene.Update();
    }
    return 0;
}
