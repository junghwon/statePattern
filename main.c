#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statePattern.h"

int main (int argc, char *argv[])
{
    initialize ();
    onPlayOrPause ();
    onPlayOrPause ();
    onPlayOrPause ();
    onStop ();

    return (0);
}