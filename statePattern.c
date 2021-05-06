#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statePattern.h"

static const state_t *ignore (const state_t *pThis);
static const state_t *startPlay (const state_t *pThis);
static const state_t *stopPlay (const state_t *pThis);
static const state_t *pausePlay (const state_t *pThis);
static const state_t *resumePlay (const state_t *pThis);

static const state_t *pCurrentState;

const state_t IDLE = {
    0,
    ignore,
    startPlay,
};

const state_t PLAY = {
    1,
    stopPlay,
    pausePlay,
};

const state_t PAUSE = {
    2,
    stopPlay,
    resumePlay,
};

static const void printCurrentState (const state_t *pThis)
{
    char *string = "     ";

    switch (pThis->state) {
        default:
        case 0:
            string = "IDLE";
            break;
        case 1:
            string = "PLAY";
            break;
        case 2:
            string = "PAUSE";
            break;
    }

    printf ("Current state is %s\n", string);
}


static const state_t *ignore (const state_t *pThis)
{ 
    return (pCurrentState);
}

static const state_t *startPlay (const state_t *pThis)
{
    return (&PLAY);
}

static const state_t *stopPlay (const state_t *pThis)
{
    return (&IDLE);
}

static const state_t *pausePlay (const state_t *pThis)
{
    return (&PAUSE);
}

static const state_t *resumePlay (const state_t *pThis)
{
    return (&PLAY);
}


void initialize (void)
{
    pCurrentState = &IDLE;
}

void onStop (void)
{
    pCurrentState = pCurrentState->stop (pCurrentState);
    printCurrentState (pCurrentState);
}

void onPlayOrPause (void)
{
    pCurrentState = pCurrentState->playOrPause (pCurrentState);
    printCurrentState (pCurrentState);
}