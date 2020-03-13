#include "reflection/index.h"
#include "future/index.h"
#include "mantra/index.h"
#include <unistd.h>
#include <sys/wait.h>
#include <thread>

using namespace std;
int main()
{

    thread fut(fut::main);
    fut.detach();
    thread man(man::main);
    man.detach();

    pid_t ref = fork();

    if (ref == 0)
    {
        // do some stuff as child
        sleep(2);
        return 0;
    }
    else
    {
        waitpid(ref);
        cout << "the other guy finished so i can go now" << endl;
        return 0;
    }
}
