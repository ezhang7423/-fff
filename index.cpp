#include "reflection/index.h"
#include "future/index.h"
#include "mantra/index.h"
#include <unistd.h>
#include <thread>

using namespace std;
int main()
{
    int *ready = new int(0);
    thread fut(fut::main);
    fut.detach();
    thread man(man::main);
    man.detach();

    pid_t ref = fork();

    if (ref == 0)
    {
        // do some stuff as child
        return 0;
    }
    else
    {
        while (true)
        {
            if (*ready == 1)
            {
                break;
            }
        }
    }
}
