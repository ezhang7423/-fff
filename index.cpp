#include "reflection/index.h"
#include "future/index.h"
#include "mantra/index.h"
#include <unistd.h>
#include <sys/wait.h>
#include <thread>
#include <iostream>

using namespace std;
int main()
{
    int *status;
    thread fut(fut::main);
    fut.detach();
    thread man(man::main);
    man.detach();

    pid_t ref = fork();

    if (ref == 0)
    {
        // do some stuff as child
        sleep(2);
        cout << "lol im going to die now" << endl;
        sleep(1);
        return 0;
    }
    else
    {
        waitpid(ref, status, WCONTINUED);
        cout << "the other guy finished so i can go now" << endl;
        return 0;
    }
}
