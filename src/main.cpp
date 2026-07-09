#include "application.h"

int main()
{
    Application application;

    if(application.init())
    {
        application.run();
        application.shutdown();
    }
}
