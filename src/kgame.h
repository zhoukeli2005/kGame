/*
 *
 *
 *
 */

#ifndef _k_Game_h_
#define _k_Game_h_

struct kGame;
struct kEGL;

struct kGame *
kGame_create(struct kEGL * egl);

void
kGame_update(struct kGame * k, float delta_time);

void
kGame_draw(struct kGame * k);

#endif

