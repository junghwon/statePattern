#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

typedef struct _state {
    int state;
    const struct _state *(*const stop)(const struct _state *pThis);
    const struct _state *(*const playOrPause)(const struct _state *pThis);
} state_t;

void initialize (void);
void onStop (void);
void onPlayOrPause (void);

#endif // STATE_PATTERN_H